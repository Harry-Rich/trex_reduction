import numpy as np
import mcstasscript as ms
import mcstastox as mx
import scipp as sc
from scipp.typing import VariableLike
from scippneutron.conversion.beamline import _canonical_length
from scipy.ndimage import label

# Utility Functions

def v_bin_norm(binner, event_object, vanad_object, mag_Q_dim = 'mag_Q'):

    if type(binner) != list:
        binner = [binner]

    hist_kwargs = {bin_dim.dims[0]: bin_dim for bin_dim in binner}
    hist_event = event_object.bin(**hist_kwargs).hist(**hist_kwargs)
    hist_vanad = vanad_object.bin(**hist_kwargs).hist(**hist_kwargs)

    if mag_Q_dim in hist_kwargs:
        Q_dict = {mag_Q_dim:hist_kwargs[mag_Q_dim]}
        vanad_q_mag = vanad_object.bin(**Q_dict).hist(**Q_dict)
        hist_norm = hist_event / vanad_q_mag
    else:
        print(f'dimension: {mag_Q_dim} not found, not normalising over q')
        vanad_q_mag = 1
        hist_norm  = np.nan

    return hist_event, hist_vanad, hist_norm


def _calc_pulse_centroid(tof_monitor,threshold=0, to_s=1e-6):
    # Assumes all pulses are evenly spaced in xaxis - but isn't bin data??? confirm this
    # Confirm correct way to axis tof data - is xaxis correct????? 
    mask = tof_monitor.Intensity != threshold
    labels, num_features = label(mask)
    weighted_sum = np.bincount(labels, weights=tof_monitor.xaxis * tof_monitor.Intensity)[1:]
    weight_total = np.bincount(labels, weights=tof_monitor.Intensity)[1:]

    coms = weighted_sum / weight_total * to_s
    coms = sc.array(dims=['tof'], values=coms, unit='s')
    return coms


def produce_trex_event_object(event_object, data_path, monitor_name, centroids=None, to_s=1e-6):
    """ """

    with mx.Read(data_path) as loaded_data:
        monitor_position = loaded_data.get_global_component_coordinates(monitor_name)

    data = ms.load_data(data_path)
    monitor = ms.name_search(monitor_name, data)

    event_object.coords["monitor_position"] = sc.vector(
        value=monitor_position, unit="m"
    )

    if centroids is None:
        centroids = _calc_pulse_centroid(monitor)

    look_up_tab = sc.DataArray(
    data=centroids,                     
    coords={'tof': centroids})

    tof_to_centroid = sc.lookup(look_up_tab, mode='previous')
    event_object = event_object.transform_coords(time_on_monitor=tof_to_centroid)

    return event_object


# Graph Functions

def straight_monitor_beam(
    source_position: VariableLike, monitor_position: VariableLike
):
    """ """
    return _canonical_length(monitor_position) - _canonical_length(source_position)


def Lm(monitor_beam):
    """ """
    return _canonical_length(sc.norm(monitor_beam))


# -------- ki ---------


def unit_ki_from_monitor_and_sample(
    monitor_position: VariableLike, sample_position: VariableLike
):
    """ """
    d = sample_position - monitor_position
    unit_ki = d / sc.norm(d)
    return unit_ki


def vi_from_monitor(Lm, time_on_monitor):
    """ """
    vi = Lm / time_on_monitor
    return vi


def mag_ki_from_vi(vi):
    """ """
    mag_ki = (sc.constants.neutron_mass * vi) / sc.constants.hbar
    return sc.to_unit(mag_ki, "1/angstrom")


def ki(mag_ki, unit_ki):
    """ """
    return mag_ki * unit_ki


# -------- kf ---------


def unit_kf_from_detector_and_sample(
    position: VariableLike, sample_position: VariableLike
):
    """ """
    d = position - sample_position
    unit_kf = d / sc.norm(d)

    return unit_kf


def time_on_sample_from_velocity(L1, vi):
    """ """
    time_on_sample = L1 / vi
    return time_on_sample


def vf_from_tof(L2, tof, time_on_sample):
    """ """
    vf = L2 / (tof - time_on_sample)
    return vf


def mag_kf_from_vf(vf):
    """ """
    mag_kf = (sc.constants.neutron_mass * vf) / sc.constants.hbar
    return sc.to_unit(mag_kf, "1/angstrom")


def kf(mag_kf, unit_kf):
    """ """
    return mag_kf * unit_kf


# --------- Q and dE --------


def Q_from_k(ki, kf):
    """ """
    return ki - kf


def mag_Q(Q):
    """ """
    return sc.to_unit(sc.norm(Q), "1/angstrom")


def energy_transfer_from_k(mag_kf, mag_ki):
    """ """
    dE = (sc.constants.hbar**2 / (2 * sc.constants.neutron_mass)) * (
        mag_ki**2 - mag_kf**2
    )
    return sc.to_unit(dE, sc.units.meV)


inelastic = {}

inelastic["Lm"] = Lm
inelastic["monitor_beam"] = straight_monitor_beam

inelastic["unit_ki"] = unit_ki_from_monitor_and_sample
inelastic["vi"] = vi_from_monitor
inelastic["mag_ki"] = mag_ki_from_vi
inelastic["ki"] = ki

inelastic["unit_kf"] = unit_kf_from_detector_and_sample
inelastic["vf"] = vf_from_tof
inelastic["mag_kf"] = mag_kf_from_vf
inelastic["kf"] = kf

inelastic["Q"] = Q_from_k
inelastic["mag_Q"] = mag_Q
inelastic["dE"] = energy_transfer_from_k
inelastic["time_on_sample"] = time_on_sample_from_velocity
