import mcstasscript as ms

def add_benzene_sample(instr, AT, AT_RELATIVE, ROTATED_RELATIVE, Sqw_coh, Sqw_inc, ROTATED = ['0.0', '0.0', '0.0'], name = 'iso_samp', before = None, after = None):
    # Comp instance iso_samp, placement and parameters
    iso_samp = instr.add_component(name,'Isotropic_Sqw', AT=AT, AT_RELATIVE=AT_RELATIVE, ROTATED=ROTATED, ROTATED_RELATIVE=ROTATED_RELATIVE, before = before, after=after)
    # EXTEND at iso_samp
    iso_samp.append_EXTEND(r'''
    if (!SCATTERED) ABSORB;
    ''')
    iso_samp.powder_format = '{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }'
    iso_samp.Sqw_coh =  Sqw_coh
    iso_samp.Sqw_inc = Sqw_inc
    iso_samp.geometry = '0'
    iso_samp.radius = '0.025'
    iso_samp.thickness = '0.0005'
    iso_samp.xwidth = '0'
    iso_samp.yheight = '0.05'
    iso_samp.zdepth = '0'
    iso_samp.threshold = '1e-20'
    iso_samp.order = '0'
    # iso_samp.T = '290'
    iso_samp.verbose = '1'
    iso_samp.d_phi = '0'
    iso_samp.concentric = '0'
    # iso_samp.rho = '0'
    iso_samp.sigma_abs = '0'
    # iso_samp.sigma_coh = '5.51'
    # iso_samp.sigma_inc = '82.02'
    iso_samp.classical = '1'
    iso_samp.powder_Dd = '0'
    iso_samp.powder_DW = '0'
    # iso_samp.density = '0'
    # iso_samp.weight = '0'
    iso_samp.p_interact = '0.2'
    iso_samp.norm = '-1'
    iso_samp.powder_barns = '1'
    # iso_samp.quantum_correction = '"Frommhold"'

def add_vanadium_sample(instr, AT, AT_RELATIVE, ROTATED_RELATIVE, ROTATED = ['0.0', '0.0', '0.0'], name = 'iso_samp', before = None, after = None):
    # Comp instance iso_samp, placement and parameters
    iso_samp = instr.add_component(name,'Incoherent', AT=AT, AT_RELATIVE=AT_RELATIVE, ROTATED=ROTATED, ROTATED_RELATIVE=ROTATED_RELATIVE, before = before, after=after)
    # EXTEND at iso_samp
    iso_samp.append_EXTEND(r'''
if (!SCATTERED) ABSORB;
    ''')
    iso_samp.geometry = '0'
    iso_samp.radius = '0.05'
    iso_samp.thickness = '0.003'
    iso_samp.xwidth = '0'
    iso_samp.yheight = '0.05'
    iso_samp.zdepth = '0'
    iso_samp.concentric = '0'
    iso_samp.p_interact = '0.2'
    # iso_samp.quantum_correction = '"Frommhold"'
