#!/usr/bin/env python3
# Automatically generated file. 
# Format:    Python script code
# McStas <http://www.mcstas.org>
# Instrument: ISIS_LET.instr (ISIS_LET)
# Date:       Tue Apr 21 14:59:02 2026
# File:       ISIS_LET_generated.py

import mcstasscript as ms

# Python McStas instrument description
def make(name="LET_generated", input_path=None):
    if input_path is not None:
        instr = ms.McStas_instr(name, author = "McCode Py-Generator", origin = "ESS DMSC", input_path=input_path)
    else:
        instr = ms.McStas_instr(name, author = "McCode Py-Generator", origin = "ESS DMSC")
    
# Add collected DEPENDENCY strings
    instr.set_dependency('')

    # *****************************************************************************
    # * Start of instrument 'ISIS_LET' generated code
    # *****************************************************************************
    # MCSTAS system dir is "/opt/anaconda3/envs/mcstas/share/mcstas/resources/"


    # *****************************************************************************
    # * instrument 'ISIS_LET' and components DECLARE
    # *****************************************************************************

    # Instrument parameters:

    Ei = instr.add_parameter('double', 'Ei', value=3.7, comment='Parameter type (double) added by McCode py-generator')
    dE = instr.add_parameter('double', 'dE', value=1.1, comment='Parameter type (double) added by McCode py-generator')
    Ch3_speed = instr.add_parameter('double', 'Ch3_speed', value=100, comment='Parameter type (double) added by McCode py-generator')
    Ch5_speed = instr.add_parameter('double', 'Ch5_speed', value=200, comment='Parameter type (double) added by McCode py-generator')
    Ch2_phase = instr.add_parameter('double', 'Ch2_phase', value=95000, comment='Parameter type (double) added by McCode py-generator')
    pha_offset = instr.add_parameter('double', 'pha_offset', value=80e-6, comment='Parameter type (double) added by McCode py-generator')
    res = instr.add_parameter('string', 'res', value='"HF"', comment='Parameter type (string) added by McCode py-generator')
    snout = instr.add_parameter('string', 'snout', value='"out"', comment='Parameter type (string) added by McCode py-generator')
    monitors_on = instr.add_parameter('int', 'monitors_on', value=1, comment='Parameter type (int) added by McCode py-generator')
    movable_monitors = instr.add_parameter('int', 'movable_monitors', value=0, comment='Parameter type (int) added by McCode py-generator')
    #sample_inc = instr.add_parameter('string', 'sample_inc', value=sample_inc_string, comment='Parameter type (string) added by McCode py-generator')

    component_definition_metadata = {
    }
    instr.append_declare(r'''
double SE2K, v_foc, emin, emax, lam_min, lam_max, jitter=7e-7;
double Ch1_speed, Ch2_speed=10, Ch2_offset=14500, Ch4_speed, Ch5_slit, snout_length;
double L_Ch1=7.833, L_Ch2=8.200, L_Ch3=11.749, L_Ch4=15.664, L_Ch5=23.499;
double L_sample=25, L2=3.5, Ch1_5_halfgap=0.005, smidge = 0.001;
    ''')


    instr.append_initialize(r'''

// get chopper5 slit width and speeds from resolution setting
if (strcmp(res,"HR") == 0){
	Ch5_slit = 0.015;
	Ch1_speed = Ch5_speed / 2;
} else if (strcmp(res,"I") == 0){
	Ch5_slit = 0.02;
	Ch1_speed = Ch5_speed / 4;
} else if (strcmp(res,"HF") == 0){
	Ch5_slit = 0.028;
	Ch1_speed = Ch5_speed / 4;
} else {
	printf("\n Need valid resolution option, 'HR', 'I' or 'HF'\n");
}

// decide whether snout is in or out
if (strcmp(snout,"out") == 0){
	snout_length = 0.0;
} else {
	snout_length = 0.23;
}

SE2K	= SE2V * V2K;
v_foc	= SE2V * sqrt(Ei);
emax	= Ei*dE;
emin	= Ei/dE;
lam_min   	= 2 * PI / SE2K / sqrt(emax);
lam_max 	= 2 * PI / SE2K / sqrt(emin);

printf("\nv_foc: %f", v_foc);
printf("\nChopper 1 delay: %f\n", (L_Ch1 - Ch1_5_halfgap)/v_foc+pha_offset);
printf("\nEnergy range: Emin = %f, Emax = %f\n", emin, emax);
    ''')


    # *****************************************************************************
    # * instrument 'ISIS_LET' TRACE
    # *****************************************************************************
    
    # Comp instance Origin, placement and parameters
    Origin = instr.add_component('Origin','Arm')
    
    
    # Comp instance SourceMantid, placement and parameters
    SourceMantid = instr.add_component('SourceMantid','Commodus_I3', AT=['0', '0', '0'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    SourceMantid.Face = '"Let_TS2_HydroMod_Upgrade2021_8cmThick.mcstas"'
    SourceMantid.E0 = 'emin'
    SourceMantid.E1 = 'emax'
    SourceMantid.modPosition = '0'
    SourceMantid.dist = '1.68'
    SourceMantid.verbose = '0'
    SourceMantid.beamcurrent = '1'
    SourceMantid.modXsize = '0.12'
    SourceMantid.modZsize = '0.12'
    SourceMantid.xw = '0.04'
    SourceMantid.yh = '0.09'
    
    # Comp instance shutter, placement and parameters
    shutter = instr.add_component('shutter','Guide_channeled', AT=['0', '0', '1.680'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    shutter.w1 = '0.04'
    shutter.h1 = '0.09'
    shutter.w2 = '0'
    shutter.h2 = '0'
    shutter.l = '1.980'
    shutter.R0 = '0.995'
    shutter.Qc = '0'
    shutter.alpha = '4.38'
    shutter.m = '0'
    shutter.nslit = '1'
    shutter.d = '0.0005'
    shutter.Qcx = '0.0218'
    shutter.Qcy = '0.0218'
    shutter.alphax = '4.38'
    shutter.alphay = '4.38'
    shutter.W = '3e-3'
    shutter.mx = '2'
    shutter.my = '3'
    shutter.nu = '0'
    shutter.phase = '0'
    
    # Comp instance insert, placement and parameters
    insert = instr.add_component('insert','Guide_channeled', AT=['0', '0', '3.740'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    insert.w1 = '0.04'
    insert.h1 = '0.09'
    insert.w2 = '0'
    insert.h2 = '0'
    insert.l = '2.500'
    insert.R0 = '0.995'
    insert.Qc = '0'
    insert.alpha = '4.38'
    insert.m = '0'
    insert.nslit = '1'
    insert.d = '0.0005'
    insert.Qcx = '0.0218'
    insert.Qcy = '0.0218'
    insert.alphax = '4.38'
    insert.alphay = '4.38'
    insert.W = '3e-3'
    insert.mx = '2'
    insert.my = '3'
    insert.nu = '0'
    insert.phase = '0'
    
    # Comp instance after_insert, placement and parameters
    after_insert = instr.add_component('after_insert','Guide_channeled', AT=['0', '0', '6.300'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    after_insert.w1 = '0.04'
    after_insert.h1 = '0.09'
    after_insert.w2 = '0'
    after_insert.h2 = '0'
    after_insert.l = '1.514'
    after_insert.R0 = '0.995'
    after_insert.Qc = '0'
    after_insert.alpha = '4.38'
    after_insert.m = '0'
    after_insert.nslit = '1'
    after_insert.d = '0.0005'
    after_insert.Qcx = '0.0218'
    after_insert.Qcy = '0.0218'
    after_insert.alphax = '4.38'
    after_insert.alphay = '4.38'
    after_insert.W = '3e-3'
    after_insert.mx = '2'
    after_insert.my = '3'
    after_insert.nu = '0'
    after_insert.phase = '0'
    
    # Comp instance Monitor1, placement and parameters
    Monitor1 = instr.add_component('Monitor1','TOF_monitor', AT=['0', '0', 'L_Ch1 - Ch1_5_halfgap - smidge'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN monitors_on == 1 at Monitor1
    Monitor1.set_WHEN('monitors_on == 1')
    
    Monitor1.nt = '100'
    Monitor1.filename = '"monitor1.dat"'
    Monitor1.xmin = '-0.05'
    Monitor1.xmax = '0.05'
    Monitor1.ymin = '-0.05'
    Monitor1.ymax = '0.05'
    Monitor1.xwidth = '0.06'
    Monitor1.yheight = '0.1'
    Monitor1.tmin = '1e6 * ( ( L_Ch1 - Ch1_5_halfgap - smidge ) / SE2V / sqrt ( emax ) + pha_offset )'
    Monitor1.tmax = '1e6 * ( ( L_Ch1 - Ch1_5_halfgap - smidge ) / SE2V / sqrt ( emin ) + pha_offset )'
    Monitor1.dt = '1.0'
    Monitor1.restore_neutron = '1'
    Monitor1.nowritefile = '! monitors_on'
    
    # Comp instance LET_Chopper1_disk1, placement and parameters
    LET_Chopper1_disk1 = instr.add_component('LET_Chopper1_disk1','DiskChopper', AT=['0', '0', 'L_Ch1 - Ch1_5_halfgap'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    LET_Chopper1_disk1.theta_0 = '0'
    LET_Chopper1_disk1.radius = '0.350'
    LET_Chopper1_disk1.yheight = '0.095'
    LET_Chopper1_disk1.nu = 'Ch1_speed'
    LET_Chopper1_disk1.nslit = '6'
    LET_Chopper1_disk1.jitter = 'jitter'
    LET_Chopper1_disk1.delay = '( L_Ch1 - Ch1_5_halfgap ) / v_foc + pha_offset'
    LET_Chopper1_disk1.isfirst = '0'
    LET_Chopper1_disk1.n_pulse = '1'
    LET_Chopper1_disk1.abs_out = '1'
    LET_Chopper1_disk1.phase = '0'
    LET_Chopper1_disk1.xwidth = '0.056'
    LET_Chopper1_disk1.verbose = '0'
    
    # Comp instance LET_Chopper1_disk2, placement and parameters
    LET_Chopper1_disk2 = instr.add_component('LET_Chopper1_disk2','DiskChopper', AT=['0', '0', '( L_Ch1 + Ch1_5_halfgap )'], AT_RELATIVE='Origin', ROTATED=['0', '0', '180'], ROTATED_RELATIVE='LET_Chopper1_disk1')
    
    LET_Chopper1_disk2.theta_0 = '0'
    LET_Chopper1_disk2.radius = '0.350'
    LET_Chopper1_disk2.yheight = '0.095'
    LET_Chopper1_disk2.nu = 'Ch1_speed'
    LET_Chopper1_disk2.nslit = '6'
    LET_Chopper1_disk2.jitter = 'jitter'
    LET_Chopper1_disk2.delay = '( L_Ch1 + Ch1_5_halfgap ) / v_foc + pha_offset'
    LET_Chopper1_disk2.isfirst = '0'
    LET_Chopper1_disk2.n_pulse = '1'
    LET_Chopper1_disk2.abs_out = '1'
    LET_Chopper1_disk2.phase = '0'
    LET_Chopper1_disk2.xwidth = '0.056'
    LET_Chopper1_disk2.verbose = '0'
    
    # Comp instance Monitor2, placement and parameters
    Monitor2 = instr.add_component('Monitor2','TOF_monitor', AT=['0', '0', 'L_Ch1 + Ch1_5_halfgap + smidge'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN monitors_on == 1 at Monitor2
    Monitor2.set_WHEN('monitors_on == 1')
    
    Monitor2.nt = '100'
    Monitor2.filename = '"monitor2.dat"'
    Monitor2.xmin = '-0.05'
    Monitor2.xmax = '0.05'
    Monitor2.ymin = '-0.05'
    Monitor2.ymax = '0.05'
    Monitor2.xwidth = '0.06'
    Monitor2.yheight = '0.1'
    Monitor2.tmin = '1e6 * ( ( L_Ch1 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emax ) + pha_offset )'
    Monitor2.tmax = '1e6 * ( ( L_Ch1 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emin ) + pha_offset )'
    Monitor2.dt = '1.0'
    Monitor2.restore_neutron = '1'
    Monitor2.nowritefile = '! monitors_on'
    
    # Comp instance between_chop1_and_chop2, placement and parameters
    between_chop1_and_chop2 = instr.add_component('between_chop1_and_chop2','Guide_channeled', AT=['0', '0', '7.852'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    between_chop1_and_chop2.w1 = '0.04'
    between_chop1_and_chop2.h1 = '0.09'
    between_chop1_and_chop2.w2 = '0'
    between_chop1_and_chop2.h2 = '0'
    between_chop1_and_chop2.l = '0.312'
    between_chop1_and_chop2.R0 = '0.995'
    between_chop1_and_chop2.Qc = '0'
    between_chop1_and_chop2.alpha = '4.38'
    between_chop1_and_chop2.m = '0'
    between_chop1_and_chop2.nslit = '1'
    between_chop1_and_chop2.d = '0.0005'
    between_chop1_and_chop2.Qcx = '0.0218'
    between_chop1_and_chop2.Qcy = '0.0218'
    between_chop1_and_chop2.alphax = '4.38'
    between_chop1_and_chop2.alphay = '4.38'
    between_chop1_and_chop2.W = '3e-3'
    between_chop1_and_chop2.mx = '2'
    between_chop1_and_chop2.my = '3'
    between_chop1_and_chop2.nu = '0'
    between_chop1_and_chop2.phase = '0'
        
    # Comp instance LET_Chopper2, placement and parameters
    LET_Chopper2 = instr.add_component('LET_Chopper2','DiskChopper', AT=['0', '0', 'L_Ch2'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    LET_Chopper2.theta_0 = '0'
    LET_Chopper2.radius = '0.600'
    LET_Chopper2.yheight = '0.107'
    LET_Chopper2.nu = 'Ch2_speed'
    LET_Chopper2.nslit = '1'
    LET_Chopper2.jitter = 'jitter'
    LET_Chopper2.delay = '( Ch2_phase + Ch2_offset ) / 1e6'
    LET_Chopper2.isfirst = '0'
    LET_Chopper2.n_pulse = '1'
    LET_Chopper2.abs_out = '1'
    LET_Chopper2.phase = '0'
    LET_Chopper2.xwidth = '0.79'
    LET_Chopper2.verbose = '0'
    
    # Comp instance Monitor3, placement and parameters
    Monitor3 = instr.add_component('Monitor3','TOF_monitor', AT=['0', '0', 'L_Ch2 + smidge'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN monitors_on == 1 at Monitor3
    Monitor3.set_WHEN('monitors_on == 1')
    
    Monitor3.nt = '100'
    Monitor3.filename = '"monitor3.dat"'
    Monitor3.xmin = '-0.05'
    Monitor3.xmax = '0.05'
    Monitor3.ymin = '-0.05'
    Monitor3.ymax = '0.05'
    Monitor3.xwidth = '0.06'
    Monitor3.yheight = '0.1'
    Monitor3.tmin = '1e6 * ( ( L_Ch2 + smidge ) / SE2V / sqrt ( emax ) + pha_offset )'
    Monitor3.tmax = '1e6 * ( ( L_Ch2 + smidge ) / SE2V / sqrt ( emin ) + pha_offset )'
    Monitor3.dt = '1.0'
    Monitor3.restore_neutron = '1'
    Monitor3.nowritefile = '! monitors_on'
    
    # Comp instance between_chop2_and_chop3, placement and parameters
    between_chop2_and_chop3 = instr.add_component('between_chop2_and_chop3','Guide_channeled', AT=['0', '0', '8.236'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    between_chop2_and_chop3.w1 = '0.04'
    between_chop2_and_chop3.h1 = '0.09'
    between_chop2_and_chop3.w2 = '0'
    between_chop2_and_chop3.h2 = '0'
    between_chop2_and_chop3.l = '3.499'
    between_chop2_and_chop3.R0 = '0.995'
    between_chop2_and_chop3.Qc = '0'
    between_chop2_and_chop3.alpha = '4.38'
    between_chop2_and_chop3.m = '0'
    between_chop2_and_chop3.nslit = '1'
    between_chop2_and_chop3.d = '0.0005'
    between_chop2_and_chop3.Qcx = '0.0218'
    between_chop2_and_chop3.Qcy = '0.0218'
    between_chop2_and_chop3.alphax = '4.38'
    between_chop2_and_chop3.alphay = '4.38'
    between_chop2_and_chop3.W = '3e-3'
    between_chop2_and_chop3.mx = '2'
    between_chop2_and_chop3.my = '3'
    between_chop2_and_chop3.nu = '0'
    between_chop2_and_chop3.phase = '0'
    
    # Comp instance LET_Chopper3, placement and parameters
    LET_Chopper3 = instr.add_component('LET_Chopper3','DiskChopper', AT=['0', '0', 'L_Ch3'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    LET_Chopper3.theta_0 = '0'
    LET_Chopper3.radius = '0.340'
    LET_Chopper3.yheight = '0.090'
    LET_Chopper3.nu = 'Ch3_speed'
    LET_Chopper3.nslit = '2'
    LET_Chopper3.jitter = 'jitter'
    LET_Chopper3.delay = 'L_Ch3 / v_foc + pha_offset'
    LET_Chopper3.isfirst = '0'
    LET_Chopper3.n_pulse = '1'
    LET_Chopper3.abs_out = '1'
    LET_Chopper3.phase = '0'
    LET_Chopper3.xwidth = '0.045'
    LET_Chopper3.verbose = '0'
    
    # Comp instance Monitor4, placement and parameters
    Monitor4 = instr.add_component('Monitor4','TOF_monitor', AT=['0', '0', 'L_Ch3 + smidge'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN monitors_on == 1 at Monitor4
    Monitor4.set_WHEN('monitors_on == 1')
    
    Monitor4.nt = '100'
    Monitor4.filename = '"monitor4.dat"'
    Monitor4.xmin = '-0.05'
    Monitor4.xmax = '0.05'
    Monitor4.ymin = '-0.05'
    Monitor4.ymax = '0.05'
    Monitor4.xwidth = '0.06'
    Monitor4.yheight = '0.1'
    Monitor4.tmin = '1e6 * ( ( L_Ch3 + smidge ) / SE2V / sqrt ( emax ) + pha_offset )'
    Monitor4.tmax = '1e6 * ( ( L_Ch3 + smidge ) / SE2V / sqrt ( emin ) + pha_offset )'
    Monitor4.dt = '1.0'
    Monitor4.restore_neutron = '1'
    Monitor4.nowritefile = '! monitors_on'
    
    # Comp instance between_chop3_and_chop4, placement and parameters
    between_chop3_and_chop4 = instr.add_component('between_chop3_and_chop4','Guide_channeled', AT=['0', '0', '11.765'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    between_chop3_and_chop4.w1 = '0.04'
    between_chop3_and_chop4.h1 = '0.09'
    between_chop3_and_chop4.w2 = '0'
    between_chop3_and_chop4.h2 = '0'
    between_chop3_and_chop4.l = '3.886'
    between_chop3_and_chop4.R0 = '0.995'
    between_chop3_and_chop4.Qc = '0'
    between_chop3_and_chop4.alpha = '4.38'
    between_chop3_and_chop4.m = '0'
    between_chop3_and_chop4.nslit = '1'
    between_chop3_and_chop4.d = '0.0005'
    between_chop3_and_chop4.Qcx = '0.0218'
    between_chop3_and_chop4.Qcy = '0.0218'
    between_chop3_and_chop4.alphax = '4.38'
    between_chop3_and_chop4.alphay = '4.38'
    between_chop3_and_chop4.W = '3e-3'
    between_chop3_and_chop4.mx = '2'
    between_chop3_and_chop4.my = '3'
    between_chop3_and_chop4.nu = '0'
    between_chop3_and_chop4.phase = '0'
    
    # Comp instance LET_Chopper4, placement and parameters
    LET_Chopper4 = instr.add_component('LET_Chopper4','DiskChopper', AT=['0', '0', 'L_Ch4'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    LET_Chopper4.theta_0 = '0'
    LET_Chopper4.radius = '0.338'
    LET_Chopper4.yheight = '0.090'
    LET_Chopper4.nu = 'Ch5_speed / 2'
    # LET_Chopper4.nu = 'Ch5_speed * 2'
    LET_Chopper4.nslit = '6'
    LET_Chopper4.jitter = 'jitter'
    LET_Chopper4.delay = 'L_Ch4 / v_foc + pha_offset'
    LET_Chopper4.isfirst = '0'
    LET_Chopper4.n_pulse = '1'
    LET_Chopper4.abs_out = '1'
    LET_Chopper4.phase = '0'
    LET_Chopper4.xwidth = '0.045'
    LET_Chopper4.verbose = '0'
    
    # Comp instance Monitor5, placement and parameters
    Monitor5 = instr.add_component('Monitor5','TOF_monitor', AT=['0', '0', 'L_Ch4 + smidge'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN monitors_on == 1 at Monitor5
    Monitor5.set_WHEN('monitors_on == 1')
    
    Monitor5.nt = '100'
    Monitor5.filename = '"monitor5.dat"'
    Monitor5.xmin = '-0.05'
    Monitor5.xmax = '0.05'
    Monitor5.ymin = '-0.05'
    Monitor5.ymax = '0.05'
    Monitor5.xwidth = '0.06'
    Monitor5.yheight = '0.08'
    Monitor5.tmin = '1e6 * ( ( L_Ch4 + smidge ) / SE2V / sqrt ( emax ) + pha_offset )'
    Monitor5.tmax = '1e6 * ( ( L_Ch4 + smidge ) / SE2V / sqrt ( emin ) + pha_offset )'
    Monitor5.dt = '1.0'
    Monitor5.restore_neutron = '1'
    Monitor5.nowritefile = '! monitors_on'
    
    # Comp instance between_chop4_and_movable, placement and parameters
    between_chop4_and_movable = instr.add_component('between_chop4_and_movable','Guide_channeled', AT=['0', '0', '15.681'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    between_chop4_and_movable.w1 = '0.04'
    between_chop4_and_movable.h1 = '0.09'
    between_chop4_and_movable.w2 = '0'
    between_chop4_and_movable.h2 = '0.0639'
    between_chop4_and_movable.l = '5.800'
    between_chop4_and_movable.R0 = '0.995'
    between_chop4_and_movable.Qc = '0'
    between_chop4_and_movable.alpha = '4.38'
    between_chop4_and_movable.m = '0'
    between_chop4_and_movable.nslit = '1'
    between_chop4_and_movable.d = '0.0005'
    between_chop4_and_movable.Qcx = '0.0218'
    between_chop4_and_movable.Qcy = '0.0218'
    between_chop4_and_movable.alphax = '4.38'
    between_chop4_and_movable.alphay = '4.38'
    between_chop4_and_movable.W = '3e-3'
    between_chop4_and_movable.mx = '2'
    between_chop4_and_movable.my = '3'
    between_chop4_and_movable.nu = '0'
    between_chop4_and_movable.phase = '0'
    
    # Comp instance moveable_front_PSDmon, placement and parameters
    moveable_front_PSDmon = instr.add_component('moveable_front_PSDmon','PSD_monitor', AT=['0', '0', '21.485'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN movable_monitors == 1 at moveable_front_PSDmon
    moveable_front_PSDmon.set_WHEN('movable_monitors == 1')
    
    moveable_front_PSDmon.nx = '50'
    moveable_front_PSDmon.ny = '50'
    moveable_front_PSDmon.filename = '"moveable_front_PSDmon.dat"'
    moveable_front_PSDmon.xmin = '-0.05'
    moveable_front_PSDmon.xmax = '0.05'
    moveable_front_PSDmon.ymin = '-0.05'
    moveable_front_PSDmon.ymax = '0.05'
    moveable_front_PSDmon.xwidth = '0.06'
    moveable_front_PSDmon.yheight = '0.08'
    moveable_front_PSDmon.restore_neutron = '1'
    moveable_front_PSDmon.nowritefile = '! movable_monitors'
    
    # Comp instance moveable_front_Divmon, placement and parameters
    moveable_front_Divmon = instr.add_component('moveable_front_Divmon','Divergence_monitor', AT=['0', '0', '21.485'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN movable_monitors == 1 at moveable_front_Divmon
    moveable_front_Divmon.set_WHEN('movable_monitors == 1')
    
    moveable_front_Divmon.nh = '50'
    moveable_front_Divmon.nv = '50'
    moveable_front_Divmon.filename = '"moveable_front_Divmon.dat"'
    moveable_front_Divmon.xmin = '-0.05'
    moveable_front_Divmon.xmax = '0.05'
    moveable_front_Divmon.ymin = '-0.05'
    moveable_front_Divmon.ymax = '0.05'
    moveable_front_Divmon.nowritefile = '! movable_monitors'
    moveable_front_Divmon.xwidth = '0.06'
    moveable_front_Divmon.yheight = '0.08'
    moveable_front_Divmon.maxdiv_h = '3'
    moveable_front_Divmon.maxdiv_v = '3'
    moveable_front_Divmon.restore_neutron = '1'
    moveable_front_Divmon.nx = '0'
    moveable_front_Divmon.ny = '0'
    moveable_front_Divmon.nz = '1'
    
    # Comp instance moveable_guide, placement and parameters
    moveable_guide = instr.add_component('moveable_guide','Guide_channeled', AT=['0', '0', '21.489'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    moveable_guide.w1 = '0.04'
    moveable_guide.h1 = '0.0639'
    moveable_guide.w2 = '0.0311'
    moveable_guide.h2 = '0.05718'
    moveable_guide.l = '0.8813'
    moveable_guide.R0 = '0.995'
    moveable_guide.Qc = '0'
    moveable_guide.alpha = '4.38'
    moveable_guide.m = '4'
    moveable_guide.nslit = '1'
    moveable_guide.d = '0.0005'
    moveable_guide.Qcx = '0.0218'
    moveable_guide.Qcy = '0.0218'
    moveable_guide.alphax = '4.38'
    moveable_guide.alphay = '4.38'
    moveable_guide.W = '3e-3'
    moveable_guide.mx = '1'
    moveable_guide.my = '1'
    moveable_guide.nu = '0'
    moveable_guide.phase = '0'
    
    # Comp instance moveable_back_PSDmon, placement and parameters
    moveable_back_PSDmon = instr.add_component('moveable_back_PSDmon','PSD_monitor', AT=['0', '0', '22.372'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN movable_monitors == 1 at moveable_back_PSDmon
    moveable_back_PSDmon.set_WHEN('movable_monitors == 1')
    
    moveable_back_PSDmon.nx = '100'
    moveable_back_PSDmon.ny = '100'
    moveable_back_PSDmon.filename = '"moveable_back_PSDmon.dat"'
    moveable_back_PSDmon.xmin = '-0.05'
    moveable_back_PSDmon.xmax = '0.05'
    moveable_back_PSDmon.ymin = '-0.05'
    moveable_back_PSDmon.ymax = '0.05'
    moveable_back_PSDmon.xwidth = '0.06'
    moveable_back_PSDmon.yheight = '0.08'
    moveable_back_PSDmon.restore_neutron = '1'
    moveable_back_PSDmon.nowritefile = '! movable_monitors'
    
    # Comp instance moveable_back_Divmon, placement and parameters
    moveable_back_Divmon = instr.add_component('moveable_back_Divmon','Divergence_monitor', AT=['0', '0', '22.372'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN movable_monitors == 1 at moveable_back_Divmon
    moveable_back_Divmon.set_WHEN('movable_monitors == 1')
    
    moveable_back_Divmon.nh = '50'
    moveable_back_Divmon.nv = '50'
    moveable_back_Divmon.filename = '"moveable_back_Divmon.dat"'
    moveable_back_Divmon.xmin = '-0.05'
    moveable_back_Divmon.xmax = '0.05'
    moveable_back_Divmon.ymin = '-0.05'
    moveable_back_Divmon.ymax = '0.05'
    moveable_back_Divmon.nowritefile = '! movable_monitors'
    moveable_back_Divmon.xwidth = '0.06'
    moveable_back_Divmon.yheight = '0.08'
    moveable_back_Divmon.maxdiv_h = '3'
    moveable_back_Divmon.maxdiv_v = '3'
    moveable_back_Divmon.restore_neutron = '1'
    moveable_back_Divmon.nx = '0'
    moveable_back_Divmon.ny = '0'
    moveable_back_Divmon.nz = '1'
    
    # Comp instance funnel, placement and parameters
    funnel = instr.add_component('funnel','Guide_channeled', AT=['0', '0', '22.373'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    funnel.w1 = '0.031'
    funnel.h1 = '0.05711'
    funnel.w2 = '0.02'
    funnel.h2 = '0.04868'
    funnel.l = '1.107'
    funnel.R0 = '0.995'
    funnel.Qc = '0'
    funnel.alpha = '4.38'
    funnel.m = '4'
    funnel.nslit = '1'
    funnel.d = '0.0005'
    funnel.Qcx = '0.0218'
    funnel.Qcy = '0.0218'
    funnel.alphax = '4.38'
    funnel.alphay = '4.38'
    funnel.W = '3e-3'
    funnel.mx = '1'
    funnel.my = '1'
    funnel.nu = '0'
    funnel.phase = '0'
    
    # Comp instance LET_Chopper5_Disk1, placement and parameters
    LET_Chopper5_Disk1 = instr.add_component('LET_Chopper5_Disk1','DiskChopper', AT=['0', '0', 'L_Ch5 - Ch1_5_halfgap'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    LET_Chopper5_Disk1.theta_0 = '0'
    LET_Chopper5_Disk1.radius = '0.350'
    LET_Chopper5_Disk1.yheight = '0.06'
    LET_Chopper5_Disk1.nu = 'Ch5_speed'
    #LET_Chopper5_Disk1.nu = 'Ch5_speed * 8'
    LET_Chopper5_Disk1.nslit = '1'
    LET_Chopper5_Disk1.jitter = 'jitter'
    LET_Chopper5_Disk1.delay = '( L_Ch5 - Ch1_5_halfgap ) / v_foc + pha_offset'
    LET_Chopper5_Disk1.isfirst = '0'
    LET_Chopper5_Disk1.n_pulse = '1'
    LET_Chopper5_Disk1.abs_out = '1'
    LET_Chopper5_Disk1.phase = '0'
    LET_Chopper5_Disk1.xwidth = 'Ch5_slit'
    LET_Chopper5_Disk1.verbose = '0'
    
    # # Comp instance LET_Chopper5_Disk2, placement and parameters
    LET_Chopper5_Disk2 = instr.add_component('LET_Chopper5_Disk2','DiskChopper', AT=['0', '0', 'L_Ch5 + Ch1_5_halfgap'], AT_RELATIVE='Origin', ROTATED=['0', '0', '180'], ROTATED_RELATIVE='LET_Chopper5_Disk1')
    
    LET_Chopper5_Disk2.theta_0 = '0'
    LET_Chopper5_Disk2.radius = '0.350'
    LET_Chopper5_Disk2.yheight = '0.06'
    LET_Chopper5_Disk2.nu = 'Ch5_speed'
    # LET_Chopper5_Disk2.nu = 'Ch5_speed * 2'
    LET_Chopper5_Disk2.nslit = '1'
    LET_Chopper5_Disk2.jitter = 'jitter'
    LET_Chopper5_Disk2.delay = '( L_Ch5 + Ch1_5_halfgap ) / v_foc + pha_offset'
    LET_Chopper5_Disk2.isfirst = '0'
    LET_Chopper5_Disk2.n_pulse = '1'
    LET_Chopper5_Disk2.abs_out = '1'
    LET_Chopper5_Disk2.phase = '0'
    LET_Chopper5_Disk2.xwidth = 'Ch5_slit'
    LET_Chopper5_Disk2.verbose = '0'
    
    # Comp instance Monitor6, placement and parameters
    Monitor6 = instr.add_component('Monitor6','TOF_monitor', AT=['0', '0', 'L_Ch5 + Ch1_5_halfgap + smidge'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    # WHEN monitors_on == 1 at Monitor6
    Monitor6.set_WHEN('monitors_on == 1')
    
    Monitor6.nt = '100'
    Monitor6.filename = '"monitor6.dat"'
    Monitor6.xmin = '-0.05'
    Monitor6.xmax = '0.05'
    Monitor6.ymin = '-0.05'
    Monitor6.ymax = '0.05'
    Monitor6.xwidth = '0.06'
    Monitor6.yheight = '0.06'
    Monitor6.tmin = '1e6 * ( ( L_Ch5 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emax ) + pha_offset )'
    Monitor6.tmax = '1e6 * ( ( L_Ch5 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emin ) + pha_offset )'
    Monitor6.dt = '1.0'
    Monitor6.restore_neutron = '1'
    Monitor6.nowritefile = '! monitors_on'
    
    # Comp instance tanksection, placement and parameters
    tanksection = instr.add_component('tanksection','Guide_channeled', AT=['0', '0', '23.52'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    tanksection.w1 = '0.02'
    tanksection.h1 = '0.0484'
    tanksection.w2 = '0.020'
    tanksection.h2 = '0.04'
    tanksection.l = '1.1'
    tanksection.R0 = '0.995'
    tanksection.Qc = '0'
    tanksection.alpha = '4.38'
    tanksection.m = '4'
    tanksection.nslit = '1'
    tanksection.d = '0.0005'
    tanksection.Qcx = '0.0218'
    tanksection.Qcy = '0.0218'
    tanksection.alphax = '4.38'
    tanksection.alphay = '4.38'
    tanksection.W = '3e-3'
    tanksection.mx = '1'
    tanksection.my = '1'
    tanksection.nu = '0'
    tanksection.phase = '0'
    
    # Comp instance snout, placement and parameters
    snout = instr.add_component('snout','Guide_channeled', AT=['0', '0', '24.622'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    snout.w1 = '0.02'
    snout.h1 = '0.04'
    snout.w2 = '0'
    snout.h2 = '0'
    snout.l = 'snout_length'
    snout.R0 = '0.995'
    snout.Qc = '0'
    snout.alpha = '4.38'
    snout.m = '4'
    snout.nslit = '1'
    snout.d = '0.0005'
    snout.Qcx = '0.0218'
    snout.Qcy = '0.0218'
    snout.alphax = '4.38'
    snout.alphay = '4.38'
    snout.W = '3e-3'
    snout.mx = '1'
    snout.my = '1'
    snout.nu = '0'
    snout.phase = '0'
    
    # Comp instance sample, placement and parameters
    sample = instr.add_component('sample','Arm', AT=['0', '0', 'L_sample'], AT_RELATIVE='Origin', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Origin')
    
    
    # Comp instance sample_PSDmon, placement and parameters
    sample_PSDmon = instr.add_component('sample_PSDmon','PSD_monitor', AT=['0', '0', '0'], AT_RELATIVE='sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample')
    
    sample_PSDmon.nx = '100'
    sample_PSDmon.ny = '100'
    sample_PSDmon.filename = '"sample_PSDmon.dat"'
    sample_PSDmon.xmin = '-0.05'
    sample_PSDmon.xmax = '0.05'
    sample_PSDmon.ymin = '-0.05'
    sample_PSDmon.ymax = '0.05'
    sample_PSDmon.xwidth = '0.04'
    sample_PSDmon.yheight = '0.06'
    sample_PSDmon.restore_neutron = '1'
    sample_PSDmon.nowritefile = '0'
    
    # Comp instance sample_Divmon, placement and parameters
    sample_Divmon = instr.add_component('sample_Divmon','Divergence_monitor', AT=['0', '0', '0'], AT_RELATIVE='sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample')
    
    sample_Divmon.nh = '50'
    sample_Divmon.nv = '50'
    sample_Divmon.filename = '"sample_Divmon.dat"'
    sample_Divmon.xmin = '-0.05'
    sample_Divmon.xmax = '0.05'
    sample_Divmon.ymin = '-0.05'
    sample_Divmon.ymax = '0.05'
    sample_Divmon.nowritefile = '0'
    sample_Divmon.xwidth = '0.06'
    sample_Divmon.yheight = '0.06'
    sample_Divmon.maxdiv_h = '3'
    sample_Divmon.maxdiv_v = '3'
    sample_Divmon.restore_neutron = '1'
    sample_Divmon.nx = '0'
    sample_Divmon.ny = '0'
    sample_Divmon.nz = '1'
    
    # Comp instance sample_tof, placement and parameters
    sample_tof = instr.add_component('sample_tof','TOF_monitor', AT=['0', '0', '0'], AT_RELATIVE='sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample')
    
    sample_tof.nt = '100'
    sample_tof.filename = '"sample_tof.dat"'
    sample_tof.xmin = '-0.05'
    sample_tof.xmax = '0.05'
    sample_tof.ymin = '-0.05'
    sample_tof.ymax = '0.05'
    sample_tof.xwidth = '0.04'
    sample_tof.yheight = '0.06'
    sample_tof.tmin = '1e6 * ( ( L_sample ) / SE2V / sqrt ( Ei ) + pha_offset ) * 0.99'
    sample_tof.tmax = '1e6 * ( ( L_sample ) / SE2V / sqrt ( Ei ) + pha_offset ) * 1.01'
    sample_tof.dt = '1.0'
    sample_tof.restore_neutron = '1'
    sample_tof.nowritefile = '0'
    
    # Comp instance sample_Emon, placement and parameters
    sample_Emon = instr.add_component('sample_Emon','E_monitor', AT=['0', '0', '0'], AT_RELATIVE='sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample')
    
    sample_Emon.nE = '100'
    sample_Emon.filename = '"sample_Emon.dat"'
    sample_Emon.xmin = '-0.05'
    sample_Emon.xmax = '0.05'
    sample_Emon.ymin = '-0.05'
    sample_Emon.ymax = '0.05'
    sample_Emon.nowritefile = '0'
    sample_Emon.xwidth = '0.04'
    sample_Emon.yheight = '0.06'
    sample_Emon.Emin = 'Ei - ( emax - emin ) / 12'
    sample_Emon.Emax = 'Ei + ( emax - emin ) / 6'
    sample_Emon.restore_neutron = '1'
    
#     # Comp instance iso_samp, placement and parameters
#     iso_samp = instr.add_component('iso_samp','Isotropic_Sqw', AT=['0', '0', '0'], AT_RELATIVE='sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample')
#     # EXTEND at iso_samp
#     iso_samp.append_EXTEND(r'''
# if (!SCATTERED) ABSORB;
#     ''')


    
#     iso_samp.powder_format = '{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }'
#     iso_samp.Sqw_coh = 'sample_coh'
#     iso_samp.Sqw_inc = 'sample_inc'
#     iso_samp.geometry = '0'
#     iso_samp.radius = '0.025'
#     iso_samp.thickness = '0.0005'
#     iso_samp.xwidth = '0'
#     iso_samp.yheight = '0.05'
#     iso_samp.zdepth = '0'
#     iso_samp.threshold = '1e-20'
#     iso_samp.order = '0'
#     # iso_samp.T = '290'
#     iso_samp.verbose = '1'
#     iso_samp.d_phi = '0'
#     iso_samp.concentric = '0'
#     # iso_samp.rho = '0'
#     iso_samp.sigma_abs = '0'
#     # iso_samp.sigma_coh = '5.51'
#     # iso_samp.sigma_inc = '82.02'
#     iso_samp.classical = '1'
#     iso_samp.powder_Dd = '0'
#     iso_samp.powder_DW = '0'
#     # iso_samp.density = '0'
#     # iso_samp.weight = '0'
#     iso_samp.p_interact = '0.2'
#     iso_samp.norm = '-1'
#     iso_samp.powder_barns = '1'
#     # iso_samp.quantum_correction = '"Frommhold"'
    
    # Comp instance detectorArm, placement and parameters
    detectorArm = instr.add_component('detectorArm','Arm', AT=['0', '0', '0'], AT_RELATIVE='sample', ROTATED=['0', '90', '0'], ROTATED_RELATIVE='sample')
    
    
    # Comp instance Banana_1, placement and parameters
    Banana_1 = instr.add_component('Banana_1','Monitor_nD', AT=['0', '0', '0.0'], AT_RELATIVE='sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample')
    
    Banana_1.user1 = '""'
    Banana_1.user2 = '""'
    Banana_1.user3 = '""'
    Banana_1.xwidth = '0'
    Banana_1.yheight = '4'
    Banana_1.zdepth = '0'
    Banana_1.xmin = '0'
    Banana_1.xmax = '0'
    Banana_1.ymin = '0'
    Banana_1.ymax = '0'
    Banana_1.zmin = '0'
    Banana_1.zmax = '0'
    Banana_1.bins = '0'
    Banana_1.min = '-1e40'
    Banana_1.max = '1e40'
    Banana_1.restore_neutron = '1'
    Banana_1.radius = '3.5'
    Banana_1.options = '"mantid banana theta bins=221 limits=[-40, 140] y bins=136, neutron pixel min=0 t, list all neutrons"'
    Banana_1.filename = '"direct_event_banana_signal.dat"'
    Banana_1.geometry = '"NULL"'
    Banana_1.nowritefile = '0'
    Banana_1.nexus_bins = '0'
    Banana_1.username1 = '"NULL"'
    Banana_1.username2 = '"NULL"'
    Banana_1.username3 = '"NULL"'
    
    # Instruct McStasscript not to 'check everythng'
    instr.settings(checks=False)
    return instr


if __name__ == '__main__':
    instr=make()
    # Use instr.settings() to add e.g. seed=1000, ncount=1e7, mpi=8, openacc=True, force_compile=False etc.)
    

# Show diagram
    instr.show_diagram()
    

# Visualise with default parameters (defaults to 'webgl-legacy' visualisation)
    instr.show_instrument()
    

# Generate a dataset with default parameters.
    data = instr.backengine()
    
# Overview plot:
    ms.make_sub_plot(data)
    

# Other useful commands follow...
    
# One plot pr. window
    #ms.make_plot(data)
    
# Load another dataset
    #data2 = ms.load_data('some_other_folder')
    
# Adjusting a specific plot
    #ms.name_plot_options("PSD_4PI", data, log=1, colormap="hot", orders_of_mag=5)
    

# Bring up the 'interface' - only relevant in Jupyter
    #%matplotlib widget
    #import mcstasscript.jb_interface as ms_widget
    #ms_widget.show(data)
    

# Bring up the simulation 'interface' - only relevant in Jupyter
    #%matplotlib widget
    #import mcstasscript.jb_interface as ms_widget
    #sim_widget = ms_widget.SimInterface(instr)
    #sim_widget.show_interface()
    

# Acessing data from the interface
    #data = sim_widget.get_data()


# end of generated Python code ISIS_LET_generated.py 