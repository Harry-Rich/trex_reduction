#!/usr/bin/env python3
# Automatically generated file. 
# Format:    Python script code
# McStas <http://www.mcstas.org>
# Instrument: TREX_McStas.instr (TRex)
# Date:       Mon May  4 13:27:20 2026
# File:       TREX_McStas_generated.py

import mcstasscript as ms

# Python McStas instrument description
def make(name="TRex_generated", input_path=None):
    if input_path is not None:
        instr = ms.McStas_instr(name, author = "McCode Py-Generator", origin = "ESS DMSC", input_path=input_path)
    else:
        instr = ms.McStas_instr(name, author = "McCode Py-Generator", origin = "ESS DMSC")
    
# Add collected DEPENDENCY strings
    instr.set_dependency('  -DUSE_OFF ')

    # *****************************************************************************
    # * Start of instrument 'TRex' generated code
    # *****************************************************************************
    # MCSTAS system dir is "/opt/anaconda3/envs/mcstas/share/mcstas/resources/"


    # *****************************************************************************
    # * instrument 'TRex' and components DECLARE
    # *****************************************************************************

    # Instrument parameters:

    L0 = instr.add_parameter('double', 'L0', value=2.4, comment='Parameter type (double) added by McCode py-generator')
    d_Li = instr.add_parameter('double', 'd_Li', value=0.845, comment='Parameter type (double) added by McCode py-generator')
    RRM = instr.add_parameter('int', 'RRM', value=18, comment='Parameter type (int) added by McCode py-generator')
    mod_type = instr.add_parameter('int', 'mod_type', value=1, comment='Parameter type (int) added by McCode py-generator')
    bender = instr.add_parameter('int', 'bender', value=0, comment='Parameter type (int) added by McCode py-generator')
    sample_rot = instr.add_parameter('double', 'sample_rot', value=0, comment='Parameter type (double) added by McCode py-generator')
    phase_M = instr.add_parameter('double', 'phase_M', value=0, comment='Parameter type (double) added by McCode py-generator')
    phase_P = instr.add_parameter('double', 'phase_P', value=0, comment='Parameter type (double) added by McCode py-generator')
    block_pulses = instr.add_parameter('string', 'block_pulses', value='"NULL"', comment='Parameter type (string) added by McCode py-generator')
    b_rot = instr.add_parameter('double', 'b_rot', value=-0.5, comment='Parameter type (double) added by McCode py-generator')
    coll = instr.add_parameter('double', 'coll', value=0, comment='Parameter type (double) added by McCode py-generator')

    component_definition_metadata = {
    }
    instr.append_declare(r'''
double frac; // used in the Source component, Defines the statistical fraction of events emitted from the cold part of the moderator, the value is determined later in the file depending in the moderator type that was chosen

double lamb_1, lamb_2, Li;

double RRM_uneven;
double half_RRM;

double tof_BW1, tof_BW2, tof_M1, tof_M2, tof_P1, tof_P2;

double tof_M1_min, tof_M2_max, tof_P1_min, tof_P2_max; //  used to calculate monitor options for monitors after the choppers

double T_offset = 1700.0*1e-6;
double f = 14.0;
//double ang_c_t;

// characteristic wavelength
double bw, stepwl;
double lf_max; 
double vi, v1, v2, v0, e1, e2; 


// distances
double L_SG = 2.;

double L_BW1 = 32;
double L_BW2 = 40;

double L_P1 = 107.95;
double L_P2 = 108.05;

double L_M1 = 161.995;
double L_M2 = 162.005;

double L_S = 163.8;           // length to sample
double L_D = 166.8;	      // length to detector
double L_SD = 3;              // length from sample to monitor --> Must be (L_D - L_S)

// Chopper parameters

    // BW1 Chopper
    double f_BW1;
    double radius_BW1;
    char theta_pos_BW1[256] = "0";
    char theta_width_BW1[256] = "61.4";
    double delta_y_BW1;
    double delay_BW1; //time delay
    double nslits_BW1;
    
    // BW2 Chopper
    double f_BW2;
    double radius_BW2;
    char theta_pos_BW2[256] = "0";
    char theta_width_BW2[256] = "63.3";
    double delta_y_BW2;
    double delay_BW2; //time delay
    double nslits_BW2;
    
    // P1 Chopper
    double f_P1;
    double radius_P1;
    char theta_pos_P1[256] = "0 -55 -180 -235";
    char theta_width_P1[256] = "20 35 20 35";
    double delta_y_P1;
    double delay_P1; //time delay
    double nslits_P1;
    double phase_P1;// angular delay
    
    // P2 Chopper
    double f_P2;
    double radius_P2;
    char theta_pos_P2[256] = "0 -55 -180 -235";
    char theta_width_P2[256] = "20 35 20 35";
    double delta_y_P2;
    double delay_P2; //time delay
    double nslits_P2;
    double phase_P2;// angular delay
    
    // FAN Chopper
    double f_FAN;
    double radius_FAN;
    char theta_pos_FAN[256] = "180";
    char theta_width_FAN[256] = "348";
    double delta_y_FAN;
    double nslits_FAN;

	double f_FAN1, f_FAN2, f_FAN3, f_FAN4, f_FAN5, f_FAN6, f_FAN7, f_FAN8, f_FAN9, f_FAN10;
	double delay_FAN1, delay_FAN2, delay_FAN3, delay_FAN4, delay_FAN5, delay_FAN6, delay_FAN7, delay_FAN8, delay_FAN9, delay_FAN10;
	double phase_FAN1, phase_FAN2, phase_FAN3, phase_FAN4, phase_FAN5, phase_FAN6, phase_FAN7, phase_FAN8, phase_FAN9, phase_FAN10;

    
    // M1 Chopper
    double f_M1;
    double radius_M1;
    char theta_pos_M1[256] = "0 175";
    char theta_width_M1[256] = "2.5 4.4";
    double delta_y_M1;
    double delay_M1; //time delay
    double nslits_M1;
    double phase_M1;// angular delay
    
    // M2 Chopper
    double f_M2;
    double radius_M2;
    char theta_pos_M2[256] = "0 175";
    char theta_width_M2[256] = "2.5 4.4";
    double delta_y_M2;
    double delay_M2; //time delay
    double nslits_M2;
    double phase_M2;// angular delay


// tof for focusing at detector
double tof_D_1;
double tof_D_2;
// detector options
char   banana_options[1024], spherical_options[1024], square_options[1024], energy_options[1024];

// monitor definitions
int lbin;
int ebin;
char setSMl[256], setSMt[256],setSMt_M[256],setSMt_P[256], setSMlhdiv[256], setSMlvdiv[256], setBW1[256], setBW2[256], setPL[256], setP[256], setFAN[256], setML[256], setM[256], setSL[256], setS[256];
    ''')


    instr.append_initialize(r'''

// Source type
switch (mod_type)
	{
	case 0: {frac = 0.0; break;} // Thermal moderator
	case 1: {frac = 0.5; break;} // Bispectral moderator
	case 2: {frac = 1.0; break;} // Cold moderator
	}
	
// frequencies
	f_BW1 = f;
	f_BW2 = f_BW1;
	f_P1 = RRM*f*0.75;
	f_P2 = -f_P1;
	f_FAN = f;
	f_M1 = RRM*f;
	f_M2 = -f_M1;


// characteristic wavelength 
	stepwl = K2V*2*PI/(L_M1+L_M2)*2.0/fabs(f_M1);
	printf("Wavelength Step: %g \n", stepwl);
	lf_max = K2V*2*PI*(1+(L_M2-L_S)/L_M2)/L_SD/f_M2;
	v0 = 2*PI*K2V/L0;       // speed center neutron

// Source parameters
	vi = 2*PI*K2V/Li;
	//Ei = VS2E*vi*vi;
	lamb_1 = L0-d_Li*1.1;
	printf("lamb_1: %g \n", lamb_1);
	lamb_2 = L0+d_Li*1.1;
	printf("lamb_2: %g \n", lamb_2);
	v1 = 2*PI*K2V/lamb_1;   // slowest neutron
	v2 = 2*PI*K2V/lamb_2;   // fastest neutron

// time of flight and chopper phases
	tof_BW1 = T_offset + L_BW1/v0;
	tof_BW2 = T_offset + L_BW2/v0;
	
	tof_M1 = T_offset + L_M1/v0;
	tof_M2 = T_offset + L_M2/v0;

	tof_P1 = T_offset + L_P1/v0;
	tof_P2 = T_offset + L_P2/v0;

// read in which pulses to block
	int max_pulses = 10;
	int blocked_pulses[max_pulses];	// Initialize all elements to 0
	for (int i = 0; i < max_pulses; i++) {
        blocked_pulses[i] = 0; 
    }
    int npulses = 0;

    // Tokenize the input string
    char *token = strtok(block_pulses, "-");
    while (token != NULL && npulses < max_pulses) {
        blocked_pulses[npulses++] = atoi(token);
        token = strtok(NULL, "-");
    }

    // Output the array
    printf("Array:\n");
    for (int i = 0; i < max_pulses; i++) {
        printf("%d\n", blocked_pulses[i]);
    }



 // Printing the blocked_pulses array
    printf("Pulses to block:\n");
    for (int i = 0; i < npulses; i++) {
        printf("%d\n", blocked_pulses[i]); // Print as integers
    }


// calculate the tof for each FAN Chopper
	half_RRM = RRM / 2;
	RRM_uneven = half_RRM * 2 + 1;

double Ls_FAN[npulses];
double lambs_FAN[npulses];
double tofs_FAN[max_pulses];
for (int i = 0; i < max_pulses; i++) {
        tofs_FAN[i] = 0; 
    }

for (int i = 0; i < npulses; i++) {
    Ls_FAN[i] =  151.51801 + i * 0.070/9;
    lambs_FAN[i] =  L0 - (half_RRM - blocked_pulses[i] + 1) * stepwl;
    tofs_FAN[i] =  T_offset + Ls_FAN[i]/( 2*PI*K2V/lambs_FAN[i]);
    printf("Abstand FAN: %f\n", Ls_FAN[i]);
}

printf("\ntof to M1: %g, M2: %g, P1: %g, P2: %g \n", tof_M1, tof_M2, tof_P1, tof_P2);  


// Chopper parameters

    // BW1 Chopper
    radius_BW1 = 0.35;
    delta_y_BW1 = -0.3075;
    delay_BW1 = tof_BW1; //time delay
    nslits_BW1 = 1;
    
    // BW2 Chopper
    radius_BW2 = 0.35;
    delta_y_BW2 = delta_y_BW1;
    delay_BW2 = tof_BW2; //time delay
    nslits_BW2 = 1;
    
    // P1 Chopper
    radius_P1 = 0.35;
    delta_y_P1 = 0.305;
    delay_P1 = tof_P1; //time delay
    nslits_P1 = 4;
    phase_P1 = phase_P;// angular delay
    
    // P2 Chopper
    radius_P2 = 0.35;
    delta_y_P2 = delta_y_P1;
    delay_P2 = tof_P2; //time delay
    nslits_P2 = 4;
    phase_P2 = phase_P;// angular delay
    
    // FAN Chopper
    radius_FAN = 0.35;
    delta_y_FAN = 0.3125;
    nslits_FAN = 1;

// only #npulses of FAN choppers need to spin set all other frequencies to 0
// FAN chopperblades block the beam by default if they are not rotating --> need to add phase to all fan choppers that dont spin
    int freq_FAN[max_pulses];
    int phases_FAN[max_pulses];

    // Initialize the array with some sample values
    for (int i = 0; i < max_pulses; i++) {
        freq_FAN[i] = 0; 
	phases_FAN[i] = 180;
    }

    // Set values based on the threshold
    for (int i = 0; i < max_pulses; i++) {
        if (i < npulses) {
            freq_FAN[i] = 14;
	    phases_FAN[i] = 0;
        } 
    }

    // Print the updated values
    printf("Updated freq_FAN and phases values:\n");
    for (int i = 0; i < max_pulses; i++) {
        printf("freq_FAN%d = %d\n", i + 1, freq_FAN[i]);
	printf("phase%d = %d\n", i + 1, phases_FAN[i]);
    }

	delay_FAN1 = tofs_FAN[0];
	delay_FAN2 = tofs_FAN[1];
	delay_FAN3 = tofs_FAN[2];
	delay_FAN4 = tofs_FAN[3];
	delay_FAN5 = tofs_FAN[4];
	delay_FAN6 = tofs_FAN[5];
	delay_FAN7 = tofs_FAN[6];
	delay_FAN8 = tofs_FAN[7];
	delay_FAN9 = tofs_FAN[8];
	delay_FAN10 =tofs_FAN[9];
	            
    printf("delays:\n");
    for (int i = 0; i < max_pulses; i++) {
        printf("%f\n", tofs_FAN[i]); // Print as integers
    }
          
        phase_FAN1  = phases_FAN[0];
	phase_FAN2  = phases_FAN[1];
	phase_FAN3  = phases_FAN[2];
	phase_FAN4  = phases_FAN[3];
	phase_FAN5  = phases_FAN[4];
	phase_FAN6  = phases_FAN[5];
	phase_FAN7  = phases_FAN[6];
	phase_FAN8  = phases_FAN[7];
	phase_FAN9  = phases_FAN[8];
	phase_FAN10 = phases_FAN[9];
	
    //printf("phases:\n %f", phase_FAN);

	f_FAN1  = freq_FAN[0];
	f_FAN2  = freq_FAN[1];
	f_FAN3  = freq_FAN[2];
	f_FAN4  = freq_FAN[3];
	f_FAN5  = freq_FAN[4];
	f_FAN6  = freq_FAN[5];
	f_FAN7  = freq_FAN[6];
	f_FAN8  = freq_FAN[7];
	f_FAN9  = freq_FAN[8];
	f_FAN10  = freq_FAN[9];

    printf("frequencies:\n");
    for (int i = 0; i < max_pulses; i++) {
        printf("%d\n", freq_FAN[i]); // Print as integers
    }


printf("phases:\n %f", delay_FAN5);
printf("phases:\n %f", f_FAN5);

    // M1 Chopper
    radius_M1 = 0.35;
    delta_y_M1 = 0.325;
    delay_M1 = tof_M1; //time delay
    nslits_M1 = 2;
    phase_M1 = phase_M;// angular delay

    // M2 Chopper
    radius_M2 = 0.35;
    delta_y_M2 = -delta_y_M1;
    delay_M2 = tof_M1; //time delay
    nslits_M2 = 2;
    phase_M2 = phase_M;// angular delay

     
// Detector parameters
tof_D_1 = T_offset + L_D/(K2V*2*PI/lamb_1);
tof_D_2 = T_offset + tof_D_1 + 0.072 + 0.00289;
lbin = round((lamb_2-lamb_1)/0.002);    

//sprintf(spherical_options, "sphere, theta limits = [10 135] bins=288, phi limits = [-25 15] bins=66, time limits=[%g %g]bins=[%li]", T_offset + L_D/v1, T_offset + L_D/v2, lbin*50);
//sprintf(banana_options, "banana, theta limits = [10 144] bins=288, phi limits = [-25 15] bins=66, time limits=[%g %g]bins=250", T_offset + L_D/v1, T_offset + L_D/v2);
//sprintf(banana_options, "xwidth = 0.1, yheight = 0.1, time limits=[%g %g]bins=[%li]", T_offset + L_D/v1, T_offset + L_D/v2, lbin*50); // 2*T_offset+L_D/v1, L_D/v2, lbin*10); // Removed T_offset +
sprintf(square_options, "time limits=[%g %g]bins=[%li]", T_offset + L_D/v1, T_offset + L_D/v2, lbin*10);
// Monitors
lbin = round((lamb_2-lamb_1)/0.002);    // number of bins for TOF monitors
printf("\n\n \t nbin: %i \n\n", lbin);
sprintf(setBW1, "time limits [%g %g] bins = [%i]", T_offset + L_BW1/v1, T_offset + L_BW1/v2, lbin*5);
sprintf(setBW2, "time limits [%g %g] bins = [%i]", T_offset + L_BW2/v1, T_offset + L_BW2/v2, lbin*5); //Changed T_offset + to what's written here
sprintf(setP, "time limits [%g %g] bins = [%i]",   T_offset + L_P2/v1,  T_offset + L_P2/v2,  lbin*5);
sprintf(setPL, "lambda limits=[%g %g], bins=%i", lamb_1, lamb_2, lbin*5);

sprintf(setFAN, "time limits [%g %g] bins = [%i]", T_offset + Ls_FAN[0]/v1, T_offset + Ls_FAN[0]/v2, lbin*10);

sprintf(setM, "time limits [%g %g] bins = [%i]",   T_offset + L_M2/v1,  T_offset + L_M2/v2,  lbin*10);
sprintf(setML, "lambda limits=[%g %g], bins=%i", lamb_1, lamb_2, lbin*5);
sprintf(setS, "time limits [%g %g] bins = [%i]",   T_offset + L_S/v1,   T_offset + L_S/v2,   lbin*10); //Added a 2* to T_offset +
sprintf(setSL, "lambda limits=[%g %g], bins=%i", lamb_1, lamb_2, lbin*5);
//tof_M1_min = T_offset+L_M1/vi-M_theta/360.0/f_M1;
//tof_M2_max = T_offset+L_M2/vi-M_theta/360.0/f_M2;

tof_M1_min = T_offset+L_M1/v1;
tof_M2_max = T_offset+L_M2/v2;

tof_P1_min = T_offset+L_P1/v1;
tof_P2_max = T_offset+L_P2/v2;
sprintf(setSMt_M, "time limits=[%g %g], bins=%i", tof_M1_min, tof_M2_max, 50);
sprintf(setSMt_P, "time limits=[%g %g], bins=%i", tof_P1_min, tof_P2_max, 100);
sprintf(setSMlhdiv, "hdiv limits [-2.5:2.5] bins = 200, lambda limits=[%g %g], bins=%i", lamb_1, lamb_2, lbin);
sprintf(setSMlvdiv, "vdiv limits [-2.5:2.5] bins = 200, lambda limits=[%g %g], bins=%i", lamb_1, lamb_2, lbin);



    ''')


    # *****************************************************************************
    # * instrument 'TRex' TRACE
    # *****************************************************************************
    
    # Comp instance origin, placement and parameters
    origin = instr.add_component('origin','Progress_bar')
    
    origin.profile = '"NULL"'
    origin.percent = '10'
    origin.flag_save = '0'
    origin.minutes = '0'
    
    # Comp instance ESS_source, placement and parameters
    ESS_source = instr.add_component('ESS_source','ESS_butterfly')
    
    ESS_source.sector = '"W"'
    ESS_source.beamline = '7'
    ESS_source.yheight = '0.03'
    ESS_source.cold_frac = 'frac'
    ESS_source.target_index = '0'
    ESS_source.dist = '2'
    ESS_source.focus_xw = '0.095'
    ESS_source.focus_yh = '0.035'
    ESS_source.c_performance = '1'
    ESS_source.t_performance = '1'
    ESS_source.Lmin = 'lamb_1'
    ESS_source.Lmax = 'lamb_2'
    ESS_source.tmax_multiplier = '3'
    ESS_source.n_pulses = '1'
    ESS_source.acc_power = '2'
    ESS_source.tfocus_dist = '0'
    ESS_source.tfocus_time = '0'
    ESS_source.tfocus_width = '0'
    
    # Comp instance source_monitor_xy, placement and parameters
    source_monitor_xy = instr.add_component('source_monitor_xy','Monitor_nD', AT=['-0.002', '0', '1.8953'])
    
    source_monitor_xy.user1 = '""'
    source_monitor_xy.user2 = '""'
    source_monitor_xy.user3 = '""'
    source_monitor_xy.xwidth = '0.1'
    source_monitor_xy.yheight = '0.04'
    source_monitor_xy.zdepth = '0'
    source_monitor_xy.xmin = '0'
    source_monitor_xy.xmax = '0'
    source_monitor_xy.ymin = '0'
    source_monitor_xy.ymax = '0'
    source_monitor_xy.zmin = '0'
    source_monitor_xy.zmax = '0'
    source_monitor_xy.bins = '0'
    source_monitor_xy.min = '-1e40'
    source_monitor_xy.max = '1e40'
    source_monitor_xy.restore_neutron = '1'
    source_monitor_xy.radius = '0'
    source_monitor_xy.options = '"x limits [-0.05:0.05] bins = 100, y limits [-0.02:0.02] bins = 100"'
    source_monitor_xy.filename = '"source_monitor_xy.dat"'
    source_monitor_xy.geometry = '"NULL"'
    source_monitor_xy.nowritefile = '0'
    source_monitor_xy.nexus_bins = '0'
    source_monitor_xy.username1 = '"NULL"'
    source_monitor_xy.username2 = '"NULL"'
    source_monitor_xy.username3 = '"NULL"'
    
    # Comp instance source_monitor_div, placement and parameters
    source_monitor_div = instr.add_component('source_monitor_div','Monitor_nD', AT=['-0.002', '0', '1.8954'])
    
    source_monitor_div.user1 = '""'
    source_monitor_div.user2 = '""'
    source_monitor_div.user3 = '""'
    source_monitor_div.xwidth = '0.09'
    source_monitor_div.yheight = '0.03'
    source_monitor_div.zdepth = '0'
    source_monitor_div.xmin = '0'
    source_monitor_div.xmax = '0'
    source_monitor_div.ymin = '0'
    source_monitor_div.ymax = '0'
    source_monitor_div.zmin = '0'
    source_monitor_div.zmax = '0'
    source_monitor_div.bins = '0'
    source_monitor_div.min = '-1e40'
    source_monitor_div.max = '1e40'
    source_monitor_div.restore_neutron = '1'
    source_monitor_div.radius = '0'
    source_monitor_div.options = '"hdiv limits [-2.5:2.5] bins = 100, vdiv limits [-2.5:2.5] bins = 100"'
    source_monitor_div.filename = '"source_monitor_div.dat"'
    source_monitor_div.geometry = '"NULL"'
    source_monitor_div.nowritefile = '0'
    source_monitor_div.nexus_bins = '0'
    source_monitor_div.username1 = '"NULL"'
    source_monitor_div.username2 = '"NULL"'
    source_monitor_div.username3 = '"NULL"'
    
    # Comp instance guide_0, placement and parameters
    guide_0 = instr.add_component('guide_0','Guide_anyshape_r')
    
    guide_0.xwidth = '0'
    guide_0.yheight = '0'
    guide_0.zdepth = '0'
    guide_0.center = '0'
    guide_0.transmit = '0'
    guide_0.R0 = '0.99'
    guide_0.Qc = '0.0219'
    guide_0.alpha = '0'
    guide_0.m = '0'
    guide_0.W = '0'
    guide_0.geometry = '"./OFF_files/try0.off"'
    
    # Comp instance guide_1, placement and parameters
    guide_1 = instr.add_component('guide_1','Guide_anyshape_r')
    
    guide_1.xwidth = '0'
    guide_1.yheight = '0'
    guide_1.zdepth = '0'
    guide_1.center = '0'
    guide_1.transmit = '0'
    guide_1.R0 = '0.99'
    guide_1.Qc = '0.0219'
    guide_1.alpha = '0'
    guide_1.m = '0'
    guide_1.W = '0'
    guide_1.geometry = '"./OFF_files/try1.off"'
    
    # Comp instance guide_3, placement and parameters
    guide_3 = instr.add_component('guide_3','Guide_anyshape_r')
    
    guide_3.xwidth = '0'
    guide_3.yheight = '0'
    guide_3.zdepth = '0'
    guide_3.center = '0'
    guide_3.transmit = '0'
    guide_3.R0 = '0.99'
    guide_3.Qc = '0.0219'
    guide_3.alpha = '0'
    guide_3.m = '0'
    guide_3.W = '0'
    guide_3.geometry = '"./OFF_files/try3.off"'
    
    # Comp instance guide_4, placement and parameters
    guide_4 = instr.add_component('guide_4','Guide_anyshape_r')
    
    guide_4.xwidth = '0'
    guide_4.yheight = '0'
    guide_4.zdepth = '0'
    guide_4.center = '0'
    guide_4.transmit = '0'
    guide_4.R0 = '0.99'
    guide_4.Qc = '0.0219'
    guide_4.alpha = '0'
    guide_4.m = '0'
    guide_4.W = '0'
    guide_4.geometry = '"./OFF_files/try4.off"'
    
    # Comp instance guide_5, placement and parameters
    guide_5 = instr.add_component('guide_5','Guide_anyshape_r')
    
    guide_5.xwidth = '0'
    guide_5.yheight = '0'
    guide_5.zdepth = '0'
    guide_5.center = '0'
    guide_5.transmit = '0'
    guide_5.R0 = '0.99'
    guide_5.Qc = '0.0219'
    guide_5.alpha = '0'
    guide_5.m = '0'
    guide_5.W = '0'
    guide_5.geometry = '"./OFF_files/try5.off"'
    
    # Comp instance guide_7, placement and parameters
    guide_7 = instr.add_component('guide_7','Guide_anyshape_r')
    
    guide_7.xwidth = '0'
    guide_7.yheight = '0'
    guide_7.zdepth = '0'
    guide_7.center = '0'
    guide_7.transmit = '0'
    guide_7.R0 = '0.99'
    guide_7.Qc = '0.0219'
    guide_7.alpha = '0'
    guide_7.m = '0'
    guide_7.W = '0'
    guide_7.geometry = '"./OFF_files/try7.off"'
    
    # Comp instance guide_8, placement and parameters
    guide_8 = instr.add_component('guide_8','Guide_anyshape_r')
    
    guide_8.xwidth = '0'
    guide_8.yheight = '0'
    guide_8.zdepth = '0'
    guide_8.center = '0'
    guide_8.transmit = '0'
    guide_8.R0 = '0.99'
    guide_8.Qc = '0.0219'
    guide_8.alpha = '0'
    guide_8.m = '0'
    guide_8.W = '0'
    guide_8.geometry = '"./OFF_files/try8.off"'
    
    # Comp instance guide_10, placement and parameters
    guide_10 = instr.add_component('guide_10','Guide_anyshape_r')
    # WHEN ( bender == 0 ) at guide_10
    guide_10.set_WHEN('( bender == 0 )')
    
    guide_10.xwidth = '0'
    guide_10.yheight = '0'
    guide_10.zdepth = '0'
    guide_10.center = '0'
    guide_10.transmit = '0'
    guide_10.R0 = '0.99'
    guide_10.Qc = '0.0219'
    guide_10.alpha = '0'
    guide_10.m = '0'
    guide_10.W = '0'
    guide_10.geometry = '"./OFF_files/try10.off"'
    
    # Comp instance bender, placement and parameters
    bender = instr.add_component('bender','Pol_bender', AT=['-0.017', '0', '5.399'], ROTATED=['0 + 0.00192', 'b_rot', '0'])
    # WHEN ( bender == 1 ) at bender
    bender.set_WHEN('( bender == 1 )')
    
    bender.xwidth = '0.06384'
    bender.yheight = '0.046'
    bender.length = '0.05'
    bender.radius = '7.2'
    bender.G = '9.8'
    bender.nslit = '425'
    bender.d = '1e-6'
    bender.debug = '0'
    bender.endFlat = '0'
    bender.rTopUpPar = '{ 0.99 , 0.0219 , 3.02 , 4.0 , 0.003 }'
    bender.rTopDownPar = '{ 0.99 , 0.0219 , 3.02 , 4.0 , 0.003 }'
    bender.rBotUpPar = '{ 0.99 , 0.0219 , 6.07 , 2.0 , 0.003 }'
    bender.rBotDownPar = '{ 0.99 , 0.0219 , 6.07 , 2.0 , 0.003 }'
    bender.rLeftUpPar = '{ 0.99 , 0.0219 , 6.07 , 2.0 , 0.003 }'
    bender.rLeftDownPar = '{ 0.99 , 0.0219 , 6.07 , 2.0 , 0.003 }'
    bender.rRightUpPar = '{ 0.99 , 0.0219 , 6.07 , 2.0 , 0.003 }'
    bender.rRightDownPar = '{ 0.99 , 0.0219 , 6.07 , 2.0 , 0.003 }'
    bender.rTopUpData = '""'
    bender.rTopDownData = '""'
    bender.rBotUpData = '""'
    bender.rBotDownData = '""'
    bender.rLeftUpData = '""'
    bender.rLeftDownData = '""'
    bender.rRightUpData = '""'
    bender.rRightDownData = '""'
    bender.drawOption = '2'
    
    # Comp instance guide_11, placement and parameters
    guide_11 = instr.add_component('guide_11','Guide_anyshape_r')
    
    guide_11.xwidth = '0'
    guide_11.yheight = '0'
    guide_11.zdepth = '0'
    guide_11.center = '0'
    guide_11.transmit = '0'
    guide_11.R0 = '0.99'
    guide_11.Qc = '0.0219'
    guide_11.alpha = '0'
    guide_11.m = '0'
    guide_11.W = '0'
    guide_11.geometry = '"./OFF_files/try11.off"'
    
    # Comp instance slit, placement and parameters
    slit = instr.add_component('slit','Slit', AT=['-0.017', '0', '5.915'])
    
    slit.xmin = 'UNSET'
    slit.xmax = 'UNSET'
    slit.ymin = 'UNSET'
    slit.ymax = 'UNSET'
    slit.radius = 'UNSET'
    slit.xwidth = '0.06'
    slit.yheight = '0.046'
    
    # Comp instance insert_monitor_xy, placement and parameters
    insert_monitor_xy = instr.add_component('insert_monitor_xy','Monitor_nD', AT=['-0.017', '0.0', '5.9151'], ROTATED=['0', '0', '0'])
    
    insert_monitor_xy.user1 = '""'
    insert_monitor_xy.user2 = '""'
    insert_monitor_xy.user3 = '""'
    insert_monitor_xy.xwidth = '0.06'
    insert_monitor_xy.yheight = '0.046'
    insert_monitor_xy.zdepth = '0'
    insert_monitor_xy.xmin = '0'
    insert_monitor_xy.xmax = '0'
    insert_monitor_xy.ymin = '0'
    insert_monitor_xy.ymax = '0'
    insert_monitor_xy.zmin = '0'
    insert_monitor_xy.zmax = '0'
    insert_monitor_xy.bins = '0'
    insert_monitor_xy.min = '-1e40'
    insert_monitor_xy.max = '1e40'
    insert_monitor_xy.restore_neutron = '1'
    insert_monitor_xy.radius = '0'
    insert_monitor_xy.options = '"x limits [-0.03:0.03] bins = 100, y limits [-0.023:0.023] bins = 100"'
    insert_monitor_xy.filename = '"insert_monitor_xy.dat"'
    insert_monitor_xy.geometry = '"NULL"'
    insert_monitor_xy.nowritefile = '0'
    insert_monitor_xy.nexus_bins = '0'
    insert_monitor_xy.username1 = '"NULL"'
    insert_monitor_xy.username2 = '"NULL"'
    insert_monitor_xy.username3 = '"NULL"'
    
    # Comp instance insert_monitor_div, placement and parameters
    insert_monitor_div = instr.add_component('insert_monitor_div','Monitor_nD', AT=['-0.017', '0', '5.9152'])
    
    insert_monitor_div.user1 = '""'
    insert_monitor_div.user2 = '""'
    insert_monitor_div.user3 = '""'
    insert_monitor_div.xwidth = '0.06'
    insert_monitor_div.yheight = '0.046'
    insert_monitor_div.zdepth = '0'
    insert_monitor_div.xmin = '0'
    insert_monitor_div.xmax = '0'
    insert_monitor_div.ymin = '0'
    insert_monitor_div.ymax = '0'
    insert_monitor_div.zmin = '0'
    insert_monitor_div.zmax = '0'
    insert_monitor_div.bins = '0'
    insert_monitor_div.min = '-1e40'
    insert_monitor_div.max = '1e40'
    insert_monitor_div.restore_neutron = '1'
    insert_monitor_div.radius = '0'
    insert_monitor_div.options = '"hdiv limits [-1.0:1.0] bins = 201, vdiv limits [-1.0:1.0] bins = 201"'
    insert_monitor_div.filename = '"insert_monitor_div.dat"'
    insert_monitor_div.geometry = '"NULL"'
    insert_monitor_div.nowritefile = '0'
    insert_monitor_div.nexus_bins = '0'
    insert_monitor_div.username1 = '"NULL"'
    insert_monitor_div.username2 = '"NULL"'
    insert_monitor_div.username3 = '"NULL"'
    
    # Comp instance guide_13, placement and parameters
    guide_13 = instr.add_component('guide_13','Guide_anyshape_r')
    
    guide_13.xwidth = '0'
    guide_13.yheight = '0'
    guide_13.zdepth = '0'
    guide_13.center = '0'
    guide_13.transmit = '0'
    guide_13.R0 = '0.99'
    guide_13.Qc = '0.0219'
    guide_13.alpha = '0'
    guide_13.m = '0'
    guide_13.W = '0'
    guide_13.geometry = '"./OFF_files/try13.off"'
    
    # Comp instance guide_14, placement and parameters
    guide_14 = instr.add_component('guide_14','Guide_anyshape_r')
    
    guide_14.xwidth = '0'
    guide_14.yheight = '0'
    guide_14.zdepth = '0'
    guide_14.center = '0'
    guide_14.transmit = '0'
    guide_14.R0 = '0.99'
    guide_14.Qc = '0.0219'
    guide_14.alpha = '0'
    guide_14.m = '0'
    guide_14.W = '0'
    guide_14.geometry = '"./OFF_files/try14.off"'
    
    # Comp instance guide_15, placement and parameters
    guide_15 = instr.add_component('guide_15','Guide_anyshape_r')
    
    guide_15.xwidth = '0'
    guide_15.yheight = '0'
    guide_15.zdepth = '0'
    guide_15.center = '0'
    guide_15.transmit = '0'
    guide_15.R0 = '0.99'
    guide_15.Qc = '0.0219'
    guide_15.alpha = '0'
    guide_15.m = '0'
    guide_15.W = '0'
    guide_15.geometry = '"./OFF_files/try15.off"'
    
    # Comp instance guide_16, placement and parameters
    guide_16 = instr.add_component('guide_16','Guide_anyshape_r')
    
    guide_16.xwidth = '0'
    guide_16.yheight = '0'
    guide_16.zdepth = '0'
    guide_16.center = '0'
    guide_16.transmit = '0'
    guide_16.R0 = '0.99'
    guide_16.Qc = '0.0219'
    guide_16.alpha = '0'
    guide_16.m = '0'
    guide_16.W = '0'
    guide_16.geometry = '"./OFF_files/try16.off"'
    
    # Comp instance guide_18, placement and parameters
    guide_18 = instr.add_component('guide_18','Guide_anyshape_r')
    
    guide_18.xwidth = '0'
    guide_18.yheight = '0'
    guide_18.zdepth = '0'
    guide_18.center = '0'
    guide_18.transmit = '0'
    guide_18.R0 = '0.99'
    guide_18.Qc = '0.0219'
    guide_18.alpha = '0'
    guide_18.m = '0'
    guide_18.W = '0'
    guide_18.geometry = '"./OFF_files/try18.off"'
    
    # Comp instance guide_19, placement and parameters
    guide_19 = instr.add_component('guide_19','Guide_anyshape_r')
    
    guide_19.xwidth = '0'
    guide_19.yheight = '0'
    guide_19.zdepth = '0'
    guide_19.center = '0'
    guide_19.transmit = '0'
    guide_19.R0 = '0.99'
    guide_19.Qc = '0.0219'
    guide_19.alpha = '0'
    guide_19.m = '0'
    guide_19.W = '0'
    guide_19.geometry = '"./OFF_files/try19.off"'
    
    # Comp instance guide_20, placement and parameters
    guide_20 = instr.add_component('guide_20','Guide_anyshape_r')
    
    guide_20.xwidth = '0'
    guide_20.yheight = '0'
    guide_20.zdepth = '0'
    guide_20.center = '0'
    guide_20.transmit = '0'
    guide_20.R0 = '0.99'
    guide_20.Qc = '0.0219'
    guide_20.alpha = '0'
    guide_20.m = '0'
    guide_20.W = '0'
    guide_20.geometry = '"./OFF_files/try20.off"'
    
    # Comp instance guide_22, placement and parameters
    guide_22 = instr.add_component('guide_22','Guide_anyshape_r')
    
    guide_22.xwidth = '0'
    guide_22.yheight = '0'
    guide_22.zdepth = '0'
    guide_22.center = '0'
    guide_22.transmit = '0'
    guide_22.R0 = '0.99'
    guide_22.Qc = '0.0219'
    guide_22.alpha = '0'
    guide_22.m = '0'
    guide_22.W = '0'
    guide_22.geometry = '"./OFF_files/try22.off"'
    
    # Comp instance guide_23, placement and parameters
    guide_23 = instr.add_component('guide_23','Guide_anyshape_r')
    
    guide_23.xwidth = '0'
    guide_23.yheight = '0'
    guide_23.zdepth = '0'
    guide_23.center = '0'
    guide_23.transmit = '0'
    guide_23.R0 = '0.99'
    guide_23.Qc = '0.0219'
    guide_23.alpha = '0'
    guide_23.m = '0'
    guide_23.W = '0'
    guide_23.geometry = '"./OFF_files/try23.off"'
    
    # Comp instance guide_24, placement and parameters
    guide_24 = instr.add_component('guide_24','Guide_anyshape_r')
    
    guide_24.xwidth = '0'
    guide_24.yheight = '0'
    guide_24.zdepth = '0'
    guide_24.center = '0'
    guide_24.transmit = '0'
    guide_24.R0 = '0.99'
    guide_24.Qc = '0.0219'
    guide_24.alpha = '0'
    guide_24.m = '0'
    guide_24.W = '0'
    guide_24.geometry = '"./OFF_files/try24.off"'
    
    # Comp instance guide_25, placement and parameters
    guide_25 = instr.add_component('guide_25','Guide_anyshape_r')
    
    guide_25.xwidth = '0'
    guide_25.yheight = '0'
    guide_25.zdepth = '0'
    guide_25.center = '0'
    guide_25.transmit = '0'
    guide_25.R0 = '0.99'
    guide_25.Qc = '0.0219'
    guide_25.alpha = '0'
    guide_25.m = '0'
    guide_25.W = '0'
    guide_25.geometry = '"./OFF_files/try25.off"'
    
    # Comp instance guide_27, placement and parameters
    guide_27 = instr.add_component('guide_27','Guide_anyshape_r')
    
    guide_27.xwidth = '0'
    guide_27.yheight = '0'
    guide_27.zdepth = '0'
    guide_27.center = '0'
    guide_27.transmit = '0'
    guide_27.R0 = '0.99'
    guide_27.Qc = '0.0219'
    guide_27.alpha = '0'
    guide_27.m = '0'
    guide_27.W = '0'
    guide_27.geometry = '"./OFF_files/try27.off"'
    
    # Comp instance guide_28, placement and parameters
    guide_28 = instr.add_component('guide_28','Guide_anyshape_r')
    
    guide_28.xwidth = '0'
    guide_28.yheight = '0'
    guide_28.zdepth = '0'
    guide_28.center = '0'
    guide_28.transmit = '0'
    guide_28.R0 = '0.99'
    guide_28.Qc = '0.0219'
    guide_28.alpha = '0'
    guide_28.m = '0'
    guide_28.W = '0'
    guide_28.geometry = '"./OFF_files/try28.off"'
    
    # Comp instance guide_29, placement and parameters
    guide_29 = instr.add_component('guide_29','Guide_anyshape_r')
    
    guide_29.xwidth = '0'
    guide_29.yheight = '0'
    guide_29.zdepth = '0'
    guide_29.center = '0'
    guide_29.transmit = '0'
    guide_29.R0 = '0.99'
    guide_29.Qc = '0.0219'
    guide_29.alpha = '0'
    guide_29.m = '0'
    guide_29.W = '0'
    guide_29.geometry = '"./OFF_files/try29.off"'
    
    # Comp instance guide_30, placement and parameters
    guide_30 = instr.add_component('guide_30','Guide_anyshape_r')
    
    guide_30.xwidth = '0'
    guide_30.yheight = '0'
    guide_30.zdepth = '0'
    guide_30.center = '0'
    guide_30.transmit = '0'
    guide_30.R0 = '0.99'
    guide_30.Qc = '0.0219'
    guide_30.alpha = '0'
    guide_30.m = '0'
    guide_30.W = '0'
    guide_30.geometry = '"./OFF_files/try30.off"'
    
    # Comp instance guide_32, placement and parameters
    guide_32 = instr.add_component('guide_32','Guide_anyshape_r')
    
    guide_32.xwidth = '0'
    guide_32.yheight = '0'
    guide_32.zdepth = '0'
    guide_32.center = '0'
    guide_32.transmit = '0'
    guide_32.R0 = '0.99'
    guide_32.Qc = '0.0219'
    guide_32.alpha = '0'
    guide_32.m = '0'
    guide_32.W = '0'
    guide_32.geometry = '"./OFF_files/try32.off"'
    
    # Comp instance guide_33, placement and parameters
    guide_33 = instr.add_component('guide_33','Guide_anyshape_r')
    
    guide_33.xwidth = '0'
    guide_33.yheight = '0'
    guide_33.zdepth = '0'
    guide_33.center = '0'
    guide_33.transmit = '0'
    guide_33.R0 = '0.99'
    guide_33.Qc = '0.0219'
    guide_33.alpha = '0'
    guide_33.m = '0'
    guide_33.W = '0'
    guide_33.geometry = '"./OFF_files/try33.off"'
    
    # Comp instance guide_34, placement and parameters
    guide_34 = instr.add_component('guide_34','Guide_anyshape_r')
    
    guide_34.xwidth = '0'
    guide_34.yheight = '0'
    guide_34.zdepth = '0'
    guide_34.center = '0'
    guide_34.transmit = '0'
    guide_34.R0 = '0.99'
    guide_34.Qc = '0.0219'
    guide_34.alpha = '0'
    guide_34.m = '0'
    guide_34.W = '0'
    guide_34.geometry = '"./OFF_files/try34.off"'
    
    # Comp instance guide_36, placement and parameters
    guide_36 = instr.add_component('guide_36','Guide_anyshape_r')
    
    guide_36.xwidth = '0'
    guide_36.yheight = '0'
    guide_36.zdepth = '0'
    guide_36.center = '0'
    guide_36.transmit = '0'
    guide_36.R0 = '0.99'
    guide_36.Qc = '0.0219'
    guide_36.alpha = '0'
    guide_36.m = '0'
    guide_36.W = '0'
    guide_36.geometry = '"./OFF_files/try36.off"'
    
    # Comp instance guide_37, placement and parameters
    guide_37 = instr.add_component('guide_37','Guide_anyshape_r')
    
    guide_37.xwidth = '0'
    guide_37.yheight = '0'
    guide_37.zdepth = '0'
    guide_37.center = '0'
    guide_37.transmit = '0'
    guide_37.R0 = '0.99'
    guide_37.Qc = '0.0219'
    guide_37.alpha = '0'
    guide_37.m = '0'
    guide_37.W = '0'
    guide_37.geometry = '"./OFF_files/try37.off"'
    
    # Comp instance guide_39, placement and parameters
    guide_39 = instr.add_component('guide_39','Guide_anyshape_r')
    
    guide_39.xwidth = '0'
    guide_39.yheight = '0'
    guide_39.zdepth = '0'
    guide_39.center = '0'
    guide_39.transmit = '0'
    guide_39.R0 = '0.99'
    guide_39.Qc = '0.0219'
    guide_39.alpha = '0'
    guide_39.m = '0'
    guide_39.W = '0'
    guide_39.geometry = '"./OFF_files/try39.off"'
    
    # Comp instance guide_40, placement and parameters
    guide_40 = instr.add_component('guide_40','Guide_anyshape_r')
    
    guide_40.xwidth = '0'
    guide_40.yheight = '0'
    guide_40.zdepth = '0'
    guide_40.center = '0'
    guide_40.transmit = '0'
    guide_40.R0 = '0.99'
    guide_40.Qc = '0.0219'
    guide_40.alpha = '0'
    guide_40.m = '0'
    guide_40.W = '0'
    guide_40.geometry = '"./OFF_files/try40.off"'
    
    # Comp instance guide_41, placement and parameters
    guide_41 = instr.add_component('guide_41','Guide_anyshape_r')
    
    guide_41.xwidth = '0'
    guide_41.yheight = '0'
    guide_41.zdepth = '0'
    guide_41.center = '0'
    guide_41.transmit = '0'
    guide_41.R0 = '0.99'
    guide_41.Qc = '0.0219'
    guide_41.alpha = '0'
    guide_41.m = '0'
    guide_41.W = '0'
    guide_41.geometry = '"./OFF_files/try41.off"'
    
    # Comp instance guide_42, placement and parameters
    guide_42 = instr.add_component('guide_42','Guide_anyshape_r')
    
    guide_42.xwidth = '0'
    guide_42.yheight = '0'
    guide_42.zdepth = '0'
    guide_42.center = '0'
    guide_42.transmit = '0'
    guide_42.R0 = '0.99'
    guide_42.Qc = '0.0219'
    guide_42.alpha = '0'
    guide_42.m = '0'
    guide_42.W = '0'
    guide_42.geometry = '"./OFF_files/try42.off"'
    
    # Comp instance guide_44, placement and parameters
    guide_44 = instr.add_component('guide_44','Guide_anyshape_r')
    
    guide_44.xwidth = '0'
    guide_44.yheight = '0'
    guide_44.zdepth = '0'
    guide_44.center = '0'
    guide_44.transmit = '0'
    guide_44.R0 = '0.99'
    guide_44.Qc = '0.0219'
    guide_44.alpha = '0'
    guide_44.m = '0'
    guide_44.W = '0'
    guide_44.geometry = '"./OFF_files/try44.off"'
    
    # Comp instance guide_45, placement and parameters
    guide_45 = instr.add_component('guide_45','Guide_anyshape_r')
    
    guide_45.xwidth = '0'
    guide_45.yheight = '0'
    guide_45.zdepth = '0'
    guide_45.center = '0'
    guide_45.transmit = '0'
    guide_45.R0 = '0.99'
    guide_45.Qc = '0.0219'
    guide_45.alpha = '0'
    guide_45.m = '0'
    guide_45.W = '0'
    guide_45.geometry = '"./OFF_files/try45.off"'
    
    # Comp instance guide_46, placement and parameters
    guide_46 = instr.add_component('guide_46','Guide_anyshape_r')
    
    guide_46.xwidth = '0'
    guide_46.yheight = '0'
    guide_46.zdepth = '0'
    guide_46.center = '0'
    guide_46.transmit = '0'
    guide_46.R0 = '0.99'
    guide_46.Qc = '0.0219'
    guide_46.alpha = '0'
    guide_46.m = '0'
    guide_46.W = '0'
    guide_46.geometry = '"./OFF_files/try46.off"'
    
    # Comp instance guide_47, placement and parameters
    guide_47 = instr.add_component('guide_47','Guide_anyshape_r')
    
    guide_47.xwidth = '0'
    guide_47.yheight = '0'
    guide_47.zdepth = '0'
    guide_47.center = '0'
    guide_47.transmit = '0'
    guide_47.R0 = '0.99'
    guide_47.Qc = '0.0219'
    guide_47.alpha = '0'
    guide_47.m = '0'
    guide_47.W = '0'
    guide_47.geometry = '"./OFF_files/try47.off"'
    
    # Comp instance BW_Chopper_1, placement and parameters
    BW_Chopper_1 = instr.add_component('BW_Chopper_1','MultiDiskChopper', AT=['0.011348994153930106', '0.0', '32.0'], ROTATED=['0', '0.124542024141650', '0'])
    
    BW_Chopper_1.slit_center = 'theta_pos_BW1'
    BW_Chopper_1.slit_width = 'theta_width_BW1'
    BW_Chopper_1.nslits = 'nslits_BW1'
    BW_Chopper_1.delta_y = 'delta_y_BW1'
    BW_Chopper_1.nu = 'f_BW1'
    BW_Chopper_1.nrev = '0'
    BW_Chopper_1.ratio = '1'
    BW_Chopper_1.jitter = '0'
    BW_Chopper_1.delay = 'delay_BW1'
    BW_Chopper_1.isfirst = '0'
    BW_Chopper_1.phase = '0'
    BW_Chopper_1.radius = 'radius_BW1'
    BW_Chopper_1.equal = '0'
    BW_Chopper_1.abs_out = '0'
    BW_Chopper_1.verbose = '0'
    
    # Comp instance B1_monitor_xy, placement and parameters
    B1_monitor_xy = instr.add_component('B1_monitor_xy','Monitor_nD', AT=['0.011348994153930106', '0', '32.1'], ROTATED=['0', '0.124542024141650', '0'])
    
    B1_monitor_xy.user1 = '""'
    B1_monitor_xy.user2 = '""'
    B1_monitor_xy.user3 = '""'
    B1_monitor_xy.xwidth = '0.070'
    B1_monitor_xy.yheight = '0.09'
    B1_monitor_xy.zdepth = '0'
    B1_monitor_xy.xmin = '0'
    B1_monitor_xy.xmax = '0'
    B1_monitor_xy.ymin = '0'
    B1_monitor_xy.ymax = '0'
    B1_monitor_xy.zmin = '0'
    B1_monitor_xy.zmax = '0'
    B1_monitor_xy.bins = '0'
    B1_monitor_xy.min = '-1e40'
    B1_monitor_xy.max = '1e40'
    B1_monitor_xy.restore_neutron = '1'
    B1_monitor_xy.radius = '0'
    B1_monitor_xy.options = '"x limits [-0.035:0.035] bins = 100, y limits [-0.045:0.045] bins = 100"'
    B1_monitor_xy.filename = '"BW1_monitor_xy.dat"'
    B1_monitor_xy.geometry = '"NULL"'
    B1_monitor_xy.nowritefile = '0'
    B1_monitor_xy.nexus_bins = '0'
    B1_monitor_xy.username1 = '"NULL"'
    B1_monitor_xy.username2 = '"NULL"'
    B1_monitor_xy.username3 = '"NULL"'
    
    # Comp instance guide_49, placement and parameters
    guide_49 = instr.add_component('guide_49','Guide_anyshape_r')
    
    guide_49.xwidth = '0'
    guide_49.yheight = '0'
    guide_49.zdepth = '0'
    guide_49.center = '0'
    guide_49.transmit = '0'
    guide_49.R0 = '0.99'
    guide_49.Qc = '0.0219'
    guide_49.alpha = '0'
    guide_49.m = '0'
    guide_49.W = '0'
    guide_49.geometry = '"./OFF_files/try49.off"'
    
    # Comp instance guide_50, placement and parameters
    guide_50 = instr.add_component('guide_50','Guide_anyshape_r')
    
    guide_50.xwidth = '0'
    guide_50.yheight = '0'
    guide_50.zdepth = '0'
    guide_50.center = '0'
    guide_50.transmit = '0'
    guide_50.R0 = '0.99'
    guide_50.Qc = '0.0219'
    guide_50.alpha = '0'
    guide_50.m = '0'
    guide_50.W = '0'
    guide_50.geometry = '"./OFF_files/try50.off"'
    
    # Comp instance guide_51, placement and parameters
    guide_51 = instr.add_component('guide_51','Guide_anyshape_r')
    
    guide_51.xwidth = '0'
    guide_51.yheight = '0'
    guide_51.zdepth = '0'
    guide_51.center = '0'
    guide_51.transmit = '0'
    guide_51.R0 = '0.99'
    guide_51.Qc = '0.0219'
    guide_51.alpha = '0'
    guide_51.m = '0'
    guide_51.W = '0'
    guide_51.geometry = '"./OFF_files/try51.off"'
    
    # Comp instance guide_52, placement and parameters
    guide_52 = instr.add_component('guide_52','Guide_anyshape_r')
    
    guide_52.xwidth = '0'
    guide_52.yheight = '0'
    guide_52.zdepth = '0'
    guide_52.center = '0'
    guide_52.transmit = '0'
    guide_52.R0 = '0.99'
    guide_52.Qc = '0.0219'
    guide_52.alpha = '0'
    guide_52.m = '0'
    guide_52.W = '0'
    guide_52.geometry = '"./OFF_files/try52.off"'
    
    # Comp instance guide_53, placement and parameters
    guide_53 = instr.add_component('guide_53','Guide_anyshape_r')
    
    guide_53.xwidth = '0'
    guide_53.yheight = '0'
    guide_53.zdepth = '0'
    guide_53.center = '0'
    guide_53.transmit = '0'
    guide_53.R0 = '0.99'
    guide_53.Qc = '0.0219'
    guide_53.alpha = '0'
    guide_53.m = '0'
    guide_53.W = '0'
    guide_53.geometry = '"./OFF_files/try53.off"'
    
    # Comp instance guide_54, placement and parameters
    guide_54 = instr.add_component('guide_54','Guide_anyshape_r')
    
    guide_54.xwidth = '0'
    guide_54.yheight = '0'
    guide_54.zdepth = '0'
    guide_54.center = '0'
    guide_54.transmit = '0'
    guide_54.R0 = '0.99'
    guide_54.Qc = '0.0219'
    guide_54.alpha = '0'
    guide_54.m = '0'
    guide_54.W = '0'
    guide_54.geometry = '"./OFF_files/try54.off"'
    
    # Comp instance guide_55, placement and parameters
    guide_55 = instr.add_component('guide_55','Guide_anyshape_r')
    
    guide_55.xwidth = '0'
    guide_55.yheight = '0'
    guide_55.zdepth = '0'
    guide_55.center = '0'
    guide_55.transmit = '0'
    guide_55.R0 = '0.99'
    guide_55.Qc = '0.0219'
    guide_55.alpha = '0'
    guide_55.m = '0'
    guide_55.W = '0'
    guide_55.geometry = '"./OFF_files/try55.off"'
    
    # Comp instance BW_Chopper_2, placement and parameters
    BW_Chopper_2 = instr.add_component('BW_Chopper_2','MultiDiskChopper', AT=['0.03140505829452013', '0.0', '40.0'], ROTATED=['0', '0.162739331227240', '0'])
    
    BW_Chopper_2.slit_center = 'theta_pos_BW2'
    BW_Chopper_2.slit_width = 'theta_width_BW2'
    BW_Chopper_2.nslits = 'nslits_BW2'
    BW_Chopper_2.delta_y = 'delta_y_BW2'
    BW_Chopper_2.nu = 'f_BW2'
    BW_Chopper_2.nrev = '0'
    BW_Chopper_2.ratio = '1'
    BW_Chopper_2.jitter = '0'
    BW_Chopper_2.delay = 'delay_BW2'
    BW_Chopper_2.isfirst = '0'
    BW_Chopper_2.phase = '0'
    BW_Chopper_2.radius = 'radius_BW2'
    BW_Chopper_2.equal = '0'
    BW_Chopper_2.abs_out = '0'
    BW_Chopper_2.verbose = '0'
    
    # Comp instance B2_monitor_xy, placement and parameters
    B2_monitor_xy = instr.add_component('B2_monitor_xy','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='BW_Chopper_2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='BW_Chopper_2')
    
    B2_monitor_xy.user1 = '""'
    B2_monitor_xy.user2 = '""'
    B2_monitor_xy.user3 = '""'
    B2_monitor_xy.xwidth = '0.060'
    B2_monitor_xy.yheight = '0.085'
    B2_monitor_xy.zdepth = '0'
    B2_monitor_xy.xmin = '0'
    B2_monitor_xy.xmax = '0'
    B2_monitor_xy.ymin = '0'
    B2_monitor_xy.ymax = '0'
    B2_monitor_xy.zmin = '0'
    B2_monitor_xy.zmax = '0'
    B2_monitor_xy.bins = '0'
    B2_monitor_xy.min = '-1e40'
    B2_monitor_xy.max = '1e40'
    B2_monitor_xy.restore_neutron = '1'
    B2_monitor_xy.radius = '0'
    B2_monitor_xy.options = '"x limits [-0.0375:0.0375] bins = 100, y limits [-0.05:0.05] bins = 100"'
    B2_monitor_xy.filename = '"BW2_monitor_xy.dat"'
    B2_monitor_xy.geometry = '"NULL"'
    B2_monitor_xy.nowritefile = '0'
    B2_monitor_xy.nexus_bins = '0'
    B2_monitor_xy.username1 = '"NULL"'
    B2_monitor_xy.username2 = '"NULL"'
    B2_monitor_xy.username3 = '"NULL"'
    
    # Comp instance guide_57, placement and parameters
    guide_57 = instr.add_component('guide_57','Guide_anyshape_r')
    
    guide_57.xwidth = '0'
    guide_57.yheight = '0'
    guide_57.zdepth = '0'
    guide_57.center = '0'
    guide_57.transmit = '0'
    guide_57.R0 = '0.99'
    guide_57.Qc = '0.0219'
    guide_57.alpha = '0'
    guide_57.m = '0'
    guide_57.W = '0'
    guide_57.geometry = '"./OFF_files/try57.off"'
    
    # Comp instance guide_58, placement and parameters
    guide_58 = instr.add_component('guide_58','Guide_anyshape_r')
    
    guide_58.xwidth = '0'
    guide_58.yheight = '0'
    guide_58.zdepth = '0'
    guide_58.center = '0'
    guide_58.transmit = '0'
    guide_58.R0 = '0.99'
    guide_58.Qc = '0.0219'
    guide_58.alpha = '0'
    guide_58.m = '0'
    guide_58.W = '0'
    guide_58.geometry = '"./OFF_files/try58.off"'
    
    # Comp instance guide_59, placement and parameters
    guide_59 = instr.add_component('guide_59','Guide_anyshape_r')
    
    guide_59.xwidth = '0'
    guide_59.yheight = '0'
    guide_59.zdepth = '0'
    guide_59.center = '0'
    guide_59.transmit = '0'
    guide_59.R0 = '0.99'
    guide_59.Qc = '0.0219'
    guide_59.alpha = '0'
    guide_59.m = '0'
    guide_59.W = '0'
    guide_59.geometry = '"./OFF_files/try59.off"'
    
    # Comp instance guide_60, placement and parameters
    guide_60 = instr.add_component('guide_60','Guide_anyshape_r')
    
    guide_60.xwidth = '0'
    guide_60.yheight = '0'
    guide_60.zdepth = '0'
    guide_60.center = '0'
    guide_60.transmit = '0'
    guide_60.R0 = '0.99'
    guide_60.Qc = '0.0219'
    guide_60.alpha = '0'
    guide_60.m = '0'
    guide_60.W = '0'
    guide_60.geometry = '"./OFF_files/try60.off"'
    
    # Comp instance guide_61, placement and parameters
    guide_61 = instr.add_component('guide_61','Guide_anyshape_r')
    
    guide_61.xwidth = '0'
    guide_61.yheight = '0'
    guide_61.zdepth = '0'
    guide_61.center = '0'
    guide_61.transmit = '0'
    guide_61.R0 = '0.99'
    guide_61.Qc = '0.0219'
    guide_61.alpha = '0'
    guide_61.m = '0'
    guide_61.W = '0'
    guide_61.geometry = '"./OFF_files/try61.off"'
    
    # Comp instance guide_62, placement and parameters
    guide_62 = instr.add_component('guide_62','Guide_anyshape_r')
    
    guide_62.xwidth = '0'
    guide_62.yheight = '0'
    guide_62.zdepth = '0'
    guide_62.center = '0'
    guide_62.transmit = '0'
    guide_62.R0 = '0.99'
    guide_62.Qc = '0.0219'
    guide_62.alpha = '0'
    guide_62.m = '0'
    guide_62.W = '0'
    guide_62.geometry = '"./OFF_files/try62.off"'
    
    # Comp instance guide_63, placement and parameters
    guide_63 = instr.add_component('guide_63','Guide_anyshape_r')
    
    guide_63.xwidth = '0'
    guide_63.yheight = '0'
    guide_63.zdepth = '0'
    guide_63.center = '0'
    guide_63.transmit = '0'
    guide_63.R0 = '0.99'
    guide_63.Qc = '0.0219'
    guide_63.alpha = '0'
    guide_63.m = '0'
    guide_63.W = '0'
    guide_63.geometry = '"./OFF_files/try63.off"'
    
    # Comp instance guide_64, placement and parameters
    guide_64 = instr.add_component('guide_64','Guide_anyshape_r')
    
    guide_64.xwidth = '0'
    guide_64.yheight = '0'
    guide_64.zdepth = '0'
    guide_64.center = '0'
    guide_64.transmit = '0'
    guide_64.R0 = '0.99'
    guide_64.Qc = '0.0219'
    guide_64.alpha = '0'
    guide_64.m = '0'
    guide_64.W = '0'
    guide_64.geometry = '"./OFF_files/try64.off"'
    
    # Comp instance guide_65, placement and parameters
    guide_65 = instr.add_component('guide_65','Guide_anyshape_r')
    
    guide_65.xwidth = '0'
    guide_65.yheight = '0'
    guide_65.zdepth = '0'
    guide_65.center = '0'
    guide_65.transmit = '0'
    guide_65.R0 = '0.99'
    guide_65.Qc = '0.0219'
    guide_65.alpha = '0'
    guide_65.m = '0'
    guide_65.W = '0'
    guide_65.geometry = '"./OFF_files/try65.off"'
    
    # Comp instance guide_66, placement and parameters
    guide_66 = instr.add_component('guide_66','Guide_anyshape_r')
    
    guide_66.xwidth = '0'
    guide_66.yheight = '0'
    guide_66.zdepth = '0'
    guide_66.center = '0'
    guide_66.transmit = '0'
    guide_66.R0 = '0.99'
    guide_66.Qc = '0.0219'
    guide_66.alpha = '0'
    guide_66.m = '0'
    guide_66.W = '0'
    guide_66.geometry = '"./OFF_files/try66.off"'
    
    # Comp instance guide_67, placement and parameters
    guide_67 = instr.add_component('guide_67','Guide_anyshape_r')
    
    guide_67.xwidth = '0'
    guide_67.yheight = '0'
    guide_67.zdepth = '0'
    guide_67.center = '0'
    guide_67.transmit = '0'
    guide_67.R0 = '0.99'
    guide_67.Qc = '0.0219'
    guide_67.alpha = '0'
    guide_67.m = '0'
    guide_67.W = '0'
    guide_67.geometry = '"./OFF_files/try67.off"'
    
    # Comp instance guide_68, placement and parameters
    guide_68 = instr.add_component('guide_68','Guide_anyshape_r')
    
    guide_68.xwidth = '0'
    guide_68.yheight = '0'
    guide_68.zdepth = '0'
    guide_68.center = '0'
    guide_68.transmit = '0'
    guide_68.R0 = '0.99'
    guide_68.Qc = '0.0219'
    guide_68.alpha = '0'
    guide_68.m = '0'
    guide_68.W = '0'
    guide_68.geometry = '"./OFF_files/try68.off"'
    
    # Comp instance guide_69, placement and parameters
    guide_69 = instr.add_component('guide_69','Guide_anyshape_r')
    
    guide_69.xwidth = '0'
    guide_69.yheight = '0'
    guide_69.zdepth = '0'
    guide_69.center = '0'
    guide_69.transmit = '0'
    guide_69.R0 = '0.99'
    guide_69.Qc = '0.0219'
    guide_69.alpha = '0'
    guide_69.m = '0'
    guide_69.W = '0'
    guide_69.geometry = '"./OFF_files/try69.off"'
    
    # Comp instance guide_70, placement and parameters
    guide_70 = instr.add_component('guide_70','Guide_anyshape_r')
    
    guide_70.xwidth = '0'
    guide_70.yheight = '0'
    guide_70.zdepth = '0'
    guide_70.center = '0'
    guide_70.transmit = '0'
    guide_70.R0 = '0.99'
    guide_70.Qc = '0.0219'
    guide_70.alpha = '0'
    guide_70.m = '0'
    guide_70.W = '0'
    guide_70.geometry = '"./OFF_files/try70.off"'
    
    # Comp instance guide_71, placement and parameters
    guide_71 = instr.add_component('guide_71','Guide_anyshape_r')
    
    guide_71.xwidth = '0'
    guide_71.yheight = '0'
    guide_71.zdepth = '0'
    guide_71.center = '0'
    guide_71.transmit = '0'
    guide_71.R0 = '0.99'
    guide_71.Qc = '0.0219'
    guide_71.alpha = '0'
    guide_71.m = '0'
    guide_71.W = '0'
    guide_71.geometry = '"./OFF_files/try71.off"'
    
    # Comp instance guide_72, placement and parameters
    guide_72 = instr.add_component('guide_72','Guide_anyshape_r')
    
    guide_72.xwidth = '0'
    guide_72.yheight = '0'
    guide_72.zdepth = '0'
    guide_72.center = '0'
    guide_72.transmit = '0'
    guide_72.R0 = '0.99'
    guide_72.Qc = '0.0219'
    guide_72.alpha = '0'
    guide_72.m = '0'
    guide_72.W = '0'
    guide_72.geometry = '"./OFF_files/try72.off"'
    
    # Comp instance guide_73, placement and parameters
    guide_73 = instr.add_component('guide_73','Guide_anyshape_r')
    
    guide_73.xwidth = '0'
    guide_73.yheight = '0'
    guide_73.zdepth = '0'
    guide_73.center = '0'
    guide_73.transmit = '0'
    guide_73.R0 = '0.99'
    guide_73.Qc = '0.0219'
    guide_73.alpha = '0'
    guide_73.m = '0'
    guide_73.W = '0'
    guide_73.geometry = '"./OFF_files/try73.off"'
    
    # Comp instance guide_74, placement and parameters
    guide_74 = instr.add_component('guide_74','Guide_anyshape_r')
    
    guide_74.xwidth = '0'
    guide_74.yheight = '0'
    guide_74.zdepth = '0'
    guide_74.center = '0'
    guide_74.transmit = '0'
    guide_74.R0 = '0.99'
    guide_74.Qc = '0.0219'
    guide_74.alpha = '0'
    guide_74.m = '0'
    guide_74.W = '0'
    guide_74.geometry = '"./OFF_files/try74.off"'
    
    # Comp instance guide_75, placement and parameters
    guide_75 = instr.add_component('guide_75','Guide_anyshape_r')
    
    guide_75.xwidth = '0'
    guide_75.yheight = '0'
    guide_75.zdepth = '0'
    guide_75.center = '0'
    guide_75.transmit = '0'
    guide_75.R0 = '0.99'
    guide_75.Qc = '0.0219'
    guide_75.alpha = '0'
    guide_75.m = '0'
    guide_75.W = '0'
    guide_75.geometry = '"./OFF_files/try75.off"'
    
    # Comp instance guide_76, placement and parameters
    guide_76 = instr.add_component('guide_76','Guide_anyshape_r')
    
    guide_76.xwidth = '0'
    guide_76.yheight = '0'
    guide_76.zdepth = '0'
    guide_76.center = '0'
    guide_76.transmit = '0'
    guide_76.R0 = '0.99'
    guide_76.Qc = '0.0219'
    guide_76.alpha = '0'
    guide_76.m = '0'
    guide_76.W = '0'
    guide_76.geometry = '"./OFF_files/try76.off"'
    
    # Comp instance guide_77, placement and parameters
    guide_77 = instr.add_component('guide_77','Guide_anyshape_r')
    
    guide_77.xwidth = '0'
    guide_77.yheight = '0'
    guide_77.zdepth = '0'
    guide_77.center = '0'
    guide_77.transmit = '0'
    guide_77.R0 = '0.99'
    guide_77.Qc = '0.0219'
    guide_77.alpha = '0'
    guide_77.m = '0'
    guide_77.W = '0'
    guide_77.geometry = '"./OFF_files/try77.off"'
    
    # Comp instance guide_78, placement and parameters
    guide_78 = instr.add_component('guide_78','Guide_anyshape_r')
    
    guide_78.xwidth = '0'
    guide_78.yheight = '0'
    guide_78.zdepth = '0'
    guide_78.center = '0'
    guide_78.transmit = '0'
    guide_78.R0 = '0.99'
    guide_78.Qc = '0.0219'
    guide_78.alpha = '0'
    guide_78.m = '0'
    guide_78.W = '0'
    guide_78.geometry = '"./OFF_files/try78.off"'
    
    # Comp instance guide_79, placement and parameters
    guide_79 = instr.add_component('guide_79','Guide_anyshape_r')
    
    guide_79.xwidth = '0'
    guide_79.yheight = '0'
    guide_79.zdepth = '0'
    guide_79.center = '0'
    guide_79.transmit = '0'
    guide_79.R0 = '0.99'
    guide_79.Qc = '0.0219'
    guide_79.alpha = '0'
    guide_79.m = '0'
    guide_79.W = '0'
    guide_79.geometry = '"./OFF_files/try79.off"'
    
    # Comp instance guide_80, placement and parameters
    guide_80 = instr.add_component('guide_80','Guide_anyshape_r')
    
    guide_80.xwidth = '0'
    guide_80.yheight = '0'
    guide_80.zdepth = '0'
    guide_80.center = '0'
    guide_80.transmit = '0'
    guide_80.R0 = '0.99'
    guide_80.Qc = '0.0219'
    guide_80.alpha = '0'
    guide_80.m = '0'
    guide_80.W = '0'
    guide_80.geometry = '"./OFF_files/try80.off"'
    
    # Comp instance guide_81, placement and parameters
    guide_81 = instr.add_component('guide_81','Guide_anyshape_r')
    
    guide_81.xwidth = '0'
    guide_81.yheight = '0'
    guide_81.zdepth = '0'
    guide_81.center = '0'
    guide_81.transmit = '0'
    guide_81.R0 = '0.99'
    guide_81.Qc = '0.0219'
    guide_81.alpha = '0'
    guide_81.m = '0'
    guide_81.W = '0'
    guide_81.geometry = '"./OFF_files/try81.off"'
    
    # Comp instance guide_82, placement and parameters
    guide_82 = instr.add_component('guide_82','Guide_anyshape_r')
    
    guide_82.xwidth = '0'
    guide_82.yheight = '0'
    guide_82.zdepth = '0'
    guide_82.center = '0'
    guide_82.transmit = '0'
    guide_82.R0 = '0.99'
    guide_82.Qc = '0.0219'
    guide_82.alpha = '0'
    guide_82.m = '0'
    guide_82.W = '0'
    guide_82.geometry = '"./OFF_files/try82.off"'
    
    # Comp instance guide_83, placement and parameters
    guide_83 = instr.add_component('guide_83','Guide_anyshape_r')
    
    guide_83.xwidth = '0'
    guide_83.yheight = '0'
    guide_83.zdepth = '0'
    guide_83.center = '0'
    guide_83.transmit = '0'
    guide_83.R0 = '0.99'
    guide_83.Qc = '0.0219'
    guide_83.alpha = '0'
    guide_83.m = '0'
    guide_83.W = '0'
    guide_83.geometry = '"./OFF_files/try83.off"'
    
    # Comp instance guide_84, placement and parameters
    guide_84 = instr.add_component('guide_84','Guide_anyshape_r')
    
    guide_84.xwidth = '0'
    guide_84.yheight = '0'
    guide_84.zdepth = '0'
    guide_84.center = '0'
    guide_84.transmit = '0'
    guide_84.R0 = '0.99'
    guide_84.Qc = '0.0219'
    guide_84.alpha = '0'
    guide_84.m = '0'
    guide_84.W = '0'
    guide_84.geometry = '"./OFF_files/try84.off"'
    
    # Comp instance guide_85, placement and parameters
    guide_85 = instr.add_component('guide_85','Guide_anyshape_r')
    
    guide_85.xwidth = '0'
    guide_85.yheight = '0'
    guide_85.zdepth = '0'
    guide_85.center = '0'
    guide_85.transmit = '0'
    guide_85.R0 = '0.99'
    guide_85.Qc = '0.0219'
    guide_85.alpha = '0'
    guide_85.m = '0'
    guide_85.W = '0'
    guide_85.geometry = '"./OFF_files/try85.off"'
    
    # Comp instance guide_86, placement and parameters
    guide_86 = instr.add_component('guide_86','Guide_anyshape_r')
    
    guide_86.xwidth = '0'
    guide_86.yheight = '0'
    guide_86.zdepth = '0'
    guide_86.center = '0'
    guide_86.transmit = '0'
    guide_86.R0 = '0.99'
    guide_86.Qc = '0.0219'
    guide_86.alpha = '0'
    guide_86.m = '0'
    guide_86.W = '0'
    guide_86.geometry = '"./OFF_files/try86.off"'
    
    # Comp instance guide_87, placement and parameters
    guide_87 = instr.add_component('guide_87','Guide_anyshape_r')
    
    guide_87.xwidth = '0'
    guide_87.yheight = '0'
    guide_87.zdepth = '0'
    guide_87.center = '0'
    guide_87.transmit = '0'
    guide_87.R0 = '0.99'
    guide_87.Qc = '0.0219'
    guide_87.alpha = '0'
    guide_87.m = '0'
    guide_87.W = '0'
    guide_87.geometry = '"./OFF_files/try87.off"'
    
    # Comp instance guide_88, placement and parameters
    guide_88 = instr.add_component('guide_88','Guide_anyshape_r')
    
    guide_88.xwidth = '0'
    guide_88.yheight = '0'
    guide_88.zdepth = '0'
    guide_88.center = '0'
    guide_88.transmit = '0'
    guide_88.R0 = '0.99'
    guide_88.Qc = '0.0219'
    guide_88.alpha = '0'
    guide_88.m = '0'
    guide_88.W = '0'
    guide_88.geometry = '"./OFF_files/try88.off"'
    
    # Comp instance guide_89, placement and parameters
    guide_89 = instr.add_component('guide_89','Guide_anyshape_r')
    
    guide_89.xwidth = '0'
    guide_89.yheight = '0'
    guide_89.zdepth = '0'
    guide_89.center = '0'
    guide_89.transmit = '0'
    guide_89.R0 = '0.99'
    guide_89.Qc = '0.0219'
    guide_89.alpha = '0'
    guide_89.m = '0'
    guide_89.W = '0'
    guide_89.geometry = '"./OFF_files/try89.off"'
    
    # Comp instance guide_90, placement and parameters
    guide_90 = instr.add_component('guide_90','Guide_anyshape_r')
    
    guide_90.xwidth = '0'
    guide_90.yheight = '0'
    guide_90.zdepth = '0'
    guide_90.center = '0'
    guide_90.transmit = '0'
    guide_90.R0 = '0.99'
    guide_90.Qc = '0.0219'
    guide_90.alpha = '0'
    guide_90.m = '0'
    guide_90.W = '0'
    guide_90.geometry = '"./OFF_files/try90.off"'
    
    # Comp instance guide_91, placement and parameters
    guide_91 = instr.add_component('guide_91','Guide_anyshape_r')
    
    guide_91.xwidth = '0'
    guide_91.yheight = '0'
    guide_91.zdepth = '0'
    guide_91.center = '0'
    guide_91.transmit = '0'
    guide_91.R0 = '0.99'
    guide_91.Qc = '0.0219'
    guide_91.alpha = '0'
    guide_91.m = '0'
    guide_91.W = '0'
    guide_91.geometry = '"./OFF_files/try91.off"'
    
    # Comp instance guide_92, placement and parameters
    guide_92 = instr.add_component('guide_92','Guide_anyshape_r')
    
    guide_92.xwidth = '0'
    guide_92.yheight = '0'
    guide_92.zdepth = '0'
    guide_92.center = '0'
    guide_92.transmit = '0'
    guide_92.R0 = '0.99'
    guide_92.Qc = '0.0219'
    guide_92.alpha = '0'
    guide_92.m = '0'
    guide_92.W = '0'
    guide_92.geometry = '"./OFF_files/try92.off"'
    
    # Comp instance guide_93, placement and parameters
    guide_93 = instr.add_component('guide_93','Guide_anyshape_r')
    
    guide_93.xwidth = '0'
    guide_93.yheight = '0'
    guide_93.zdepth = '0'
    guide_93.center = '0'
    guide_93.transmit = '0'
    guide_93.R0 = '0.99'
    guide_93.Qc = '0.0219'
    guide_93.alpha = '0'
    guide_93.m = '0'
    guide_93.W = '0'
    guide_93.geometry = '"./OFF_files/try93.off"'
    
    # Comp instance guide_94, placement and parameters
    guide_94 = instr.add_component('guide_94','Guide_anyshape_r')
    
    guide_94.xwidth = '0'
    guide_94.yheight = '0'
    guide_94.zdepth = '0'
    guide_94.center = '0'
    guide_94.transmit = '0'
    guide_94.R0 = '0.99'
    guide_94.Qc = '0.0219'
    guide_94.alpha = '0'
    guide_94.m = '0'
    guide_94.W = '0'
    guide_94.geometry = '"./OFF_files/try94.off"'
    
    # Comp instance guide_95, placement and parameters
    guide_95 = instr.add_component('guide_95','Guide_anyshape_r')
    
    guide_95.xwidth = '0'
    guide_95.yheight = '0'
    guide_95.zdepth = '0'
    guide_95.center = '0'
    guide_95.transmit = '0'
    guide_95.R0 = '0.99'
    guide_95.Qc = '0.0219'
    guide_95.alpha = '0'
    guide_95.m = '0'
    guide_95.W = '0'
    guide_95.geometry = '"./OFF_files/try95.off"'
    
    # Comp instance guide_96, placement and parameters
    guide_96 = instr.add_component('guide_96','Guide_anyshape_r')
    
    guide_96.xwidth = '0'
    guide_96.yheight = '0'
    guide_96.zdepth = '0'
    guide_96.center = '0'
    guide_96.transmit = '0'
    guide_96.R0 = '0.99'
    guide_96.Qc = '0.0219'
    guide_96.alpha = '0'
    guide_96.m = '0'
    guide_96.W = '0'
    guide_96.geometry = '"./OFF_files/try96.off"'
    
    # Comp instance guide_97, placement and parameters
    guide_97 = instr.add_component('guide_97','Guide_anyshape_r')
    
    guide_97.xwidth = '0'
    guide_97.yheight = '0'
    guide_97.zdepth = '0'
    guide_97.center = '0'
    guide_97.transmit = '0'
    guide_97.R0 = '0.99'
    guide_97.Qc = '0.0219'
    guide_97.alpha = '0'
    guide_97.m = '0'
    guide_97.W = '0'
    guide_97.geometry = '"./OFF_files/try97.off"'
    
    # Comp instance guide_98, placement and parameters
    guide_98 = instr.add_component('guide_98','Guide_anyshape_r')
    
    guide_98.xwidth = '0'
    guide_98.yheight = '0'
    guide_98.zdepth = '0'
    guide_98.center = '0'
    guide_98.transmit = '0'
    guide_98.R0 = '0.99'
    guide_98.Qc = '0.0219'
    guide_98.alpha = '0'
    guide_98.m = '0'
    guide_98.W = '0'
    guide_98.geometry = '"./OFF_files/try98.off"'
    
    # Comp instance guide_99, placement and parameters
    guide_99 = instr.add_component('guide_99','Guide_anyshape_r')
    
    guide_99.xwidth = '0'
    guide_99.yheight = '0'
    guide_99.zdepth = '0'
    guide_99.center = '0'
    guide_99.transmit = '0'
    guide_99.R0 = '0.99'
    guide_99.Qc = '0.0219'
    guide_99.alpha = '0'
    guide_99.m = '0'
    guide_99.W = '0'
    guide_99.geometry = '"./OFF_files/try99.off"'
    
    # Comp instance guide_100, placement and parameters
    guide_100 = instr.add_component('guide_100','Guide_anyshape_r')
    
    guide_100.xwidth = '0'
    guide_100.yheight = '0'
    guide_100.zdepth = '0'
    guide_100.center = '0'
    guide_100.transmit = '0'
    guide_100.R0 = '0.99'
    guide_100.Qc = '0.0219'
    guide_100.alpha = '0'
    guide_100.m = '0'
    guide_100.W = '0'
    guide_100.geometry = '"./OFF_files/try100.off"'
    
    # Comp instance guide_101, placement and parameters
    guide_101 = instr.add_component('guide_101','Guide_anyshape_r')
    
    guide_101.xwidth = '0'
    guide_101.yheight = '0'
    guide_101.zdepth = '0'
    guide_101.center = '0'
    guide_101.transmit = '0'
    guide_101.R0 = '0.99'
    guide_101.Qc = '0.0219'
    guide_101.alpha = '0'
    guide_101.m = '0'
    guide_101.W = '0'
    guide_101.geometry = '"./OFF_files/try101.off"'
    
    # Comp instance PulseShapingChopper1, placement and parameters
    PulseShapingChopper1 = instr.add_component('PulseShapingChopper1','MultiDiskChopper', AT=['0.4108460115539497', '0.0', '107.95'], ROTATED=['0', '0.430122381481144', '0'])
    
    PulseShapingChopper1.slit_center = 'theta_pos_P1'
    PulseShapingChopper1.slit_width = 'theta_width_P1'
    PulseShapingChopper1.nslits = 'nslits_P1'
    PulseShapingChopper1.delta_y = 'delta_y_P1'
    PulseShapingChopper1.nu = 'f_P1'
    PulseShapingChopper1.nrev = '0'
    PulseShapingChopper1.ratio = '1'
    PulseShapingChopper1.jitter = '0'
    PulseShapingChopper1.delay = 'delay_P1'
    PulseShapingChopper1.isfirst = '0'
    PulseShapingChopper1.phase = '0'
    PulseShapingChopper1.radius = 'radius_P1'
    PulseShapingChopper1.equal = '0'
    PulseShapingChopper1.abs_out = '0'
    PulseShapingChopper1.verbose = '0'
    
    # Comp instance PulseShapingChopper2, placement and parameters
    PulseShapingChopper2 = instr.add_component('PulseShapingChopper2','MultiDiskChopper', AT=['0.41159673083080733', '0.0', '108.05'], ROTATED=['0', '0.430122381481144', '0'])
    
    PulseShapingChopper2.slit_center = 'theta_pos_P2'
    PulseShapingChopper2.slit_width = 'theta_width_P2'
    PulseShapingChopper2.nslits = 'nslits_P2'
    PulseShapingChopper2.delta_y = 'delta_y_P2'
    PulseShapingChopper2.nu = 'f_P2'
    PulseShapingChopper2.nrev = '0'
    PulseShapingChopper2.ratio = '1'
    PulseShapingChopper2.jitter = '0'
    PulseShapingChopper2.delay = 'delay_P2'
    PulseShapingChopper2.isfirst = '0'
    PulseShapingChopper2.phase = '0'
    PulseShapingChopper2.radius = 'radius_P2'
    PulseShapingChopper2.equal = '0'
    PulseShapingChopper2.abs_out = '0'
    PulseShapingChopper2.verbose = '0'
    
    # Comp instance P_monitor_ToF, placement and parameters
    P_monitor_ToF = instr.add_component('P_monitor_ToF','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='PulseShapingChopper2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='PulseShapingChopper2')
    
    P_monitor_ToF.user1 = '""'
    P_monitor_ToF.user2 = '""'
    P_monitor_ToF.user3 = '""'
    P_monitor_ToF.xwidth = '0.06'
    P_monitor_ToF.yheight = '0.084'
    P_monitor_ToF.zdepth = '0'
    P_monitor_ToF.xmin = '0'
    P_monitor_ToF.xmax = '0'
    P_monitor_ToF.ymin = '0'
    P_monitor_ToF.ymax = '0'
    P_monitor_ToF.zmin = '0'
    P_monitor_ToF.zmax = '0'
    P_monitor_ToF.bins = '0'
    P_monitor_ToF.min = '-1e40'
    P_monitor_ToF.max = '1e40'
    P_monitor_ToF.restore_neutron = '1'
    P_monitor_ToF.radius = '0'
    P_monitor_ToF.options = 'setP'
    P_monitor_ToF.filename = '"P_monitor_tof.dat"'
    P_monitor_ToF.geometry = '"NULL"'
    P_monitor_ToF.nowritefile = '0'
    P_monitor_ToF.nexus_bins = '0'
    P_monitor_ToF.username1 = '"NULL"'
    P_monitor_ToF.username2 = '"NULL"'
    P_monitor_ToF.username3 = '"NULL"'
    
    # Comp instance P_monitor_lam, placement and parameters
    P_monitor_lam = instr.add_component('P_monitor_lam','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='P_monitor_ToF', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='P_monitor_ToF')
    
    P_monitor_lam.user1 = '""'
    P_monitor_lam.user2 = '""'
    P_monitor_lam.user3 = '""'
    P_monitor_lam.xwidth = '0.060'
    P_monitor_lam.yheight = '0.085'
    P_monitor_lam.zdepth = '0'
    P_monitor_lam.xmin = '0'
    P_monitor_lam.xmax = '0'
    P_monitor_lam.ymin = '0'
    P_monitor_lam.ymax = '0'
    P_monitor_lam.zmin = '0'
    P_monitor_lam.zmax = '0'
    P_monitor_lam.bins = '0'
    P_monitor_lam.min = '-1e40'
    P_monitor_lam.max = '1e40'
    P_monitor_lam.restore_neutron = '1'
    P_monitor_lam.radius = '0'
    P_monitor_lam.options = 'setPL'
    P_monitor_lam.filename = '"P_monitor_lam.dat"'
    P_monitor_lam.geometry = '"NULL"'
    P_monitor_lam.nowritefile = '0'
    P_monitor_lam.nexus_bins = '0'
    P_monitor_lam.username1 = '"NULL"'
    P_monitor_lam.username2 = '"NULL"'
    P_monitor_lam.username3 = '"NULL"'
    
    # Comp instance P_monitor_xy, placement and parameters
    P_monitor_xy = instr.add_component('P_monitor_xy','Monitor_nD', AT=['0', '0', '0.05'], AT_RELATIVE='P_monitor_lam', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='P_monitor_lam')
    
    P_monitor_xy.user1 = '""'
    P_monitor_xy.user2 = '""'
    P_monitor_xy.user3 = '""'
    P_monitor_xy.xwidth = '0.060'
    P_monitor_xy.yheight = '0.085'
    P_monitor_xy.zdepth = '0'
    P_monitor_xy.xmin = '0'
    P_monitor_xy.xmax = '0'
    P_monitor_xy.ymin = '0'
    P_monitor_xy.ymax = '0'
    P_monitor_xy.zmin = '0'
    P_monitor_xy.zmax = '0'
    P_monitor_xy.bins = '0'
    P_monitor_xy.min = '-1e40'
    P_monitor_xy.max = '1e40'
    P_monitor_xy.restore_neutron = '1'
    P_monitor_xy.radius = '0'
    P_monitor_xy.options = '"x limits [-0.035:0.035] bins = 100, y limits [-0.045:0.045] bins = 100"'
    P_monitor_xy.filename = '"P_monitor_xy.dat"'
    P_monitor_xy.geometry = '"NULL"'
    P_monitor_xy.nowritefile = '0'
    P_monitor_xy.nexus_bins = '0'
    P_monitor_xy.username1 = '"NULL"'
    P_monitor_xy.username2 = '"NULL"'
    P_monitor_xy.username3 = '"NULL"'
    
    # Comp instance guide_103, placement and parameters
    guide_103 = instr.add_component('guide_103','Guide_anyshape_r')
    
    guide_103.xwidth = '0'
    guide_103.yheight = '0'
    guide_103.zdepth = '0'
    guide_103.center = '0'
    guide_103.transmit = '0'
    guide_103.R0 = '0.99'
    guide_103.Qc = '0.0219'
    guide_103.alpha = '0'
    guide_103.m = '0'
    guide_103.W = '0'
    guide_103.geometry = '"./OFF_files/try103.off"'
    
    # Comp instance guide_104, placement and parameters
    guide_104 = instr.add_component('guide_104','Guide_anyshape_r')
    
    guide_104.xwidth = '0'
    guide_104.yheight = '0'
    guide_104.zdepth = '0'
    guide_104.center = '0'
    guide_104.transmit = '0'
    guide_104.R0 = '0.99'
    guide_104.Qc = '0.0219'
    guide_104.alpha = '0'
    guide_104.m = '0'
    guide_104.W = '0'
    guide_104.geometry = '"./OFF_files/try104.off"'
    
    # Comp instance guide_105, placement and parameters
    guide_105 = instr.add_component('guide_105','Guide_anyshape_r')
    
    guide_105.xwidth = '0'
    guide_105.yheight = '0'
    guide_105.zdepth = '0'
    guide_105.center = '0'
    guide_105.transmit = '0'
    guide_105.R0 = '0.99'
    guide_105.Qc = '0.0219'
    guide_105.alpha = '0'
    guide_105.m = '0'
    guide_105.W = '0'
    guide_105.geometry = '"./OFF_files/try105.off"'
    
    # Comp instance guide_106, placement and parameters
    guide_106 = instr.add_component('guide_106','Guide_anyshape_r')
    
    guide_106.xwidth = '0'
    guide_106.yheight = '0'
    guide_106.zdepth = '0'
    guide_106.center = '0'
    guide_106.transmit = '0'
    guide_106.R0 = '0.99'
    guide_106.Qc = '0.0219'
    guide_106.alpha = '0'
    guide_106.m = '0'
    guide_106.W = '0'
    guide_106.geometry = '"./OFF_files/try106.off"'
    
    # Comp instance guide_107, placement and parameters
    guide_107 = instr.add_component('guide_107','Guide_anyshape_r')
    
    guide_107.xwidth = '0'
    guide_107.yheight = '0'
    guide_107.zdepth = '0'
    guide_107.center = '0'
    guide_107.transmit = '0'
    guide_107.R0 = '0.99'
    guide_107.Qc = '0.0219'
    guide_107.alpha = '0'
    guide_107.m = '0'
    guide_107.W = '0'
    guide_107.geometry = '"./OFF_files/try107.off"'
    
    # Comp instance guide_108, placement and parameters
    guide_108 = instr.add_component('guide_108','Guide_anyshape_r')
    
    guide_108.xwidth = '0'
    guide_108.yheight = '0'
    guide_108.zdepth = '0'
    guide_108.center = '0'
    guide_108.transmit = '0'
    guide_108.R0 = '0.99'
    guide_108.Qc = '0.0219'
    guide_108.alpha = '0'
    guide_108.m = '0'
    guide_108.W = '0'
    guide_108.geometry = '"./OFF_files/try108.off"'
    
    # Comp instance guide_109, placement and parameters
    guide_109 = instr.add_component('guide_109','Guide_anyshape_r')
    
    guide_109.xwidth = '0'
    guide_109.yheight = '0'
    guide_109.zdepth = '0'
    guide_109.center = '0'
    guide_109.transmit = '0'
    guide_109.R0 = '0.99'
    guide_109.Qc = '0.0219'
    guide_109.alpha = '0'
    guide_109.m = '0'
    guide_109.W = '0'
    guide_109.geometry = '"./OFF_files/try109.off"'
    
    # Comp instance guide_110, placement and parameters
    guide_110 = instr.add_component('guide_110','Guide_anyshape_r')
    
    guide_110.xwidth = '0'
    guide_110.yheight = '0'
    guide_110.zdepth = '0'
    guide_110.center = '0'
    guide_110.transmit = '0'
    guide_110.R0 = '0.99'
    guide_110.Qc = '0.0219'
    guide_110.alpha = '0'
    guide_110.m = '0'
    guide_110.W = '0'
    guide_110.geometry = '"./OFF_files/try110.off"'
    
    # Comp instance guide_111, placement and parameters
    guide_111 = instr.add_component('guide_111','Guide_anyshape_r')
    
    guide_111.xwidth = '0'
    guide_111.yheight = '0'
    guide_111.zdepth = '0'
    guide_111.center = '0'
    guide_111.transmit = '0'
    guide_111.R0 = '0.99'
    guide_111.Qc = '0.0219'
    guide_111.alpha = '0'
    guide_111.m = '0'
    guide_111.W = '0'
    guide_111.geometry = '"./OFF_files/try111.off"'
    
    # Comp instance guide_112, placement and parameters
    guide_112 = instr.add_component('guide_112','Guide_anyshape_r')
    
    guide_112.xwidth = '0'
    guide_112.yheight = '0'
    guide_112.zdepth = '0'
    guide_112.center = '0'
    guide_112.transmit = '0'
    guide_112.R0 = '0.99'
    guide_112.Qc = '0.0219'
    guide_112.alpha = '0'
    guide_112.m = '0'
    guide_112.W = '0'
    guide_112.geometry = '"./OFF_files/try112.off"'
    
    # Comp instance guide_113, placement and parameters
    guide_113 = instr.add_component('guide_113','Guide_anyshape_r')
    
    guide_113.xwidth = '0'
    guide_113.yheight = '0'
    guide_113.zdepth = '0'
    guide_113.center = '0'
    guide_113.transmit = '0'
    guide_113.R0 = '0.99'
    guide_113.Qc = '0.0219'
    guide_113.alpha = '0'
    guide_113.m = '0'
    guide_113.W = '0'
    guide_113.geometry = '"./OFF_files/try113.off"'
    
    # Comp instance guide_114, placement and parameters
    guide_114 = instr.add_component('guide_114','Guide_anyshape_r')
    
    guide_114.xwidth = '0'
    guide_114.yheight = '0'
    guide_114.zdepth = '0'
    guide_114.center = '0'
    guide_114.transmit = '0'
    guide_114.R0 = '0.99'
    guide_114.Qc = '0.0219'
    guide_114.alpha = '0'
    guide_114.m = '0'
    guide_114.W = '0'
    guide_114.geometry = '"./OFF_files/try114.off"'
    
    # Comp instance guide_115, placement and parameters
    guide_115 = instr.add_component('guide_115','Guide_anyshape_r')
    
    guide_115.xwidth = '0'
    guide_115.yheight = '0'
    guide_115.zdepth = '0'
    guide_115.center = '0'
    guide_115.transmit = '0'
    guide_115.R0 = '0.99'
    guide_115.Qc = '0.0219'
    guide_115.alpha = '0'
    guide_115.m = '0'
    guide_115.W = '0'
    guide_115.geometry = '"./OFF_files/try115.off"'
    
    # Comp instance guide_116, placement and parameters
    guide_116 = instr.add_component('guide_116','Guide_anyshape_r')
    
    guide_116.xwidth = '0'
    guide_116.yheight = '0'
    guide_116.zdepth = '0'
    guide_116.center = '0'
    guide_116.transmit = '0'
    guide_116.R0 = '0.99'
    guide_116.Qc = '0.0219'
    guide_116.alpha = '0'
    guide_116.m = '0'
    guide_116.W = '0'
    guide_116.geometry = '"./OFF_files/try116.off"'
    
    # Comp instance guide_117, placement and parameters
    guide_117 = instr.add_component('guide_117','Guide_anyshape_r')
    
    guide_117.xwidth = '0'
    guide_117.yheight = '0'
    guide_117.zdepth = '0'
    guide_117.center = '0'
    guide_117.transmit = '0'
    guide_117.R0 = '0.99'
    guide_117.Qc = '0.0219'
    guide_117.alpha = '0'
    guide_117.m = '0'
    guide_117.W = '0'
    guide_117.geometry = '"./OFF_files/try117.off"'
    
    # Comp instance guide_118, placement and parameters
    guide_118 = instr.add_component('guide_118','Guide_anyshape_r')
    
    guide_118.xwidth = '0'
    guide_118.yheight = '0'
    guide_118.zdepth = '0'
    guide_118.center = '0'
    guide_118.transmit = '0'
    guide_118.R0 = '0.99'
    guide_118.Qc = '0.0219'
    guide_118.alpha = '0'
    guide_118.m = '0'
    guide_118.W = '0'
    guide_118.geometry = '"./OFF_files/try118.off"'
    
    # Comp instance guide_119, placement and parameters
    guide_119 = instr.add_component('guide_119','Guide_anyshape_r')
    
    guide_119.xwidth = '0'
    guide_119.yheight = '0'
    guide_119.zdepth = '0'
    guide_119.center = '0'
    guide_119.transmit = '0'
    guide_119.R0 = '0.99'
    guide_119.Qc = '0.0219'
    guide_119.alpha = '0'
    guide_119.m = '0'
    guide_119.W = '0'
    guide_119.geometry = '"./OFF_files/try119.off"'
    
    # Comp instance guide_120, placement and parameters
    guide_120 = instr.add_component('guide_120','Guide_anyshape_r')
    
    guide_120.xwidth = '0'
    guide_120.yheight = '0'
    guide_120.zdepth = '0'
    guide_120.center = '0'
    guide_120.transmit = '0'
    guide_120.R0 = '0.99'
    guide_120.Qc = '0.0219'
    guide_120.alpha = '0'
    guide_120.m = '0'
    guide_120.W = '0'
    guide_120.geometry = '"./OFF_files/try120.off"'
    
    # Comp instance guide_121, placement and parameters
    guide_121 = instr.add_component('guide_121','Guide_anyshape_r')
    
    guide_121.xwidth = '0'
    guide_121.yheight = '0'
    guide_121.zdepth = '0'
    guide_121.center = '0'
    guide_121.transmit = '0'
    guide_121.R0 = '0.99'
    guide_121.Qc = '0.0219'
    guide_121.alpha = '0'
    guide_121.m = '0'
    guide_121.W = '0'
    guide_121.geometry = '"./OFF_files/try121.off"'
    
    # Comp instance guide_122, placement and parameters
    guide_122 = instr.add_component('guide_122','Guide_anyshape_r')
    
    guide_122.xwidth = '0'
    guide_122.yheight = '0'
    guide_122.zdepth = '0'
    guide_122.center = '0'
    guide_122.transmit = '0'
    guide_122.R0 = '0.99'
    guide_122.Qc = '0.0219'
    guide_122.alpha = '0'
    guide_122.m = '0'
    guide_122.W = '0'
    guide_122.geometry = '"./OFF_files/try122.off"'
    
    # Comp instance guide_123, placement and parameters
    guide_123 = instr.add_component('guide_123','Guide_anyshape_r')
    
    guide_123.xwidth = '0'
    guide_123.yheight = '0'
    guide_123.zdepth = '0'
    guide_123.center = '0'
    guide_123.transmit = '0'
    guide_123.R0 = '0.99'
    guide_123.Qc = '0.0219'
    guide_123.alpha = '0'
    guide_123.m = '0'
    guide_123.W = '0'
    guide_123.geometry = '"./OFF_files/try123.off"'
    
    # Comp instance guide_124, placement and parameters
    guide_124 = instr.add_component('guide_124','Guide_anyshape_r')
    
    guide_124.xwidth = '0'
    guide_124.yheight = '0'
    guide_124.zdepth = '0'
    guide_124.center = '0'
    guide_124.transmit = '0'
    guide_124.R0 = '0.99'
    guide_124.Qc = '0.0219'
    guide_124.alpha = '0'
    guide_124.m = '0'
    guide_124.W = '0'
    guide_124.geometry = '"./OFF_files/try124.off"'
    
    # Comp instance FanChopper_1, placement and parameters
    FanChopper_1 = instr.add_component('FanChopper_1','MultiDiskChopper', AT=['0.7379194611672716', '0.0', '151.51801'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_1.slit_center = 'theta_pos_FAN'
    FanChopper_1.slit_width = 'theta_width_FAN'
    FanChopper_1.nslits = 'nslits_FAN'
    FanChopper_1.delta_y = 'delta_y_FAN'
    FanChopper_1.nu = 'f_FAN1'
    FanChopper_1.nrev = '0'
    FanChopper_1.ratio = '1'
    FanChopper_1.jitter = '0'
    FanChopper_1.delay = 'delay_FAN1'
    FanChopper_1.isfirst = '0'
    FanChopper_1.phase = 'phase_FAN1'
    FanChopper_1.radius = 'radius_FAN'
    FanChopper_1.equal = '0'
    FanChopper_1.abs_out = '0'
    FanChopper_1.verbose = '0'
    
    # Comp instance FanChopper_2, placement and parameters
    FanChopper_2 = instr.add_component('FanChopper_2','MultiDiskChopper', AT=['0.7379778170790591', '0.0', '151.52578333333332'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_2.slit_center = 'theta_pos_FAN'
    FanChopper_2.slit_width = 'theta_width_FAN'
    FanChopper_2.nslits = 'nslits_FAN'
    FanChopper_2.delta_y = 'delta_y_FAN'
    FanChopper_2.nu = 'f_FAN2'
    FanChopper_2.nrev = '0'
    FanChopper_2.ratio = '1'
    FanChopper_2.jitter = '0'
    FanChopper_2.delay = 'delay_FAN2'
    FanChopper_2.isfirst = '0'
    FanChopper_2.phase = 'phase_FAN2'
    FanChopper_2.radius = 'radius_FAN'
    FanChopper_2.equal = '0'
    FanChopper_2.abs_out = '0'
    FanChopper_2.verbose = '0'
    
    # Comp instance FanChopper_3, placement and parameters
    FanChopper_3 = instr.add_component('FanChopper_3','MultiDiskChopper', AT=['0.738036172990847', '0.0', '151.53355666666667'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_3.slit_center = 'theta_pos_FAN'
    FanChopper_3.slit_width = 'theta_width_FAN'
    FanChopper_3.nslits = 'nslits_FAN'
    FanChopper_3.delta_y = 'delta_y_FAN'
    FanChopper_3.nu = 'f_FAN3'
    FanChopper_3.nrev = '0'
    FanChopper_3.ratio = '1'
    FanChopper_3.jitter = '0'
    FanChopper_3.delay = 'delay_FAN3'
    FanChopper_3.isfirst = '0'
    FanChopper_3.phase = 'phase_FAN3'
    FanChopper_3.radius = 'radius_FAN'
    FanChopper_3.equal = '0'
    FanChopper_3.abs_out = '0'
    FanChopper_3.verbose = '0'
    
    # Comp instance FanChopper_4, placement and parameters
    FanChopper_4 = instr.add_component('FanChopper_4','MultiDiskChopper', AT=['0.7380945289026345', '0.0', '151.54133'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_4.slit_center = 'theta_pos_FAN'
    FanChopper_4.slit_width = 'theta_width_FAN'
    FanChopper_4.nslits = 'nslits_FAN'
    FanChopper_4.delta_y = 'delta_y_FAN'
    FanChopper_4.nu = 'f_FAN4'
    FanChopper_4.nrev = '0'
    FanChopper_4.ratio = '1'
    FanChopper_4.jitter = '0'
    FanChopper_4.delay = 'delay_FAN4'
    FanChopper_4.isfirst = '0'
    FanChopper_4.phase = 'phase_FAN4'
    FanChopper_4.radius = 'radius_FAN'
    FanChopper_4.equal = '0'
    FanChopper_4.abs_out = '0'
    FanChopper_4.verbose = '0'
    
    # Comp instance FanChopper_5, placement and parameters
    FanChopper_5 = instr.add_component('FanChopper_5','MultiDiskChopper', AT=['0.7381528848144224', '0.0', '151.54910333333333'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_5.slit_center = 'theta_pos_FAN'
    FanChopper_5.slit_width = 'theta_width_FAN'
    FanChopper_5.nslits = 'nslits_FAN'
    FanChopper_5.delta_y = 'delta_y_FAN'
    FanChopper_5.nu = 'f_FAN5'
    FanChopper_5.nrev = '0'
    FanChopper_5.ratio = '1'
    FanChopper_5.jitter = '0'
    FanChopper_5.delay = 'delay_FAN5'
    FanChopper_5.isfirst = '0'
    FanChopper_5.phase = 'phase_FAN5'
    FanChopper_5.radius = 'radius_FAN'
    FanChopper_5.equal = '0'
    FanChopper_5.abs_out = '0'
    FanChopper_5.verbose = '0'
    
    # Comp instance FanChopper_6, placement and parameters
    FanChopper_6 = instr.add_component('FanChopper_6','MultiDiskChopper', AT=['0.7382112407262101', '0.0', '151.55687666666665'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_6.slit_center = 'theta_pos_FAN'
    FanChopper_6.slit_width = 'theta_width_FAN'
    FanChopper_6.nslits = 'nslits_FAN'
    FanChopper_6.delta_y = 'delta_y_FAN'
    FanChopper_6.nu = 'f_FAN6'
    FanChopper_6.nrev = '0'
    FanChopper_6.ratio = '1'
    FanChopper_6.jitter = '0'
    FanChopper_6.delay = 'delay_FAN6'
    FanChopper_6.isfirst = '0'
    FanChopper_6.phase = 'phase_FAN6'
    FanChopper_6.radius = 'radius_FAN'
    FanChopper_6.equal = '0'
    FanChopper_6.abs_out = '0'
    FanChopper_6.verbose = '0'
    
    # Comp instance FanChopper_7, placement and parameters
    FanChopper_7 = instr.add_component('FanChopper_7','MultiDiskChopper', AT=['0.7382695966379978', '0.0', '151.56465'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_7.slit_center = 'theta_pos_FAN'
    FanChopper_7.slit_width = 'theta_width_FAN'
    FanChopper_7.nslits = 'nslits_FAN'
    FanChopper_7.delta_y = 'delta_y_FAN'
    FanChopper_7.nu = 'f_FAN7'
    FanChopper_7.nrev = '0'
    FanChopper_7.ratio = '1'
    FanChopper_7.jitter = '0'
    FanChopper_7.delay = 'delay_FAN7'
    FanChopper_7.isfirst = '0'
    FanChopper_7.phase = 'phase_FAN7'
    FanChopper_7.radius = 'radius_FAN'
    FanChopper_7.equal = '0'
    FanChopper_7.abs_out = '0'
    FanChopper_7.verbose = '0'
    
    # Comp instance FanChopper_8, placement and parameters
    FanChopper_8 = instr.add_component('FanChopper_8','MultiDiskChopper', AT=['0.7383279525497856', '0.0', '151.57242333333332'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_8.slit_center = 'theta_pos_FAN'
    FanChopper_8.slit_width = 'theta_width_FAN'
    FanChopper_8.nslits = 'nslits_FAN'
    FanChopper_8.delta_y = 'delta_y_FAN'
    FanChopper_8.nu = 'f_FAN8'
    FanChopper_8.nrev = '0'
    FanChopper_8.ratio = '1'
    FanChopper_8.jitter = '0'
    FanChopper_8.delay = 'delay_FAN8'
    FanChopper_8.isfirst = '0'
    FanChopper_8.phase = 'phase_FAN8'
    FanChopper_8.radius = 'radius_FAN'
    FanChopper_8.equal = '0'
    FanChopper_8.abs_out = '0'
    FanChopper_8.verbose = '0'
    
    # Comp instance FanChopper_9, placement and parameters
    FanChopper_9 = instr.add_component('FanChopper_9','MultiDiskChopper', AT=['0.7383863084615735', '0.0', '151.58019666666667'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_9.slit_center = 'theta_pos_FAN'
    FanChopper_9.slit_width = 'theta_width_FAN'
    FanChopper_9.nslits = 'nslits_FAN'
    FanChopper_9.delta_y = 'delta_y_FAN'
    FanChopper_9.nu = 'f_FAN9'
    FanChopper_9.nrev = '0'
    FanChopper_9.ratio = '1'
    FanChopper_9.jitter = '0'
    FanChopper_9.delay = 'delay_FAN9'
    FanChopper_9.isfirst = '0'
    FanChopper_9.phase = 'phase_FAN9'
    FanChopper_9.radius = 'radius_FAN'
    FanChopper_9.equal = '0'
    FanChopper_9.abs_out = '0'
    FanChopper_9.verbose = '0'
    
    # Comp instance FanChopper_10, placement and parameters
    FanChopper_10 = instr.add_component('FanChopper_10','MultiDiskChopper', AT=['0.738444664373361', '0.0', '151.58796999999998'], ROTATED=['0', '0.430122381481144', '0'])
    
    FanChopper_10.slit_center = 'theta_pos_FAN'
    FanChopper_10.slit_width = 'theta_width_FAN'
    FanChopper_10.nslits = 'nslits_FAN'
    FanChopper_10.delta_y = 'delta_y_FAN'
    FanChopper_10.nu = 'f_FAN10'
    FanChopper_10.nrev = '0'
    FanChopper_10.ratio = '1'
    FanChopper_10.jitter = '0'
    FanChopper_10.delay = 'delay_FAN10'
    FanChopper_10.isfirst = '0'
    FanChopper_10.phase = 'phase_FAN10'
    FanChopper_10.radius = 'radius_FAN'
    FanChopper_10.equal = '0'
    FanChopper_10.abs_out = '0'
    FanChopper_10.verbose = '0'
    
    # Comp instance F_monitor_flux, placement and parameters
    F_monitor_flux = instr.add_component('F_monitor_flux','Monitor_nD', AT=['0.7384448145172166', '0.0', '151.58799'], ROTATED=['0', '0.430122381481144', '0'])
    
    F_monitor_flux.user1 = '""'
    F_monitor_flux.user2 = '""'
    F_monitor_flux.user3 = '""'
    F_monitor_flux.xwidth = '0.040'
    F_monitor_flux.yheight = '0.050'
    F_monitor_flux.zdepth = '0'
    F_monitor_flux.xmin = '0'
    F_monitor_flux.xmax = '0'
    F_monitor_flux.ymin = '0'
    F_monitor_flux.ymax = '0'
    F_monitor_flux.zmin = '0'
    F_monitor_flux.zmax = '0'
    F_monitor_flux.bins = '0'
    F_monitor_flux.min = '-1e40'
    F_monitor_flux.max = '1e40'
    F_monitor_flux.restore_neutron = '1'
    F_monitor_flux.radius = '0'
    F_monitor_flux.options = '"flux bins=1"'
    F_monitor_flux.filename = '"F_flux.dat"'
    F_monitor_flux.geometry = '"NULL"'
    F_monitor_flux.nowritefile = '0'
    F_monitor_flux.nexus_bins = '0'
    F_monitor_flux.username1 = '"NULL"'
    F_monitor_flux.username2 = '"NULL"'
    F_monitor_flux.username3 = '"NULL"'
    
    # Comp instance F_monitor_hdiv, placement and parameters
    F_monitor_hdiv = instr.add_component('F_monitor_hdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='F_monitor_flux', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='F_monitor_flux')
    
    F_monitor_hdiv.user1 = '""'
    F_monitor_hdiv.user2 = '""'
    F_monitor_hdiv.user3 = '""'
    F_monitor_hdiv.xwidth = '0.040'
    F_monitor_hdiv.yheight = '0.050'
    F_monitor_hdiv.zdepth = '0'
    F_monitor_hdiv.xmin = '0'
    F_monitor_hdiv.xmax = '0'
    F_monitor_hdiv.ymin = '0'
    F_monitor_hdiv.ymax = '0'
    F_monitor_hdiv.zmin = '0'
    F_monitor_hdiv.zmax = '0'
    F_monitor_hdiv.bins = '0'
    F_monitor_hdiv.min = '-1e40'
    F_monitor_hdiv.max = '1e40'
    F_monitor_hdiv.restore_neutron = '1'
    F_monitor_hdiv.radius = '0'
    F_monitor_hdiv.options = '"hdiv limits [-2.0:2.0] bins = 100"'
    F_monitor_hdiv.filename = '"F_monitor_hdiv.dat"'
    F_monitor_hdiv.geometry = '"NULL"'
    F_monitor_hdiv.nowritefile = '0'
    F_monitor_hdiv.nexus_bins = '0'
    F_monitor_hdiv.username1 = '"NULL"'
    F_monitor_hdiv.username2 = '"NULL"'
    F_monitor_hdiv.username3 = '"NULL"'
    
    # Comp instance F_monitor_vdiv, placement and parameters
    F_monitor_vdiv = instr.add_component('F_monitor_vdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='F_monitor_hdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='F_monitor_hdiv')
    
    F_monitor_vdiv.user1 = '""'
    F_monitor_vdiv.user2 = '""'
    F_monitor_vdiv.user3 = '""'
    F_monitor_vdiv.xwidth = '0.040'
    F_monitor_vdiv.yheight = '0.050'
    F_monitor_vdiv.zdepth = '0'
    F_monitor_vdiv.xmin = '0'
    F_monitor_vdiv.xmax = '0'
    F_monitor_vdiv.ymin = '0'
    F_monitor_vdiv.ymax = '0'
    F_monitor_vdiv.zmin = '0'
    F_monitor_vdiv.zmax = '0'
    F_monitor_vdiv.bins = '0'
    F_monitor_vdiv.min = '-1e40'
    F_monitor_vdiv.max = '1e40'
    F_monitor_vdiv.restore_neutron = '1'
    F_monitor_vdiv.radius = '0'
    F_monitor_vdiv.options = '"vdiv limits [-2.0:2.0] bins = 100"'
    F_monitor_vdiv.filename = '"F_monitor_vdiv.dat"'
    F_monitor_vdiv.geometry = '"NULL"'
    F_monitor_vdiv.nowritefile = '0'
    F_monitor_vdiv.nexus_bins = '0'
    F_monitor_vdiv.username1 = '"NULL"'
    F_monitor_vdiv.username2 = '"NULL"'
    F_monitor_vdiv.username3 = '"NULL"'
    
    # Comp instance F_monitor_lam, placement and parameters
    F_monitor_lam = instr.add_component('F_monitor_lam','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='F_monitor_vdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='F_monitor_vdiv')
    
    F_monitor_lam.user1 = '""'
    F_monitor_lam.user2 = '""'
    F_monitor_lam.user3 = '""'
    F_monitor_lam.xwidth = '0.040'
    F_monitor_lam.yheight = '0.050'
    F_monitor_lam.zdepth = '0'
    F_monitor_lam.xmin = '0'
    F_monitor_lam.xmax = '0'
    F_monitor_lam.ymin = '0'
    F_monitor_lam.ymax = '0'
    F_monitor_lam.zmin = '0'
    F_monitor_lam.zmax = '0'
    F_monitor_lam.bins = '0'
    F_monitor_lam.min = '-1e40'
    F_monitor_lam.max = '1e40'
    F_monitor_lam.restore_neutron = '1'
    F_monitor_lam.radius = '0'
    F_monitor_lam.options = '"lambda limits [0.5:5] bins = 1301"'
    F_monitor_lam.filename = '"F_monitor_lam.dat"'
    F_monitor_lam.geometry = '"NULL"'
    F_monitor_lam.nowritefile = '0'
    F_monitor_lam.nexus_bins = '0'
    F_monitor_lam.username1 = '"NULL"'
    F_monitor_lam.username2 = '"NULL"'
    F_monitor_lam.username3 = '"NULL"'
    
    # Comp instance F_monitor_ToF, placement and parameters
    F_monitor_ToF = instr.add_component('F_monitor_ToF','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='F_monitor_lam', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='F_monitor_lam')
    
    F_monitor_ToF.user1 = '""'
    F_monitor_ToF.user2 = '""'
    F_monitor_ToF.user3 = '""'
    F_monitor_ToF.xwidth = '0.04'
    F_monitor_ToF.yheight = '0.05'
    F_monitor_ToF.zdepth = '0'
    F_monitor_ToF.xmin = '0'
    F_monitor_ToF.xmax = '0'
    F_monitor_ToF.ymin = '0'
    F_monitor_ToF.ymax = '0'
    F_monitor_ToF.zmin = '0'
    F_monitor_ToF.zmax = '0'
    F_monitor_ToF.bins = '0'
    F_monitor_ToF.min = '-1e40'
    F_monitor_ToF.max = '1e40'
    F_monitor_ToF.restore_neutron = '1'
    F_monitor_ToF.radius = '0'
    F_monitor_ToF.options = 'setFAN'
    F_monitor_ToF.filename = '"F_monitor_tof.dat"'
    F_monitor_ToF.geometry = '"NULL"'
    F_monitor_ToF.nowritefile = '0'
    F_monitor_ToF.nexus_bins = '0'
    F_monitor_ToF.username1 = '"NULL"'
    F_monitor_ToF.username2 = '"NULL"'
    F_monitor_ToF.username3 = '"NULL"'
    
    # Comp instance F_monitor_xy, placement and parameters
    F_monitor_xy = instr.add_component('F_monitor_xy','Monitor_nD', AT=['0.7384448145172166', '0.0', '151.58799'], ROTATED=['0', '0.430122381481145', '0'])
    
    F_monitor_xy.user1 = '""'
    F_monitor_xy.user2 = '""'
    F_monitor_xy.user3 = '""'
    F_monitor_xy.xwidth = '0.050'
    F_monitor_xy.yheight = '0.065'
    F_monitor_xy.zdepth = '0'
    F_monitor_xy.xmin = '0'
    F_monitor_xy.xmax = '0'
    F_monitor_xy.ymin = '0'
    F_monitor_xy.ymax = '0'
    F_monitor_xy.zmin = '0'
    F_monitor_xy.zmax = '0'
    F_monitor_xy.bins = '0'
    F_monitor_xy.min = '-1e40'
    F_monitor_xy.max = '1e40'
    F_monitor_xy.restore_neutron = '1'
    F_monitor_xy.radius = '0'
    F_monitor_xy.options = '"x limits [-0.025:0.025] bins = 100, y limits [-0.0325:0.0325] bins = 100"'
    F_monitor_xy.filename = '"F_monitor_xy.dat"'
    F_monitor_xy.geometry = '"NULL"'
    F_monitor_xy.nowritefile = '0'
    F_monitor_xy.nexus_bins = '0'
    F_monitor_xy.username1 = '"NULL"'
    F_monitor_xy.username2 = '"NULL"'
    F_monitor_xy.username3 = '"NULL"'
    
    # Comp instance guide_126, placement and parameters
    guide_126 = instr.add_component('guide_126','Guide_anyshape_r')
    
    guide_126.xwidth = '0'
    guide_126.yheight = '0'
    guide_126.zdepth = '0'
    guide_126.center = '0'
    guide_126.transmit = '0'
    guide_126.R0 = '0.99'
    guide_126.Qc = '0.0219'
    guide_126.alpha = '0'
    guide_126.m = '0'
    guide_126.W = '0'
    guide_126.geometry = '"./OFF_files/try126.off"'
    
    # Comp instance guide_127, placement and parameters
    guide_127 = instr.add_component('guide_127','Guide_anyshape_r')
    
    guide_127.xwidth = '0'
    guide_127.yheight = '0'
    guide_127.zdepth = '0'
    guide_127.center = '0'
    guide_127.transmit = '0'
    guide_127.R0 = '0.99'
    guide_127.Qc = '0.0219'
    guide_127.alpha = '0'
    guide_127.m = '0'
    guide_127.W = '0'
    guide_127.geometry = '"./OFF_files/try127.off"'
    
    # Comp instance guide_128, placement and parameters
    guide_128 = instr.add_component('guide_128','Guide_anyshape_r')
    
    guide_128.xwidth = '0'
    guide_128.yheight = '0'
    guide_128.zdepth = '0'
    guide_128.center = '0'
    guide_128.transmit = '0'
    guide_128.R0 = '0.99'
    guide_128.Qc = '0.0219'
    guide_128.alpha = '0'
    guide_128.m = '0'
    guide_128.W = '0'
    guide_128.geometry = '"./OFF_files/try128.off"'
    
    # Comp instance guide_129, placement and parameters
    guide_129 = instr.add_component('guide_129','Guide_anyshape_r')
    
    guide_129.xwidth = '0'
    guide_129.yheight = '0'
    guide_129.zdepth = '0'
    guide_129.center = '0'
    guide_129.transmit = '0'
    guide_129.R0 = '0.99'
    guide_129.Qc = '0.0219'
    guide_129.alpha = '0'
    guide_129.m = '0'
    guide_129.W = '0'
    guide_129.geometry = '"./OFF_files/try129.off"'
    
    # Comp instance guide_130, placement and parameters
    guide_130 = instr.add_component('guide_130','Guide_anyshape_r')
    
    guide_130.xwidth = '0'
    guide_130.yheight = '0'
    guide_130.zdepth = '0'
    guide_130.center = '0'
    guide_130.transmit = '0'
    guide_130.R0 = '0.99'
    guide_130.Qc = '0.0219'
    guide_130.alpha = '0'
    guide_130.m = '0'
    guide_130.W = '0'
    guide_130.geometry = '"./OFF_files/try130.off"'
    
    # Comp instance guide_131, placement and parameters
    guide_131 = instr.add_component('guide_131','Guide_anyshape_r')
    
    guide_131.xwidth = '0'
    guide_131.yheight = '0'
    guide_131.zdepth = '0'
    guide_131.center = '0'
    guide_131.transmit = '0'
    guide_131.R0 = '0.99'
    guide_131.Qc = '0.0219'
    guide_131.alpha = '0'
    guide_131.m = '0'
    guide_131.W = '0'
    guide_131.geometry = '"./OFF_files/try131.off"'
    
    # Comp instance guide_132, placement and parameters
    guide_132 = instr.add_component('guide_132','Guide_anyshape_r')
    
    guide_132.xwidth = '0'
    guide_132.yheight = '0'
    guide_132.zdepth = '0'
    guide_132.center = '0'
    guide_132.transmit = '0'
    guide_132.R0 = '0.99'
    guide_132.Qc = '0.0219'
    guide_132.alpha = '0'
    guide_132.m = '0'
    guide_132.W = '0'
    guide_132.geometry = '"./OFF_files/try132.off"'
    
    # Comp instance guide_133, placement and parameters
    guide_133 = instr.add_component('guide_133','Guide_anyshape_r')
    
    guide_133.xwidth = '0'
    guide_133.yheight = '0'
    guide_133.zdepth = '0'
    guide_133.center = '0'
    guide_133.transmit = '0'
    guide_133.R0 = '0.99'
    guide_133.Qc = '0.0219'
    guide_133.alpha = '0'
    guide_133.m = '0'
    guide_133.W = '0'
    guide_133.geometry = '"./OFF_files/try133.off"'
    
    # Comp instance guide_134, placement and parameters
    guide_134 = instr.add_component('guide_134','Guide_anyshape_r')
    
    guide_134.xwidth = '0'
    guide_134.yheight = '0'
    guide_134.zdepth = '0'
    guide_134.center = '0'
    guide_134.transmit = '0'
    guide_134.R0 = '0.99'
    guide_134.Qc = '0.0219'
    guide_134.alpha = '0'
    guide_134.m = '0'
    guide_134.W = '0'
    guide_134.geometry = '"./OFF_files/try134.off"'
    
    # Comp instance guide_135, placement and parameters
    guide_135 = instr.add_component('guide_135','Guide_anyshape_r')
    
    guide_135.xwidth = '0'
    guide_135.yheight = '0'
    guide_135.zdepth = '0'
    guide_135.center = '0'
    guide_135.transmit = '0'
    guide_135.R0 = '0.99'
    guide_135.Qc = '0.0219'
    guide_135.alpha = '0'
    guide_135.m = '0'
    guide_135.W = '0'
    guide_135.geometry = '"./OFF_files/try135.off"'
    
    # Comp instance guide_136, placement and parameters
    guide_136 = instr.add_component('guide_136','Guide_anyshape_r')
    
    guide_136.xwidth = '0'
    guide_136.yheight = '0'
    guide_136.zdepth = '0'
    guide_136.center = '0'
    guide_136.transmit = '0'
    guide_136.R0 = '0.99'
    guide_136.Qc = '0.0219'
    guide_136.alpha = '0'
    guide_136.m = '0'
    guide_136.W = '0'
    guide_136.geometry = '"./OFF_files/try136.off"'
    
    # Comp instance MonochromatingChopper1, placement and parameters
    MonochromatingChopper1 = instr.add_component('MonochromatingChopper1','MultiDiskChopper', AT=['0.8166097806955753', '0.0', '162.0 -0.005'], ROTATED=['0', '0.430122381481144', '0'])
    
    MonochromatingChopper1.slit_center = 'theta_pos_M1'
    MonochromatingChopper1.slit_width = 'theta_width_M1'
    MonochromatingChopper1.nslits = 'nslits_M1'
    MonochromatingChopper1.delta_y = 'delta_y_M1'
    MonochromatingChopper1.nu = 'f_M1'
    MonochromatingChopper1.nrev = '0'
    MonochromatingChopper1.ratio = '1'
    MonochromatingChopper1.jitter = '0'
    MonochromatingChopper1.delay = 'delay_M1'
    MonochromatingChopper1.isfirst = '0'
    MonochromatingChopper1.phase = 'phase_M'
    MonochromatingChopper1.radius = 'radius_M1'
    MonochromatingChopper1.equal = '0'
    MonochromatingChopper1.abs_out = '0'
    MonochromatingChopper1.verbose = '0'
    
    # Comp instance MonochromatingChopper2, placement and parameters
    MonochromatingChopper2 = instr.add_component('MonochromatingChopper2','MultiDiskChopper', AT=['0.8166097806955753', '0.0', '162.0 + 0.005'], ROTATED=['0', '0.430122381481144', '0'])
    
    MonochromatingChopper2.slit_center = 'theta_pos_M2'
    MonochromatingChopper2.slit_width = 'theta_width_M2'
    MonochromatingChopper2.nslits = 'nslits_M2'
    MonochromatingChopper2.delta_y = 'delta_y_M2'
    MonochromatingChopper2.nu = 'f_M2'
    MonochromatingChopper2.nrev = '0'
    MonochromatingChopper2.ratio = '1'
    MonochromatingChopper2.jitter = '0'
    MonochromatingChopper2.delay = 'delay_M2'
    MonochromatingChopper2.isfirst = '0'
    MonochromatingChopper2.phase = 'phase_M'
    MonochromatingChopper2.radius = 'radius_M2'
    MonochromatingChopper2.equal = '0'
    MonochromatingChopper2.abs_out = '0'
    MonochromatingChopper2.verbose = '0'
    
    # Comp instance M_monitor_flux, placement and parameters
    M_monitor_flux = instr.add_component('M_monitor_flux','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='MonochromatingChopper2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='MonochromatingChopper2')
    
    M_monitor_flux.user1 = '""'
    M_monitor_flux.user2 = '""'
    M_monitor_flux.user3 = '""'
    M_monitor_flux.xwidth = '0.040'
    M_monitor_flux.yheight = '0.050'
    M_monitor_flux.zdepth = '0'
    M_monitor_flux.xmin = '0'
    M_monitor_flux.xmax = '0'
    M_monitor_flux.ymin = '0'
    M_monitor_flux.ymax = '0'
    M_monitor_flux.zmin = '0'
    M_monitor_flux.zmax = '0'
    M_monitor_flux.bins = '0'
    M_monitor_flux.min = '-1e40'
    M_monitor_flux.max = '1e40'
    M_monitor_flux.restore_neutron = '1'
    M_monitor_flux.radius = '0'
    M_monitor_flux.options = '"flux bins=1"'
    M_monitor_flux.filename = '"M_flux.dat"'
    M_monitor_flux.geometry = '"NULL"'
    M_monitor_flux.nowritefile = '0'
    M_monitor_flux.nexus_bins = '0'
    M_monitor_flux.username1 = '"NULL"'
    M_monitor_flux.username2 = '"NULL"'
    M_monitor_flux.username3 = '"NULL"'
    
    # Comp instance M_monitor_hdiv, placement and parameters
    M_monitor_hdiv = instr.add_component('M_monitor_hdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='M_monitor_flux', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M_monitor_flux')
    
    M_monitor_hdiv.user1 = '""'
    M_monitor_hdiv.user2 = '""'
    M_monitor_hdiv.user3 = '""'
    M_monitor_hdiv.xwidth = '0.040'
    M_monitor_hdiv.yheight = '0.050'
    M_monitor_hdiv.zdepth = '0'
    M_monitor_hdiv.xmin = '0'
    M_monitor_hdiv.xmax = '0'
    M_monitor_hdiv.ymin = '0'
    M_monitor_hdiv.ymax = '0'
    M_monitor_hdiv.zmin = '0'
    M_monitor_hdiv.zmax = '0'
    M_monitor_hdiv.bins = '0'
    M_monitor_hdiv.min = '-1e40'
    M_monitor_hdiv.max = '1e40'
    M_monitor_hdiv.restore_neutron = '1'
    M_monitor_hdiv.radius = '0'
    M_monitor_hdiv.options = '"hdiv limits [-2.0:2.0] bins = 100"'
    M_monitor_hdiv.filename = '"M_monitor_hdiv.dat"'
    M_monitor_hdiv.geometry = '"NULL"'
    M_monitor_hdiv.nowritefile = '0'
    M_monitor_hdiv.nexus_bins = '0'
    M_monitor_hdiv.username1 = '"NULL"'
    M_monitor_hdiv.username2 = '"NULL"'
    M_monitor_hdiv.username3 = '"NULL"'
    
    # Comp instance M_monitor_vdiv, placement and parameters
    M_monitor_vdiv = instr.add_component('M_monitor_vdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='M_monitor_hdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M_monitor_hdiv')
    
    M_monitor_vdiv.user1 = '""'
    M_monitor_vdiv.user2 = '""'
    M_monitor_vdiv.user3 = '""'
    M_monitor_vdiv.xwidth = '0.040'
    M_monitor_vdiv.yheight = '0.050'
    M_monitor_vdiv.zdepth = '0'
    M_monitor_vdiv.xmin = '0'
    M_monitor_vdiv.xmax = '0'
    M_monitor_vdiv.ymin = '0'
    M_monitor_vdiv.ymax = '0'
    M_monitor_vdiv.zmin = '0'
    M_monitor_vdiv.zmax = '0'
    M_monitor_vdiv.bins = '0'
    M_monitor_vdiv.min = '-1e40'
    M_monitor_vdiv.max = '1e40'
    M_monitor_vdiv.restore_neutron = '1'
    M_monitor_vdiv.radius = '0'
    M_monitor_vdiv.options = '"vdiv limits [-2.0:2.0] bins = 100"'
    M_monitor_vdiv.filename = '"M_monitor_vdiv.dat"'
    M_monitor_vdiv.geometry = '"NULL"'
    M_monitor_vdiv.nowritefile = '0'
    M_monitor_vdiv.nexus_bins = '0'
    M_monitor_vdiv.username1 = '"NULL"'
    M_monitor_vdiv.username2 = '"NULL"'
    M_monitor_vdiv.username3 = '"NULL"'
    
    # Comp instance M_monitor_lam, placement and parameters
    M_monitor_lam = instr.add_component('M_monitor_lam','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='M_monitor_vdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M_monitor_vdiv')
    
    M_monitor_lam.user1 = '""'
    M_monitor_lam.user2 = '""'
    M_monitor_lam.user3 = '""'
    M_monitor_lam.xwidth = '0.040'
    M_monitor_lam.yheight = '0.050'
    M_monitor_lam.zdepth = '0'
    M_monitor_lam.xmin = '0'
    M_monitor_lam.xmax = '0'
    M_monitor_lam.ymin = '0'
    M_monitor_lam.ymax = '0'
    M_monitor_lam.zmin = '0'
    M_monitor_lam.zmax = '0'
    M_monitor_lam.bins = '0'
    M_monitor_lam.min = '-1e40'
    M_monitor_lam.max = '1e40'
    M_monitor_lam.restore_neutron = '1'
    M_monitor_lam.radius = '0'
    M_monitor_lam.options = '"lambda limits [.5:5] bins = 1301"'
    M_monitor_lam.filename = '"M_monitor_lam.dat"'
    M_monitor_lam.geometry = '"NULL"'
    M_monitor_lam.nowritefile = '0'
    M_monitor_lam.nexus_bins = '0'
    M_monitor_lam.username1 = '"NULL"'
    M_monitor_lam.username2 = '"NULL"'
    M_monitor_lam.username3 = '"NULL"'
    
    # Comp instance M_monitor_xy, placement and parameters
    M_monitor_xy = instr.add_component('M_monitor_xy','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='M_monitor_lam', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M_monitor_lam')
    
    M_monitor_xy.user1 = '""'
    M_monitor_xy.user2 = '""'
    M_monitor_xy.user3 = '""'
    M_monitor_xy.xwidth = '0.050'
    M_monitor_xy.yheight = '0.065'
    M_monitor_xy.zdepth = '0'
    M_monitor_xy.xmin = '0'
    M_monitor_xy.xmax = '0'
    M_monitor_xy.ymin = '0'
    M_monitor_xy.ymax = '0'
    M_monitor_xy.zmin = '0'
    M_monitor_xy.zmax = '0'
    M_monitor_xy.bins = '0'
    M_monitor_xy.min = '-1e40'
    M_monitor_xy.max = '1e40'
    M_monitor_xy.restore_neutron = '1'
    M_monitor_xy.radius = '0'
    M_monitor_xy.options = '"x limits [-0.025:0.025] bins = 100, y limits [-0.0325:0.0325] bins = 100"'
    M_monitor_xy.filename = '"M_monitor_xy.dat"'
    M_monitor_xy.geometry = '"NULL"'
    M_monitor_xy.nowritefile = '0'
    M_monitor_xy.nexus_bins = '0'
    M_monitor_xy.username1 = '"NULL"'
    M_monitor_xy.username2 = '"NULL"'
    M_monitor_xy.username3 = '"NULL"'
    
    # Comp instance M_monitor_ToF, placement and parameters
    M_monitor_ToF = instr.add_component('M_monitor_ToF','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='M_monitor_xy', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M_monitor_xy')
    
    M_monitor_ToF.user1 = '""'
    M_monitor_ToF.user2 = '""'
    M_monitor_ToF.user3 = '""'
    M_monitor_ToF.xwidth = '0.04'
    M_monitor_ToF.yheight = '0.050'
    M_monitor_ToF.zdepth = '0'
    M_monitor_ToF.xmin = '0'
    M_monitor_ToF.xmax = '0'
    M_monitor_ToF.ymin = '0'
    M_monitor_ToF.ymax = '0'
    M_monitor_ToF.zmin = '0'
    M_monitor_ToF.zmax = '0'
    M_monitor_ToF.bins = '0'
    M_monitor_ToF.min = '-1e40'
    M_monitor_ToF.max = '1e40'
    M_monitor_ToF.restore_neutron = '1'
    M_monitor_ToF.radius = '0'
    M_monitor_ToF.options = 'setM'
    M_monitor_ToF.filename = '"M_monitor_tof.dat"'
    M_monitor_ToF.geometry = '"NULL"'
    M_monitor_ToF.nowritefile = '0'
    M_monitor_ToF.nexus_bins = '0'
    M_monitor_ToF.username1 = '"NULL"'
    M_monitor_ToF.username2 = '"NULL"'
    M_monitor_ToF.username3 = '"NULL"'
    
    # Comp instance slitMC, placement and parameters
    slitMC = instr.add_component('slitMC','Slit', AT=['0.817', '0', '162.07'])
    
    slitMC.xmin = 'UNSET'
    slitMC.xmax = 'UNSET'
    slitMC.ymin = 'UNSET'
    slitMC.ymax = 'UNSET'
    slitMC.radius = 'UNSET'
    slitMC.xwidth = '0.0205'
    slitMC.yheight = '0.0345'
    
    # Comp instance guide_138, placement and parameters
    guide_138 = instr.add_component('guide_138','Guide_anyshape_r')
    # WHEN ( coll == 0 ) at guide_138
    guide_138.set_WHEN('( coll == 0 )')
    
    guide_138.xwidth = '0'
    guide_138.yheight = '0'
    guide_138.zdepth = '0'
    guide_138.center = '0'
    guide_138.transmit = '0'
    guide_138.R0 = '0.99'
    guide_138.Qc = '0.0219'
    guide_138.alpha = '0'
    guide_138.m = '0'
    guide_138.W = '0'
    guide_138.geometry = '"./OFF_files/try138.off"'
    
    # Comp instance guide_139, placement and parameters
    guide_139 = instr.add_component('guide_139','Guide_anyshape_r')
    # WHEN ( coll == 0 ) at guide_139
    guide_139.set_WHEN('( coll == 0 )')
    
    guide_139.xwidth = '0'
    guide_139.yheight = '0'
    guide_139.zdepth = '0'
    guide_139.center = '0'
    guide_139.transmit = '0'
    guide_139.R0 = '0.99'
    guide_139.Qc = '0.0219'
    guide_139.alpha = '0'
    guide_139.m = '0'
    guide_139.W = '0'
    guide_139.geometry = '"./OFF_files/try139.off"'
    
    # Comp instance guide_140, placement and parameters
    guide_140 = instr.add_component('guide_140','Guide_anyshape_r')
    # WHEN ( coll == 0 ) at guide_140
    guide_140.set_WHEN('( coll == 0 )')
    
    guide_140.xwidth = '0'
    guide_140.yheight = '0'
    guide_140.zdepth = '0'
    guide_140.center = '0'
    guide_140.transmit = '0'
    guide_140.R0 = '0.99'
    guide_140.Qc = '0.0219'
    guide_140.alpha = '0'
    guide_140.m = '0'
    guide_140.W = '0'
    guide_140.geometry = '"./OFF_files/try140.off"'
    
    # Comp instance guide_141, placement and parameters
    guide_141 = instr.add_component('guide_141','Guide_anyshape_r')
    # WHEN ( coll == 0 ) at guide_141
    guide_141.set_WHEN('( coll == 0 )')
    
    guide_141.xwidth = '0'
    guide_141.yheight = '0'
    guide_141.zdepth = '0'
    guide_141.center = '0'
    guide_141.transmit = '0'
    guide_141.R0 = '0.99'
    guide_141.Qc = '0.0219'
    guide_141.alpha = '0'
    guide_141.m = '0'
    guide_141.W = '0'
    guide_141.geometry = '"./OFF_files/try141.off"'
    
    # Comp instance coll1, placement and parameters
    coll1 = instr.add_component('coll1','Guide_honeycomb', AT=['0.817', '0', '162.07'], ROTATED=['0', '0.430122381481144', '0'])
    # WHEN ( coll == 1 ) at coll1
    coll1.set_WHEN('( coll == 1 )')
    
    coll1.w1 = '0.03523'
    coll1.w2 = '0.02920'
    coll1.l = '1.080'
    coll1.R0 = '0.995'
    coll1.Qc = '0.0218'
    coll1.alpha = '4.38'
    coll1.m = '1.0'
    coll1.W = '0.003'
    coll1.nslit = '5'
    coll1.d = '0.0005'
    coll1.mleftup = '-1'
    coll1.mrightup = '-1'
    coll1.mleftdown = '-1'
    coll1.mrightdown = '-1'
    coll1.mleft = '-1'
    coll1.mright = '-1'
    coll1.G = '0'
    
    # Comp instance coll2, placement and parameters
    coll2 = instr.add_component('coll2','Guide_honeycomb', AT=['0.817', '0', '162.07'], ROTATED=['0', '0.430122381481144', '0'])
    # WHEN ( coll == 2 ) at coll2
    coll2.set_WHEN('( coll == 2 )')
    
    coll2.w1 = '0.03523'
    coll2.w2 = '0.02920'
    coll2.l = '1.080'
    coll2.R0 = '0.995'
    coll2.Qc = '0.0218'
    coll2.alpha = '4.38'
    coll2.m = '1.0'
    coll2.W = '0.003'
    coll2.nslit = '10'
    coll2.d = '0.0005'
    coll2.mleftup = '-1'
    coll2.mrightup = '-1'
    coll2.mleftdown = '-1'
    coll2.mrightdown = '-1'
    coll2.mleft = '-1'
    coll2.mright = '-1'
    coll2.G = '0'
    
    # Comp instance Sample_pos, placement and parameters
    Sample_pos = instr.add_component('Sample_pos','Arm', AT=['0.8301227276790154', '0.0', '163.8'], ROTATED=['0', '0.430122381481144', '0'])
    
    
    # Comp instance sample_monitor_xy, placement and parameters
    sample_monitor_xy = instr.add_component('sample_monitor_xy','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='Sample_pos', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Sample_pos')
    
    sample_monitor_xy.user1 = '""'
    sample_monitor_xy.user2 = '""'
    sample_monitor_xy.user3 = '""'
    sample_monitor_xy.xwidth = '0.1'
    sample_monitor_xy.yheight = '0.05'
    sample_monitor_xy.zdepth = '0'
    sample_monitor_xy.xmin = '0'
    sample_monitor_xy.xmax = '0'
    sample_monitor_xy.ymin = '0'
    sample_monitor_xy.ymax = '0'
    sample_monitor_xy.zmin = '0'
    sample_monitor_xy.zmax = '0'
    sample_monitor_xy.bins = '0'
    sample_monitor_xy.min = '-1e40'
    sample_monitor_xy.max = '1e40'
    sample_monitor_xy.restore_neutron = '1'
    sample_monitor_xy.radius = '0'
    sample_monitor_xy.options = '"x limits [-0.05:0.05] bins = 100, y limits [-0.025:0.025] bins = 100"'
    sample_monitor_xy.filename = '"sample_monitor_xy.dat"'
    sample_monitor_xy.geometry = '"NULL"'
    sample_monitor_xy.nowritefile = '0'
    sample_monitor_xy.nexus_bins = '0'
    sample_monitor_xy.username1 = '"NULL"'
    sample_monitor_xy.username2 = '"NULL"'
    sample_monitor_xy.username3 = '"NULL"'
    
    # Comp instance sample_monitor_div, placement and parameters
    sample_monitor_div = instr.add_component('sample_monitor_div','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_xy', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_xy')
    
    sample_monitor_div.user1 = '""'
    sample_monitor_div.user2 = '""'
    sample_monitor_div.user3 = '""'
    sample_monitor_div.xwidth = '0.055'
    sample_monitor_div.yheight = '0.075'
    sample_monitor_div.zdepth = '0'
    sample_monitor_div.xmin = '0'
    sample_monitor_div.xmax = '0'
    sample_monitor_div.ymin = '0'
    sample_monitor_div.ymax = '0'
    sample_monitor_div.zmin = '0'
    sample_monitor_div.zmax = '0'
    sample_monitor_div.bins = '0'
    sample_monitor_div.min = '-1e40'
    sample_monitor_div.max = '1e40'
    sample_monitor_div.restore_neutron = '1'
    sample_monitor_div.radius = '0'
    sample_monitor_div.options = '"hdiv limits [-1.5:1.5] bins = 100, vdiv limits [-1.0:1.0] bins = 100"'
    sample_monitor_div.filename = '"sample_monitor_div.dat"'
    sample_monitor_div.geometry = '"NULL"'
    sample_monitor_div.nowritefile = '0'
    sample_monitor_div.nexus_bins = '0'
    sample_monitor_div.username1 = '"NULL"'
    sample_monitor_div.username2 = '"NULL"'
    sample_monitor_div.username3 = '"NULL"'
    
    # Comp instance sample_monitor_hdiv, placement and parameters
    sample_monitor_hdiv = instr.add_component('sample_monitor_hdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_div', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_div')
    
    sample_monitor_hdiv.user1 = '""'
    sample_monitor_hdiv.user2 = '""'
    sample_monitor_hdiv.user3 = '""'
    sample_monitor_hdiv.xwidth = '0.055'
    sample_monitor_hdiv.yheight = '0.075'
    sample_monitor_hdiv.zdepth = '0'
    sample_monitor_hdiv.xmin = '0'
    sample_monitor_hdiv.xmax = '0'
    sample_monitor_hdiv.ymin = '0'
    sample_monitor_hdiv.ymax = '0'
    sample_monitor_hdiv.zmin = '0'
    sample_monitor_hdiv.zmax = '0'
    sample_monitor_hdiv.bins = '0'
    sample_monitor_hdiv.min = '-1e40'
    sample_monitor_hdiv.max = '1e40'
    sample_monitor_hdiv.restore_neutron = '1'
    sample_monitor_hdiv.radius = '0'
    sample_monitor_hdiv.options = '"hdiv limits [-2.0:2.0] bins = 100"'
    sample_monitor_hdiv.filename = '"sample_monitor_hdiv.dat"'
    sample_monitor_hdiv.geometry = '"NULL"'
    sample_monitor_hdiv.nowritefile = '0'
    sample_monitor_hdiv.nexus_bins = '0'
    sample_monitor_hdiv.username1 = '"NULL"'
    sample_monitor_hdiv.username2 = '"NULL"'
    sample_monitor_hdiv.username3 = '"NULL"'
    
    # Comp instance sample_monitor_vdiv, placement and parameters
    sample_monitor_vdiv = instr.add_component('sample_monitor_vdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_hdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_hdiv')
    
    sample_monitor_vdiv.user1 = '""'
    sample_monitor_vdiv.user2 = '""'
    sample_monitor_vdiv.user3 = '""'
    sample_monitor_vdiv.xwidth = '0.055'
    sample_monitor_vdiv.yheight = '0.075'
    sample_monitor_vdiv.zdepth = '0'
    sample_monitor_vdiv.xmin = '0'
    sample_monitor_vdiv.xmax = '0'
    sample_monitor_vdiv.ymin = '0'
    sample_monitor_vdiv.ymax = '0'
    sample_monitor_vdiv.zmin = '0'
    sample_monitor_vdiv.zmax = '0'
    sample_monitor_vdiv.bins = '0'
    sample_monitor_vdiv.min = '-1e40'
    sample_monitor_vdiv.max = '1e40'
    sample_monitor_vdiv.restore_neutron = '1'
    sample_monitor_vdiv.radius = '0'
    sample_monitor_vdiv.options = '"vdiv limits [-2.0:2.0] bins = 100"'
    sample_monitor_vdiv.filename = '"sample_monitor_vdiv.dat"'
    sample_monitor_vdiv.geometry = '"NULL"'
    sample_monitor_vdiv.nowritefile = '0'
    sample_monitor_vdiv.nexus_bins = '0'
    sample_monitor_vdiv.username1 = '"NULL"'
    sample_monitor_vdiv.username2 = '"NULL"'
    sample_monitor_vdiv.username3 = '"NULL"'
    
    # Comp instance sample_monitor_xhdiv, placement and parameters
    sample_monitor_xhdiv = instr.add_component('sample_monitor_xhdiv','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_vdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_vdiv')
    
    sample_monitor_xhdiv.user1 = '""'
    sample_monitor_xhdiv.user2 = '""'
    sample_monitor_xhdiv.user3 = '""'
    sample_monitor_xhdiv.xwidth = '0.055'
    sample_monitor_xhdiv.yheight = '0.075'
    sample_monitor_xhdiv.zdepth = '0'
    sample_monitor_xhdiv.xmin = '0'
    sample_monitor_xhdiv.xmax = '0'
    sample_monitor_xhdiv.ymin = '0'
    sample_monitor_xhdiv.ymax = '0'
    sample_monitor_xhdiv.zmin = '0'
    sample_monitor_xhdiv.zmax = '0'
    sample_monitor_xhdiv.bins = '0'
    sample_monitor_xhdiv.min = '-1e40'
    sample_monitor_xhdiv.max = '1e40'
    sample_monitor_xhdiv.restore_neutron = '1'
    sample_monitor_xhdiv.radius = '0'
    sample_monitor_xhdiv.options = '"x limits [-0.05:0.05] bins = 100, hdiv limits [-1.5:1.5] bins = 100"'
    sample_monitor_xhdiv.filename = '"sample_monitor_xhdiv.dat"'
    sample_monitor_xhdiv.geometry = '"NULL"'
    sample_monitor_xhdiv.nowritefile = '0'
    sample_monitor_xhdiv.nexus_bins = '0'
    sample_monitor_xhdiv.username1 = '"NULL"'
    sample_monitor_xhdiv.username2 = '"NULL"'
    sample_monitor_xhdiv.username3 = '"NULL"'
    
    # Comp instance sample_monitor_ToF_BeamSize, placement and parameters
    sample_monitor_ToF_BeamSize = instr.add_component('sample_monitor_ToF_BeamSize','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_xhdiv', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_xhdiv')
    
    sample_monitor_ToF_BeamSize.user1 = '""'
    sample_monitor_ToF_BeamSize.user2 = '""'
    sample_monitor_ToF_BeamSize.user3 = '""'
    sample_monitor_ToF_BeamSize.xwidth = '0.01'
    sample_monitor_ToF_BeamSize.yheight = '0.03'
    sample_monitor_ToF_BeamSize.zdepth = '0'
    sample_monitor_ToF_BeamSize.xmin = '0'
    sample_monitor_ToF_BeamSize.xmax = '0'
    sample_monitor_ToF_BeamSize.ymin = '0'
    sample_monitor_ToF_BeamSize.ymax = '0'
    sample_monitor_ToF_BeamSize.zmin = '0'
    sample_monitor_ToF_BeamSize.zmax = '0'
    sample_monitor_ToF_BeamSize.bins = '0'
    sample_monitor_ToF_BeamSize.min = '-1e40'
    sample_monitor_ToF_BeamSize.max = '1e40'
    sample_monitor_ToF_BeamSize.restore_neutron = '1'
    sample_monitor_ToF_BeamSize.radius = '0'
    sample_monitor_ToF_BeamSize.options = 'setS'
    sample_monitor_ToF_BeamSize.filename = '"sample_monitor_tof_BeamSize.dat"'
    sample_monitor_ToF_BeamSize.geometry = '"NULL"'
    sample_monitor_ToF_BeamSize.nowritefile = '0'
    sample_monitor_ToF_BeamSize.nexus_bins = '0'
    sample_monitor_ToF_BeamSize.username1 = '"NULL"'
    sample_monitor_ToF_BeamSize.username2 = '"NULL"'
    sample_monitor_ToF_BeamSize.username3 = '"NULL"'
    
    # Comp instance sample_monitor_ToF_cm2, placement and parameters
    sample_monitor_ToF_cm2 = instr.add_component('sample_monitor_ToF_cm2','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_ToF_BeamSize', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_ToF_BeamSize')
    
    sample_monitor_ToF_cm2.user1 = '""'
    sample_monitor_ToF_cm2.user2 = '""'
    sample_monitor_ToF_cm2.user3 = '""'
    sample_monitor_ToF_cm2.xwidth = '0.01'
    sample_monitor_ToF_cm2.yheight = '0.01'
    sample_monitor_ToF_cm2.zdepth = '0'
    sample_monitor_ToF_cm2.xmin = '0'
    sample_monitor_ToF_cm2.xmax = '0'
    sample_monitor_ToF_cm2.ymin = '0'
    sample_monitor_ToF_cm2.ymax = '0'
    sample_monitor_ToF_cm2.zmin = '0'
    sample_monitor_ToF_cm2.zmax = '0'
    sample_monitor_ToF_cm2.bins = '0'
    sample_monitor_ToF_cm2.min = '-1e40'
    sample_monitor_ToF_cm2.max = '1e40'
    sample_monitor_ToF_cm2.restore_neutron = '1'
    sample_monitor_ToF_cm2.radius = '0'
    sample_monitor_ToF_cm2.options = 'setS'
    sample_monitor_ToF_cm2.filename = '"sample_monitor_tof_1cm2.dat"'
    sample_monitor_ToF_cm2.geometry = '"NULL"'
    sample_monitor_ToF_cm2.nowritefile = '0'
    sample_monitor_ToF_cm2.nexus_bins = '0'
    sample_monitor_ToF_cm2.username1 = '"NULL"'
    sample_monitor_ToF_cm2.username2 = '"NULL"'
    sample_monitor_ToF_cm2.username3 = '"NULL"'
    
    # Comp instance sample_monitor_ToF, placement and parameters
    sample_monitor_ToF = instr.add_component('sample_monitor_ToF','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_ToF_cm2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_ToF_cm2')
    
    sample_monitor_ToF.user1 = '""'
    sample_monitor_ToF.user2 = '""'
    sample_monitor_ToF.user3 = '""'
    sample_monitor_ToF.xwidth = '0.075'
    sample_monitor_ToF.yheight = '0.05'
    sample_monitor_ToF.zdepth = '0'
    sample_monitor_ToF.xmin = '0'
    sample_monitor_ToF.xmax = '0'
    sample_monitor_ToF.ymin = '0'
    sample_monitor_ToF.ymax = '0'
    sample_monitor_ToF.zmin = '0'
    sample_monitor_ToF.zmax = '0'
    sample_monitor_ToF.bins = '0'
    sample_monitor_ToF.min = '-1e40'
    sample_monitor_ToF.max = '1e40'
    sample_monitor_ToF.restore_neutron = '1'
    sample_monitor_ToF.radius = '0'
    sample_monitor_ToF.options = 'setS'
    sample_monitor_ToF.filename = '"sample_monitor_tof.dat"'
    sample_monitor_ToF.geometry = '"NULL"'
    sample_monitor_ToF.nowritefile = '0'
    sample_monitor_ToF.nexus_bins = '0'
    sample_monitor_ToF.username1 = '"NULL"'
    sample_monitor_ToF.username2 = '"NULL"'
    sample_monitor_ToF.username3 = '"NULL"'
    
    # Comp instance sample_monitor_lam, placement and parameters
    sample_monitor_lam = instr.add_component('sample_monitor_lam','Monitor_nD', AT=['0', '0', '1E-6'], AT_RELATIVE='sample_monitor_ToF', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sample_monitor_ToF')
    
    sample_monitor_lam.user1 = '""'
    sample_monitor_lam.user2 = '""'
    sample_monitor_lam.user3 = '""'
    sample_monitor_lam.xwidth = '0.055'
    sample_monitor_lam.yheight = '0.075'
    sample_monitor_lam.zdepth = '0'
    sample_monitor_lam.xmin = '0'
    sample_monitor_lam.xmax = '0'
    sample_monitor_lam.ymin = '0'
    sample_monitor_lam.ymax = '0'
    sample_monitor_lam.zmin = '0'
    sample_monitor_lam.zmax = '0'
    sample_monitor_lam.bins = '0'
    sample_monitor_lam.min = '-1e40'
    sample_monitor_lam.max = '1e40'
    sample_monitor_lam.restore_neutron = '1'
    sample_monitor_lam.radius = '0'
    sample_monitor_lam.options = 'setSL'
    sample_monitor_lam.filename = '"sample_monitor_lam.dat"'
    sample_monitor_lam.geometry = '"NULL"'
    sample_monitor_lam.nowritefile = '0'
    sample_monitor_lam.nexus_bins = '0'
    sample_monitor_lam.username1 = '"NULL"'
    sample_monitor_lam.username2 = '"NULL"'
    sample_monitor_lam.username3 = '"NULL"'
    
#     # Comp instance Sample, placement and parameters
#     Sample = instr.add_component('Sample','Incoherent', AT=['0', '0', '0.015'], AT_RELATIVE='Sample_pos', ROTATED=['0', '0', '0'], ROTATED_RELATIVE='Sample_pos')
#     # EXTEND at Sample
#     Sample.append_EXTEND(r'''
#   if (!SCATTERED) ABSORB;
#     ''')


    
#     Sample.geometry = '0'
#     Sample.radius = '0'
#     Sample.xwidth = '0.01'
#     Sample.yheight = '0.03'
#     Sample.zdepth = '0.01'
#     Sample.thickness = '0'
#     Sample.target_x = '0'
#     Sample.target_y = '0'
#     Sample.target_z = '0'
#     Sample.focus_r = '0'
#     Sample.focus_xw = '0.02'
#     Sample.focus_yh = '0.03'
#     Sample.focus_aw = '0'
#     Sample.focus_ah = '0'
#     Sample.target_index = '+ 1'
#     Sample.pack = '1'
#     Sample.p_interact = '1'
#     Sample.f_QE = '0'
#     Sample.gamma = '0'
#     Sample.Etrans = '0'
#     Sample.deltaE = '0'
#     Sample.sigma_abs = '5.08'
#     Sample.sigma_inc = '5.08'
#     Sample.Vc = '13.827'
#     Sample.concentric = '0'
#     Sample.order = '0'

        # Comp instance Banana_1, placement and parameters
    Banana_1 = instr.add_component('Banana_1','Monitor_nD', AT=['0', '0', '0.0'], AT_RELATIVE='Sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Sample')
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
    Banana_1.options = '"mantid banana theta bins=221 limits=[30, 140] y bins=136, neutron pixel min=0 t, list all neutrons"'
    Banana_1.filename = '"direct_event_banana_signal.dat"'
    Banana_1.geometry = '"NULL"'
    Banana_1.nowritefile = '0'
    Banana_1.nexus_bins = '0'
    Banana_1.username1 = '"NULL"'
    Banana_1.username2 = '"NULL"'
    Banana_1.username3 = '"NULL"'
    
    # Comp instance Trex_banana_det, placement and parameters
    Trex_banana_det = instr.add_component('Trex_banana_det','Monitor_nD', AT=['0', '0', '3'], AT_RELATIVE='Sample', ROTATED=['0', '0', '0'], ROTATED_RELATIVE='Sample')
    
    Trex_banana_det.user1 = '""'
    Trex_banana_det.user2 = '""'
    Trex_banana_det.user3 = '""'
    Trex_banana_det.xwidth = '0.055'
    Trex_banana_det.yheight = '0.075'
    Trex_banana_det.zdepth = '0'
    Trex_banana_det.xmin = '0'
    Trex_banana_det.xmax = '0'
    Trex_banana_det.ymin = '0'
    Trex_banana_det.ymax = '0'
    Trex_banana_det.zmin = '0'
    Trex_banana_det.zmax = '0'
    Trex_banana_det.bins = '0'
    Trex_banana_det.min = '-1e40'
    Trex_banana_det.max = '1e40'
    Trex_banana_det.restore_neutron = '1'
    Trex_banana_det.radius = '0'
    Trex_banana_det.options = 'square_options'
    Trex_banana_det.filename = '"Trex_banana_tof_monitor.dat"'
    Trex_banana_det.geometry = '"NULL"'
    Trex_banana_det.nowritefile = '0'
    Trex_banana_det.nexus_bins = '0'
    Trex_banana_det.username1 = '"NULL"'
    Trex_banana_det.username2 = '"NULL"'
    Trex_banana_det.username3 = '"NULL"'


    
    
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


# end of generated Python code TREX_McStas_generated.py 
