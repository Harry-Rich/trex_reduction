#!/usr/bin/env python3
# Automatically generated file. 
# Format:    Python script code
# McStas <http://www.mcstas.org>
# Instrument: CSPEC.instr (CSPEC)
# Date:       Thu Apr 30 14:52:07 2026
# File:       CSPEC_generated.py

import mcstasscript as ms

# Python McStas instrument description
def make(name="CSPEC_generated", input_path=None):
    
    if input_path is not None:
        instr = ms.McStas_instr(name, author = "McCode Py-Generator", origin = "ESS DMSC", input_path=input_path)
    else:
        instr = ms.McStas_instr(name, author = "McCode Py-Generator", origin = "ESS DMSC")
    
# Add collected DEPENDENCY strings
    instr.set_dependency('')

    # *****************************************************************************
    # * Start of instrument 'CSPEC' generated code
    # *****************************************************************************
    # MCSTAS system dir is "/opt/miniconda3/envs/mcstas_plus_test/share/mcstas/resources/"


    # *****************************************************************************
    # * instrument 'CSPEC' and components DECLARE
    # *****************************************************************************

    # Instrument parameters:

    lambda_min = instr.add_parameter('double', 'lambda_min', value=3, comment='Parameter type (double) added by McCode py-generator')
    dist_focus = instr.add_parameter('double', 'dist_focus', value=1.9, comment='Parameter type (double) added by McCode py-generator')
    AC_Power = instr.add_parameter('double', 'AC_Power', value=2, comment='Parameter type (double) added by McCode py-generator')
    move_x = instr.add_parameter('double', 'move_x', value=0.0163, comment='Parameter type (double) added by McCode py-generator')
    move_y = instr.add_parameter('double', 'move_y', value=0.000, comment='Parameter type (double) added by McCode py-generator')
    phi_x = instr.add_parameter('double', 'phi_x', value=0.0, comment='Parameter type (double) added by McCode py-generator')
    phi_y = instr.add_parameter('double', 'phi_y', value=-0.5, comment='Parameter type (double) added by McCode py-generator')
    phi_z = instr.add_parameter('double', 'phi_z', value=0.0, comment='Parameter type (double) added by McCode py-generator')
    ROC_H = instr.add_parameter('double', 'ROC_H', value=4000, comment='Parameter type (double) added by McCode py-generator')
    ROC_V = instr.add_parameter('double', 'ROC_V', value=1600, comment='Parameter type (double) added by McCode py-generator')
    gap = instr.add_parameter('double', 'gap', value=0.001, comment='Parameter type (double) added by McCode py-generator')
    L = instr.add_parameter('double', 'L', value=26, comment='Parameter type (double) added by McCode py-generator')
    m_insert_t = instr.add_parameter('double', 'm_insert_t', value=3.5, comment='Parameter type (double) added by McCode py-generator')
    m_insert_b = instr.add_parameter('double', 'm_insert_b', value=3.5, comment='Parameter type (double) added by McCode py-generator')
    m_insert_r = instr.add_parameter('double', 'm_insert_r', value=3.5, comment='Parameter type (double) added by McCode py-generator')
    m_insert_l = instr.add_parameter('double', 'm_insert_l', value=3.5, comment='Parameter type (double) added by McCode py-generator')
    W_par = instr.add_parameter('double', 'W_par', value=0.003, comment='Parameter type (double) added by McCode py-generator')
    R0_par = instr.add_parameter('double', 'R0_par', value=0.99, comment='Parameter type (double) added by McCode py-generator')
    Qcrit = instr.add_parameter('double', 'Qcrit', value=0.0217, comment='Parameter type (double) added by McCode py-generator')
    alpha_par = instr.add_parameter('double', 'alpha_par', value=6.07, comment='Parameter type (double) added by McCode py-generator')
    gravity = instr.add_parameter('double', 'gravity', value=-9.81, comment='Parameter type (double) added by McCode py-generator')
    height = instr.add_parameter('double', 'height', value=0.1, comment='Parameter type (double) added by McCode py-generator')
    h1_in = instr.add_parameter('double', 'h1_in', value=0.055, comment='Parameter type (double) added by McCode py-generator')
    theta_BW1 = instr.add_parameter('double', 'theta_BW1', value=40.7, comment='Parameter type (double) added by McCode py-generator')
    theta_BW2 = instr.add_parameter('double', 'theta_BW2', value=41.9, comment='Parameter type (double) added by McCode py-generator')
    theta_BW3 = instr.add_parameter('double', 'theta_BW3', value=193.0, comment='Parameter type (double) added by McCode py-generator')
    theta_PS = instr.add_parameter('double', 'theta_PS', value=24.23, comment='Parameter type (double) added by McCode py-generator')
    theta_RRM = instr.add_parameter('double', 'theta_RRM', value=4.45, comment='Parameter type (double) added by McCode py-generator')
    theta_M = instr.add_parameter('double', 'theta_M', value=4.45, comment='Parameter type (double) added by McCode py-generator')
    Freq_BW1 = instr.add_parameter('double', 'Freq_BW1', value=14.0, comment='Parameter type (double) added by McCode py-generator')
    Freq_BW2 = instr.add_parameter('double', 'Freq_BW2', value=14.0, comment='Parameter type (double) added by McCode py-generator')
    Freq_BW3 = instr.add_parameter('double', 'Freq_BW3', value=14.0, comment='Parameter type (double) added by McCode py-generator')
    Freq_M = instr.add_parameter('double', 'Freq_M', value=168.0, comment='Parameter type (double) added by McCode py-generator')
    Distance_BW1 = instr.add_parameter('double', 'Distance_BW1', value=13.7236, comment='Parameter type (double) added by McCode py-generator')
    Distance_BW2 = instr.add_parameter('double', 'Distance_BW2', value=20.4766, comment='Parameter type (double) added by McCode py-generator')
    Distance_BW3 = instr.add_parameter('double', 'Distance_BW3', value=104.52, comment='Parameter type (double) added by McCode py-generator')
    Distance_PS1 = instr.add_parameter('double', 'Distance_PS1', value=105.7046, comment='Parameter type (double) added by McCode py-generator')
    Distance_PS2 = instr.add_parameter('double', 'Distance_PS2', value=105.7106, comment='Parameter type (double) added by McCode py-generator')
    Distance_RRM = instr.add_parameter('double', 'Distance_RRM', value=105.67, comment='Parameter type (double) added by McCode py-generator')
    Distance_M1 = instr.add_parameter('double', 'Distance_M1', value=158.55, comment='Parameter type (double) added by McCode py-generator')
    Distance_M2 = instr.add_parameter('double', 'Distance_M2', value=158.556, comment='Parameter type (double) added by McCode py-generator')
    Source_Offset = instr.add_parameter('double', 'Source_Offset', value=0.0014, comment='Parameter type (double) added by McCode py-generator')
    dist_m = instr.add_parameter('double', 'dist_m', value=0.03, comment='Parameter type (double) added by McCode py-generator')
    dist = instr.add_parameter('double', 'dist', value=0.1, comment='Parameter type (double) added by McCode py-generator')
    N_trains_par = instr.add_parameter('int', 'N_trains_par', value=200, comment='Parameter type (int) added by McCode py-generator')
    target_tsplit = instr.add_parameter('double', 'target_tsplit', value=5, comment='Parameter type (double) added by McCode py-generator')

    component_definition_metadata = {
    }
    instr.append_declare(r'''
 double BW1_Delay, BW2_Delay, BW3_Delay, PS1_Delay , PS2_Delay , RRM_Delay , M1_Delay, M2_Delay ;
 double v0;
 double Freq_PS;
 
 double curve_ang_V_w03_01_012,curve_ang_H_w03_01_012; /* angle for calculation in radian */
 double dx_v_w03_01_012, dy_v_w03_01_012, dz_v_w03_01_012, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 
 double curve_ang_V_w03_01_02,curve_ang_H_w03_01_02; /* angle for calculation in radian */
 double dx_v_w03_01_02, dy_v_w03_01_02, dz_v_w03_01_02, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 
  double curve_ang_V_w03_01_03,curve_ang_H_w03_01_03; /* angle for calculation in radian */
  double dx_v_w03_01_03, dy_v_w03_01_03, dz_v_w03_01_03, dtrans;  /* to calculate exit position */
  double sign;             /* sign of radius in Bender   */
 
  double curve_ang_V_w03_02_01,curve_ang_H_w03_02_01; /* angle for calculation in radian */
  double dx_v_w03_02_01, dy_v_w03_02_01, dz_v_w03_02_01, dtrans;  /* to calculate exit position */
  double sign;             /* sign of radius in Bender   */

  double curve_ang_V_w03_03_01,curve_ang_H_w03_03_01; /* angle for calculation in radian */
  double dx_v_w03_03_01, dy_v_w03_03_01, dz_v_w03_03_01, dtrans;  /* to calculate exit position */
  double sign;             /* sign of radius in Bender   */

  double curve_ang_V_w03_03_02,curve_ang_H_w03_03_02; /* angle for calculation in radian */
  double dx_v_w03_03_02, dy_v_w03_03_02, dz_v_w03_03_02, dtrans;  /* to calculate exit position */
  double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_04_01,curve_ang_H_w03_04_01; /* angle for calculation in radian */
 double dx_v_w03_04_01, dy_v_w03_04_01, dz_v_w03_04_01, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_04_02,curve_ang_H_w03_04_02; /* angle for calculation in radian */
 double dx_v_w03_04_02, dy_v_w03_04_02, dz_v_w03_04_02, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_01,curve_ang_H_w03_05_01; /* angle for calculation in radian */
 double dx_v_w03_05_01, dy_v_w03_05_01, dz_v_w03_05_01, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_01_a,curve_ang_H_w03_05_01_a; /* angle for calculation in radian */
 double dx_v_w03_05_01_a, dy_v_w03_05_01_a, dz_v_w03_05_01_a, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_02,curve_ang_H_w03_05_02; /* angle for calculation in radian */
 double dx_v_w03_05_02, dy_v_w03_05_02, dz_v_w03_05_02, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_03,curve_ang_H_w03_05_03; /* angle for calculation in radian */
 double dx_v_w03_05_03, dy_v_w03_05_03, dz_v_w03_05_03, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_04, curve_ang_H_w03_05_04; /* angle for calculation in radian */
 double dx_v_w03_05_04, dy_v_w03_05_04, dz_v_w03_05_04, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_05, curve_ang_H_w03_05_05; /* angle for calculation in radian */
 double dx_v_w03_05_05, dy_v_w03_05_05, dz_v_w03_05_05, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_05_a,curve_ang_H_w03_05_05_a; /* angle for calculation in radian */
 double dx_v_w03_05_05_a, dy_v_w03_05_05_a, dz_v_w03_05_05_a, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */


 double curve_ang_V_w03_05_06, curve_ang_H_w03_05_06; /* angle for calculation in radian */
 double dx_v_w03_05_06, dy_v_w03_05_06, dz_v_w03_05_06, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_07, curve_ang_H_w03_05_07; /* angle for calculation in radian */
 double dx_v_w03_05_07, dy_v_w03_05_07, dz_v_w03_05_07, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_08, curve_ang_H_w03_05_08; /* angle for calculation in radian */
 double dx_v_w03_05_08, dy_v_w03_05_08, dz_v_w03_05_08, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_09, curve_ang_H_w03_05_09; /* angle for calculation in radian */
 double dx_v_w03_05_09, dy_v_w03_05_09, dz_v_w03_05_09, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_05_10, curve_ang_H_w03_05_10; /* angle for calculation in radian */
 double dx_v_w03_05_10, dy_v_w03_05_10, dz_v_w03_05_10, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_011, curve_ang_H_w03_06_011; /* angle for calculation in radian */
 double dx_v_w03_06_011, dy_v_w03_06_011, dz_v_w03_06_011, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_06_012, curve_ang_H_w03_06_012; /* angle for calculation in radian */
 double dx_v_w03_06_012, dy_v_w03_06_012, dz_v_w03_06_012, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */

 double curve_ang_V_w03_06_02, curve_ang_H_w03_06_02; /* angle for calculation in radian */
 double dx_v_w03_06_02, dy_v_w03_06_02, dz_v_w03_06_02, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_03, curve_ang_H_w03_06_03; /* angle for calculation in radian */
 double dx_v_w03_06_03, dy_v_w03_06_03, dz_v_w03_06_03, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_04, curve_ang_H_w03_06_04; /* angle for calculation in radian */
 double dx_v_w03_06_04, dy_v_w03_06_04, dz_v_w03_06_04, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_05, curve_ang_H_w03_06_05; /* angle for calculation in radian */
 double dx_v_w03_06_05, dy_v_w03_06_05, dz_v_w03_06_05, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_06, curve_ang_H_w03_06_06; /* angle for calculation in radian */
 double dx_v_w03_06_06, dy_v_w03_06_06, dz_v_w03_06_06, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_07, curve_ang_H_w03_06_07; /* angle for calculation in radian */
 double dx_v_w03_06_07, dy_v_w03_06_07, dz_v_w03_06_07, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_08, curve_ang_H_w03_06_08; /* angle for calculation in radian */
 double dx_v_w03_06_08, dy_v_w03_06_08, dz_v_w03_06_08, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_09, curve_ang_H_w03_06_09; /* angle for calculation in radian */
 double dx_v_w03_06_09, dy_v_w03_06_09, dz_v_w03_06_09, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_10, curve_ang_H_w03_06_10; /* angle for calculation in radian */
 double dx_v_w03_06_10, dy_v_w03_06_10, dz_v_w03_06_10, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 double curve_ang_V_w03_06_11, curve_ang_H_w03_06_11; /* angle for calculation in radian */
 double dx_v_w03_06_11, dy_v_w03_06_11, dz_v_w03_06_11, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 
 double curve_ang_V_w03_06_12, curve_ang_H_w03_06_12; /* angle for calculation in radian */
 double dx_v_w03_06_12, dy_v_w03_06_12, dz_v_w03_06_12, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 
 double curve_ang_V_w03_06_13, curve_ang_H_w03_06_13; /* angle for calculation in radian */
 double dx_v_w03_06_13, dy_v_w03_06_13, dz_v_w03_06_13, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
 
 
 double curve_ang_V_w03_06_14, curve_ang_H_w03_06_14; /* angle for calculation in radian */
 double dx_v_w03_06_14, dy_v_w03_06_14, dz_v_w03_06_14, dtrans;  /* to calculate exit position */
 double sign;             /* sign of radius in Bender   */
  
 double smallaxis_from_guide_elliptical_LEFT;
 double smallaxis_from_guide_elliptical_TOP;
 double largeaxis_from_guide_elliptical_LEFT;
 double largeaxis_from_guide_elliptical_TOP;
 
 int allocated;
 
    ''')


    instr.append_initialize(r'''
 v0 =3956.035/lambda_min;
 Freq_PS=Freq_M/2;
 BW1_Delay = Source_Offset+Distance_BW1/v0;
 BW2_Delay = Source_Offset+Distance_BW2/v0;
 BW3_Delay = Source_Offset+Distance_BW3/v0;
 PS1_Delay = Source_Offset+Distance_PS1/v0;
 PS2_Delay = Source_Offset+Distance_PS2/v0;
 RRM_Delay = Source_Offset+Distance_RRM/v0;
 M1_Delay = Source_Offset+Distance_M1/v0;
 M2_Delay = Source_Offset+Distance_M2/v0;
 
 curve_ang_V_w03_01_012 = (0.4995+0.001)/ROC_V;
 curve_ang_H_w03_01_012 = (0.4995+0.001)/ROC_H;
 dx_v_w03_01_012 = 0;
 dz_v_w03_01_012 = ROC_V * sin(curve_ang_V_w03_01_012);     
 dy_v_w03_01_012 = ROC_V * (1- cos(curve_ang_V_w03_01_012));
 
 
 curve_ang_V_w03_01_02 = (0.999+0.001)/ROC_V;
 dx_v_w03_01_02 = 0;
 dz_v_w03_01_02 = ROC_V * sin(curve_ang_V_w03_01_02);     
 dy_v_w03_01_02 = ROC_V * (1- cos(curve_ang_V_w03_01_02));
 curve_ang_H_w03_01_02 = (0.999+0.001)/ROC_H;
 
 
 curve_ang_V_w03_01_03 = (1.480+0.002)/ROC_V;
 dx_v_w03_01_03 = 0;
 dz_v_w03_01_03 = ROC_V * sin(curve_ang_V_w03_01_03);     
 dy_v_w03_01_03 = ROC_V * (1- cos(curve_ang_V_w03_01_03));
 curve_ang_H_w03_01_03 = (1.480+0.002)/ROC_H;
 
 
 curve_ang_V_w03_02_01 = (0.516+0.025)/ROC_V;
 dx_v_w03_02_01 = 0;
 dz_v_w03_02_01 = ROC_V * sin(curve_ang_V_w03_02_01);     
 dy_v_w03_02_01 = ROC_V * (1- cos(curve_ang_V_w03_02_01));
 curve_ang_H_w03_02_01 = (0.516+0.025)/ROC_H;  
    
 
 curve_ang_V_w03_03_01 = (1.9412+0.001)/ROC_V;
 dx_v_w03_03_01 = 0;
 dz_v_w03_03_01 = ROC_V * sin(curve_ang_V_w03_03_01);     
 dy_v_w03_03_01 = ROC_V * (1- cos(curve_ang_V_w03_03_01));
 curve_ang_H_w03_03_01 = (1.9412+0.001)/ROC_H;
    
 curve_ang_V_w03_03_02 = (1.9412+0.012)/ROC_V;
 dx_v_w03_03_02 = 0;
 dz_v_w03_03_02 = ROC_V * sin(curve_ang_V_w03_03_02);     
 dy_v_w03_03_02 = ROC_V * (1- cos(curve_ang_V_w03_03_02));
 curve_ang_H_w03_03_02 = (1.9412+0.012)/ROC_H;
	
 curve_ang_V_w03_04_01 = (1.9412+0.001)/ROC_V;
 dx_v_w03_04_01 = 0;
 dz_v_w03_04_01 = ROC_V * sin(curve_ang_V_w03_03_01);     
 dy_v_w03_04_01 = ROC_V * (1- cos(curve_ang_V_w03_03_01));
 curve_ang_H_w03_04_01 = (1.9412+0.001)/ROC_H;
	
 curve_ang_V_w03_04_02 = (1.9412+0.012)/ROC_V;
 dx_v_w03_04_02 = 0;
 dz_v_w03_04_02 = ROC_V * sin(curve_ang_V_w03_04_02);     
 dy_v_w03_04_02 = ROC_V * (1- cos(curve_ang_V_w03_04_02));
  curve_ang_H_w03_04_02 = (1.9412+0.012)/ROC_H;
  
  
 curve_ang_V_w03_05_01 = (1.2+0.03)/ROC_V;
 dx_v_w03_05_01 = 0;
 dz_v_w03_05_01 = ROC_V * sin(curve_ang_V_w03_05_01);     
 dy_v_w03_05_01 = ROC_V * (1- cos(curve_ang_V_w03_05_01));
 curve_ang_H_w03_05_01 = (1.2+0.03)/ROC_H;
  
 curve_ang_V_w03_05_02 = (0.8+0.002)/ROC_V;
 dx_v_w03_05_02 = 0;
 dz_v_w03_05_02 = ROC_V * sin(curve_ang_V_w03_05_02);     
 dy_v_w03_05_02 = ROC_V * (1- cos(curve_ang_V_w03_05_02));
 curve_ang_H_w03_05_02 = (0.8+0.002)/ROC_H;

 curve_ang_V_w03_05_03 = ( 1.9435   +0.001)/ROC_V;
 dx_v_w03_05_03 = 0;
 dz_v_w03_05_03 = ROC_V * sin(curve_ang_V_w03_05_03);     
 dy_v_w03_05_03 = ROC_V * (1- cos(curve_ang_V_w03_05_03));
 curve_ang_H_w03_05_03 = ( 1.9435   +0.001)/ROC_H;
  
 curve_ang_V_w03_05_04 =  (1.9435   +0.002)/ROC_V;
 dx_v_w03_05_04 = 0;
 dz_v_w03_05_04 = ROC_V * sin(curve_ang_V_w03_05_04);     
 dy_v_w03_05_04 = ROC_V * (1- cos(curve_ang_V_w03_05_04));
 curve_ang_H_w03_05_04 =  (1.9435   +0.002)/ROC_H;
  
  
 curve_ang_V_w03_05_05 = (0.8+0.03)/ROC_V;
 dx_v_w03_05_05 = 0;
 dz_v_w03_05_05 = ROC_V * sin(curve_ang_V_w03_05_05);     
 dy_v_w03_05_05 = ROC_V * (1- cos(curve_ang_V_w03_05_05));
 curve_ang_H_w03_05_05 = (0.8+0.03)/ROC_H;
  
  
 curve_ang_V_w03_05_06 = (0.8+0.002)/ROC_V;
 dx_v_w03_05_06 = 0;
 dz_v_w03_05_06 = ROC_V * sin(curve_ang_V_w03_05_06);     
 dy_v_w03_05_06 = ROC_V * (1- cos(curve_ang_V_w03_05_06));
 curve_ang_H_w03_05_06 = (0.8+0.002)/ROC_H;
  
 curve_ang_V_w03_05_07 = ( 1.4531   +0.001)/ROC_V;
 dx_v_w03_05_07 = 0;
 dz_v_w03_05_07 = ROC_V * sin(curve_ang_V_w03_05_07);     
 dy_v_w03_05_07 = ROC_V * (1- cos(curve_ang_V_w03_05_07));
 curve_ang_H_w03_05_07 = ( 1.4531   +0.001)/ROC_H;
 
 
 curve_ang_V_w03_05_08 = ( 1.4531   +0.003)/ROC_V;
 dx_v_w03_05_08 = 0;
 dz_v_w03_05_08 = ROC_V * sin(curve_ang_V_w03_05_08);     
 dy_v_w03_05_08 = ROC_V * (1- cos(curve_ang_V_w03_05_08));
 curve_ang_H_w03_05_08 = ( 1.4531   +0.003)/ROC_H;
 
 curve_ang_V_w03_05_09 = ( 2.040+0.001)/ROC_V;
 dx_v_w03_05_09 = 0;
 dz_v_w03_05_09 = ROC_V * sin(curve_ang_V_w03_05_09);     
 dy_v_w03_05_09 = ROC_V * (1- cos(curve_ang_V_w03_05_09));
 curve_ang_H_w03_05_09 = ( 2.040+0.001)/ROC_H;
 
 curve_ang_V_w03_05_10 = ( 1.65 +0.04)/ROC_V;
 dx_v_w03_05_10 = 0;
 dz_v_w03_05_10 = ROC_V * sin(curve_ang_V_w03_05_10);     
 dy_v_w03_05_10 = ROC_V * (1- cos(curve_ang_V_w03_05_10));
 curve_ang_H_w03_05_10 = ( 1.65 +0.04)/ROC_H;
 
 curve_ang_V_w03_06_011 = ( 0.4903)/ROC_V;
 dx_v_w03_06_011 = 0;
 dz_v_w03_06_011 = ROC_V * sin(curve_ang_V_w03_06_011);     
 dy_v_w03_06_011 = ROC_V * (1- cos(curve_ang_V_w03_06_011));
 curve_ang_H_w03_06_011 = ( 0.4906)/ROC_H;
 
 curve_ang_V_w03_06_012 = ( 1.982+0.001)/ROC_V;
 dx_v_w03_06_012 = 0;
 dz_v_w03_06_012 = ROC_V * sin(curve_ang_V_w03_06_012);     
 dy_v_w03_06_012 = ROC_V * (1- cos(curve_ang_V_w03_06_012));
 curve_ang_H_w03_06_012 = ( 1.982+0.001)/ROC_H;
 
 curve_ang_V_w03_06_02 = ( 2+0.002)/ROC_V;
 dx_v_w03_06_02 = 0;
 dz_v_w03_06_02 = ROC_V * sin(curve_ang_V_w03_06_02);     
 dy_v_w03_06_02 = ROC_V * (1- cos(curve_ang_V_w03_06_02));
 curve_ang_H_w03_06_02 = ( 2+0.002)/ROC_H;
 
  
 curve_ang_V_w03_06_03 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_03 = 0;
 dz_v_w03_06_03 = ROC_V * sin(curve_ang_V_w03_06_03);     
 dy_v_w03_06_03 = ROC_V * (1- cos(curve_ang_V_w03_06_03));
 curve_ang_H_w03_06_03 = ( 2+0.001)/ROC_H;
 
 curve_ang_V_w03_06_04 = ( 2+0.002)/ROC_V;
 dx_v_w03_06_04 = 0;
 dz_v_w03_06_04 = ROC_V * sin(curve_ang_V_w03_06_04);     
 dy_v_w03_06_04 = ROC_V * (1- cos(curve_ang_V_w03_06_04));
 curve_ang_H_w03_06_04 = ( 2+0.002)/ROC_H;
 
 curve_ang_V_w03_06_05 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_05 = 0;
 dz_v_w03_06_05 = ROC_V * sin(curve_ang_V_w03_06_05);     
 dy_v_w03_06_05 = ROC_V * (1- cos(curve_ang_V_w03_06_05));
 curve_ang_H_w03_06_05 = ( 2+0.001)/ROC_H;
 
 curve_ang_V_w03_06_06 = ( 2+0.002)/ROC_V;
 dx_v_w03_06_06 = 0;
 dz_v_w03_06_06 = ROC_V * sin(curve_ang_V_w03_06_06);     
 dy_v_w03_06_06 = ROC_V * (1- cos(curve_ang_V_w03_06_06));
 curve_ang_H_w03_06_06 = ( 2+0.002)/ROC_H;
 
 curve_ang_V_w03_06_07 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_07 = 0;
 dz_v_w03_06_07 = ROC_V * sin(curve_ang_V_w03_06_07);     
 dy_v_w03_06_07 = ROC_V * (1- cos(curve_ang_V_w03_06_07));
 curve_ang_H_w03_06_07 = ( 2+0.001)/ROC_H;
 
 curve_ang_V_w03_06_08 = ( 2+0.002)/ROC_V;
 dx_v_w03_06_08 = 0;
 dz_v_w03_06_08 = ROC_V * sin(curve_ang_V_w03_06_08);     
 dy_v_w03_06_08 = ROC_V * (1- cos(curve_ang_V_w03_06_08));
 curve_ang_H_w03_06_08 = ( 2+0.002)/ROC_H;
 
 curve_ang_V_w03_06_09 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_09 = 0;
 dz_v_w03_06_09 = ROC_V * sin(curve_ang_V_w03_06_09);     
 dy_v_w03_06_09 = ROC_V * (1- cos(curve_ang_V_w03_06_09));
 curve_ang_H_w03_06_09 = ( 2+0.001)/ROC_H;
 
 curve_ang_V_w03_06_10 = ( 2+0.002)/ROC_V;
 dx_v_w03_06_10 = 0;
 dz_v_w03_06_10 = ROC_V * sin(curve_ang_V_w03_06_10);     
 dy_v_w03_06_10 = ROC_V * (1- cos(curve_ang_V_w03_06_10));
 curve_ang_H_w03_06_10 = ( 2+0.002)/ROC_H;
   
  
 curve_ang_V_w03_06_11 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_11 = 0;
 dz_v_w03_06_11 = ROC_V * sin(curve_ang_V_w03_06_11);     
 dy_v_w03_06_11 = ROC_V * (1- cos(curve_ang_V_w03_06_11));
 curve_ang_H_w03_06_11 = ( 2+0.001)/ROC_H;
 
 curve_ang_V_w03_06_12 = ( 2+0.002)/ROC_V;
 dx_v_w03_06_12 = 0;
 dz_v_w03_06_12 = ROC_V * sin(curve_ang_V_w03_06_12);     
 dy_v_w03_06_12 = ROC_V * (1- cos(curve_ang_V_w03_06_12));
 curve_ang_H_w03_06_12 = ( 2+0.002)/ROC_H;
 
 curve_ang_V_w03_06_13 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_13 = 0;
 dz_v_w03_06_13 = ROC_V * sin(curve_ang_V_w03_06_13);     
 dy_v_w03_06_13 = ROC_V * (1- cos(curve_ang_V_w03_06_13));
 curve_ang_H_w03_06_13 = ( 2+0.001)/ROC_H;
 
 curve_ang_V_w03_06_14 = ( 2+0.001)/ROC_V;
 dx_v_w03_06_14 = 0;
 dz_v_w03_06_14 = ROC_V * sin(curve_ang_V_w03_06_14);     
 dy_v_w03_06_14 = ROC_V * (1- cos(curve_ang_V_w03_06_14));
 curve_ang_H_w03_06_14 = ( 2+0.001)/ROC_H;
 
 allocated = 0;

 #define N_trains INSTRUMENT_GETPAR(N_trains_par)

 MPI_MASTER(
   struct timespec ts;

   if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
      perror("clock_gettime");
      exit(EXIT_FAILURE);
   }

   double wall_time = ts.tv_sec + ts.tv_nsec * 1e-9;

   FILE *f = fopen("time_spent.txt", "w");
   if (!f) {
       perror("fopen");
       exit(EXIT_FAILURE);
   }

   fprintf(f, "%.9f\n", wall_time);
   fclose(f);
 );   

    ''')


    uv_t_offset = instr.add_user_var("double *", "t_offset", comment="USERVAR added by McCode py-generator")
    uv_p_trains = instr.add_user_var("double *", "p_trains", comment="USERVAR added by McCode py-generator")
    uv_p_last_time_manipulation = instr.add_user_var("double ", "p_last_time_manipulation", comment="USERVAR added by McCode py-generator")
    uv_adaptive_N = instr.add_user_var("int ", "adaptive_N", comment="USERVAR added by McCode py-generator")
    uv_N_active = instr.add_user_var("int ", "N_active", comment="USERVAR added by McCode py-generator")
    uv_total_arrived = instr.add_user_var("long ", "total_arrived", comment="USERVAR added by McCode py-generator")
    uv_total_N_sent = instr.add_user_var("long ", "total_N_sent", comment="USERVAR added by McCode py-generator")
    uv_total_rays_sent = instr.add_user_var("long ", "total_rays_sent", comment="USERVAR added by McCode py-generator")
    # *****************************************************************************
    # * instrument 'CSPEC' TRACE
    # *****************************************************************************
    
    # Comp instance Origin, placement and parameters
    Origin = instr.add_component('Origin','Arm')
    # EXTEND at Origin
    Origin.append_EXTEND(r'''
	
		if (allocated == 0) {
		  t_offset = malloc(INSTRUMENT_GETPAR(N_trains_par)*sizeof(double));
		  p_trains = malloc(INSTRUMENT_GETPAR(N_trains_par)*sizeof(double));	
		  adaptive_N=INSTRUMENT_GETPAR(N_trains_par);
		  total_arrived=0;
		  total_N_sent=0;
		  total_rays_sent=0;
		  allocated = 1;
	    }
    ''')


    
    
    # Comp instance ESS_Source, placement and parameters
    ESS_Source = instr.add_component('ESS_Source','ESS_butterfly', AT=['0', '0', '0.0'])
    
    ESS_Source.sector = '"W"'
    ESS_Source.beamline = '3'
    ESS_Source.yheight = '0.03'
    ESS_Source.cold_frac = '1.0'
    ESS_Source.target_index = '0'
    ESS_Source.dist = '1.9'
    ESS_Source.focus_xw = '0.1'
    ESS_Source.focus_yh = '0.1'
    ESS_Source.c_performance = '1'
    ESS_Source.t_performance = '1'
    ESS_Source.Lmin = '2'
    ESS_Source.Lmax = '20'
    ESS_Source.tmax_multiplier = '3'
    ESS_Source.n_pulses = '1'
    ESS_Source.acc_power = 'AC_Power'
    ESS_Source.tfocus_dist = '0'
    ESS_Source.tfocus_time = '0'
    ESS_Source.tfocus_width = '0'
    ESS_Source.target_tsplit = 'target_tsplit'
    
    # Comp instance Instrument_Direction, placement and parameters
    Instrument_Direction = instr.add_component('Instrument_Direction','Arm', AT=['move_x', 'move_y', '1.90424'], AT_RELATIVE='ESS_Source', ROTATED=['phi_x', 'phi_y', 'phi_z'], ROTATED_RELATIVE='ESS_Source')
    
    
    # Comp instance Mon_LambdaX_In, placement and parameters
    Mon_LambdaX_In = instr.add_component('Mon_LambdaX_In','Monitor_nD', AT=['0', '0', '0'], AT_RELATIVE='Instrument_Direction', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Instrument_Direction')
    
    Mon_LambdaX_In.user1 = '""'
    Mon_LambdaX_In.user2 = '""'
    Mon_LambdaX_In.user3 = '""'
    Mon_LambdaX_In.xwidth = '1.1 * 0.07'
    Mon_LambdaX_In.yheight = '1.1 * 0.055'
    Mon_LambdaX_In.zdepth = '0'
    Mon_LambdaX_In.xmin = '0'
    Mon_LambdaX_In.xmax = '0'
    Mon_LambdaX_In.ymin = '0'
    Mon_LambdaX_In.ymax = '0'
    Mon_LambdaX_In.zmin = '0'
    Mon_LambdaX_In.zmax = '0'
    Mon_LambdaX_In.bins = '100'
    Mon_LambdaX_In.min = '-1e40'
    Mon_LambdaX_In.max = '1e40'
    Mon_LambdaX_In.restore_neutron = '1'
    Mon_LambdaX_In.radius = '0'
    Mon_LambdaX_In.options = '"x , lambda limits=[1 25]"'
    Mon_LambdaX_In.filename = '"NULL"'
    Mon_LambdaX_In.geometry = '"NULL"'
    Mon_LambdaX_In.nowritefile = '0'
    Mon_LambdaX_In.username1 = '"NULL"'
    Mon_LambdaX_In.username2 = '"NULL"'
    Mon_LambdaX_In.username3 = '"NULL"'
    Mon_LambdaX_In.tsplit = '0'
    Mon_LambdaX_In.adaptive_target = '0'
    
    # Comp instance Mon_LambdaY_In, placement and parameters
    Mon_LambdaY_In = instr.add_component('Mon_LambdaY_In','Monitor_nD', AT=['0', '0', '0'], AT_RELATIVE='Mon_LambdaX_In', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Mon_LambdaX_In')
    
    Mon_LambdaY_In.user1 = '""'
    Mon_LambdaY_In.user2 = '""'
    Mon_LambdaY_In.user3 = '""'
    Mon_LambdaY_In.xwidth = '1.1 * 0.07'
    Mon_LambdaY_In.yheight = '1.1 * 0.055'
    Mon_LambdaY_In.zdepth = '0'
    Mon_LambdaY_In.xmin = '0'
    Mon_LambdaY_In.xmax = '0'
    Mon_LambdaY_In.ymin = '0'
    Mon_LambdaY_In.ymax = '0'
    Mon_LambdaY_In.zmin = '0'
    Mon_LambdaY_In.zmax = '0'
    Mon_LambdaY_In.bins = '100'
    Mon_LambdaY_In.min = '-1e40'
    Mon_LambdaY_In.max = '1e40'
    Mon_LambdaY_In.restore_neutron = '1'
    Mon_LambdaY_In.radius = '0'
    Mon_LambdaY_In.options = '"y , lambda limits=[1 25]"'
    Mon_LambdaY_In.filename = '"NULL"'
    Mon_LambdaY_In.geometry = '"NULL"'
    Mon_LambdaY_In.nowritefile = '0'
    Mon_LambdaY_In.username1 = '"NULL"'
    Mon_LambdaY_In.username2 = '"NULL"'
    Mon_LambdaY_In.username3 = '"NULL"'
    Mon_LambdaY_In.tsplit = '0'
    Mon_LambdaY_In.adaptive_target = '0'
    
    # Comp instance Mon_LambdaDX_In, placement and parameters
    Mon_LambdaDX_In = instr.add_component('Mon_LambdaDX_In','Monitor_nD', AT=['0', '0', '0'], AT_RELATIVE='Mon_LambdaY_In', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Mon_LambdaY_In')
    
    Mon_LambdaDX_In.user1 = '""'
    Mon_LambdaDX_In.user2 = '""'
    Mon_LambdaDX_In.user3 = '""'
    Mon_LambdaDX_In.xwidth = '1.1 * 0.07'
    Mon_LambdaDX_In.yheight = '1.1 * 0.055'
    Mon_LambdaDX_In.zdepth = '0'
    Mon_LambdaDX_In.xmin = '0'
    Mon_LambdaDX_In.xmax = '0'
    Mon_LambdaDX_In.ymin = '0'
    Mon_LambdaDX_In.ymax = '0'
    Mon_LambdaDX_In.zmin = '0'
    Mon_LambdaDX_In.zmax = '0'
    Mon_LambdaDX_In.bins = '100'
    Mon_LambdaDX_In.min = '-1e40'
    Mon_LambdaDX_In.max = '1e40'
    Mon_LambdaDX_In.restore_neutron = '1'
    Mon_LambdaDX_In.radius = '0'
    Mon_LambdaDX_In.options = '"dx limits=[-6 6], lambda limits=[1 25]"'
    Mon_LambdaDX_In.filename = '"NULL"'
    Mon_LambdaDX_In.geometry = '"NULL"'
    Mon_LambdaDX_In.nowritefile = '0'
    Mon_LambdaDX_In.username1 = '"NULL"'
    Mon_LambdaDX_In.username2 = '"NULL"'
    Mon_LambdaDX_In.username3 = '"NULL"'
    Mon_LambdaDX_In.tsplit = '0'
    Mon_LambdaDX_In.adaptive_target = '0'
    
    # Comp instance Mon_LambdaDY_In, placement and parameters
    Mon_LambdaDY_In = instr.add_component('Mon_LambdaDY_In','Monitor_nD', AT=['0', '0', '0'], AT_RELATIVE='Mon_LambdaDX_In', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Mon_LambdaDX_In')
    
    Mon_LambdaDY_In.user1 = '""'
    Mon_LambdaDY_In.user2 = '""'
    Mon_LambdaDY_In.user3 = '""'
    Mon_LambdaDY_In.xwidth = '1.1 * 0.07'
    Mon_LambdaDY_In.yheight = '1.1 * 0.055'
    Mon_LambdaDY_In.zdepth = '0'
    Mon_LambdaDY_In.xmin = '0'
    Mon_LambdaDY_In.xmax = '0'
    Mon_LambdaDY_In.ymin = '0'
    Mon_LambdaDY_In.ymax = '0'
    Mon_LambdaDY_In.zmin = '0'
    Mon_LambdaDY_In.zmax = '0'
    Mon_LambdaDY_In.bins = '100'
    Mon_LambdaDY_In.min = '-1e40'
    Mon_LambdaDY_In.max = '1e40'
    Mon_LambdaDY_In.restore_neutron = '1'
    Mon_LambdaDY_In.radius = '0'
    Mon_LambdaDY_In.options = '"dy limits=[-6 6], lambda limits=[1 25]"'
    Mon_LambdaDY_In.filename = '"NULL"'
    Mon_LambdaDY_In.geometry = '"NULL"'
    Mon_LambdaDY_In.nowritefile = '0'
    Mon_LambdaDY_In.username1 = '"NULL"'
    Mon_LambdaDY_In.username2 = '"NULL"'
    Mon_LambdaDY_In.username3 = '"NULL"'
    Mon_LambdaDY_In.tsplit = '0'
    Mon_LambdaDY_In.adaptive_target = '0'
    
    # Comp instance Al_Window1, placement and parameters
    Al_Window1 = instr.add_component('Al_Window1','Al_window', AT=['move_x', 'move_y', '1.9025'], AT_RELATIVE='ESS_Source', ROTATED=['phi_x', 'phi_y', 'phi_z'], ROTATED_RELATIVE='ESS_Source')
    
    Al_Window1.thickness = '0.0015'
    
    # Comp instance Guide_benderw03_01_011, placement and parameters
    Guide_benderw03_01_011 = instr.add_component('Guide_benderw03_01_011','Guide_gravity', AT=['0', '0', '0'], AT_RELATIVE='Instrument_Direction', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Instrument_Direction')
    
    Guide_benderw03_01_011.w1 = '0.045'
    Guide_benderw03_01_011.h1 = '0.043'
    Guide_benderw03_01_011.w2 = '0.053'
    Guide_benderw03_01_011.h2 = '0.047'
    Guide_benderw03_01_011.l = '0.4995'
    Guide_benderw03_01_011.R0 = 'R0_par'
    Guide_benderw03_01_011.Qc = '0.0218'
    Guide_benderw03_01_011.alpha = 'alpha_par'
    Guide_benderw03_01_011.m = '1.0'
    Guide_benderw03_01_011.W = 'W_par'
    Guide_benderw03_01_011.nslit = '1'
    Guide_benderw03_01_011.d = '0.0005'
    Guide_benderw03_01_011.mleft = '3'
    Guide_benderw03_01_011.mright = '3.5'
    Guide_benderw03_01_011.mtop = '4'
    Guide_benderw03_01_011.mbottom = '3.5'
    Guide_benderw03_01_011.nhslit = '1'
    Guide_benderw03_01_011.G = '0'
    Guide_benderw03_01_011.aleft = '-1'
    Guide_benderw03_01_011.aright = '-1'
    Guide_benderw03_01_011.atop = '-1'
    Guide_benderw03_01_011.abottom = '-1'
    Guide_benderw03_01_011.wavy = '0'
    Guide_benderw03_01_011.wavy_z = '0'
    Guide_benderw03_01_011.wavy_tb = '0'
    Guide_benderw03_01_011.wavy_lr = '0'
    Guide_benderw03_01_011.chamfers = '0'
    Guide_benderw03_01_011.chamfers_z = '0'
    Guide_benderw03_01_011.chamfers_lr = '0'
    Guide_benderw03_01_011.chamfers_tb = '0'
    Guide_benderw03_01_011.nelements = '1'
    Guide_benderw03_01_011.nu = '0'
    Guide_benderw03_01_011.phase = '0'
    Guide_benderw03_01_011.reflect = '"NULL"'
    
    # Comp instance Arm1a, placement and parameters
    Arm1a = instr.add_component('Arm1a','Arm', AT=['0', '0', '0.4995 + 1e-06'], AT_RELATIVE='Guide_benderw03_01_011', ROTATED=['-0.009', '-0.004', '0'], ROTATED_RELATIVE='Instrument_Direction')
    
    
    # Comp instance Guide_benderw03_01_012, placement and parameters
    Guide_benderw03_01_012 = instr.add_component('Guide_benderw03_01_012','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm1a', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm1a')
    
    Guide_benderw03_01_012.w1 = '0.053'
    Guide_benderw03_01_012.h1 = '0.047'
    Guide_benderw03_01_012.w2 = '0.0617'
    Guide_benderw03_01_012.h2 = '0.051'
    Guide_benderw03_01_012.l = '0.4995'
    Guide_benderw03_01_012.R0 = 'R0_par'
    Guide_benderw03_01_012.Qc = '0.0218'
    Guide_benderw03_01_012.alpha = 'alpha_par'
    Guide_benderw03_01_012.m = '1.0'
    Guide_benderw03_01_012.W = 'W_par'
    Guide_benderw03_01_012.nslit = '1'
    Guide_benderw03_01_012.d = '0.0005'
    Guide_benderw03_01_012.mleft = '3'
    Guide_benderw03_01_012.mright = '3.5'
    Guide_benderw03_01_012.mtop = '4'
    Guide_benderw03_01_012.mbottom = '3.5'
    Guide_benderw03_01_012.nhslit = '1'
    Guide_benderw03_01_012.G = '0'
    Guide_benderw03_01_012.aleft = '-1'
    Guide_benderw03_01_012.aright = '-1'
    Guide_benderw03_01_012.atop = '-1'
    Guide_benderw03_01_012.abottom = '-1'
    Guide_benderw03_01_012.wavy = '0'
    Guide_benderw03_01_012.wavy_z = '0'
    Guide_benderw03_01_012.wavy_tb = '0'
    Guide_benderw03_01_012.wavy_lr = '0'
    Guide_benderw03_01_012.chamfers = '0'
    Guide_benderw03_01_012.chamfers_z = '0'
    Guide_benderw03_01_012.chamfers_lr = '0'
    Guide_benderw03_01_012.chamfers_tb = '0'
    Guide_benderw03_01_012.nelements = '1'
    Guide_benderw03_01_012.nu = '0'
    Guide_benderw03_01_012.phase = '0'
    Guide_benderw03_01_012.reflect = '"NULL"'
    
    # Comp instance Arm1b, placement and parameters
    Arm1b = instr.add_component('Arm1b','Arm', AT=['dx_v_w03_01_012', '- dy_v_w03_01_012', 'dz_v_w03_01_012 + 1e-06'], AT_RELATIVE='Guide_benderw03_01_012', ROTATED=['curve_ang_V_w03_01_012 * RAD2DEG', 'curve_ang_H_w03_01_012 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_01_012')
    
    
    # Comp instance Guide_benderw03_01_02, placement and parameters
    Guide_benderw03_01_02 = instr.add_component('Guide_benderw03_01_02','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm1b', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm1b')
    
    Guide_benderw03_01_02.w1 = '0.0617'
    Guide_benderw03_01_02.h1 = '0.051'
    Guide_benderw03_01_02.w2 = '0.07'
    Guide_benderw03_01_02.h2 = '0.055'
    Guide_benderw03_01_02.l = '0.999'
    Guide_benderw03_01_02.R0 = 'R0_par'
    Guide_benderw03_01_02.Qc = '0.0218'
    Guide_benderw03_01_02.alpha = 'alpha_par'
    Guide_benderw03_01_02.m = '1.0'
    Guide_benderw03_01_02.W = 'W_par'
    Guide_benderw03_01_02.nslit = '1'
    Guide_benderw03_01_02.d = '0.0005'
    Guide_benderw03_01_02.mleft = '3'
    Guide_benderw03_01_02.mright = '3.5'
    Guide_benderw03_01_02.mtop = '4'
    Guide_benderw03_01_02.mbottom = '3.5'
    Guide_benderw03_01_02.nhslit = '1'
    Guide_benderw03_01_02.G = '0'
    Guide_benderw03_01_02.aleft = '-1'
    Guide_benderw03_01_02.aright = '-1'
    Guide_benderw03_01_02.atop = '-1'
    Guide_benderw03_01_02.abottom = '-1'
    Guide_benderw03_01_02.wavy = '0'
    Guide_benderw03_01_02.wavy_z = '0'
    Guide_benderw03_01_02.wavy_tb = '0'
    Guide_benderw03_01_02.wavy_lr = '0'
    Guide_benderw03_01_02.chamfers = '0'
    Guide_benderw03_01_02.chamfers_z = '0'
    Guide_benderw03_01_02.chamfers_lr = '0'
    Guide_benderw03_01_02.chamfers_tb = '0'
    Guide_benderw03_01_02.nelements = '1'
    Guide_benderw03_01_02.nu = '0'
    Guide_benderw03_01_02.phase = '0'
    Guide_benderw03_01_02.reflect = '"NULL"'
    
    # Comp instance Armc, placement and parameters
    Armc = instr.add_component('Armc','Arm', AT=['dx_v_w03_01_02', '- dy_v_w03_01_02', 'dz_v_w03_01_02 + 1e-06'], AT_RELATIVE='Guide_benderw03_01_02', ROTATED=['curve_ang_V_w03_01_02 * RAD2DEG', 'curve_ang_H_w03_01_02 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_01_02')
    
    
    # Comp instance Guide_benderw03_01_03, placement and parameters
    Guide_benderw03_01_03 = instr.add_component('Guide_benderw03_01_03','Vertical_Bender', AT=['0', '0', '1e-06'], AT_RELATIVE='Armc', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Armc')
    
    Guide_benderw03_01_03.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_01_03.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_01_03.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_01_03.xwidth = '0.07'
    Guide_benderw03_01_03.yheight = '0.055'
    Guide_benderw03_01_03.length = '1.480'
    Guide_benderw03_01_03.radius = '- ROC_V'
    Guide_benderw03_01_03.G = '9.8'
    Guide_benderw03_01_03.nchan = '1'
    Guide_benderw03_01_03.d = '0'
    Guide_benderw03_01_03.debug = '0'
    Guide_benderw03_01_03.endFlat = '0'
    Guide_benderw03_01_03.drawOption = '1'
    Guide_benderw03_01_03.alwaystrack = '0'
    Guide_benderw03_01_03.diststep1 = '0.020'
    Guide_benderw03_01_03.diststep2 = '0.002'
    Guide_benderw03_01_03.recurse_max = '1000'
    
    # Comp instance Arm2_GapBeforeBBG, placement and parameters
    Arm2_GapBeforeBBG = instr.add_component('Arm2_GapBeforeBBG','Arm', AT=['dx_v_w03_01_03', '- dy_v_w03_01_03', 'dz_v_w03_01_03 + 1e-06'], AT_RELATIVE='Guide_benderw03_01_03', ROTATED=['curve_ang_V_w03_01_03 * RAD2DEG', 'curve_ang_H_w03_01_03 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_01_03')
    
    
    # Comp instance GuideBBG_benderw03_02_01, placement and parameters
    GuideBBG_benderw03_02_01 = instr.add_component('GuideBBG_benderw03_02_01','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm2_GapBeforeBBG', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm2_GapBeforeBBG')
    
    GuideBBG_benderw03_02_01.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    GuideBBG_benderw03_02_01.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    GuideBBG_benderw03_02_01.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    GuideBBG_benderw03_02_01.xwidth = '0.07'
    GuideBBG_benderw03_02_01.yheight = '0.055'
    GuideBBG_benderw03_02_01.length = '0.516'
    GuideBBG_benderw03_02_01.radius = '- ROC_V'
    GuideBBG_benderw03_02_01.G = '9.8'
    GuideBBG_benderw03_02_01.nchan = '1'
    GuideBBG_benderw03_02_01.d = '0'
    GuideBBG_benderw03_02_01.debug = '0'
    GuideBBG_benderw03_02_01.endFlat = '0'
    GuideBBG_benderw03_02_01.drawOption = '1'
    GuideBBG_benderw03_02_01.alwaystrack = '0'
    GuideBBG_benderw03_02_01.diststep1 = '0.020'
    GuideBBG_benderw03_02_01.diststep2 = '0.002'
    GuideBBG_benderw03_02_01.recurse_max = '1000'
    
    # Comp instance Arm3_GapAfterBBG, placement and parameters
    Arm3_GapAfterBBG = instr.add_component('Arm3_GapAfterBBG','Arm', AT=['dx_v_w03_02_01', '- dy_v_w03_02_01', 'dz_v_w03_02_01'], AT_RELATIVE='GuideBBG_benderw03_02_01', ROTATED=['curve_ang_V_w03_02_01 * RAD2DEG', 'curve_ang_H_w03_02_01 * RAD2DEG', '0'], ROTATED_RELATIVE='GuideBBG_benderw03_02_01')
    
    
    # Comp instance Guide_benderw03_03_01, placement and parameters
    Guide_benderw03_03_01 = instr.add_component('Guide_benderw03_03_01','Vertical_Bender', AT=['0.0', '0.0', '1e-6'], AT_RELATIVE='Arm3_GapAfterBBG', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm3_GapAfterBBG')
    
    Guide_benderw03_03_01.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_03_01.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_03_01.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_03_01.xwidth = '0.07'
    Guide_benderw03_03_01.yheight = '0.055'
    Guide_benderw03_03_01.length = '1.9462'
    Guide_benderw03_03_01.radius = '- ROC_V'
    Guide_benderw03_03_01.G = '9.8'
    Guide_benderw03_03_01.nchan = '1'
    Guide_benderw03_03_01.d = '0'
    Guide_benderw03_03_01.debug = '0'
    Guide_benderw03_03_01.endFlat = '0'
    Guide_benderw03_03_01.drawOption = '1'
    Guide_benderw03_03_01.alwaystrack = '0'
    Guide_benderw03_03_01.diststep1 = '0.020'
    Guide_benderw03_03_01.diststep2 = '0.002'
    Guide_benderw03_03_01.recurse_max = '1000'
    
    # Comp instance Arm4, placement and parameters
    Arm4 = instr.add_component('Arm4','Arm', AT=['dx_v_w03_03_01', '- dy_v_w03_03_01', 'dz_v_w03_03_01'], AT_RELATIVE='Guide_benderw03_03_01', ROTATED=['curve_ang_V_w03_03_01 * RAD2DEG', 'curve_ang_H_w03_03_01 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_03_01')
    
    
    # Comp instance Guide_benderw03_03_02, placement and parameters
    Guide_benderw03_03_02 = instr.add_component('Guide_benderw03_03_02','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm4', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm4')
    
    Guide_benderw03_03_02.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_03_02.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_03_02.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_03_02.xwidth = '0.07'
    Guide_benderw03_03_02.yheight = '0.055'
    Guide_benderw03_03_02.length = '1.9462'
    Guide_benderw03_03_02.radius = '- ROC_V'
    Guide_benderw03_03_02.G = '9.8'
    Guide_benderw03_03_02.nchan = '1'
    Guide_benderw03_03_02.d = '0'
    Guide_benderw03_03_02.debug = '0'
    Guide_benderw03_03_02.endFlat = '0'
    Guide_benderw03_03_02.drawOption = '1'
    Guide_benderw03_03_02.alwaystrack = '0'
    Guide_benderw03_03_02.diststep1 = '0.020'
    Guide_benderw03_03_02.diststep2 = '0.002'
    Guide_benderw03_03_02.recurse_max = '1000'
    
    # Comp instance Arm5, placement and parameters
    Arm5 = instr.add_component('Arm5','Arm', AT=['dx_v_w03_03_02', '- dy_v_w03_03_02', 'dz_v_w03_03_02'], AT_RELATIVE='Guide_benderw03_03_02', ROTATED=['curve_ang_V_w03_03_02 * RAD2DEG', 'curve_ang_H_w03_03_02 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_03_02')
    
    
    # Comp instance Guide_benderw03_04_01, placement and parameters
    Guide_benderw03_04_01 = instr.add_component('Guide_benderw03_04_01','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm5', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm5')
    
    Guide_benderw03_04_01.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_04_01.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_04_01.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_04_01.xwidth = '0.07'
    Guide_benderw03_04_01.yheight = '0.055'
    Guide_benderw03_04_01.length = '1.9462'
    Guide_benderw03_04_01.radius = '- ROC_V'
    Guide_benderw03_04_01.G = '9.8'
    Guide_benderw03_04_01.nchan = '1'
    Guide_benderw03_04_01.d = '0'
    Guide_benderw03_04_01.debug = '0'
    Guide_benderw03_04_01.endFlat = '0'
    Guide_benderw03_04_01.drawOption = '1'
    Guide_benderw03_04_01.alwaystrack = '0'
    Guide_benderw03_04_01.diststep1 = '0.020'
    Guide_benderw03_04_01.diststep2 = '0.002'
    Guide_benderw03_04_01.recurse_max = '1000'
    
    # Comp instance Arm6, placement and parameters
    Arm6 = instr.add_component('Arm6','Arm', AT=['dx_v_w03_04_01', '- dy_v_w03_04_01', 'dz_v_w03_04_01'], AT_RELATIVE='Guide_benderw03_04_01', ROTATED=['curve_ang_V_w03_04_01 * RAD2DEG', 'curve_ang_H_w03_04_01 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_04_01')
    
    
    # Comp instance Guide_benderw03_04_02, placement and parameters
    Guide_benderw03_04_02 = instr.add_component('Guide_benderw03_04_02','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm6', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm6')
    
    Guide_benderw03_04_02.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_04_02.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_04_02.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_04_02.xwidth = '0.07'
    Guide_benderw03_04_02.yheight = '0.055'
    Guide_benderw03_04_02.length = '1.9462'
    Guide_benderw03_04_02.radius = '- ROC_V'
    Guide_benderw03_04_02.G = '9.8'
    Guide_benderw03_04_02.nchan = '1'
    Guide_benderw03_04_02.d = '0'
    Guide_benderw03_04_02.debug = '0'
    Guide_benderw03_04_02.endFlat = '0'
    Guide_benderw03_04_02.drawOption = '1'
    Guide_benderw03_04_02.alwaystrack = '0'
    Guide_benderw03_04_02.diststep1 = '0.020'
    Guide_benderw03_04_02.diststep2 = '0.002'
    Guide_benderw03_04_02.recurse_max = '1000'
    
    # Comp instance Arm7, placement and parameters
    Arm7 = instr.add_component('Arm7','Arm', AT=['dx_v_w03_04_02', '- dy_v_w03_04_02', 'dz_v_w03_04_02'], AT_RELATIVE='Guide_benderw03_04_02', ROTATED=['curve_ang_V_w03_04_02 * RAD2DEG', 'curve_ang_H_w03_04_02 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_04_02')
    
    
    # Comp instance Guide_benderw03_05_01, placement and parameters
    Guide_benderw03_05_01 = instr.add_component('Guide_benderw03_05_01','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm7', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm7')
    
    Guide_benderw03_05_01.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_01.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_01.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_01.xwidth = '0.07'
    Guide_benderw03_05_01.yheight = '0.055'
    Guide_benderw03_05_01.length = '1.2'
    Guide_benderw03_05_01.radius = '- ROC_V'
    Guide_benderw03_05_01.G = '9.8'
    Guide_benderw03_05_01.nchan = '1'
    Guide_benderw03_05_01.d = '0'
    Guide_benderw03_05_01.debug = '0'
    Guide_benderw03_05_01.endFlat = '0'
    Guide_benderw03_05_01.drawOption = '1'
    Guide_benderw03_05_01.alwaystrack = '0'
    Guide_benderw03_05_01.diststep1 = '0.020'
    Guide_benderw03_05_01.diststep2 = '0.002'
    Guide_benderw03_05_01.recurse_max = '1000'
    
    # Comp instance BW_1, placement and parameters
    BW_1 = instr.add_component('BW_1','DiskChopper', AT=['dx_v_w03_05_01_a', '- dy_v_w03_05_01_a', 'dz_v_w03_05_01_a'], AT_RELATIVE='Guide_benderw03_05_01', ROTATED=['curve_ang_V_w03_05_01_a * RAD2DEG', 'curve_ang_H_w03_05_01_a * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_01')
    
    BW_1.theta_0 = 'theta_BW1'
    BW_1.radius = '0.35'
    BW_1.yheight = 'h1_in'
    BW_1.nu = 'Freq_BW1'
    BW_1.nslit = '1'
    BW_1.jitter = '0'
    BW_1.delay = 'BW1_Delay'
    BW_1.isfirst = '0'
    BW_1.n_pulse = '1'
    BW_1.abs_out = '1'
    BW_1.phase = '0'
    BW_1.xwidth = '0'
    BW_1.verbose = '1'
    
    # Comp instance Lambda_BW1, placement and parameters
    Lambda_BW1 = instr.add_component('Lambda_BW1','L_monitor', AT=['0', '0', '0.001'], AT_RELATIVE='BW_1', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='BW_1')
    
    Lambda_BW1.nL = '1000'
    Lambda_BW1.filename = '"Lambda_BW1"'
    Lambda_BW1.nowritefile = '0'
    Lambda_BW1.xmin = '-0.05'
    Lambda_BW1.xmax = '0.05'
    Lambda_BW1.ymin = '-0.05'
    Lambda_BW1.ymax = '0.05'
    Lambda_BW1.xwidth = '0'
    Lambda_BW1.yheight = '0'
    Lambda_BW1.Lmin = '0.5'
    Lambda_BW1.Lmax = '100'
    Lambda_BW1.restore_neutron = '1'
    
    # Comp instance Arm8, placement and parameters
    Arm8 = instr.add_component('Arm8','Arm', AT=['dx_v_w03_05_01', '- dy_v_w03_05_01', 'dz_v_w03_05_01'], AT_RELATIVE='Guide_benderw03_05_01', ROTATED=['curve_ang_V_w03_05_01 * RAD2DEG', 'curve_ang_H_w03_05_01 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_01')
    
    
    # Comp instance Guide_benderw03_05_02, placement and parameters
    Guide_benderw03_05_02 = instr.add_component('Guide_benderw03_05_02','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm8', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm8')
    
    Guide_benderw03_05_02.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_02.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_02.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_02.xwidth = '0.07'
    Guide_benderw03_05_02.yheight = '0.055'
    Guide_benderw03_05_02.length = '0.8'
    Guide_benderw03_05_02.radius = '- ROC_V'
    Guide_benderw03_05_02.G = '9.8'
    Guide_benderw03_05_02.nchan = '1'
    Guide_benderw03_05_02.d = '0'
    Guide_benderw03_05_02.debug = '0'
    Guide_benderw03_05_02.endFlat = '0'
    Guide_benderw03_05_02.drawOption = '1'
    Guide_benderw03_05_02.alwaystrack = '0'
    Guide_benderw03_05_02.diststep1 = '0.020'
    Guide_benderw03_05_02.diststep2 = '0.002'
    Guide_benderw03_05_02.recurse_max = '1000'
    
    # Comp instance Arm9, placement and parameters
    Arm9 = instr.add_component('Arm9','Arm', AT=['dx_v_w03_05_02', '- dy_v_w03_05_02', 'dz_v_w03_05_02'], AT_RELATIVE='Guide_benderw03_05_02', ROTATED=['curve_ang_V_w03_05_02 * RAD2DEG', 'curve_ang_H_w03_05_02 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_02')
    
    
    # Comp instance Guide_benderw03_05_03, placement and parameters
    Guide_benderw03_05_03 = instr.add_component('Guide_benderw03_05_03','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm9', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm9')
    
    Guide_benderw03_05_03.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_03.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_03.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_03.xwidth = '0.07'
    Guide_benderw03_05_03.yheight = '0.055'
    Guide_benderw03_05_03.length = '1.9435'
    Guide_benderw03_05_03.radius = '- ROC_V'
    Guide_benderw03_05_03.G = '9.8'
    Guide_benderw03_05_03.nchan = '1'
    Guide_benderw03_05_03.d = '0'
    Guide_benderw03_05_03.debug = '0'
    Guide_benderw03_05_03.endFlat = '0'
    Guide_benderw03_05_03.drawOption = '1'
    Guide_benderw03_05_03.alwaystrack = '0'
    Guide_benderw03_05_03.diststep1 = '0.020'
    Guide_benderw03_05_03.diststep2 = '0.002'
    Guide_benderw03_05_03.recurse_max = '1000'
    
    # Comp instance Arm10, placement and parameters
    Arm10 = instr.add_component('Arm10','Arm', AT=['dx_v_w03_05_03', '- dy_v_w03_05_03', 'dz_v_w03_05_03'], AT_RELATIVE='Guide_benderw03_05_03', ROTATED=['curve_ang_V_w03_05_03 * RAD2DEG', 'curve_ang_H_w03_05_03 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_03')
    
    
    # Comp instance Guide_benderw03_05_04, placement and parameters
    Guide_benderw03_05_04 = instr.add_component('Guide_benderw03_05_04','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm10', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm10')
    
    Guide_benderw03_05_04.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_04.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_04.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_04.xwidth = '0.07'
    Guide_benderw03_05_04.yheight = '0.055'
    Guide_benderw03_05_04.length = '1.9435'
    Guide_benderw03_05_04.radius = '- ROC_V'
    Guide_benderw03_05_04.G = '9.8'
    Guide_benderw03_05_04.nchan = '1'
    Guide_benderw03_05_04.d = '0'
    Guide_benderw03_05_04.debug = '0'
    Guide_benderw03_05_04.endFlat = '0'
    Guide_benderw03_05_04.drawOption = '1'
    Guide_benderw03_05_04.alwaystrack = '0'
    Guide_benderw03_05_04.diststep1 = '0.020'
    Guide_benderw03_05_04.diststep2 = '0.002'
    Guide_benderw03_05_04.recurse_max = '1000'
    
    # Comp instance Arm11, placement and parameters
    Arm11 = instr.add_component('Arm11','Arm', AT=['dx_v_w03_05_04', '- dy_v_w03_05_04', 'dz_v_w03_05_04'], AT_RELATIVE='Guide_benderw03_05_04', ROTATED=['curve_ang_V_w03_05_04 * RAD2DEG', 'curve_ang_H_w03_05_04 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_04')
    
    
    # Comp instance Guide_benderw03_05_05, placement and parameters
    Guide_benderw03_05_05 = instr.add_component('Guide_benderw03_05_05','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm11', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm11')
    
    Guide_benderw03_05_05.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_05.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_05.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_05.xwidth = '0.07'
    Guide_benderw03_05_05.yheight = '0.055'
    Guide_benderw03_05_05.length = '0.8'
    Guide_benderw03_05_05.radius = '- ROC_V'
    Guide_benderw03_05_05.G = '9.8'
    Guide_benderw03_05_05.nchan = '1'
    Guide_benderw03_05_05.d = '0'
    Guide_benderw03_05_05.debug = '0'
    Guide_benderw03_05_05.endFlat = '0'
    Guide_benderw03_05_05.drawOption = '1'
    Guide_benderw03_05_05.alwaystrack = '0'
    Guide_benderw03_05_05.diststep1 = '0.020'
    Guide_benderw03_05_05.diststep2 = '0.002'
    Guide_benderw03_05_05.recurse_max = '1000'
    
    # Comp instance BW_2, placement and parameters
    BW_2 = instr.add_component('BW_2','DiskChopper', AT=['dx_v_w03_05_05_a', '- dy_v_w03_05_05_a', 'dz_v_w03_05_05_a'], AT_RELATIVE='Guide_benderw03_05_05', ROTATED=['curve_ang_V_w03_05_05_a * RAD2DEG', 'curve_ang_H_w03_05_05_a * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_05')
    
    BW_2.theta_0 = 'theta_BW2'
    BW_2.radius = '0.35'
    BW_2.yheight = 'h1_in'
    BW_2.nu = 'Freq_BW2'
    BW_2.nslit = '1'
    BW_2.jitter = '0'
    BW_2.delay = 'BW2_Delay'
    BW_2.isfirst = '0'
    BW_2.n_pulse = '1'
    BW_2.abs_out = '1'
    BW_2.phase = '0'
    BW_2.xwidth = '0'
    BW_2.verbose = '1'
    
    # Comp instance Lambda_BW2, placement and parameters
    Lambda_BW2 = instr.add_component('Lambda_BW2','L_monitor', AT=['0', '0', '0.001'], AT_RELATIVE='BW_2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='BW_2')
    
    Lambda_BW2.nL = '1000'
    Lambda_BW2.filename = '"Lambda_BW2"'
    Lambda_BW2.nowritefile = '0'
    Lambda_BW2.xmin = '-0.05'
    Lambda_BW2.xmax = '0.05'
    Lambda_BW2.ymin = '-0.05'
    Lambda_BW2.ymax = '0.05'
    Lambda_BW2.xwidth = '0'
    Lambda_BW2.yheight = '0'
    Lambda_BW2.Lmin = '0.5'
    Lambda_BW2.Lmax = '100'
    Lambda_BW2.restore_neutron = '1'
    
    # Comp instance Arm12, placement and parameters
    Arm12 = instr.add_component('Arm12','Arm', AT=['dx_v_w03_05_05', '- dy_v_w03_05_05', 'dz_v_w03_05_05'], AT_RELATIVE='Guide_benderw03_05_05', ROTATED=['curve_ang_V_w03_05_05 * RAD2DEG', 'curve_ang_H_w03_05_05 * RAD2DEG', '0'], ROTATED_RELATIVE='Lambda_BW2')
    
    
    # Comp instance Guide_benderw03_05_06, placement and parameters
    Guide_benderw03_05_06 = instr.add_component('Guide_benderw03_05_06','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm12', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm12')
    
    Guide_benderw03_05_06.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_06.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_06.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_06.xwidth = '0.07'
    Guide_benderw03_05_06.yheight = '0.055'
    Guide_benderw03_05_06.length = '0.8'
    Guide_benderw03_05_06.radius = '- ROC_V'
    Guide_benderw03_05_06.G = '9.8'
    Guide_benderw03_05_06.nchan = '1'
    Guide_benderw03_05_06.d = '0'
    Guide_benderw03_05_06.debug = '0'
    Guide_benderw03_05_06.endFlat = '0'
    Guide_benderw03_05_06.drawOption = '1'
    Guide_benderw03_05_06.alwaystrack = '0'
    Guide_benderw03_05_06.diststep1 = '0.020'
    Guide_benderw03_05_06.diststep2 = '0.002'
    Guide_benderw03_05_06.recurse_max = '1000'
    
    # Comp instance Arm13, placement and parameters
    Arm13 = instr.add_component('Arm13','Arm', AT=['dx_v_w03_05_06', '- dy_v_w03_05_06', 'dz_v_w03_05_06'], AT_RELATIVE='Guide_benderw03_05_06', ROTATED=['curve_ang_V_w03_05_06 * RAD2DEG', 'curve_ang_H_w03_05_06 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_06')
    
    
    # Comp instance Guide_benderw03_05_07, placement and parameters
    Guide_benderw03_05_07 = instr.add_component('Guide_benderw03_05_07','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm13', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm13')
    
    Guide_benderw03_05_07.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_07.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_07.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_07.xwidth = '0.07'
    Guide_benderw03_05_07.yheight = '0.055'
    Guide_benderw03_05_07.length = '1.453'
    Guide_benderw03_05_07.radius = '- ROC_V'
    Guide_benderw03_05_07.G = '9.8'
    Guide_benderw03_05_07.nchan = '1'
    Guide_benderw03_05_07.d = '0'
    Guide_benderw03_05_07.debug = '0'
    Guide_benderw03_05_07.endFlat = '0'
    Guide_benderw03_05_07.drawOption = '1'
    Guide_benderw03_05_07.alwaystrack = '0'
    Guide_benderw03_05_07.diststep1 = '0.020'
    Guide_benderw03_05_07.diststep2 = '0.002'
    Guide_benderw03_05_07.recurse_max = '1000'
    
    # Comp instance Arm14, placement and parameters
    Arm14 = instr.add_component('Arm14','Arm', AT=['dx_v_w03_05_07', '- dy_v_w03_05_07', 'dz_v_w03_05_07'], AT_RELATIVE='Guide_benderw03_05_07', ROTATED=['curve_ang_V_w03_05_07 * RAD2DEG', 'curve_ang_H_w03_05_07 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_07')
    
    
    # Comp instance Guide_benderw03_05_08, placement and parameters
    Guide_benderw03_05_08 = instr.add_component('Guide_benderw03_05_08','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm14', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm14')
    
    Guide_benderw03_05_08.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_08.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_08.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_08.xwidth = '0.07'
    Guide_benderw03_05_08.yheight = '0.055'
    Guide_benderw03_05_08.length = '1.453'
    Guide_benderw03_05_08.radius = '- ROC_V'
    Guide_benderw03_05_08.G = '9.8'
    Guide_benderw03_05_08.nchan = '1'
    Guide_benderw03_05_08.d = '0'
    Guide_benderw03_05_08.debug = '0'
    Guide_benderw03_05_08.endFlat = '0'
    Guide_benderw03_05_08.drawOption = '1'
    Guide_benderw03_05_08.alwaystrack = '0'
    Guide_benderw03_05_08.diststep1 = '0.020'
    Guide_benderw03_05_08.diststep2 = '0.002'
    Guide_benderw03_05_08.recurse_max = '1000'
    
    # Comp instance Arm15, placement and parameters
    Arm15 = instr.add_component('Arm15','Arm', AT=['dx_v_w03_05_08', '- dy_v_w03_05_08', 'dz_v_w03_05_08'], AT_RELATIVE='Guide_benderw03_05_08', ROTATED=['curve_ang_V_w03_05_08 * RAD2DEG', 'curve_ang_H_w03_05_08 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_08')
    
    
    # Comp instance Guide_benderw03_05_09, placement and parameters
    Guide_benderw03_05_09 = instr.add_component('Guide_benderw03_05_09','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm15', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm15')
    
    Guide_benderw03_05_09.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_09.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_09.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_09.xwidth = '0.07'
    Guide_benderw03_05_09.yheight = '0.055'
    Guide_benderw03_05_09.length = '2.040'
    Guide_benderw03_05_09.radius = '- ROC_V'
    Guide_benderw03_05_09.G = '9.8'
    Guide_benderw03_05_09.nchan = '1'
    Guide_benderw03_05_09.d = '0'
    Guide_benderw03_05_09.debug = '0'
    Guide_benderw03_05_09.endFlat = '0'
    Guide_benderw03_05_09.drawOption = '1'
    Guide_benderw03_05_09.alwaystrack = '0'
    Guide_benderw03_05_09.diststep1 = '0.020'
    Guide_benderw03_05_09.diststep2 = '0.002'
    Guide_benderw03_05_09.recurse_max = '1000'
    
    # Comp instance Arm16, placement and parameters
    Arm16 = instr.add_component('Arm16','Arm', AT=['dx_v_w03_05_09', '- dy_v_w03_05_09', 'dz_v_w03_05_09'], AT_RELATIVE='Guide_benderw03_05_09', ROTATED=['curve_ang_V_w03_05_09 * RAD2DEG', 'curve_ang_H_w03_05_09 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_09')
    
    
    # Comp instance Guide_benderw03_05_10, placement and parameters
    Guide_benderw03_05_10 = instr.add_component('Guide_benderw03_05_10','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm16', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm16')
    
    Guide_benderw03_05_10.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_10.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_05_10.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_05_10.xwidth = '0.07'
    Guide_benderw03_05_10.yheight = '0.055'
    Guide_benderw03_05_10.length = '1.65'
    Guide_benderw03_05_10.radius = '- ROC_V'
    Guide_benderw03_05_10.G = '9.8'
    Guide_benderw03_05_10.nchan = '1'
    Guide_benderw03_05_10.d = '0'
    Guide_benderw03_05_10.debug = '0'
    Guide_benderw03_05_10.endFlat = '0'
    Guide_benderw03_05_10.drawOption = '1'
    Guide_benderw03_05_10.alwaystrack = '0'
    Guide_benderw03_05_10.diststep1 = '0.020'
    Guide_benderw03_05_10.diststep2 = '0.002'
    Guide_benderw03_05_10.recurse_max = '1000'
    
    # Comp instance Arm17, placement and parameters
    Arm17 = instr.add_component('Arm17','Arm', AT=['dx_v_w03_05_10', '- dy_v_w03_05_10', 'dz_v_w03_05_10'], AT_RELATIVE='Guide_benderw03_05_10', ROTATED=['curve_ang_V_w03_05_10 * RAD2DEG', 'curve_ang_H_w03_05_10 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_05_10')
    
    
    # Comp instance Guide_benderw03_06_011, placement and parameters
    Guide_benderw03_06_011 = instr.add_component('Guide_benderw03_06_011','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm17', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm17')
    
    Guide_benderw03_06_011.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_011.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_011.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_011.xwidth = '0.07'
    Guide_benderw03_06_011.yheight = '0.055'
    Guide_benderw03_06_011.length = '0.4906'
    Guide_benderw03_06_011.radius = '- ROC_V'
    Guide_benderw03_06_011.G = '9.8'
    Guide_benderw03_06_011.nchan = '1'
    Guide_benderw03_06_011.d = '0'
    Guide_benderw03_06_011.debug = '0'
    Guide_benderw03_06_011.endFlat = '0'
    Guide_benderw03_06_011.drawOption = '1'
    Guide_benderw03_06_011.alwaystrack = '0'
    Guide_benderw03_06_011.diststep1 = '0.020'
    Guide_benderw03_06_011.diststep2 = '0.002'
    Guide_benderw03_06_011.recurse_max = '1000'
    
    # Comp instance Arm18, placement and parameters
    Arm18 = instr.add_component('Arm18','Arm', AT=['dx_v_w03_06_011', '- dy_v_w03_06_011', 'dz_v_w03_06_011'], AT_RELATIVE='Guide_benderw03_06_011', ROTATED=['curve_ang_V_w03_06_011 * RAD2DEG', 'curve_ang_H_w03_06_011 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_011')
    
    
    # Comp instance Guide_benderw03_06_012, placement and parameters
    Guide_benderw03_06_012 = instr.add_component('Guide_benderw03_06_012','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm18', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm18')
    
    Guide_benderw03_06_012.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_012.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_012.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_012.xwidth = '0.07'
    Guide_benderw03_06_012.yheight = '0.055'
    Guide_benderw03_06_012.length = '1.982'
    Guide_benderw03_06_012.radius = '- ROC_V'
    Guide_benderw03_06_012.G = '9.8'
    Guide_benderw03_06_012.nchan = '1'
    Guide_benderw03_06_012.d = '0'
    Guide_benderw03_06_012.debug = '0'
    Guide_benderw03_06_012.endFlat = '0'
    Guide_benderw03_06_012.drawOption = '1'
    Guide_benderw03_06_012.alwaystrack = '0'
    Guide_benderw03_06_012.diststep1 = '0.020'
    Guide_benderw03_06_012.diststep2 = '0.002'
    Guide_benderw03_06_012.recurse_max = '1000'
    
    # Comp instance Arm19, placement and parameters
    Arm19 = instr.add_component('Arm19','Arm', AT=['dx_v_w03_06_012', '- dy_v_w03_06_012', 'dz_v_w03_06_012'], AT_RELATIVE='Guide_benderw03_06_012', ROTATED=['- curve_ang_V_w03_06_12 * RAD2DEG', 'curve_ang_H_w03_06_12 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_012')
    
    
    # Comp instance Guide_benderw03_06_02, placement and parameters
    Guide_benderw03_06_02 = instr.add_component('Guide_benderw03_06_02','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm19', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm19')
    
    Guide_benderw03_06_02.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_02.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_02.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_02.xwidth = '0.07'
    Guide_benderw03_06_02.yheight = '0.055'
    Guide_benderw03_06_02.length = '2.0'
    Guide_benderw03_06_02.radius = '- ROC_V'
    Guide_benderw03_06_02.G = '9.8'
    Guide_benderw03_06_02.nchan = '1'
    Guide_benderw03_06_02.d = '0'
    Guide_benderw03_06_02.debug = '0'
    Guide_benderw03_06_02.endFlat = '0'
    Guide_benderw03_06_02.drawOption = '1'
    Guide_benderw03_06_02.alwaystrack = '0'
    Guide_benderw03_06_02.diststep1 = '0.020'
    Guide_benderw03_06_02.diststep2 = '0.002'
    Guide_benderw03_06_02.recurse_max = '1000'
    
    # Comp instance Arm20, placement and parameters
    Arm20 = instr.add_component('Arm20','Arm', AT=['dx_v_w03_06_02', '- dy_v_w03_06_02', 'dz_v_w03_06_02'], AT_RELATIVE='Guide_benderw03_06_02', ROTATED=['- curve_ang_V_w03_06_02 * RAD2DEG', 'curve_ang_H_w03_06_02 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_02')
    
    
    # Comp instance Guide_benderw03_06_03, placement and parameters
    Guide_benderw03_06_03 = instr.add_component('Guide_benderw03_06_03','Vertical_Bender', AT=['0', '0', '0.001'], AT_RELATIVE='Arm20', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm20')
    
    Guide_benderw03_06_03.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_03.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_03.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_03.xwidth = '0.07'
    Guide_benderw03_06_03.yheight = '0.055'
    Guide_benderw03_06_03.length = '2.0'
    Guide_benderw03_06_03.radius = '- ROC_V'
    Guide_benderw03_06_03.G = '9.8'
    Guide_benderw03_06_03.nchan = '1'
    Guide_benderw03_06_03.d = '0'
    Guide_benderw03_06_03.debug = '0'
    Guide_benderw03_06_03.endFlat = '0'
    Guide_benderw03_06_03.drawOption = '1'
    Guide_benderw03_06_03.alwaystrack = '0'
    Guide_benderw03_06_03.diststep1 = '0.020'
    Guide_benderw03_06_03.diststep2 = '0.002'
    Guide_benderw03_06_03.recurse_max = '1000'
    
    # Comp instance Arm21, placement and parameters
    Arm21 = instr.add_component('Arm21','Arm', AT=['dx_v_w03_06_03', '- dy_v_w03_06_03', 'dz_v_w03_06_03'], AT_RELATIVE='Guide_benderw03_06_03', ROTATED=['- curve_ang_V_w03_06_02 * RAD2DEG', 'curve_ang_H_w03_06_02 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_03')
    
    
    # Comp instance Guide_benderw03_06_04, placement and parameters
    Guide_benderw03_06_04 = instr.add_component('Guide_benderw03_06_04','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm21', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm21')
    
    Guide_benderw03_06_04.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_04.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_04.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_04.xwidth = '0.07'
    Guide_benderw03_06_04.yheight = '0.055'
    Guide_benderw03_06_04.length = '2.0'
    Guide_benderw03_06_04.radius = '- ROC_V'
    Guide_benderw03_06_04.G = '9.8'
    Guide_benderw03_06_04.nchan = '1'
    Guide_benderw03_06_04.d = '0'
    Guide_benderw03_06_04.debug = '0'
    Guide_benderw03_06_04.endFlat = '0'
    Guide_benderw03_06_04.drawOption = '1'
    Guide_benderw03_06_04.alwaystrack = '0'
    Guide_benderw03_06_04.diststep1 = '0.020'
    Guide_benderw03_06_04.diststep2 = '0.002'
    Guide_benderw03_06_04.recurse_max = '1000'
    
    # Comp instance Arm22, placement and parameters
    Arm22 = instr.add_component('Arm22','Arm', AT=['dx_v_w03_06_04', '- dy_v_w03_06_04', 'dz_v_w03_06_04'], AT_RELATIVE='Guide_benderw03_06_04', ROTATED=['- curve_ang_V_w03_06_04 * RAD2DEG', 'curve_ang_H_w03_06_04 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_04')
    
    
    # Comp instance Guide_benderw03_06_05, placement and parameters
    Guide_benderw03_06_05 = instr.add_component('Guide_benderw03_06_05','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm22', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm22')
    
    Guide_benderw03_06_05.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_05.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_05.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_05.xwidth = '0.07'
    Guide_benderw03_06_05.yheight = '0.055'
    Guide_benderw03_06_05.length = '2.0'
    Guide_benderw03_06_05.radius = '- ROC_V'
    Guide_benderw03_06_05.G = '9.8'
    Guide_benderw03_06_05.nchan = '1'
    Guide_benderw03_06_05.d = '0'
    Guide_benderw03_06_05.debug = '0'
    Guide_benderw03_06_05.endFlat = '0'
    Guide_benderw03_06_05.drawOption = '1'
    Guide_benderw03_06_05.alwaystrack = '0'
    Guide_benderw03_06_05.diststep1 = '0.020'
    Guide_benderw03_06_05.diststep2 = '0.002'
    Guide_benderw03_06_05.recurse_max = '1000'
    
    # Comp instance Arm23, placement and parameters
    Arm23 = instr.add_component('Arm23','Arm', AT=['dx_v_w03_06_05', '- dy_v_w03_06_05', 'dz_v_w03_06_05'], AT_RELATIVE='Guide_benderw03_06_05', ROTATED=['- curve_ang_V_w03_06_05 * RAD2DEG', 'curve_ang_H_w03_06_05 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_05')
    
    
    # Comp instance Guide_benderw03_06_06, placement and parameters
    Guide_benderw03_06_06 = instr.add_component('Guide_benderw03_06_06','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm23', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm23')
    
    Guide_benderw03_06_06.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_06.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_06.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_06.xwidth = '0.07'
    Guide_benderw03_06_06.yheight = '0.055'
    Guide_benderw03_06_06.length = '2.0'
    Guide_benderw03_06_06.radius = '- ROC_V'
    Guide_benderw03_06_06.G = '9.8'
    Guide_benderw03_06_06.nchan = '1'
    Guide_benderw03_06_06.d = '0'
    Guide_benderw03_06_06.debug = '0'
    Guide_benderw03_06_06.endFlat = '0'
    Guide_benderw03_06_06.drawOption = '1'
    Guide_benderw03_06_06.alwaystrack = '0'
    Guide_benderw03_06_06.diststep1 = '0.020'
    Guide_benderw03_06_06.diststep2 = '0.002'
    Guide_benderw03_06_06.recurse_max = '1000'
    
    # Comp instance Arm24, placement and parameters
    Arm24 = instr.add_component('Arm24','Arm', AT=['dx_v_w03_06_06', '- dy_v_w03_06_06', 'dz_v_w03_06_06'], AT_RELATIVE='Guide_benderw03_06_06', ROTATED=['- curve_ang_V_w03_06_06 * RAD2DEG', 'curve_ang_H_w03_06_06 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_06')
    
    
    # Comp instance Guide_benderw03_06_07, placement and parameters
    Guide_benderw03_06_07 = instr.add_component('Guide_benderw03_06_07','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm24', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm24')
    
    Guide_benderw03_06_07.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_07.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_07.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_07.xwidth = '0.07'
    Guide_benderw03_06_07.yheight = '0.055'
    Guide_benderw03_06_07.length = '2.0'
    Guide_benderw03_06_07.radius = '- ROC_V'
    Guide_benderw03_06_07.G = '9.8'
    Guide_benderw03_06_07.nchan = '1'
    Guide_benderw03_06_07.d = '0'
    Guide_benderw03_06_07.debug = '0'
    Guide_benderw03_06_07.endFlat = '0'
    Guide_benderw03_06_07.drawOption = '1'
    Guide_benderw03_06_07.alwaystrack = '0'
    Guide_benderw03_06_07.diststep1 = '0.020'
    Guide_benderw03_06_07.diststep2 = '0.002'
    Guide_benderw03_06_07.recurse_max = '1000'
    
    # Comp instance Arm25, placement and parameters
    Arm25 = instr.add_component('Arm25','Arm', AT=['dx_v_w03_06_07', '- dy_v_w03_06_07', 'dz_v_w03_06_07'], AT_RELATIVE='Guide_benderw03_06_07', ROTATED=['- curve_ang_V_w03_06_07 * RAD2DEG', 'curve_ang_H_w03_06_07 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_07')
    
    
    # Comp instance Guide_benderw03_06_08, placement and parameters
    Guide_benderw03_06_08 = instr.add_component('Guide_benderw03_06_08','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm25', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm25')
    
    Guide_benderw03_06_08.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_08.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_08.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_08.xwidth = '0.07'
    Guide_benderw03_06_08.yheight = '0.055'
    Guide_benderw03_06_08.length = '2.0'
    Guide_benderw03_06_08.radius = '- ROC_V'
    Guide_benderw03_06_08.G = '9.8'
    Guide_benderw03_06_08.nchan = '1'
    Guide_benderw03_06_08.d = '0'
    Guide_benderw03_06_08.debug = '0'
    Guide_benderw03_06_08.endFlat = '0'
    Guide_benderw03_06_08.drawOption = '1'
    Guide_benderw03_06_08.alwaystrack = '0'
    Guide_benderw03_06_08.diststep1 = '0.020'
    Guide_benderw03_06_08.diststep2 = '0.002'
    Guide_benderw03_06_08.recurse_max = '1000'
    
    # Comp instance Arm26, placement and parameters
    Arm26 = instr.add_component('Arm26','Arm', AT=['dx_v_w03_06_08', '- dy_v_w03_06_08', 'dz_v_w03_06_08'], AT_RELATIVE='Guide_benderw03_06_08', ROTATED=['- curve_ang_V_w03_06_08 * RAD2DEG', 'curve_ang_H_w03_06_08 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_08')
    
    
    # Comp instance Guide_benderw03_06_09, placement and parameters
    Guide_benderw03_06_09 = instr.add_component('Guide_benderw03_06_09','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm26', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm26')
    
    Guide_benderw03_06_09.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_09.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_09.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_09.xwidth = '0.07'
    Guide_benderw03_06_09.yheight = '0.055'
    Guide_benderw03_06_09.length = '2.0'
    Guide_benderw03_06_09.radius = '- ROC_V'
    Guide_benderw03_06_09.G = '9.8'
    Guide_benderw03_06_09.nchan = '1'
    Guide_benderw03_06_09.d = '0'
    Guide_benderw03_06_09.debug = '0'
    Guide_benderw03_06_09.endFlat = '0'
    Guide_benderw03_06_09.drawOption = '1'
    Guide_benderw03_06_09.alwaystrack = '0'
    Guide_benderw03_06_09.diststep1 = '0.020'
    Guide_benderw03_06_09.diststep2 = '0.002'
    Guide_benderw03_06_09.recurse_max = '1000'
    
    # Comp instance Arm27, placement and parameters
    Arm27 = instr.add_component('Arm27','Arm', AT=['dx_v_w03_06_09', '- dy_v_w03_06_09', 'dz_v_w03_06_09'], AT_RELATIVE='Guide_benderw03_06_09', ROTATED=['- curve_ang_V_w03_06_09 * RAD2DEG', 'curve_ang_H_w03_06_09 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_09')
    
    
    # Comp instance Guide_benderw03_06_10, placement and parameters
    Guide_benderw03_06_10 = instr.add_component('Guide_benderw03_06_10','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm27', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm27')
    
    Guide_benderw03_06_10.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_10.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_10.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_10.xwidth = '0.07'
    Guide_benderw03_06_10.yheight = '0.055'
    Guide_benderw03_06_10.length = '2.0'
    Guide_benderw03_06_10.radius = '- ROC_V'
    Guide_benderw03_06_10.G = '9.8'
    Guide_benderw03_06_10.nchan = '1'
    Guide_benderw03_06_10.d = '0'
    Guide_benderw03_06_10.debug = '0'
    Guide_benderw03_06_10.endFlat = '0'
    Guide_benderw03_06_10.drawOption = '1'
    Guide_benderw03_06_10.alwaystrack = '0'
    Guide_benderw03_06_10.diststep1 = '0.020'
    Guide_benderw03_06_10.diststep2 = '0.002'
    Guide_benderw03_06_10.recurse_max = '1000'
    
    # Comp instance Arm28, placement and parameters
    Arm28 = instr.add_component('Arm28','Arm', AT=['dx_v_w03_06_10', '- dy_v_w03_06_10', 'dz_v_w03_06_10'], AT_RELATIVE='Guide_benderw03_06_10', ROTATED=['- curve_ang_V_w03_06_10 * RAD2DEG', 'curve_ang_H_w03_06_10 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_10')
    
    
    # Comp instance Guide_benderw03_06_11, placement and parameters
    Guide_benderw03_06_11 = instr.add_component('Guide_benderw03_06_11','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm28', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm28')
    
    Guide_benderw03_06_11.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_11.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_11.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_11.xwidth = '0.07'
    Guide_benderw03_06_11.yheight = '0.055'
    Guide_benderw03_06_11.length = '2.0'
    Guide_benderw03_06_11.radius = '- ROC_V'
    Guide_benderw03_06_11.G = '9.8'
    Guide_benderw03_06_11.nchan = '1'
    Guide_benderw03_06_11.d = '0'
    Guide_benderw03_06_11.debug = '0'
    Guide_benderw03_06_11.endFlat = '0'
    Guide_benderw03_06_11.drawOption = '1'
    Guide_benderw03_06_11.alwaystrack = '0'
    Guide_benderw03_06_11.diststep1 = '0.020'
    Guide_benderw03_06_11.diststep2 = '0.002'
    Guide_benderw03_06_11.recurse_max = '1000'
    
    # Comp instance Arm29, placement and parameters
    Arm29 = instr.add_component('Arm29','Arm', AT=['dx_v_w03_06_11', '- dy_v_w03_06_11', 'dz_v_w03_06_11'], AT_RELATIVE='Guide_benderw03_06_11', ROTATED=['- curve_ang_V_w03_06_11 * RAD2DEG', 'curve_ang_H_w03_06_11 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_11')
    
    
    # Comp instance Guide_benderw03_06_12, placement and parameters
    Guide_benderw03_06_12 = instr.add_component('Guide_benderw03_06_12','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm29', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm29')
    
    Guide_benderw03_06_12.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_12.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_12.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_12.xwidth = '0.07'
    Guide_benderw03_06_12.yheight = '0.055'
    Guide_benderw03_06_12.length = '2.0'
    Guide_benderw03_06_12.radius = '- ROC_V'
    Guide_benderw03_06_12.G = '9.8'
    Guide_benderw03_06_12.nchan = '1'
    Guide_benderw03_06_12.d = '0'
    Guide_benderw03_06_12.debug = '0'
    Guide_benderw03_06_12.endFlat = '0'
    Guide_benderw03_06_12.drawOption = '1'
    Guide_benderw03_06_12.alwaystrack = '0'
    Guide_benderw03_06_12.diststep1 = '0.020'
    Guide_benderw03_06_12.diststep2 = '0.002'
    Guide_benderw03_06_12.recurse_max = '1000'
    
    # Comp instance Arm30, placement and parameters
    Arm30 = instr.add_component('Arm30','Arm', AT=['dx_v_w03_06_12', '- dy_v_w03_06_12', 'dz_v_w03_06_12'], AT_RELATIVE='Guide_benderw03_06_12', ROTATED=['- curve_ang_V_w03_06_12 * RAD2DEG', 'curve_ang_H_w03_06_12 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_12')
    
    
    # Comp instance Guide_benderw03_06_13, placement and parameters
    Guide_benderw03_06_13 = instr.add_component('Guide_benderw03_06_13','Vertical_Bender', AT=['0', '0', '1e-6'], AT_RELATIVE='Arm30', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm30')
    
    Guide_benderw03_06_13.rTopPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_13.rBottomPar = '{ 0.99 , 0.0219 , 6.07 , 3.5 , 0.001 }'
    Guide_benderw03_06_13.rSidesPar = '{ 0.99 , 0.0219 , 6.07 , 3.0 , 0.001 }'
    Guide_benderw03_06_13.xwidth = '0.07'
    Guide_benderw03_06_13.yheight = '0.055'
    Guide_benderw03_06_13.length = '2.0'
    Guide_benderw03_06_13.radius = '- ROC_V'
    Guide_benderw03_06_13.G = '9.8'
    Guide_benderw03_06_13.nchan = '1'
    Guide_benderw03_06_13.d = '0'
    Guide_benderw03_06_13.debug = '0'
    Guide_benderw03_06_13.endFlat = '0'
    Guide_benderw03_06_13.drawOption = '1'
    Guide_benderw03_06_13.alwaystrack = '0'
    Guide_benderw03_06_13.diststep1 = '0.020'
    Guide_benderw03_06_13.diststep2 = '0.002'
    Guide_benderw03_06_13.recurse_max = '1000'
    
    # Comp instance Arm31, placement and parameters
    Arm31 = instr.add_component('Arm31','Arm', AT=['dx_v_w03_06_13', '- dy_v_w03_06_13', 'dz_v_w03_06_13'], AT_RELATIVE='Guide_benderw03_06_13', ROTATED=['- curve_ang_V_w03_06_13 * RAD2DEG', 'curve_ang_H_w03_06_13 * RAD2DEG', '0'], ROTATED_RELATIVE='Guide_benderw03_06_13')
    
    
    # Comp instance Guide_w03_06_14, placement and parameters
    Guide_w03_06_14 = instr.add_component('Guide_w03_06_14','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm31', ROTATED=['curve_ang_V_w03_06_14 * RAD2DEG * 0.135', 'curve_ang_H_w03_06_14 * RAD2DEG', '0'], ROTATED_RELATIVE='Arm31')
    
    Guide_w03_06_14.w1 = '0.07'
    Guide_w03_06_14.h1 = '0.055'
    Guide_w03_06_14.w2 = '0.08411'
    Guide_w03_06_14.h2 = '0.06837'
    Guide_w03_06_14.l = '2.0'
    Guide_w03_06_14.R0 = '0.99'
    Guide_w03_06_14.Qc = '0.0219'
    Guide_w03_06_14.alpha = '6.07'
    Guide_w03_06_14.m = '1.0'
    Guide_w03_06_14.W = '0.003'
    Guide_w03_06_14.nslit = '1'
    Guide_w03_06_14.d = '0.0005'
    Guide_w03_06_14.mleft = '2'
    Guide_w03_06_14.mright = '2'
    Guide_w03_06_14.mtop = '2'
    Guide_w03_06_14.mbottom = '2'
    Guide_w03_06_14.nhslit = '1'
    Guide_w03_06_14.G = '0'
    Guide_w03_06_14.aleft = '-1'
    Guide_w03_06_14.aright = '-1'
    Guide_w03_06_14.atop = '-1'
    Guide_w03_06_14.abottom = '-1'
    Guide_w03_06_14.wavy = '0'
    Guide_w03_06_14.wavy_z = '0'
    Guide_w03_06_14.wavy_tb = '0'
    Guide_w03_06_14.wavy_lr = '0'
    Guide_w03_06_14.chamfers = '0'
    Guide_w03_06_14.chamfers_z = '0'
    Guide_w03_06_14.chamfers_lr = '0'
    Guide_w03_06_14.chamfers_tb = '0'
    Guide_w03_06_14.nelements = '1'
    Guide_w03_06_14.nu = '0'
    Guide_w03_06_14.phase = '0'
    Guide_w03_06_14.reflect = '"NULL"'
    
    # Comp instance Arm32, placement and parameters
    Arm32 = instr.add_component('Arm32','Arm', AT=['0', '0', '2 + 0.002'], AT_RELATIVE='Guide_w03_06_14', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_14')
    
    
    # Comp instance Guide_w03_06_15, placement and parameters
    Guide_w03_06_15 = instr.add_component('Guide_w03_06_15','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm32', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm32')
    
    Guide_w03_06_15.w1 = '0.08412'
    Guide_w03_06_15.h1 = '0.06838'
    Guide_w03_06_15.w2 = '0.09663'
    Guide_w03_06_15.h2 = '0.08073'
    Guide_w03_06_15.l = '2.4'
    Guide_w03_06_15.R0 = '0.99'
    Guide_w03_06_15.Qc = '0.0219'
    Guide_w03_06_15.alpha = '6.07'
    Guide_w03_06_15.m = '1.0'
    Guide_w03_06_15.W = '0.003'
    Guide_w03_06_15.nslit = '1'
    Guide_w03_06_15.d = '0.0005'
    Guide_w03_06_15.mleft = '2'
    Guide_w03_06_15.mright = '2'
    Guide_w03_06_15.mtop = '2'
    Guide_w03_06_15.mbottom = '2'
    Guide_w03_06_15.nhslit = '1'
    Guide_w03_06_15.G = '0'
    Guide_w03_06_15.aleft = '-1'
    Guide_w03_06_15.aright = '-1'
    Guide_w03_06_15.atop = '-1'
    Guide_w03_06_15.abottom = '-1'
    Guide_w03_06_15.wavy = '0'
    Guide_w03_06_15.wavy_z = '0'
    Guide_w03_06_15.wavy_tb = '0'
    Guide_w03_06_15.wavy_lr = '0'
    Guide_w03_06_15.chamfers = '0'
    Guide_w03_06_15.chamfers_z = '0'
    Guide_w03_06_15.chamfers_lr = '0'
    Guide_w03_06_15.chamfers_tb = '0'
    Guide_w03_06_15.nelements = '1'
    Guide_w03_06_15.nu = '0'
    Guide_w03_06_15.phase = '0'
    Guide_w03_06_15.reflect = '"NULL"'
    
    # Comp instance Arm33, placement and parameters
    Arm33 = instr.add_component('Arm33','Arm', AT=['0', '0', '2.4 + 0.001'], AT_RELATIVE='Guide_w03_06_15', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_15')
    
    
    # Comp instance Guide_w03_06_16, placement and parameters
    Guide_w03_06_16 = instr.add_component('Guide_w03_06_16','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm33', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm33')
    
    Guide_w03_06_16.w1 = '0.09664'
    Guide_w03_06_16.h1 = '0.08073'
    Guide_w03_06_16.w2 = '0.10594'
    Guide_w03_06_16.h2 = '0.0906'
    Guide_w03_06_16.l = '2.4'
    Guide_w03_06_16.R0 = '0.99'
    Guide_w03_06_16.Qc = '0.0219'
    Guide_w03_06_16.alpha = '6.07'
    Guide_w03_06_16.m = '1.0'
    Guide_w03_06_16.W = '0.003'
    Guide_w03_06_16.nslit = '1'
    Guide_w03_06_16.d = '0.0005'
    Guide_w03_06_16.mleft = '2'
    Guide_w03_06_16.mright = '2'
    Guide_w03_06_16.mtop = '2'
    Guide_w03_06_16.mbottom = '2'
    Guide_w03_06_16.nhslit = '1'
    Guide_w03_06_16.G = '0'
    Guide_w03_06_16.aleft = '-1'
    Guide_w03_06_16.aright = '-1'
    Guide_w03_06_16.atop = '-1'
    Guide_w03_06_16.abottom = '-1'
    Guide_w03_06_16.wavy = '0'
    Guide_w03_06_16.wavy_z = '0'
    Guide_w03_06_16.wavy_tb = '0'
    Guide_w03_06_16.wavy_lr = '0'
    Guide_w03_06_16.chamfers = '0'
    Guide_w03_06_16.chamfers_z = '0'
    Guide_w03_06_16.chamfers_lr = '0'
    Guide_w03_06_16.chamfers_tb = '0'
    Guide_w03_06_16.nelements = '1'
    Guide_w03_06_16.nu = '0'
    Guide_w03_06_16.phase = '0'
    Guide_w03_06_16.reflect = '"NULL"'
    
    # Comp instance Arm34, placement and parameters
    Arm34 = instr.add_component('Arm34','Arm', AT=['0', '0', '2.4 + 0.002'], AT_RELATIVE='Guide_w03_06_16', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_16')
    
    
    # Comp instance Guide_w03_06_17, placement and parameters
    Guide_w03_06_17 = instr.add_component('Guide_w03_06_17','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm34', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm34')
    
    Guide_w03_06_17.w1 = '0.10594'
    Guide_w03_06_17.h1 = '0.09061'
    Guide_w03_06_17.w2 = '0.11077'
    Guide_w03_06_17.h2 = '0.09620'
    Guide_w03_06_17.l = '1.6'
    Guide_w03_06_17.R0 = '0.99'
    Guide_w03_06_17.Qc = '0.0219'
    Guide_w03_06_17.alpha = '6.07'
    Guide_w03_06_17.m = '1.0'
    Guide_w03_06_17.W = '0.003'
    Guide_w03_06_17.nslit = '1'
    Guide_w03_06_17.d = '0.0005'
    Guide_w03_06_17.mleft = '2'
    Guide_w03_06_17.mright = '2'
    Guide_w03_06_17.mtop = '2'
    Guide_w03_06_17.mbottom = '2'
    Guide_w03_06_17.nhslit = '1'
    Guide_w03_06_17.G = '0'
    Guide_w03_06_17.aleft = '-1'
    Guide_w03_06_17.aright = '-1'
    Guide_w03_06_17.atop = '-1'
    Guide_w03_06_17.abottom = '-1'
    Guide_w03_06_17.wavy = '0'
    Guide_w03_06_17.wavy_z = '0'
    Guide_w03_06_17.wavy_tb = '0'
    Guide_w03_06_17.wavy_lr = '0'
    Guide_w03_06_17.chamfers = '0'
    Guide_w03_06_17.chamfers_z = '0'
    Guide_w03_06_17.chamfers_lr = '0'
    Guide_w03_06_17.chamfers_tb = '0'
    Guide_w03_06_17.nelements = '1'
    Guide_w03_06_17.nu = '0'
    Guide_w03_06_17.phase = '0'
    Guide_w03_06_17.reflect = '"NULL"'
    
    # Comp instance Arm35, placement and parameters
    Arm35 = instr.add_component('Arm35','Arm', AT=['0', '0', '1.6 + 0.001'], AT_RELATIVE='Guide_w03_06_17', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_17')
    
    
    # Comp instance Guide_w03_06_18, placement and parameters
    Guide_w03_06_18 = instr.add_component('Guide_w03_06_18','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm35', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm35')
    
    Guide_w03_06_18.w1 = '0.11077'
    Guide_w03_06_18.h1 = '0.0962'
    Guide_w03_06_18.w2 = '0.11466'
    Guide_w03_06_18.h2 = '0.10115'
    Guide_w03_06_18.l = '1.6'
    Guide_w03_06_18.R0 = '0.99'
    Guide_w03_06_18.Qc = '0.0219'
    Guide_w03_06_18.alpha = '6.07'
    Guide_w03_06_18.m = '1.0'
    Guide_w03_06_18.W = '0.003'
    Guide_w03_06_18.nslit = '1'
    Guide_w03_06_18.d = '0.0005'
    Guide_w03_06_18.mleft = '2'
    Guide_w03_06_18.mright = '2'
    Guide_w03_06_18.mtop = '2'
    Guide_w03_06_18.mbottom = '2'
    Guide_w03_06_18.nhslit = '1'
    Guide_w03_06_18.G = '0'
    Guide_w03_06_18.aleft = '-1'
    Guide_w03_06_18.aright = '-1'
    Guide_w03_06_18.atop = '-1'
    Guide_w03_06_18.abottom = '-1'
    Guide_w03_06_18.wavy = '0'
    Guide_w03_06_18.wavy_z = '0'
    Guide_w03_06_18.wavy_tb = '0'
    Guide_w03_06_18.wavy_lr = '0'
    Guide_w03_06_18.chamfers = '0'
    Guide_w03_06_18.chamfers_z = '0'
    Guide_w03_06_18.chamfers_lr = '0'
    Guide_w03_06_18.chamfers_tb = '0'
    Guide_w03_06_18.nelements = '1'
    Guide_w03_06_18.nu = '0'
    Guide_w03_06_18.phase = '0'
    Guide_w03_06_18.reflect = '"NULL"'
    
    # Comp instance Arm36, placement and parameters
    Arm36 = instr.add_component('Arm36','Arm', AT=['0', '0', '1.6 + 0.002'], AT_RELATIVE='Guide_w03_06_18', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_18')
    
    
    # Comp instance Guide_w03_06_19, placement and parameters
    Guide_w03_06_19 = instr.add_component('Guide_w03_06_19','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm36', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm36')
    
    Guide_w03_06_19.w1 = '0.11466'
    Guide_w03_06_19.h1 = '0.10116'
    Guide_w03_06_19.w2 = '0.11466'
    Guide_w03_06_19.h2 = '0.10658'
    Guide_w03_06_19.l = '2.0'
    Guide_w03_06_19.R0 = '0.99'
    Guide_w03_06_19.Qc = '0.0219'
    Guide_w03_06_19.alpha = '6.07'
    Guide_w03_06_19.m = '1.0'
    Guide_w03_06_19.W = '0.003'
    Guide_w03_06_19.nslit = '1'
    Guide_w03_06_19.d = '0.0005'
    Guide_w03_06_19.mleft = '2'
    Guide_w03_06_19.mright = '2'
    Guide_w03_06_19.mtop = '2'
    Guide_w03_06_19.mbottom = '2'
    Guide_w03_06_19.nhslit = '1'
    Guide_w03_06_19.G = '0'
    Guide_w03_06_19.aleft = '-1'
    Guide_w03_06_19.aright = '-1'
    Guide_w03_06_19.atop = '-1'
    Guide_w03_06_19.abottom = '-1'
    Guide_w03_06_19.wavy = '0'
    Guide_w03_06_19.wavy_z = '0'
    Guide_w03_06_19.wavy_tb = '0'
    Guide_w03_06_19.wavy_lr = '0'
    Guide_w03_06_19.chamfers = '0'
    Guide_w03_06_19.chamfers_z = '0'
    Guide_w03_06_19.chamfers_lr = '0'
    Guide_w03_06_19.chamfers_tb = '0'
    Guide_w03_06_19.nelements = '1'
    Guide_w03_06_19.nu = '0'
    Guide_w03_06_19.phase = '0'
    Guide_w03_06_19.reflect = '"NULL"'
    
    # Comp instance Arm37, placement and parameters
    Arm37 = instr.add_component('Arm37','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_19', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_19')
    
    
    # Comp instance Guide_w03_06_20, placement and parameters
    Guide_w03_06_20 = instr.add_component('Guide_w03_06_20','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm37', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm37')
    
    Guide_w03_06_20.w1 = '0.11466'
    Guide_w03_06_20.h1 = '0.10659'
    Guide_w03_06_20.w2 = '0.11466'
    Guide_w03_06_20.h2 = '0.11128'
    Guide_w03_06_20.l = '2.0'
    Guide_w03_06_20.R0 = '0.99'
    Guide_w03_06_20.Qc = '0.0219'
    Guide_w03_06_20.alpha = '6.07'
    Guide_w03_06_20.m = '1.0'
    Guide_w03_06_20.W = '0.003'
    Guide_w03_06_20.nslit = '1'
    Guide_w03_06_20.d = '0.0005'
    Guide_w03_06_20.mleft = '2'
    Guide_w03_06_20.mright = '2'
    Guide_w03_06_20.mtop = '2'
    Guide_w03_06_20.mbottom = '2'
    Guide_w03_06_20.nhslit = '1'
    Guide_w03_06_20.G = '0'
    Guide_w03_06_20.aleft = '-1'
    Guide_w03_06_20.aright = '-1'
    Guide_w03_06_20.atop = '-1'
    Guide_w03_06_20.abottom = '-1'
    Guide_w03_06_20.wavy = '0'
    Guide_w03_06_20.wavy_z = '0'
    Guide_w03_06_20.wavy_tb = '0'
    Guide_w03_06_20.wavy_lr = '0'
    Guide_w03_06_20.chamfers = '0'
    Guide_w03_06_20.chamfers_z = '0'
    Guide_w03_06_20.chamfers_lr = '0'
    Guide_w03_06_20.chamfers_tb = '0'
    Guide_w03_06_20.nelements = '1'
    Guide_w03_06_20.nu = '0'
    Guide_w03_06_20.phase = '0'
    Guide_w03_06_20.reflect = '"NULL"'
    
    # Comp instance Arm38, placement and parameters
    Arm38 = instr.add_component('Arm38','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_20', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_20')
    
    
    # Comp instance Guide_w03_06_21, placement and parameters
    Guide_w03_06_21 = instr.add_component('Guide_w03_06_21','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm38', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm38')
    
    Guide_w03_06_21.w1 = '0.11466'
    Guide_w03_06_21.h1 = '0.11128'
    Guide_w03_06_21.w2 = '0.11466'
    Guide_w03_06_21.h2 = '0.11128'
    Guide_w03_06_21.l = '2.0'
    Guide_w03_06_21.R0 = '0.99'
    Guide_w03_06_21.Qc = '0.0219'
    Guide_w03_06_21.alpha = '6.07'
    Guide_w03_06_21.m = '1.0'
    Guide_w03_06_21.W = '0.003'
    Guide_w03_06_21.nslit = '1'
    Guide_w03_06_21.d = '0.0005'
    Guide_w03_06_21.mleft = '2'
    Guide_w03_06_21.mright = '2'
    Guide_w03_06_21.mtop = '2'
    Guide_w03_06_21.mbottom = '2'
    Guide_w03_06_21.nhslit = '1'
    Guide_w03_06_21.G = '0'
    Guide_w03_06_21.aleft = '-1'
    Guide_w03_06_21.aright = '-1'
    Guide_w03_06_21.atop = '-1'
    Guide_w03_06_21.abottom = '-1'
    Guide_w03_06_21.wavy = '0'
    Guide_w03_06_21.wavy_z = '0'
    Guide_w03_06_21.wavy_tb = '0'
    Guide_w03_06_21.wavy_lr = '0'
    Guide_w03_06_21.chamfers = '0'
    Guide_w03_06_21.chamfers_z = '0'
    Guide_w03_06_21.chamfers_lr = '0'
    Guide_w03_06_21.chamfers_tb = '0'
    Guide_w03_06_21.nelements = '1'
    Guide_w03_06_21.nu = '0'
    Guide_w03_06_21.phase = '0'
    Guide_w03_06_21.reflect = '"NULL"'
    
    # Comp instance Arm39, placement and parameters
    Arm39 = instr.add_component('Arm39','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_21', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_21')
    
    
    # Comp instance Guide_w03_06_22, placement and parameters
    Guide_w03_06_22 = instr.add_component('Guide_w03_06_22','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm39', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm39')
    
    Guide_w03_06_22.w1 = '0.11466'
    Guide_w03_06_22.h1 = '0.11128'
    Guide_w03_06_22.w2 = '0.11466'
    Guide_w03_06_22.h2 = '0.11128'
    Guide_w03_06_22.l = '2.0'
    Guide_w03_06_22.R0 = '0.99'
    Guide_w03_06_22.Qc = '0.0219'
    Guide_w03_06_22.alpha = '6.07'
    Guide_w03_06_22.m = '1.0'
    Guide_w03_06_22.W = '0.003'
    Guide_w03_06_22.nslit = '1'
    Guide_w03_06_22.d = '0.0005'
    Guide_w03_06_22.mleft = '2'
    Guide_w03_06_22.mright = '2'
    Guide_w03_06_22.mtop = '2'
    Guide_w03_06_22.mbottom = '2'
    Guide_w03_06_22.nhslit = '1'
    Guide_w03_06_22.G = '0'
    Guide_w03_06_22.aleft = '-1'
    Guide_w03_06_22.aright = '-1'
    Guide_w03_06_22.atop = '-1'
    Guide_w03_06_22.abottom = '-1'
    Guide_w03_06_22.wavy = '0'
    Guide_w03_06_22.wavy_z = '0'
    Guide_w03_06_22.wavy_tb = '0'
    Guide_w03_06_22.wavy_lr = '0'
    Guide_w03_06_22.chamfers = '0'
    Guide_w03_06_22.chamfers_z = '0'
    Guide_w03_06_22.chamfers_lr = '0'
    Guide_w03_06_22.chamfers_tb = '0'
    Guide_w03_06_22.nelements = '1'
    Guide_w03_06_22.nu = '0'
    Guide_w03_06_22.phase = '0'
    Guide_w03_06_22.reflect = '"NULL"'
    
    # Comp instance Arm40, placement and parameters
    Arm40 = instr.add_component('Arm40','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_22', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_22')
    
    
    # Comp instance Guide_w03_06_23, placement and parameters
    Guide_w03_06_23 = instr.add_component('Guide_w03_06_23','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm40', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm40')
    
    Guide_w03_06_23.w1 = '0.11466'
    Guide_w03_06_23.h1 = '0.11128'
    Guide_w03_06_23.w2 = '0.11466'
    Guide_w03_06_23.h2 = '0.11128'
    Guide_w03_06_23.l = '2.0'
    Guide_w03_06_23.R0 = '0.99'
    Guide_w03_06_23.Qc = '0.0219'
    Guide_w03_06_23.alpha = '6.07'
    Guide_w03_06_23.m = '1.0'
    Guide_w03_06_23.W = '0.003'
    Guide_w03_06_23.nslit = '1'
    Guide_w03_06_23.d = '0.0005'
    Guide_w03_06_23.mleft = '2'
    Guide_w03_06_23.mright = '2'
    Guide_w03_06_23.mtop = '2'
    Guide_w03_06_23.mbottom = '2'
    Guide_w03_06_23.nhslit = '1'
    Guide_w03_06_23.G = '0'
    Guide_w03_06_23.aleft = '-1'
    Guide_w03_06_23.aright = '-1'
    Guide_w03_06_23.atop = '-1'
    Guide_w03_06_23.abottom = '-1'
    Guide_w03_06_23.wavy = '0'
    Guide_w03_06_23.wavy_z = '0'
    Guide_w03_06_23.wavy_tb = '0'
    Guide_w03_06_23.wavy_lr = '0'
    Guide_w03_06_23.chamfers = '0'
    Guide_w03_06_23.chamfers_z = '0'
    Guide_w03_06_23.chamfers_lr = '0'
    Guide_w03_06_23.chamfers_tb = '0'
    Guide_w03_06_23.nelements = '1'
    Guide_w03_06_23.nu = '0'
    Guide_w03_06_23.phase = '0'
    Guide_w03_06_23.reflect = '"NULL"'
    
    # Comp instance Arm41, placement and parameters
    Arm41 = instr.add_component('Arm41','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_23', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_23')
    
    
    # Comp instance Guide_w03_06_24, placement and parameters
    Guide_w03_06_24 = instr.add_component('Guide_w03_06_24','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm41', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm41')
    
    Guide_w03_06_24.w1 = '0.11466'
    Guide_w03_06_24.h1 = '0.11128'
    Guide_w03_06_24.w2 = '0.11466'
    Guide_w03_06_24.h2 = '0.11128'
    Guide_w03_06_24.l = '2.0'
    Guide_w03_06_24.R0 = '0.99'
    Guide_w03_06_24.Qc = '0.0219'
    Guide_w03_06_24.alpha = '6.07'
    Guide_w03_06_24.m = '1.0'
    Guide_w03_06_24.W = '0.003'
    Guide_w03_06_24.nslit = '1'
    Guide_w03_06_24.d = '0.0005'
    Guide_w03_06_24.mleft = '2'
    Guide_w03_06_24.mright = '2'
    Guide_w03_06_24.mtop = '2'
    Guide_w03_06_24.mbottom = '2'
    Guide_w03_06_24.nhslit = '1'
    Guide_w03_06_24.G = '0'
    Guide_w03_06_24.aleft = '-1'
    Guide_w03_06_24.aright = '-1'
    Guide_w03_06_24.atop = '-1'
    Guide_w03_06_24.abottom = '-1'
    Guide_w03_06_24.wavy = '0'
    Guide_w03_06_24.wavy_z = '0'
    Guide_w03_06_24.wavy_tb = '0'
    Guide_w03_06_24.wavy_lr = '0'
    Guide_w03_06_24.chamfers = '0'
    Guide_w03_06_24.chamfers_z = '0'
    Guide_w03_06_24.chamfers_lr = '0'
    Guide_w03_06_24.chamfers_tb = '0'
    Guide_w03_06_24.nelements = '1'
    Guide_w03_06_24.nu = '0'
    Guide_w03_06_24.phase = '0'
    Guide_w03_06_24.reflect = '"NULL"'
    
    # Comp instance Arm42, placement and parameters
    Arm42 = instr.add_component('Arm42','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_24', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_24')
    
    
    # Comp instance Guide_w03_06_25, placement and parameters
    Guide_w03_06_25 = instr.add_component('Guide_w03_06_25','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm42', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm42')
    
    Guide_w03_06_25.w1 = '0.11466'
    Guide_w03_06_25.h1 = '0.11128'
    Guide_w03_06_25.w2 = '0.11466'
    Guide_w03_06_25.h2 = '0.11128'
    Guide_w03_06_25.l = '2.0'
    Guide_w03_06_25.R0 = '0.99'
    Guide_w03_06_25.Qc = '0.0219'
    Guide_w03_06_25.alpha = '6.07'
    Guide_w03_06_25.m = '1.0'
    Guide_w03_06_25.W = '0.003'
    Guide_w03_06_25.nslit = '1'
    Guide_w03_06_25.d = '0.0005'
    Guide_w03_06_25.mleft = '2'
    Guide_w03_06_25.mright = '2'
    Guide_w03_06_25.mtop = '2'
    Guide_w03_06_25.mbottom = '2'
    Guide_w03_06_25.nhslit = '1'
    Guide_w03_06_25.G = '0'
    Guide_w03_06_25.aleft = '-1'
    Guide_w03_06_25.aright = '-1'
    Guide_w03_06_25.atop = '-1'
    Guide_w03_06_25.abottom = '-1'
    Guide_w03_06_25.wavy = '0'
    Guide_w03_06_25.wavy_z = '0'
    Guide_w03_06_25.wavy_tb = '0'
    Guide_w03_06_25.wavy_lr = '0'
    Guide_w03_06_25.chamfers = '0'
    Guide_w03_06_25.chamfers_z = '0'
    Guide_w03_06_25.chamfers_lr = '0'
    Guide_w03_06_25.chamfers_tb = '0'
    Guide_w03_06_25.nelements = '1'
    Guide_w03_06_25.nu = '0'
    Guide_w03_06_25.phase = '0'
    Guide_w03_06_25.reflect = '"NULL"'
    
    # Comp instance Arm43, placement and parameters
    Arm43 = instr.add_component('Arm43','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_25', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_25')
    
    
    # Comp instance Guide_w03_06_26, placement and parameters
    Guide_w03_06_26 = instr.add_component('Guide_w03_06_26','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm43', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm43')
    
    Guide_w03_06_26.w1 = '0.11466'
    Guide_w03_06_26.h1 = '0.11128'
    Guide_w03_06_26.w2 = '0.11466'
    Guide_w03_06_26.h2 = '0.11128'
    Guide_w03_06_26.l = '2.0'
    Guide_w03_06_26.R0 = '0.99'
    Guide_w03_06_26.Qc = '0.0219'
    Guide_w03_06_26.alpha = '6.07'
    Guide_w03_06_26.m = '1.0'
    Guide_w03_06_26.W = '0.003'
    Guide_w03_06_26.nslit = '1'
    Guide_w03_06_26.d = '0.0005'
    Guide_w03_06_26.mleft = '2'
    Guide_w03_06_26.mright = '2'
    Guide_w03_06_26.mtop = '2'
    Guide_w03_06_26.mbottom = '2'
    Guide_w03_06_26.nhslit = '1'
    Guide_w03_06_26.G = '0'
    Guide_w03_06_26.aleft = '-1'
    Guide_w03_06_26.aright = '-1'
    Guide_w03_06_26.atop = '-1'
    Guide_w03_06_26.abottom = '-1'
    Guide_w03_06_26.wavy = '0'
    Guide_w03_06_26.wavy_z = '0'
    Guide_w03_06_26.wavy_tb = '0'
    Guide_w03_06_26.wavy_lr = '0'
    Guide_w03_06_26.chamfers = '0'
    Guide_w03_06_26.chamfers_z = '0'
    Guide_w03_06_26.chamfers_lr = '0'
    Guide_w03_06_26.chamfers_tb = '0'
    Guide_w03_06_26.nelements = '1'
    Guide_w03_06_26.nu = '0'
    Guide_w03_06_26.phase = '0'
    Guide_w03_06_26.reflect = '"NULL"'
    
    # Comp instance Arm44, placement and parameters
    Arm44 = instr.add_component('Arm44','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_26', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_26')
    
    
    # Comp instance Guide_w03_06_27, placement and parameters
    Guide_w03_06_27 = instr.add_component('Guide_w03_06_27','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm44', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm44')
    
    Guide_w03_06_27.w1 = '0.11466'
    Guide_w03_06_27.h1 = '0.11128'
    Guide_w03_06_27.w2 = '0.11466'
    Guide_w03_06_27.h2 = '0.11128'
    Guide_w03_06_27.l = '2.0'
    Guide_w03_06_27.R0 = '0.99'
    Guide_w03_06_27.Qc = '0.0219'
    Guide_w03_06_27.alpha = '6.07'
    Guide_w03_06_27.m = '1.0'
    Guide_w03_06_27.W = '0.003'
    Guide_w03_06_27.nslit = '1'
    Guide_w03_06_27.d = '0.0005'
    Guide_w03_06_27.mleft = '2'
    Guide_w03_06_27.mright = '2'
    Guide_w03_06_27.mtop = '2'
    Guide_w03_06_27.mbottom = '2'
    Guide_w03_06_27.nhslit = '1'
    Guide_w03_06_27.G = '0'
    Guide_w03_06_27.aleft = '-1'
    Guide_w03_06_27.aright = '-1'
    Guide_w03_06_27.atop = '-1'
    Guide_w03_06_27.abottom = '-1'
    Guide_w03_06_27.wavy = '0'
    Guide_w03_06_27.wavy_z = '0'
    Guide_w03_06_27.wavy_tb = '0'
    Guide_w03_06_27.wavy_lr = '0'
    Guide_w03_06_27.chamfers = '0'
    Guide_w03_06_27.chamfers_z = '0'
    Guide_w03_06_27.chamfers_lr = '0'
    Guide_w03_06_27.chamfers_tb = '0'
    Guide_w03_06_27.nelements = '1'
    Guide_w03_06_27.nu = '0'
    Guide_w03_06_27.phase = '0'
    Guide_w03_06_27.reflect = '"NULL"'
    
    # Comp instance Arm45, placement and parameters
    Arm45 = instr.add_component('Arm45','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_27', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_27')
    
    
    # Comp instance Guide_w03_06_28, placement and parameters
    Guide_w03_06_28 = instr.add_component('Guide_w03_06_28','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm45', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm45')
    
    Guide_w03_06_28.w1 = '0.11466'
    Guide_w03_06_28.h1 = '0.11128'
    Guide_w03_06_28.w2 = '0.11466'
    Guide_w03_06_28.h2 = '0.11128'
    Guide_w03_06_28.l = '2.0'
    Guide_w03_06_28.R0 = '0.99'
    Guide_w03_06_28.Qc = '0.0219'
    Guide_w03_06_28.alpha = '6.07'
    Guide_w03_06_28.m = '1.0'
    Guide_w03_06_28.W = '0.003'
    Guide_w03_06_28.nslit = '1'
    Guide_w03_06_28.d = '0.0005'
    Guide_w03_06_28.mleft = '2'
    Guide_w03_06_28.mright = '2'
    Guide_w03_06_28.mtop = '2'
    Guide_w03_06_28.mbottom = '2'
    Guide_w03_06_28.nhslit = '1'
    Guide_w03_06_28.G = '0'
    Guide_w03_06_28.aleft = '-1'
    Guide_w03_06_28.aright = '-1'
    Guide_w03_06_28.atop = '-1'
    Guide_w03_06_28.abottom = '-1'
    Guide_w03_06_28.wavy = '0'
    Guide_w03_06_28.wavy_z = '0'
    Guide_w03_06_28.wavy_tb = '0'
    Guide_w03_06_28.wavy_lr = '0'
    Guide_w03_06_28.chamfers = '0'
    Guide_w03_06_28.chamfers_z = '0'
    Guide_w03_06_28.chamfers_lr = '0'
    Guide_w03_06_28.chamfers_tb = '0'
    Guide_w03_06_28.nelements = '1'
    Guide_w03_06_28.nu = '0'
    Guide_w03_06_28.phase = '0'
    Guide_w03_06_28.reflect = '"NULL"'
    
    # Comp instance Arm46, placement and parameters
    Arm46 = instr.add_component('Arm46','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_28', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_28')
    
    
    # Comp instance Guide_w03_06_29, placement and parameters
    Guide_w03_06_29 = instr.add_component('Guide_w03_06_29','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm46', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm46')
    
    Guide_w03_06_29.w1 = '0.11466'
    Guide_w03_06_29.h1 = '0.11128'
    Guide_w03_06_29.w2 = '0.11466'
    Guide_w03_06_29.h2 = '0.11128'
    Guide_w03_06_29.l = '2.0'
    Guide_w03_06_29.R0 = '0.99'
    Guide_w03_06_29.Qc = '0.0219'
    Guide_w03_06_29.alpha = '6.07'
    Guide_w03_06_29.m = '1.0'
    Guide_w03_06_29.W = '0.003'
    Guide_w03_06_29.nslit = '1'
    Guide_w03_06_29.d = '0.0005'
    Guide_w03_06_29.mleft = '2'
    Guide_w03_06_29.mright = '2'
    Guide_w03_06_29.mtop = '2'
    Guide_w03_06_29.mbottom = '2'
    Guide_w03_06_29.nhslit = '1'
    Guide_w03_06_29.G = '0'
    Guide_w03_06_29.aleft = '-1'
    Guide_w03_06_29.aright = '-1'
    Guide_w03_06_29.atop = '-1'
    Guide_w03_06_29.abottom = '-1'
    Guide_w03_06_29.wavy = '0'
    Guide_w03_06_29.wavy_z = '0'
    Guide_w03_06_29.wavy_tb = '0'
    Guide_w03_06_29.wavy_lr = '0'
    Guide_w03_06_29.chamfers = '0'
    Guide_w03_06_29.chamfers_z = '0'
    Guide_w03_06_29.chamfers_lr = '0'
    Guide_w03_06_29.chamfers_tb = '0'
    Guide_w03_06_29.nelements = '1'
    Guide_w03_06_29.nu = '0'
    Guide_w03_06_29.phase = '0'
    Guide_w03_06_29.reflect = '"NULL"'
    
    # Comp instance Arm47, placement and parameters
    Arm47 = instr.add_component('Arm47','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_29', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_29')
    
    
    # Comp instance Guide_w03_06_30, placement and parameters
    Guide_w03_06_30 = instr.add_component('Guide_w03_06_30','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm47', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm47')
    
    Guide_w03_06_30.w1 = '0.11466'
    Guide_w03_06_30.h1 = '0.11128'
    Guide_w03_06_30.w2 = '0.11466'
    Guide_w03_06_30.h2 = '0.11128'
    Guide_w03_06_30.l = '2.0'
    Guide_w03_06_30.R0 = '0.99'
    Guide_w03_06_30.Qc = '0.0219'
    Guide_w03_06_30.alpha = '6.07'
    Guide_w03_06_30.m = '1.0'
    Guide_w03_06_30.W = '0.003'
    Guide_w03_06_30.nslit = '1'
    Guide_w03_06_30.d = '0.0005'
    Guide_w03_06_30.mleft = '2'
    Guide_w03_06_30.mright = '2'
    Guide_w03_06_30.mtop = '2'
    Guide_w03_06_30.mbottom = '2'
    Guide_w03_06_30.nhslit = '1'
    Guide_w03_06_30.G = '0'
    Guide_w03_06_30.aleft = '-1'
    Guide_w03_06_30.aright = '-1'
    Guide_w03_06_30.atop = '-1'
    Guide_w03_06_30.abottom = '-1'
    Guide_w03_06_30.wavy = '0'
    Guide_w03_06_30.wavy_z = '0'
    Guide_w03_06_30.wavy_tb = '0'
    Guide_w03_06_30.wavy_lr = '0'
    Guide_w03_06_30.chamfers = '0'
    Guide_w03_06_30.chamfers_z = '0'
    Guide_w03_06_30.chamfers_lr = '0'
    Guide_w03_06_30.chamfers_tb = '0'
    Guide_w03_06_30.nelements = '1'
    Guide_w03_06_30.nu = '0'
    Guide_w03_06_30.phase = '0'
    Guide_w03_06_30.reflect = '"NULL"'
    
    # Comp instance Arm48, placement and parameters
    Arm48 = instr.add_component('Arm48','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_30', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_30')
    
    
    # Comp instance Guide_w03_06_31, placement and parameters
    Guide_w03_06_31 = instr.add_component('Guide_w03_06_31','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm48', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm48')
    
    Guide_w03_06_31.w1 = '0.11466'
    Guide_w03_06_31.h1 = '0.11128'
    Guide_w03_06_31.w2 = '0.11466'
    Guide_w03_06_31.h2 = '0.11128'
    Guide_w03_06_31.l = '2.0'
    Guide_w03_06_31.R0 = '0.99'
    Guide_w03_06_31.Qc = '0.0219'
    Guide_w03_06_31.alpha = '6.07'
    Guide_w03_06_31.m = '1.0'
    Guide_w03_06_31.W = '0.003'
    Guide_w03_06_31.nslit = '1'
    Guide_w03_06_31.d = '0.0005'
    Guide_w03_06_31.mleft = '2'
    Guide_w03_06_31.mright = '2'
    Guide_w03_06_31.mtop = '2'
    Guide_w03_06_31.mbottom = '2'
    Guide_w03_06_31.nhslit = '1'
    Guide_w03_06_31.G = '0'
    Guide_w03_06_31.aleft = '-1'
    Guide_w03_06_31.aright = '-1'
    Guide_w03_06_31.atop = '-1'
    Guide_w03_06_31.abottom = '-1'
    Guide_w03_06_31.wavy = '0'
    Guide_w03_06_31.wavy_z = '0'
    Guide_w03_06_31.wavy_tb = '0'
    Guide_w03_06_31.wavy_lr = '0'
    Guide_w03_06_31.chamfers = '0'
    Guide_w03_06_31.chamfers_z = '0'
    Guide_w03_06_31.chamfers_lr = '0'
    Guide_w03_06_31.chamfers_tb = '0'
    Guide_w03_06_31.nelements = '1'
    Guide_w03_06_31.nu = '0'
    Guide_w03_06_31.phase = '0'
    Guide_w03_06_31.reflect = '"NULL"'
    
    # Comp instance Arm49, placement and parameters
    Arm49 = instr.add_component('Arm49','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_31', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_31')
    
    
    # Comp instance Guide_w03_06_32, placement and parameters
    Guide_w03_06_32 = instr.add_component('Guide_w03_06_32','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm49', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm49')
    
    Guide_w03_06_32.w1 = '0.11466'
    Guide_w03_06_32.h1 = '0.11128'
    Guide_w03_06_32.w2 = '0.11466'
    Guide_w03_06_32.h2 = '0.11128'
    Guide_w03_06_32.l = '2.0'
    Guide_w03_06_32.R0 = '0.99'
    Guide_w03_06_32.Qc = '0.0219'
    Guide_w03_06_32.alpha = '6.07'
    Guide_w03_06_32.m = '1.0'
    Guide_w03_06_32.W = '0.003'
    Guide_w03_06_32.nslit = '1'
    Guide_w03_06_32.d = '0.0005'
    Guide_w03_06_32.mleft = '2'
    Guide_w03_06_32.mright = '2'
    Guide_w03_06_32.mtop = '2'
    Guide_w03_06_32.mbottom = '2'
    Guide_w03_06_32.nhslit = '1'
    Guide_w03_06_32.G = '0'
    Guide_w03_06_32.aleft = '-1'
    Guide_w03_06_32.aright = '-1'
    Guide_w03_06_32.atop = '-1'
    Guide_w03_06_32.abottom = '-1'
    Guide_w03_06_32.wavy = '0'
    Guide_w03_06_32.wavy_z = '0'
    Guide_w03_06_32.wavy_tb = '0'
    Guide_w03_06_32.wavy_lr = '0'
    Guide_w03_06_32.chamfers = '0'
    Guide_w03_06_32.chamfers_z = '0'
    Guide_w03_06_32.chamfers_lr = '0'
    Guide_w03_06_32.chamfers_tb = '0'
    Guide_w03_06_32.nelements = '1'
    Guide_w03_06_32.nu = '0'
    Guide_w03_06_32.phase = '0'
    Guide_w03_06_32.reflect = '"NULL"'
    
    # Comp instance Arm50, placement and parameters
    Arm50 = instr.add_component('Arm50','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_32', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_32')
    
    
    # Comp instance Guide_w03_06_331, placement and parameters
    Guide_w03_06_331 = instr.add_component('Guide_w03_06_331','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm50', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm50')
    
    Guide_w03_06_331.w1 = '0.11466'
    Guide_w03_06_331.h1 = '0.11128'
    Guide_w03_06_331.w2 = '0.11466'
    Guide_w03_06_331.h2 = '0.11128'
    Guide_w03_06_331.l = '1.0624'
    Guide_w03_06_331.R0 = '0.99'
    Guide_w03_06_331.Qc = '0.0219'
    Guide_w03_06_331.alpha = '6.07'
    Guide_w03_06_331.m = '1.0'
    Guide_w03_06_331.W = '0.003'
    Guide_w03_06_331.nslit = '1'
    Guide_w03_06_331.d = '0.0005'
    Guide_w03_06_331.mleft = '2'
    Guide_w03_06_331.mright = '2'
    Guide_w03_06_331.mtop = '2'
    Guide_w03_06_331.mbottom = '2'
    Guide_w03_06_331.nhslit = '1'
    Guide_w03_06_331.G = '0'
    Guide_w03_06_331.aleft = '-1'
    Guide_w03_06_331.aright = '-1'
    Guide_w03_06_331.atop = '-1'
    Guide_w03_06_331.abottom = '-1'
    Guide_w03_06_331.wavy = '0'
    Guide_w03_06_331.wavy_z = '0'
    Guide_w03_06_331.wavy_tb = '0'
    Guide_w03_06_331.wavy_lr = '0'
    Guide_w03_06_331.chamfers = '0'
    Guide_w03_06_331.chamfers_z = '0'
    Guide_w03_06_331.chamfers_lr = '0'
    Guide_w03_06_331.chamfers_tb = '0'
    Guide_w03_06_331.nelements = '1'
    Guide_w03_06_331.nu = '0'
    Guide_w03_06_331.phase = '0'
    Guide_w03_06_331.reflect = '"NULL"'
    
    # Comp instance Arm51, placement and parameters
    Arm51 = instr.add_component('Arm51','Arm', AT=['0', '0', '1.0624 + 1e-06'], AT_RELATIVE='Guide_w03_06_331', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_331')
    
    
    # Comp instance Guide_w03_06_332, placement and parameters
    Guide_w03_06_332 = instr.add_component('Guide_w03_06_332','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm51', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm51')
    
    Guide_w03_06_332.w1 = '0.11466'
    Guide_w03_06_332.h1 = '0.11128'
    Guide_w03_06_332.w2 = '0.11466'
    Guide_w03_06_332.h2 = '0.10915'
    Guide_w03_06_332.l = '0.9376'
    Guide_w03_06_332.R0 = '0.99'
    Guide_w03_06_332.Qc = '0.0219'
    Guide_w03_06_332.alpha = '6.07'
    Guide_w03_06_332.m = '1.0'
    Guide_w03_06_332.W = '0.003'
    Guide_w03_06_332.nslit = '1'
    Guide_w03_06_332.d = '0.0005'
    Guide_w03_06_332.mleft = '2.5'
    Guide_w03_06_332.mright = '2.5'
    Guide_w03_06_332.mtop = '2.5'
    Guide_w03_06_332.mbottom = '2.5'
    Guide_w03_06_332.nhslit = '1'
    Guide_w03_06_332.G = '0'
    Guide_w03_06_332.aleft = '-1'
    Guide_w03_06_332.aright = '-1'
    Guide_w03_06_332.atop = '-1'
    Guide_w03_06_332.abottom = '-1'
    Guide_w03_06_332.wavy = '0'
    Guide_w03_06_332.wavy_z = '0'
    Guide_w03_06_332.wavy_tb = '0'
    Guide_w03_06_332.wavy_lr = '0'
    Guide_w03_06_332.chamfers = '0'
    Guide_w03_06_332.chamfers_z = '0'
    Guide_w03_06_332.chamfers_lr = '0'
    Guide_w03_06_332.chamfers_tb = '0'
    Guide_w03_06_332.nelements = '1'
    Guide_w03_06_332.nu = '0'
    Guide_w03_06_332.phase = '0'
    Guide_w03_06_332.reflect = '"NULL"'
    
    # Comp instance Arm52, placement and parameters
    Arm52 = instr.add_component('Arm52','Arm', AT=['0', '0', '0.9376 + 0.001'], AT_RELATIVE='Guide_w03_06_332', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_332')
    
    
    # Comp instance Guide_w03_06_34, placement and parameters
    Guide_w03_06_34 = instr.add_component('Guide_w03_06_34','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm52', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm52')
    
    Guide_w03_06_34.w1 = '0.11466'
    Guide_w03_06_34.h1 = '0.10915'
    Guide_w03_06_34.w2 = '0.11466'
    Guide_w03_06_34.h2 = '0.10412'
    Guide_w03_06_34.l = '2.0'
    Guide_w03_06_34.R0 = '0.99'
    Guide_w03_06_34.Qc = '0.0219'
    Guide_w03_06_34.alpha = '6.07'
    Guide_w03_06_34.m = '1.0'
    Guide_w03_06_34.W = '0.003'
    Guide_w03_06_34.nslit = '1'
    Guide_w03_06_34.d = '0.0005'
    Guide_w03_06_34.mleft = '2.5'
    Guide_w03_06_34.mright = '2.5'
    Guide_w03_06_34.mtop = '2.5'
    Guide_w03_06_34.mbottom = '2.5'
    Guide_w03_06_34.nhslit = '1'
    Guide_w03_06_34.G = '0'
    Guide_w03_06_34.aleft = '-1'
    Guide_w03_06_34.aright = '-1'
    Guide_w03_06_34.atop = '-1'
    Guide_w03_06_34.abottom = '-1'
    Guide_w03_06_34.wavy = '0'
    Guide_w03_06_34.wavy_z = '0'
    Guide_w03_06_34.wavy_tb = '0'
    Guide_w03_06_34.wavy_lr = '0'
    Guide_w03_06_34.chamfers = '0'
    Guide_w03_06_34.chamfers_z = '0'
    Guide_w03_06_34.chamfers_lr = '0'
    Guide_w03_06_34.chamfers_tb = '0'
    Guide_w03_06_34.nelements = '1'
    Guide_w03_06_34.nu = '0'
    Guide_w03_06_34.phase = '0'
    Guide_w03_06_34.reflect = '"NULL"'
    
    # Comp instance Arm53, placement and parameters
    Arm53 = instr.add_component('Arm53','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_34', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_34')
    
    
    # Comp instance Guide_w03_06_35, placement and parameters
    Guide_w03_06_35 = instr.add_component('Guide_w03_06_35','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm53', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm53')
    
    Guide_w03_06_35.w1 = '0.11466'
    Guide_w03_06_35.h1 = '0.10412'
    Guide_w03_06_35.w2 = '0.11466'
    Guide_w03_06_35.h2 = '0.09830'
    Guide_w03_06_35.l = '2.0'
    Guide_w03_06_35.R0 = '0.99'
    Guide_w03_06_35.Qc = '0.0219'
    Guide_w03_06_35.alpha = '6.07'
    Guide_w03_06_35.m = '1.0'
    Guide_w03_06_35.W = '0.003'
    Guide_w03_06_35.nslit = '1'
    Guide_w03_06_35.d = '0.0005'
    Guide_w03_06_35.mleft = '2.5'
    Guide_w03_06_35.mright = '2.5'
    Guide_w03_06_35.mtop = '2.5'
    Guide_w03_06_35.mbottom = '2.5'
    Guide_w03_06_35.nhslit = '1'
    Guide_w03_06_35.G = '0'
    Guide_w03_06_35.aleft = '-1'
    Guide_w03_06_35.aright = '-1'
    Guide_w03_06_35.atop = '-1'
    Guide_w03_06_35.abottom = '-1'
    Guide_w03_06_35.wavy = '0'
    Guide_w03_06_35.wavy_z = '0'
    Guide_w03_06_35.wavy_tb = '0'
    Guide_w03_06_35.wavy_lr = '0'
    Guide_w03_06_35.chamfers = '0'
    Guide_w03_06_35.chamfers_z = '0'
    Guide_w03_06_35.chamfers_lr = '0'
    Guide_w03_06_35.chamfers_tb = '0'
    Guide_w03_06_35.nelements = '1'
    Guide_w03_06_35.nu = '0'
    Guide_w03_06_35.phase = '0'
    Guide_w03_06_35.reflect = '"NULL"'
    
    # Comp instance Arm54, placement and parameters
    Arm54 = instr.add_component('Arm54','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_06_35', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_35')
    
    
    # Comp instance Guide_w03_06_36, placement and parameters
    Guide_w03_06_36 = instr.add_component('Guide_w03_06_36','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm54', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm54')
    
    Guide_w03_06_36.w1 = '0.11466'
    Guide_w03_06_36.h1 = '0.09830'
    Guide_w03_06_36.w2 = '0.11466'
    Guide_w03_06_36.h2 = '0.09155'
    Guide_w03_06_36.l = '2.0'
    Guide_w03_06_36.R0 = '0.99'
    Guide_w03_06_36.Qc = '0.0219'
    Guide_w03_06_36.alpha = '6.07'
    Guide_w03_06_36.m = '1.0'
    Guide_w03_06_36.W = '0.003'
    Guide_w03_06_36.nslit = '1'
    Guide_w03_06_36.d = '0.0005'
    Guide_w03_06_36.mleft = '2.5'
    Guide_w03_06_36.mright = '2.5'
    Guide_w03_06_36.mtop = '2.5'
    Guide_w03_06_36.mbottom = '2.5'
    Guide_w03_06_36.nhslit = '1'
    Guide_w03_06_36.G = '0'
    Guide_w03_06_36.aleft = '-1'
    Guide_w03_06_36.aright = '-1'
    Guide_w03_06_36.atop = '-1'
    Guide_w03_06_36.abottom = '-1'
    Guide_w03_06_36.wavy = '0'
    Guide_w03_06_36.wavy_z = '0'
    Guide_w03_06_36.wavy_tb = '0'
    Guide_w03_06_36.wavy_lr = '0'
    Guide_w03_06_36.chamfers = '0'
    Guide_w03_06_36.chamfers_z = '0'
    Guide_w03_06_36.chamfers_lr = '0'
    Guide_w03_06_36.chamfers_tb = '0'
    Guide_w03_06_36.nelements = '1'
    Guide_w03_06_36.nu = '0'
    Guide_w03_06_36.phase = '0'
    Guide_w03_06_36.reflect = '"NULL"'
    
    # Comp instance Arm55, placement and parameters
    Arm55 = instr.add_component('Arm55','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_06_36', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_36')
    
    
    # Comp instance Guide_w03_06_37, placement and parameters
    Guide_w03_06_37 = instr.add_component('Guide_w03_06_37','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm55', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm55')
    
    Guide_w03_06_37.w1 = '0.11466'
    Guide_w03_06_37.h1 = '0.09155'
    Guide_w03_06_37.w2 = '0.11466'
    Guide_w03_06_37.h2 = '0.08521'
    Guide_w03_06_37.l = '1.6269'
    Guide_w03_06_37.R0 = '0.99'
    Guide_w03_06_37.Qc = '0.0219'
    Guide_w03_06_37.alpha = '6.07'
    Guide_w03_06_37.m = '1.0'
    Guide_w03_06_37.W = '0.003'
    Guide_w03_06_37.nslit = '1'
    Guide_w03_06_37.d = '0.0005'
    Guide_w03_06_37.mleft = '2.5'
    Guide_w03_06_37.mright = '2.5'
    Guide_w03_06_37.mtop = '2.5'
    Guide_w03_06_37.mbottom = '2.5'
    Guide_w03_06_37.nhslit = '1'
    Guide_w03_06_37.G = '0'
    Guide_w03_06_37.aleft = '-1'
    Guide_w03_06_37.aright = '-1'
    Guide_w03_06_37.atop = '-1'
    Guide_w03_06_37.abottom = '-1'
    Guide_w03_06_37.wavy = '0'
    Guide_w03_06_37.wavy_z = '0'
    Guide_w03_06_37.wavy_tb = '0'
    Guide_w03_06_37.wavy_lr = '0'
    Guide_w03_06_37.chamfers = '0'
    Guide_w03_06_37.chamfers_z = '0'
    Guide_w03_06_37.chamfers_lr = '0'
    Guide_w03_06_37.chamfers_tb = '0'
    Guide_w03_06_37.nelements = '1'
    Guide_w03_06_37.nu = '0'
    Guide_w03_06_37.phase = '0'
    Guide_w03_06_37.reflect = '"NULL"'
    
    # Comp instance Arm56, placement and parameters
    Arm56 = instr.add_component('Arm56','Arm', AT=['0', '0', '1.6269 + 0.001'], AT_RELATIVE='Guide_w03_06_37', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_37')
    
    
    # Comp instance Guide_w03_06_38, placement and parameters
    Guide_w03_06_38 = instr.add_component('Guide_w03_06_38','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm56', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm56')
    
    Guide_w03_06_38.w1 = '0.11466'
    Guide_w03_06_38.h1 = '0.08521'
    Guide_w03_06_38.w2 = '0.11466'
    Guide_w03_06_38.h2 = '0.07792'
    Guide_w03_06_38.l = '1.6269'
    Guide_w03_06_38.R0 = '0.99'
    Guide_w03_06_38.Qc = '0.0219'
    Guide_w03_06_38.alpha = '6.07'
    Guide_w03_06_38.m = '1.0'
    Guide_w03_06_38.W = '0.003'
    Guide_w03_06_38.nslit = '1'
    Guide_w03_06_38.d = '0.0005'
    Guide_w03_06_38.mleft = '2.5'
    Guide_w03_06_38.mright = '2.5'
    Guide_w03_06_38.mtop = '2.5'
    Guide_w03_06_38.mbottom = '2.5'
    Guide_w03_06_38.nhslit = '1'
    Guide_w03_06_38.G = '0'
    Guide_w03_06_38.aleft = '-1'
    Guide_w03_06_38.aright = '-1'
    Guide_w03_06_38.atop = '-1'
    Guide_w03_06_38.abottom = '-1'
    Guide_w03_06_38.wavy = '0'
    Guide_w03_06_38.wavy_z = '0'
    Guide_w03_06_38.wavy_tb = '0'
    Guide_w03_06_38.wavy_lr = '0'
    Guide_w03_06_38.chamfers = '0'
    Guide_w03_06_38.chamfers_z = '0'
    Guide_w03_06_38.chamfers_lr = '0'
    Guide_w03_06_38.chamfers_tb = '0'
    Guide_w03_06_38.nelements = '1'
    Guide_w03_06_38.nu = '0'
    Guide_w03_06_38.phase = '0'
    Guide_w03_06_38.reflect = '"NULL"'
    
    # Comp instance Arm57, placement and parameters
    Arm57 = instr.add_component('Arm57','Arm', AT=['0', '0', '1.6269 + 0.002'], AT_RELATIVE='Guide_w03_06_38', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_38')
    
    
    # Comp instance Guide_w03_06_39, placement and parameters
    Guide_w03_06_39 = instr.add_component('Guide_w03_06_39','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm57', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm57')
    
    Guide_w03_06_39.w1 = '0.11466'
    Guide_w03_06_39.h1 = '0.07792'
    Guide_w03_06_39.w2 = '0.11466'
    Guide_w03_06_39.h2 = '0.07390'
    Guide_w03_06_39.l = '0.8'
    Guide_w03_06_39.R0 = '0.99'
    Guide_w03_06_39.Qc = '0.0219'
    Guide_w03_06_39.alpha = '6.07'
    Guide_w03_06_39.m = '1.0'
    Guide_w03_06_39.W = '0.003'
    Guide_w03_06_39.nslit = '1'
    Guide_w03_06_39.d = '0.0005'
    Guide_w03_06_39.mleft = '2.5'
    Guide_w03_06_39.mright = '2.5'
    Guide_w03_06_39.mtop = '2.5'
    Guide_w03_06_39.mbottom = '2.5'
    Guide_w03_06_39.nhslit = '1'
    Guide_w03_06_39.G = '0'
    Guide_w03_06_39.aleft = '-1'
    Guide_w03_06_39.aright = '-1'
    Guide_w03_06_39.atop = '-1'
    Guide_w03_06_39.abottom = '-1'
    Guide_w03_06_39.wavy = '0'
    Guide_w03_06_39.wavy_z = '0'
    Guide_w03_06_39.wavy_tb = '0'
    Guide_w03_06_39.wavy_lr = '0'
    Guide_w03_06_39.chamfers = '0'
    Guide_w03_06_39.chamfers_z = '0'
    Guide_w03_06_39.chamfers_lr = '0'
    Guide_w03_06_39.chamfers_tb = '0'
    Guide_w03_06_39.nelements = '1'
    Guide_w03_06_39.nu = '0'
    Guide_w03_06_39.phase = '0'
    Guide_w03_06_39.reflect = '"NULL"'
    
    # Comp instance BW_3, placement and parameters
    BW_3 = instr.add_component('BW_3','DiskChopper', AT=['0', '0', '0.8 + 0.015'], AT_RELATIVE='Guide_w03_06_39', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_39')
    
    BW_3.theta_0 = 'theta_BW3'
    BW_3.radius = '0.35'
    BW_3.yheight = '0.07390'
    BW_3.nu = 'Freq_BW3'
    BW_3.nslit = '1'
    BW_3.jitter = '0'
    BW_3.delay = 'BW3_Delay'
    BW_3.isfirst = '0'
    BW_3.n_pulse = '1'
    BW_3.abs_out = '1'
    BW_3.phase = '0'
    BW_3.xwidth = '0'
    BW_3.verbose = '1'
    
    # Comp instance Lambda_BW3, placement and parameters
    Lambda_BW3 = instr.add_component('Lambda_BW3','L_monitor', AT=['0', '0', '0.001'], AT_RELATIVE='BW_3', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='BW_3')
    
    Lambda_BW3.nL = '1000'
    Lambda_BW3.filename = '"Lambda_BW3"'
    Lambda_BW3.nowritefile = '0'
    Lambda_BW3.xmin = '-0.05'
    Lambda_BW3.xmax = '0.05'
    Lambda_BW3.ymin = '-0.05'
    Lambda_BW3.ymax = '0.05'
    Lambda_BW3.xwidth = '0'
    Lambda_BW3.yheight = '0'
    Lambda_BW3.Lmin = '0.5'
    Lambda_BW3.Lmax = '100'
    Lambda_BW3.restore_neutron = '1'
    
    # Comp instance Arm58, placement and parameters
    Arm58 = instr.add_component('Arm58','Arm', AT=['0', '0', '0.8 + 0.03'], AT_RELATIVE='Guide_w03_06_39', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_39')
    
    
    # Comp instance Guide_w03_06_40, placement and parameters
    Guide_w03_06_40 = instr.add_component('Guide_w03_06_40','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm58', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm58')
    
    Guide_w03_06_40.w1 = '0.11466'
    Guide_w03_06_40.h1 = '0.07389'
    Guide_w03_06_40.w2 = '0.11466'
    Guide_w03_06_40.h2 = '0.07389'
    Guide_w03_06_40.l = '0.5'
    Guide_w03_06_40.R0 = '0.99'
    Guide_w03_06_40.Qc = '0.0219'
    Guide_w03_06_40.alpha = '6.07'
    Guide_w03_06_40.m = '1.0'
    Guide_w03_06_40.W = '0.003'
    Guide_w03_06_40.nslit = '1'
    Guide_w03_06_40.d = '0.0005'
    Guide_w03_06_40.mleft = '2.0'
    Guide_w03_06_40.mright = '2.0'
    Guide_w03_06_40.mtop = '2.5'
    Guide_w03_06_40.mbottom = '2.5'
    Guide_w03_06_40.nhslit = '1'
    Guide_w03_06_40.G = '0'
    Guide_w03_06_40.aleft = '-1'
    Guide_w03_06_40.aright = '-1'
    Guide_w03_06_40.atop = '-1'
    Guide_w03_06_40.abottom = '-1'
    Guide_w03_06_40.wavy = '0'
    Guide_w03_06_40.wavy_z = '0'
    Guide_w03_06_40.wavy_tb = '0'
    Guide_w03_06_40.wavy_lr = '0'
    Guide_w03_06_40.chamfers = '0'
    Guide_w03_06_40.chamfers_z = '0'
    Guide_w03_06_40.chamfers_lr = '0'
    Guide_w03_06_40.chamfers_tb = '0'
    Guide_w03_06_40.nelements = '1'
    Guide_w03_06_40.nu = '0'
    Guide_w03_06_40.phase = '0'
    Guide_w03_06_40.reflect = '"NULL"'
    
    # Comp instance Arm59, placement and parameters
    Arm59 = instr.add_component('Arm59','Arm', AT=['0', '0', '0.5 + 0.01'], AT_RELATIVE='Guide_w03_06_40', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_06_40')
    
    
    # Comp instance Guide_w03_07_01, placement and parameters
    Guide_w03_07_01 = instr.add_component('Guide_w03_07_01','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm59', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm59')
    
    Guide_w03_07_01.w1 = '0.11466'
    Guide_w03_07_01.h1 = '0.07389'
    Guide_w03_07_01.w2 = '0.11466'
    Guide_w03_07_01.h2 = '0.07389'
    Guide_w03_07_01.l = '0.5001 + 0.1'
    Guide_w03_07_01.R0 = '0.99'
    Guide_w03_07_01.Qc = '0.0219'
    Guide_w03_07_01.alpha = '6.07'
    Guide_w03_07_01.m = '1.0'
    Guide_w03_07_01.W = '0.003'
    Guide_w03_07_01.nslit = '1'
    Guide_w03_07_01.d = '0.0005'
    Guide_w03_07_01.mleft = '2.5'
    Guide_w03_07_01.mright = '2.5'
    Guide_w03_07_01.mtop = '2.5'
    Guide_w03_07_01.mbottom = '2.5'
    Guide_w03_07_01.nhslit = '1'
    Guide_w03_07_01.G = '0'
    Guide_w03_07_01.aleft = '-1'
    Guide_w03_07_01.aright = '-1'
    Guide_w03_07_01.atop = '-1'
    Guide_w03_07_01.abottom = '-1'
    Guide_w03_07_01.wavy = '0'
    Guide_w03_07_01.wavy_z = '0'
    Guide_w03_07_01.wavy_tb = '0'
    Guide_w03_07_01.wavy_lr = '0'
    Guide_w03_07_01.chamfers = '0'
    Guide_w03_07_01.chamfers_z = '0'
    Guide_w03_07_01.chamfers_lr = '0'
    Guide_w03_07_01.chamfers_tb = '0'
    Guide_w03_07_01.nelements = '1'
    Guide_w03_07_01.nu = '0'
    Guide_w03_07_01.phase = '0'
    Guide_w03_07_01.reflect = '"NULL"'
    
    # Comp instance PS1, placement and parameters
    PS1 = instr.add_component('PS1','DiskChopper', AT=['0', '0', '0.5001 + 0.1 + 0.02'], AT_RELATIVE='Guide_w03_07_01', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_07_01')
    
    PS1.theta_0 = 'theta_PS'
    PS1.radius = '0.35'
    PS1.yheight = '0.07389'
    PS1.nu = 'Freq_PS'
    PS1.nslit = '3'
    PS1.jitter = '0'
    PS1.delay = 'PS1_Delay'
    PS1.isfirst = '0'
    PS1.n_pulse = '1'
    PS1.abs_out = '1'
    PS1.phase = '0'
    PS1.xwidth = '0'
    PS1.verbose = '1'
    
    # Comp instance TOF_PS, placement and parameters
    TOF_PS = instr.add_component('TOF_PS','TOF_monitor', AT=['0', '0', '0.000000001'], AT_RELATIVE='PS1', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='PS1')
    
    TOF_PS.nt = '1000'
    TOF_PS.filename = '"TOF_PS"'
    TOF_PS.xmin = '-0.05'
    TOF_PS.xmax = '0.05'
    TOF_PS.ymin = '-0.05'
    TOF_PS.ymax = '0.05'
    TOF_PS.xwidth = '0'
    TOF_PS.yheight = '0'
    TOF_PS.tmin = '252.78 * ( lambda_min -1 ) * Distance_PS1'
    TOF_PS.tmax = '252.78 * ( lambda_min + 1 ) * Distance_PS1'
    TOF_PS.dt = '1.0'
    TOF_PS.restore_neutron = '1'
    TOF_PS.nowritefile = '0'
    
    # Comp instance PS2, placement and parameters
    PS2 = instr.add_component('PS2','DiskChopper', AT=['0', '0', '0.006'], AT_RELATIVE='TOF_PS', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='TOF_PS')
    
    PS2.theta_0 = 'theta_PS'
    PS2.radius = '0.35'
    PS2.yheight = '0.07389'
    PS2.nu = '- Freq_PS'
    PS2.nslit = '3'
    PS2.jitter = '0'
    PS2.delay = 'PS2_Delay'
    PS2.isfirst = '0'
    PS2.n_pulse = '1'
    PS2.abs_out = '1'
    PS2.phase = '0'
    PS2.xwidth = '0'
    PS2.verbose = '1'
    
    # Comp instance Lambda_PS, placement and parameters
    Lambda_PS = instr.add_component('Lambda_PS','L_monitor', AT=['0', '0', '0.001'], AT_RELATIVE='PS2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='PS2')
    
    Lambda_PS.nL = '1000'
    Lambda_PS.filename = '"Lambda_PS"'
    Lambda_PS.nowritefile = '0'
    Lambda_PS.xmin = '-0.05'
    Lambda_PS.xmax = '0.05'
    Lambda_PS.ymin = '-0.05'
    Lambda_PS.ymax = '0.05'
    Lambda_PS.xwidth = '0'
    Lambda_PS.yheight = '0'
    Lambda_PS.Lmin = 'lambda_min -0.8'
    Lambda_PS.Lmax = 'lambda_min + 0.8'
    Lambda_PS.restore_neutron = '1'
    
    # Comp instance Arm60, placement and parameters
    Arm60 = instr.add_component('Arm60','Arm', AT=['0', '0', '0.5001 + 0.1 + 0.1165'], AT_RELATIVE='Guide_w03_07_01', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_07_01')
    
    
    # Comp instance Guide_w03_08_01, placement and parameters
    Guide_w03_08_01 = instr.add_component('Guide_w03_08_01','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm60', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm60')
    
    Guide_w03_08_01.w1 = '0.11466'
    Guide_w03_08_01.h1 = '0.07389'
    Guide_w03_08_01.w2 = '0.11466'
    Guide_w03_08_01.h2 = '0.07389'
    Guide_w03_08_01.l = '2.5'
    Guide_w03_08_01.R0 = '0.99'
    Guide_w03_08_01.Qc = '0.0219'
    Guide_w03_08_01.alpha = '6.07'
    Guide_w03_08_01.m = '1.0'
    Guide_w03_08_01.W = '0.003'
    Guide_w03_08_01.nslit = '1'
    Guide_w03_08_01.d = '0.0005'
    Guide_w03_08_01.mleft = '2.0'
    Guide_w03_08_01.mright = '2.0'
    Guide_w03_08_01.mtop = '2.5'
    Guide_w03_08_01.mbottom = '2.5'
    Guide_w03_08_01.nhslit = '1'
    Guide_w03_08_01.G = '0'
    Guide_w03_08_01.aleft = '-1'
    Guide_w03_08_01.aright = '-1'
    Guide_w03_08_01.atop = '-1'
    Guide_w03_08_01.abottom = '-1'
    Guide_w03_08_01.wavy = '0'
    Guide_w03_08_01.wavy_z = '0'
    Guide_w03_08_01.wavy_tb = '0'
    Guide_w03_08_01.wavy_lr = '0'
    Guide_w03_08_01.chamfers = '0'
    Guide_w03_08_01.chamfers_z = '0'
    Guide_w03_08_01.chamfers_lr = '0'
    Guide_w03_08_01.chamfers_tb = '0'
    Guide_w03_08_01.nelements = '1'
    Guide_w03_08_01.nu = '0'
    Guide_w03_08_01.phase = '0'
    Guide_w03_08_01.reflect = '"NULL"'
    
    # Comp instance Arm61, placement and parameters
    Arm61 = instr.add_component('Arm61','Arm', AT=['0', '0', '2.5 + 0.001'], AT_RELATIVE='Guide_w03_08_01', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_01')
    
    
    # Comp instance Guide_w03_08_02, placement and parameters
    Guide_w03_08_02 = instr.add_component('Guide_w03_08_02','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm61', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm61')
    
    Guide_w03_08_02.w1 = '0.11466'
    Guide_w03_08_02.h1 = '0.07389'
    Guide_w03_08_02.w2 = '0.11466'
    Guide_w03_08_02.h2 = '0.07389'
    Guide_w03_08_02.l = '2.5'
    Guide_w03_08_02.R0 = '0.99'
    Guide_w03_08_02.Qc = '0.0219'
    Guide_w03_08_02.alpha = '6.07'
    Guide_w03_08_02.m = '1.0'
    Guide_w03_08_02.W = '0.003'
    Guide_w03_08_02.nslit = '1'
    Guide_w03_08_02.d = '0.0005'
    Guide_w03_08_02.mleft = '2.0'
    Guide_w03_08_02.mright = '2.0'
    Guide_w03_08_02.mtop = '2.5'
    Guide_w03_08_02.mbottom = '2.5'
    Guide_w03_08_02.nhslit = '1'
    Guide_w03_08_02.G = '0'
    Guide_w03_08_02.aleft = '-1'
    Guide_w03_08_02.aright = '-1'
    Guide_w03_08_02.atop = '-1'
    Guide_w03_08_02.abottom = '-1'
    Guide_w03_08_02.wavy = '0'
    Guide_w03_08_02.wavy_z = '0'
    Guide_w03_08_02.wavy_tb = '0'
    Guide_w03_08_02.wavy_lr = '0'
    Guide_w03_08_02.chamfers = '0'
    Guide_w03_08_02.chamfers_z = '0'
    Guide_w03_08_02.chamfers_lr = '0'
    Guide_w03_08_02.chamfers_tb = '0'
    Guide_w03_08_02.nelements = '1'
    Guide_w03_08_02.nu = '0'
    Guide_w03_08_02.phase = '0'
    Guide_w03_08_02.reflect = '"NULL"'
    
    # Comp instance Arm62, placement and parameters
    Arm62 = instr.add_component('Arm62','Arm', AT=['0', '0', '2.5 + 0.002'], AT_RELATIVE='Guide_w03_08_02', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_02')
    
    
    # Comp instance Guide_w03_08_03, placement and parameters
    Guide_w03_08_03 = instr.add_component('Guide_w03_08_03','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm62', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm62')
    
    Guide_w03_08_03.w1 = '0.11466'
    Guide_w03_08_03.h1 = '0.07389'
    Guide_w03_08_03.w2 = '0.11436'
    Guide_w03_08_03.h2 = '0.07389'
    Guide_w03_08_03.l = '2.0'
    Guide_w03_08_03.R0 = '0.99'
    Guide_w03_08_03.Qc = '0.0219'
    Guide_w03_08_03.alpha = '6.07'
    Guide_w03_08_03.m = '1.0'
    Guide_w03_08_03.W = '0.003'
    Guide_w03_08_03.nslit = '1'
    Guide_w03_08_03.d = '0.0005'
    Guide_w03_08_03.mleft = '2.0'
    Guide_w03_08_03.mright = '2'
    Guide_w03_08_03.mtop = '3.0'
    Guide_w03_08_03.mbottom = '3.0'
    Guide_w03_08_03.nhslit = '1'
    Guide_w03_08_03.G = '0'
    Guide_w03_08_03.aleft = '-1'
    Guide_w03_08_03.aright = '-1'
    Guide_w03_08_03.atop = '-1'
    Guide_w03_08_03.abottom = '-1'
    Guide_w03_08_03.wavy = '0'
    Guide_w03_08_03.wavy_z = '0'
    Guide_w03_08_03.wavy_tb = '0'
    Guide_w03_08_03.wavy_lr = '0'
    Guide_w03_08_03.chamfers = '0'
    Guide_w03_08_03.chamfers_z = '0'
    Guide_w03_08_03.chamfers_lr = '0'
    Guide_w03_08_03.chamfers_tb = '0'
    Guide_w03_08_03.nelements = '1'
    Guide_w03_08_03.nu = '0'
    Guide_w03_08_03.phase = '0'
    Guide_w03_08_03.reflect = '"NULL"'
    
    # Comp instance Arm63, placement and parameters
    Arm63 = instr.add_component('Arm63','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_03', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_03')
    
    
    # Comp instance Guide_w03_08_04, placement and parameters
    Guide_w03_08_04 = instr.add_component('Guide_w03_08_04','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm63', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm63')
    
    Guide_w03_08_04.w1 = '0.11436'
    Guide_w03_08_04.h1 = '0.07389'
    Guide_w03_08_04.w2 = '0.11407'
    Guide_w03_08_04.h2 = '0.07389'
    Guide_w03_08_04.l = '2.0'
    Guide_w03_08_04.R0 = '0.99'
    Guide_w03_08_04.Qc = '0.0219'
    Guide_w03_08_04.alpha = '6.07'
    Guide_w03_08_04.m = '1.0'
    Guide_w03_08_04.W = '0.003'
    Guide_w03_08_04.nslit = '1'
    Guide_w03_08_04.d = '0.0005'
    Guide_w03_08_04.mleft = '2.0'
    Guide_w03_08_04.mright = '2'
    Guide_w03_08_04.mtop = '3.0'
    Guide_w03_08_04.mbottom = '3.0'
    Guide_w03_08_04.nhslit = '1'
    Guide_w03_08_04.G = '0'
    Guide_w03_08_04.aleft = '-1'
    Guide_w03_08_04.aright = '-1'
    Guide_w03_08_04.atop = '-1'
    Guide_w03_08_04.abottom = '-1'
    Guide_w03_08_04.wavy = '0'
    Guide_w03_08_04.wavy_z = '0'
    Guide_w03_08_04.wavy_tb = '0'
    Guide_w03_08_04.wavy_lr = '0'
    Guide_w03_08_04.chamfers = '0'
    Guide_w03_08_04.chamfers_z = '0'
    Guide_w03_08_04.chamfers_lr = '0'
    Guide_w03_08_04.chamfers_tb = '0'
    Guide_w03_08_04.nelements = '1'
    Guide_w03_08_04.nu = '0'
    Guide_w03_08_04.phase = '0'
    Guide_w03_08_04.reflect = '"NULL"'
    
    # Comp instance Arm64, placement and parameters
    Arm64 = instr.add_component('Arm64','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_04', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_04')
    
    
    # Comp instance Guide_w03_08_05, placement and parameters
    Guide_w03_08_05 = instr.add_component('Guide_w03_08_05','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm64', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm64')
    
    Guide_w03_08_05.w1 = '0.11407'
    Guide_w03_08_05.h1 = '0.07389'
    Guide_w03_08_05.w2 = '0.11359'
    Guide_w03_08_05.h2 = '0.07389'
    Guide_w03_08_05.l = '2.0'
    Guide_w03_08_05.R0 = '0.99'
    Guide_w03_08_05.Qc = '0.0219'
    Guide_w03_08_05.alpha = '6.07'
    Guide_w03_08_05.m = '1.0'
    Guide_w03_08_05.W = '0.003'
    Guide_w03_08_05.nslit = '1'
    Guide_w03_08_05.d = '0.0005'
    Guide_w03_08_05.mleft = '2.0'
    Guide_w03_08_05.mright = '2'
    Guide_w03_08_05.mtop = '3.0'
    Guide_w03_08_05.mbottom = '3.0'
    Guide_w03_08_05.nhslit = '1'
    Guide_w03_08_05.G = '0'
    Guide_w03_08_05.aleft = '-1'
    Guide_w03_08_05.aright = '-1'
    Guide_w03_08_05.atop = '-1'
    Guide_w03_08_05.abottom = '-1'
    Guide_w03_08_05.wavy = '0'
    Guide_w03_08_05.wavy_z = '0'
    Guide_w03_08_05.wavy_tb = '0'
    Guide_w03_08_05.wavy_lr = '0'
    Guide_w03_08_05.chamfers = '0'
    Guide_w03_08_05.chamfers_z = '0'
    Guide_w03_08_05.chamfers_lr = '0'
    Guide_w03_08_05.chamfers_tb = '0'
    Guide_w03_08_05.nelements = '1'
    Guide_w03_08_05.nu = '0'
    Guide_w03_08_05.phase = '0'
    Guide_w03_08_05.reflect = '"NULL"'
    
    # Comp instance Arm65, placement and parameters
    Arm65 = instr.add_component('Arm65','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_05', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_05')
    
    
    # Comp instance Guide_w03_08_06, placement and parameters
    Guide_w03_08_06 = instr.add_component('Guide_w03_08_06','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm65', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm65')
    
    Guide_w03_08_06.w1 = '0.11359'
    Guide_w03_08_06.h1 = '0.07389'
    Guide_w03_08_06.w2 = '0.11290'
    Guide_w03_08_06.h2 = '0.07389'
    Guide_w03_08_06.l = '2.0'
    Guide_w03_08_06.R0 = '0.99'
    Guide_w03_08_06.Qc = '0.0219'
    Guide_w03_08_06.alpha = '6.07'
    Guide_w03_08_06.m = '1.0'
    Guide_w03_08_06.W = '0.003'
    Guide_w03_08_06.nslit = '1'
    Guide_w03_08_06.d = '0.0005'
    Guide_w03_08_06.mleft = '2.0'
    Guide_w03_08_06.mright = '2'
    Guide_w03_08_06.mtop = '3.0'
    Guide_w03_08_06.mbottom = '3.0'
    Guide_w03_08_06.nhslit = '1'
    Guide_w03_08_06.G = '0'
    Guide_w03_08_06.aleft = '-1'
    Guide_w03_08_06.aright = '-1'
    Guide_w03_08_06.atop = '-1'
    Guide_w03_08_06.abottom = '-1'
    Guide_w03_08_06.wavy = '0'
    Guide_w03_08_06.wavy_z = '0'
    Guide_w03_08_06.wavy_tb = '0'
    Guide_w03_08_06.wavy_lr = '0'
    Guide_w03_08_06.chamfers = '0'
    Guide_w03_08_06.chamfers_z = '0'
    Guide_w03_08_06.chamfers_lr = '0'
    Guide_w03_08_06.chamfers_tb = '0'
    Guide_w03_08_06.nelements = '1'
    Guide_w03_08_06.nu = '0'
    Guide_w03_08_06.phase = '0'
    Guide_w03_08_06.reflect = '"NULL"'
    
    # Comp instance Arm66, placement and parameters
    Arm66 = instr.add_component('Arm66','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_06', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_06')
    
    
    # Comp instance Guide_w03_08_07, placement and parameters
    Guide_w03_08_07 = instr.add_component('Guide_w03_08_07','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm66', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm66')
    
    Guide_w03_08_07.w1 = '0.1129'
    Guide_w03_08_07.h1 = '0.07389'
    Guide_w03_08_07.w2 = '0.11202'
    Guide_w03_08_07.h2 = '0.07389'
    Guide_w03_08_07.l = '2.0'
    Guide_w03_08_07.R0 = '0.99'
    Guide_w03_08_07.Qc = '0.0219'
    Guide_w03_08_07.alpha = '6.07'
    Guide_w03_08_07.m = '1.0'
    Guide_w03_08_07.W = '0.003'
    Guide_w03_08_07.nslit = '1'
    Guide_w03_08_07.d = '0.0005'
    Guide_w03_08_07.mleft = '2.0'
    Guide_w03_08_07.mright = '2'
    Guide_w03_08_07.mtop = '3.0'
    Guide_w03_08_07.mbottom = '3.0'
    Guide_w03_08_07.nhslit = '1'
    Guide_w03_08_07.G = '0'
    Guide_w03_08_07.aleft = '-1'
    Guide_w03_08_07.aright = '-1'
    Guide_w03_08_07.atop = '-1'
    Guide_w03_08_07.abottom = '-1'
    Guide_w03_08_07.wavy = '0'
    Guide_w03_08_07.wavy_z = '0'
    Guide_w03_08_07.wavy_tb = '0'
    Guide_w03_08_07.wavy_lr = '0'
    Guide_w03_08_07.chamfers = '0'
    Guide_w03_08_07.chamfers_z = '0'
    Guide_w03_08_07.chamfers_lr = '0'
    Guide_w03_08_07.chamfers_tb = '0'
    Guide_w03_08_07.nelements = '1'
    Guide_w03_08_07.nu = '0'
    Guide_w03_08_07.phase = '0'
    Guide_w03_08_07.reflect = '"NULL"'
    
    # Comp instance Arm67, placement and parameters
    Arm67 = instr.add_component('Arm67','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_07', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_07')
    
    
    # Comp instance Guide_w03_08_08, placement and parameters
    Guide_w03_08_08 = instr.add_component('Guide_w03_08_08','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm67', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm67')
    
    Guide_w03_08_08.w1 = '0.11202'
    Guide_w03_08_08.h1 = '0.07389'
    Guide_w03_08_08.w2 = '0.11092'
    Guide_w03_08_08.h2 = '0.07389'
    Guide_w03_08_08.l = '2.0'
    Guide_w03_08_08.R0 = '0.99'
    Guide_w03_08_08.Qc = '0.0219'
    Guide_w03_08_08.alpha = '6.07'
    Guide_w03_08_08.m = '1.0'
    Guide_w03_08_08.W = '0.003'
    Guide_w03_08_08.nslit = '1'
    Guide_w03_08_08.d = '0.0005'
    Guide_w03_08_08.mleft = '2.0'
    Guide_w03_08_08.mright = '2'
    Guide_w03_08_08.mtop = '3.0'
    Guide_w03_08_08.mbottom = '3.0'
    Guide_w03_08_08.nhslit = '1'
    Guide_w03_08_08.G = '0'
    Guide_w03_08_08.aleft = '-1'
    Guide_w03_08_08.aright = '-1'
    Guide_w03_08_08.atop = '-1'
    Guide_w03_08_08.abottom = '-1'
    Guide_w03_08_08.wavy = '0'
    Guide_w03_08_08.wavy_z = '0'
    Guide_w03_08_08.wavy_tb = '0'
    Guide_w03_08_08.wavy_lr = '0'
    Guide_w03_08_08.chamfers = '0'
    Guide_w03_08_08.chamfers_z = '0'
    Guide_w03_08_08.chamfers_lr = '0'
    Guide_w03_08_08.chamfers_tb = '0'
    Guide_w03_08_08.nelements = '1'
    Guide_w03_08_08.nu = '0'
    Guide_w03_08_08.phase = '0'
    Guide_w03_08_08.reflect = '"NULL"'
    
    # Comp instance Arm68, placement and parameters
    Arm68 = instr.add_component('Arm68','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_08', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_08')
    
    
    # Comp instance Guide_w03_08_09, placement and parameters
    Guide_w03_08_09 = instr.add_component('Guide_w03_08_09','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm68', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm68')
    
    Guide_w03_08_09.w1 = '0.11096'
    Guide_w03_08_09.h1 = '0.07389'
    Guide_w03_08_09.w2 = '0.10962'
    Guide_w03_08_09.h2 = '0.07389'
    Guide_w03_08_09.l = '2.0'
    Guide_w03_08_09.R0 = '0.99'
    Guide_w03_08_09.Qc = '0.0219'
    Guide_w03_08_09.alpha = '6.07'
    Guide_w03_08_09.m = '1.0'
    Guide_w03_08_09.W = '0.003'
    Guide_w03_08_09.nslit = '1'
    Guide_w03_08_09.d = '0.0005'
    Guide_w03_08_09.mleft = '2.0'
    Guide_w03_08_09.mright = '2'
    Guide_w03_08_09.mtop = '3.0'
    Guide_w03_08_09.mbottom = '3.0'
    Guide_w03_08_09.nhslit = '1'
    Guide_w03_08_09.G = '0'
    Guide_w03_08_09.aleft = '-1'
    Guide_w03_08_09.aright = '-1'
    Guide_w03_08_09.atop = '-1'
    Guide_w03_08_09.abottom = '-1'
    Guide_w03_08_09.wavy = '0'
    Guide_w03_08_09.wavy_z = '0'
    Guide_w03_08_09.wavy_tb = '0'
    Guide_w03_08_09.wavy_lr = '0'
    Guide_w03_08_09.chamfers = '0'
    Guide_w03_08_09.chamfers_z = '0'
    Guide_w03_08_09.chamfers_lr = '0'
    Guide_w03_08_09.chamfers_tb = '0'
    Guide_w03_08_09.nelements = '1'
    Guide_w03_08_09.nu = '0'
    Guide_w03_08_09.phase = '0'
    Guide_w03_08_09.reflect = '"NULL"'
    
    # Comp instance Arm69, placement and parameters
    Arm69 = instr.add_component('Arm69','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_09', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_09')
    
    
    # Comp instance Guide_w03_08_10, placement and parameters
    Guide_w03_08_10 = instr.add_component('Guide_w03_08_10','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm69', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm69')
    
    Guide_w03_08_10.w1 = '0.10962'
    Guide_w03_08_10.h1 = '0.07389'
    Guide_w03_08_10.w2 = '0.10809'
    Guide_w03_08_10.h2 = '0.07382'
    Guide_w03_08_10.l = '2.0'
    Guide_w03_08_10.R0 = '0.99'
    Guide_w03_08_10.Qc = '0.0219'
    Guide_w03_08_10.alpha = '6.07'
    Guide_w03_08_10.m = '1.0'
    Guide_w03_08_10.W = '0.003'
    Guide_w03_08_10.nslit = '1'
    Guide_w03_08_10.d = '0.0005'
    Guide_w03_08_10.mleft = '2.5'
    Guide_w03_08_10.mright = '2.5'
    Guide_w03_08_10.mtop = '2.5'
    Guide_w03_08_10.mbottom = '2.5'
    Guide_w03_08_10.nhslit = '1'
    Guide_w03_08_10.G = '0'
    Guide_w03_08_10.aleft = '-1'
    Guide_w03_08_10.aright = '-1'
    Guide_w03_08_10.atop = '-1'
    Guide_w03_08_10.abottom = '-1'
    Guide_w03_08_10.wavy = '0'
    Guide_w03_08_10.wavy_z = '0'
    Guide_w03_08_10.wavy_tb = '0'
    Guide_w03_08_10.wavy_lr = '0'
    Guide_w03_08_10.chamfers = '0'
    Guide_w03_08_10.chamfers_z = '0'
    Guide_w03_08_10.chamfers_lr = '0'
    Guide_w03_08_10.chamfers_tb = '0'
    Guide_w03_08_10.nelements = '1'
    Guide_w03_08_10.nu = '0'
    Guide_w03_08_10.phase = '0'
    Guide_w03_08_10.reflect = '"NULL"'
    
    # Comp instance Arm70, placement and parameters
    Arm70 = instr.add_component('Arm70','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_10', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_10')
    
    
    # Comp instance Guide_w03_08_11, placement and parameters
    Guide_w03_08_11 = instr.add_component('Guide_w03_08_11','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm70', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm70')
    
    Guide_w03_08_11.w1 = '0.10809'
    Guide_w03_08_11.h1 = '0.07382'
    Guide_w03_08_11.w2 = '0.10633'
    Guide_w03_08_11.h2 = '0.07360'
    Guide_w03_08_11.l = '2.0'
    Guide_w03_08_11.R0 = '0.99'
    Guide_w03_08_11.Qc = '0.0219'
    Guide_w03_08_11.alpha = '6.07'
    Guide_w03_08_11.m = '1.0'
    Guide_w03_08_11.W = '0.003'
    Guide_w03_08_11.nslit = '1'
    Guide_w03_08_11.d = '0.0005'
    Guide_w03_08_11.mleft = '2.0'
    Guide_w03_08_11.mright = '2'
    Guide_w03_08_11.mtop = '3.0'
    Guide_w03_08_11.mbottom = '3.0'
    Guide_w03_08_11.nhslit = '1'
    Guide_w03_08_11.G = '0'
    Guide_w03_08_11.aleft = '-1'
    Guide_w03_08_11.aright = '-1'
    Guide_w03_08_11.atop = '-1'
    Guide_w03_08_11.abottom = '-1'
    Guide_w03_08_11.wavy = '0'
    Guide_w03_08_11.wavy_z = '0'
    Guide_w03_08_11.wavy_tb = '0'
    Guide_w03_08_11.wavy_lr = '0'
    Guide_w03_08_11.chamfers = '0'
    Guide_w03_08_11.chamfers_z = '0'
    Guide_w03_08_11.chamfers_lr = '0'
    Guide_w03_08_11.chamfers_tb = '0'
    Guide_w03_08_11.nelements = '1'
    Guide_w03_08_11.nu = '0'
    Guide_w03_08_11.phase = '0'
    Guide_w03_08_11.reflect = '"NULL"'
    
    # Comp instance Arm71, placement and parameters
    Arm71 = instr.add_component('Arm71','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_11', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_11')
    
    
    # Comp instance Guide_w03_08_12, placement and parameters
    Guide_w03_08_12 = instr.add_component('Guide_w03_08_12','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm71', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm71')
    
    Guide_w03_08_12.w1 = '0.10633'
    Guide_w03_08_12.h1 = '0.0736'
    Guide_w03_08_12.w2 = '0.10434'
    Guide_w03_08_12.h2 = '0.07323'
    Guide_w03_08_12.l = '2.0'
    Guide_w03_08_12.R0 = '0.99'
    Guide_w03_08_12.Qc = '0.0219'
    Guide_w03_08_12.alpha = '6.07'
    Guide_w03_08_12.m = '1.0'
    Guide_w03_08_12.W = '0.003'
    Guide_w03_08_12.nslit = '1'
    Guide_w03_08_12.d = '0.0005'
    Guide_w03_08_12.mleft = '2.0'
    Guide_w03_08_12.mright = '2'
    Guide_w03_08_12.mtop = '3.5'
    Guide_w03_08_12.mbottom = '3.5'
    Guide_w03_08_12.nhslit = '1'
    Guide_w03_08_12.G = '0'
    Guide_w03_08_12.aleft = '-1'
    Guide_w03_08_12.aright = '-1'
    Guide_w03_08_12.atop = '-1'
    Guide_w03_08_12.abottom = '-1'
    Guide_w03_08_12.wavy = '0'
    Guide_w03_08_12.wavy_z = '0'
    Guide_w03_08_12.wavy_tb = '0'
    Guide_w03_08_12.wavy_lr = '0'
    Guide_w03_08_12.chamfers = '0'
    Guide_w03_08_12.chamfers_z = '0'
    Guide_w03_08_12.chamfers_lr = '0'
    Guide_w03_08_12.chamfers_tb = '0'
    Guide_w03_08_12.nelements = '1'
    Guide_w03_08_12.nu = '0'
    Guide_w03_08_12.phase = '0'
    Guide_w03_08_12.reflect = '"NULL"'
    
    # Comp instance Arm72, placement and parameters
    Arm72 = instr.add_component('Arm72','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_12', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_12')
    
    
    # Comp instance Guide_w03_08_13, placement and parameters
    Guide_w03_08_13 = instr.add_component('Guide_w03_08_13','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm72', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm72')
    
    Guide_w03_08_13.w1 = '0.10433'
    Guide_w03_08_13.h1 = '0.07323'
    Guide_w03_08_13.w2 = '0.10208'
    Guide_w03_08_13.h2 = '0.07271'
    Guide_w03_08_13.l = '2.0'
    Guide_w03_08_13.R0 = '0.99'
    Guide_w03_08_13.Qc = '0.0219'
    Guide_w03_08_13.alpha = '6.07'
    Guide_w03_08_13.m = '1.0'
    Guide_w03_08_13.W = '0.003'
    Guide_w03_08_13.nslit = '1'
    Guide_w03_08_13.d = '0.0005'
    Guide_w03_08_13.mleft = '2.0'
    Guide_w03_08_13.mright = '2.0'
    Guide_w03_08_13.mtop = '3.5'
    Guide_w03_08_13.mbottom = '3.5'
    Guide_w03_08_13.nhslit = '1'
    Guide_w03_08_13.G = '0'
    Guide_w03_08_13.aleft = '-1'
    Guide_w03_08_13.aright = '-1'
    Guide_w03_08_13.atop = '-1'
    Guide_w03_08_13.abottom = '-1'
    Guide_w03_08_13.wavy = '0'
    Guide_w03_08_13.wavy_z = '0'
    Guide_w03_08_13.wavy_tb = '0'
    Guide_w03_08_13.wavy_lr = '0'
    Guide_w03_08_13.chamfers = '0'
    Guide_w03_08_13.chamfers_z = '0'
    Guide_w03_08_13.chamfers_lr = '0'
    Guide_w03_08_13.chamfers_tb = '0'
    Guide_w03_08_13.nelements = '1'
    Guide_w03_08_13.nu = '0'
    Guide_w03_08_13.phase = '0'
    Guide_w03_08_13.reflect = '"NULL"'
    
    # Comp instance Arm73, placement and parameters
    Arm73 = instr.add_component('Arm73','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_13', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_13')
    
    
    # Comp instance Guide_w03_08_14, placement and parameters
    Guide_w03_08_14 = instr.add_component('Guide_w03_08_14','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm73', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm73')
    
    Guide_w03_08_14.w1 = '0.10208'
    Guide_w03_08_14.h1 = '0.07271'
    Guide_w03_08_14.w2 = '0.09956'
    Guide_w03_08_14.h2 = '0.07204'
    Guide_w03_08_14.l = '2.0'
    Guide_w03_08_14.R0 = '0.99'
    Guide_w03_08_14.Qc = '0.0219'
    Guide_w03_08_14.alpha = '6.07'
    Guide_w03_08_14.m = '1.0'
    Guide_w03_08_14.W = '0.003'
    Guide_w03_08_14.nslit = '1'
    Guide_w03_08_14.d = '0.0005'
    Guide_w03_08_14.mleft = '2.0'
    Guide_w03_08_14.mright = '2.0'
    Guide_w03_08_14.mtop = '2.5'
    Guide_w03_08_14.mbottom = '2.5'
    Guide_w03_08_14.nhslit = '1'
    Guide_w03_08_14.G = '0'
    Guide_w03_08_14.aleft = '-1'
    Guide_w03_08_14.aright = '-1'
    Guide_w03_08_14.atop = '-1'
    Guide_w03_08_14.abottom = '-1'
    Guide_w03_08_14.wavy = '0'
    Guide_w03_08_14.wavy_z = '0'
    Guide_w03_08_14.wavy_tb = '0'
    Guide_w03_08_14.wavy_lr = '0'
    Guide_w03_08_14.chamfers = '0'
    Guide_w03_08_14.chamfers_z = '0'
    Guide_w03_08_14.chamfers_lr = '0'
    Guide_w03_08_14.chamfers_tb = '0'
    Guide_w03_08_14.nelements = '1'
    Guide_w03_08_14.nu = '0'
    Guide_w03_08_14.phase = '0'
    Guide_w03_08_14.reflect = '"NULL"'
    
    # Comp instance Arm74, placement and parameters
    Arm74 = instr.add_component('Arm74','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_14', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_14')
    
    
    # Comp instance Guide_w03_08_15, placement and parameters
    Guide_w03_08_15 = instr.add_component('Guide_w03_08_15','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm74', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm74')
    
    Guide_w03_08_15.w1 = '0.09955'
    Guide_w03_08_15.h1 = '0.07204'
    Guide_w03_08_15.w2 = '0.09673'
    Guide_w03_08_15.h2 = '0.07121'
    Guide_w03_08_15.l = '2.0'
    Guide_w03_08_15.R0 = '0.99'
    Guide_w03_08_15.Qc = '0.0219'
    Guide_w03_08_15.alpha = '6.07'
    Guide_w03_08_15.m = '1.0'
    Guide_w03_08_15.W = '0.003'
    Guide_w03_08_15.nslit = '1'
    Guide_w03_08_15.d = '0.0005'
    Guide_w03_08_15.mleft = '2.0'
    Guide_w03_08_15.mright = '2.0'
    Guide_w03_08_15.mtop = '2.5'
    Guide_w03_08_15.mbottom = '2.5'
    Guide_w03_08_15.nhslit = '1'
    Guide_w03_08_15.G = '0'
    Guide_w03_08_15.aleft = '-1'
    Guide_w03_08_15.aright = '-1'
    Guide_w03_08_15.atop = '-1'
    Guide_w03_08_15.abottom = '-1'
    Guide_w03_08_15.wavy = '0'
    Guide_w03_08_15.wavy_z = '0'
    Guide_w03_08_15.wavy_tb = '0'
    Guide_w03_08_15.wavy_lr = '0'
    Guide_w03_08_15.chamfers = '0'
    Guide_w03_08_15.chamfers_z = '0'
    Guide_w03_08_15.chamfers_lr = '0'
    Guide_w03_08_15.chamfers_tb = '0'
    Guide_w03_08_15.nelements = '1'
    Guide_w03_08_15.nu = '0'
    Guide_w03_08_15.phase = '0'
    Guide_w03_08_15.reflect = '"NULL"'
    
    # Comp instance Arm75, placement and parameters
    Arm75 = instr.add_component('Arm75','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_15', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_15')
    
    
    # Comp instance Guide_w03_08_16, placement and parameters
    Guide_w03_08_16 = instr.add_component('Guide_w03_08_16','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm75', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm75')
    
    Guide_w03_08_16.w1 = '0.09673'
    Guide_w03_08_16.h1 = '0.07121'
    Guide_w03_08_16.w2 = '0.09359'
    Guide_w03_08_16.h2 = '0.07022'
    Guide_w03_08_16.l = '2.0'
    Guide_w03_08_16.R0 = '0.99'
    Guide_w03_08_16.Qc = '0.0219'
    Guide_w03_08_16.alpha = '6.07'
    Guide_w03_08_16.m = '1.0'
    Guide_w03_08_16.W = '0.003'
    Guide_w03_08_16.nslit = '1'
    Guide_w03_08_16.d = '0.0005'
    Guide_w03_08_16.mleft = '2.5'
    Guide_w03_08_16.mright = '2.5'
    Guide_w03_08_16.mtop = '3.5'
    Guide_w03_08_16.mbottom = '3.5'
    Guide_w03_08_16.nhslit = '1'
    Guide_w03_08_16.G = '0'
    Guide_w03_08_16.aleft = '-1'
    Guide_w03_08_16.aright = '-1'
    Guide_w03_08_16.atop = '-1'
    Guide_w03_08_16.abottom = '-1'
    Guide_w03_08_16.wavy = '0'
    Guide_w03_08_16.wavy_z = '0'
    Guide_w03_08_16.wavy_tb = '0'
    Guide_w03_08_16.wavy_lr = '0'
    Guide_w03_08_16.chamfers = '0'
    Guide_w03_08_16.chamfers_z = '0'
    Guide_w03_08_16.chamfers_lr = '0'
    Guide_w03_08_16.chamfers_tb = '0'
    Guide_w03_08_16.nelements = '1'
    Guide_w03_08_16.nu = '0'
    Guide_w03_08_16.phase = '0'
    Guide_w03_08_16.reflect = '"NULL"'
    
    # Comp instance Arm76, placement and parameters
    Arm76 = instr.add_component('Arm76','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_16', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_16')
    
    
    # Comp instance Guide_w03_08_17, placement and parameters
    Guide_w03_08_17 = instr.add_component('Guide_w03_08_17','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm76', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm76')
    
    Guide_w03_08_17.w1 = '0.09359'
    Guide_w03_08_17.h1 = '0.07022'
    Guide_w03_08_17.w2 = '0.09009'
    Guide_w03_08_17.h2 = '0.06906'
    Guide_w03_08_17.l = '2.0'
    Guide_w03_08_17.R0 = '0.99'
    Guide_w03_08_17.Qc = '0.0219'
    Guide_w03_08_17.alpha = '6.07'
    Guide_w03_08_17.m = '1.0'
    Guide_w03_08_17.W = '0.003'
    Guide_w03_08_17.nslit = '1'
    Guide_w03_08_17.d = '0.0005'
    Guide_w03_08_17.mleft = '2.5'
    Guide_w03_08_17.mright = '2.5'
    Guide_w03_08_17.mtop = '3.5'
    Guide_w03_08_17.mbottom = '3.5'
    Guide_w03_08_17.nhslit = '1'
    Guide_w03_08_17.G = '0'
    Guide_w03_08_17.aleft = '-1'
    Guide_w03_08_17.aright = '-1'
    Guide_w03_08_17.atop = '-1'
    Guide_w03_08_17.abottom = '-1'
    Guide_w03_08_17.wavy = '0'
    Guide_w03_08_17.wavy_z = '0'
    Guide_w03_08_17.wavy_tb = '0'
    Guide_w03_08_17.wavy_lr = '0'
    Guide_w03_08_17.chamfers = '0'
    Guide_w03_08_17.chamfers_z = '0'
    Guide_w03_08_17.chamfers_lr = '0'
    Guide_w03_08_17.chamfers_tb = '0'
    Guide_w03_08_17.nelements = '1'
    Guide_w03_08_17.nu = '0'
    Guide_w03_08_17.phase = '0'
    Guide_w03_08_17.reflect = '"NULL"'
    
    # Comp instance Arm77, placement and parameters
    Arm77 = instr.add_component('Arm77','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_17', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_17')
    
    
    # Comp instance Guide_w03_08_18, placement and parameters
    Guide_w03_08_18 = instr.add_component('Guide_w03_08_18','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm77', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm77')
    
    Guide_w03_08_18.w1 = '0.09009'
    Guide_w03_08_18.h1 = '0.06906'
    Guide_w03_08_18.w2 = '0.08620'
    Guide_w03_08_18.h2 = '0.06772'
    Guide_w03_08_18.l = '2.0'
    Guide_w03_08_18.R0 = '0.99'
    Guide_w03_08_18.Qc = '0.0219'
    Guide_w03_08_18.alpha = '6.07'
    Guide_w03_08_18.m = '1.0'
    Guide_w03_08_18.W = '0.003'
    Guide_w03_08_18.nslit = '1'
    Guide_w03_08_18.d = '0.0005'
    Guide_w03_08_18.mleft = '2.5'
    Guide_w03_08_18.mright = '2.5'
    Guide_w03_08_18.mtop = '3.5'
    Guide_w03_08_18.mbottom = '3.5'
    Guide_w03_08_18.nhslit = '1'
    Guide_w03_08_18.G = '0'
    Guide_w03_08_18.aleft = '-1'
    Guide_w03_08_18.aright = '-1'
    Guide_w03_08_18.atop = '-1'
    Guide_w03_08_18.abottom = '-1'
    Guide_w03_08_18.wavy = '0'
    Guide_w03_08_18.wavy_z = '0'
    Guide_w03_08_18.wavy_tb = '0'
    Guide_w03_08_18.wavy_lr = '0'
    Guide_w03_08_18.chamfers = '0'
    Guide_w03_08_18.chamfers_z = '0'
    Guide_w03_08_18.chamfers_lr = '0'
    Guide_w03_08_18.chamfers_tb = '0'
    Guide_w03_08_18.nelements = '1'
    Guide_w03_08_18.nu = '0'
    Guide_w03_08_18.phase = '0'
    Guide_w03_08_18.reflect = '"NULL"'
    
    # Comp instance Arm78, placement and parameters
    Arm78 = instr.add_component('Arm78','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_18', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_18')
    
    
    # Comp instance Guide_w03_08_19, placement and parameters
    Guide_w03_08_19 = instr.add_component('Guide_w03_08_19','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm78', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm78')
    
    Guide_w03_08_19.w1 = '0.08620'
    Guide_w03_08_19.h1 = '0.06772'
    Guide_w03_08_19.w2 = '0.08185'
    Guide_w03_08_19.h2 = '0.06619'
    Guide_w03_08_19.l = '2.0'
    Guide_w03_08_19.R0 = '0.99'
    Guide_w03_08_19.Qc = '0.0219'
    Guide_w03_08_19.alpha = '6.07'
    Guide_w03_08_19.m = '1.0'
    Guide_w03_08_19.W = '0.003'
    Guide_w03_08_19.nslit = '1'
    Guide_w03_08_19.d = '0.0005'
    Guide_w03_08_19.mleft = '3.0'
    Guide_w03_08_19.mright = '3.0'
    Guide_w03_08_19.mtop = '3.5'
    Guide_w03_08_19.mbottom = '3.5'
    Guide_w03_08_19.nhslit = '1'
    Guide_w03_08_19.G = '0'
    Guide_w03_08_19.aleft = '-1'
    Guide_w03_08_19.aright = '-1'
    Guide_w03_08_19.atop = '-1'
    Guide_w03_08_19.abottom = '-1'
    Guide_w03_08_19.wavy = '0'
    Guide_w03_08_19.wavy_z = '0'
    Guide_w03_08_19.wavy_tb = '0'
    Guide_w03_08_19.wavy_lr = '0'
    Guide_w03_08_19.chamfers = '0'
    Guide_w03_08_19.chamfers_z = '0'
    Guide_w03_08_19.chamfers_lr = '0'
    Guide_w03_08_19.chamfers_tb = '0'
    Guide_w03_08_19.nelements = '1'
    Guide_w03_08_19.nu = '0'
    Guide_w03_08_19.phase = '0'
    Guide_w03_08_19.reflect = '"NULL"'
    
    # Comp instance Arm79, placement and parameters
    Arm79 = instr.add_component('Arm79','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_19', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_19')
    
    
    # Comp instance Guide_w03_08_20, placement and parameters
    Guide_w03_08_20 = instr.add_component('Guide_w03_08_20','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm79', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm79')
    
    Guide_w03_08_20.w1 = '0.08185'
    Guide_w03_08_20.h1 = '0.06619'
    Guide_w03_08_20.w2 = '0.07697'
    Guide_w03_08_20.h2 = '0.06446'
    Guide_w03_08_20.l = '2.0'
    Guide_w03_08_20.R0 = '0.99'
    Guide_w03_08_20.Qc = '0.0219'
    Guide_w03_08_20.alpha = '6.07'
    Guide_w03_08_20.m = '1.0'
    Guide_w03_08_20.W = '0.003'
    Guide_w03_08_20.nslit = '1'
    Guide_w03_08_20.d = '0.0005'
    Guide_w03_08_20.mleft = '3.0'
    Guide_w03_08_20.mright = '3.0'
    Guide_w03_08_20.mtop = '3.5'
    Guide_w03_08_20.mbottom = '3.5'
    Guide_w03_08_20.nhslit = '1'
    Guide_w03_08_20.G = '0'
    Guide_w03_08_20.aleft = '-1'
    Guide_w03_08_20.aright = '-1'
    Guide_w03_08_20.atop = '-1'
    Guide_w03_08_20.abottom = '-1'
    Guide_w03_08_20.wavy = '0'
    Guide_w03_08_20.wavy_z = '0'
    Guide_w03_08_20.wavy_tb = '0'
    Guide_w03_08_20.wavy_lr = '0'
    Guide_w03_08_20.chamfers = '0'
    Guide_w03_08_20.chamfers_z = '0'
    Guide_w03_08_20.chamfers_lr = '0'
    Guide_w03_08_20.chamfers_tb = '0'
    Guide_w03_08_20.nelements = '1'
    Guide_w03_08_20.nu = '0'
    Guide_w03_08_20.phase = '0'
    Guide_w03_08_20.reflect = '"NULL"'
    
    # Comp instance Arm80, placement and parameters
    Arm80 = instr.add_component('Arm80','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_20', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_20')
    
    
    # Comp instance Guide_w03_08_21, placement and parameters
    Guide_w03_08_21 = instr.add_component('Guide_w03_08_21','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm80', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm80')
    
    Guide_w03_08_21.w1 = '0.07696'
    Guide_w03_08_21.h1 = '0.06446'
    Guide_w03_08_21.w2 = '0.07144'
    Guide_w03_08_21.h2 = '0.06250'
    Guide_w03_08_21.l = '2.0'
    Guide_w03_08_21.R0 = '0.99'
    Guide_w03_08_21.Qc = '0.0219'
    Guide_w03_08_21.alpha = '6.07'
    Guide_w03_08_21.m = '1.0'
    Guide_w03_08_21.W = '0.003'
    Guide_w03_08_21.nslit = '1'
    Guide_w03_08_21.d = '0.0005'
    Guide_w03_08_21.mleft = '3.0'
    Guide_w03_08_21.mright = '3.0'
    Guide_w03_08_21.mtop = '3.5'
    Guide_w03_08_21.mbottom = '3.5'
    Guide_w03_08_21.nhslit = '1'
    Guide_w03_08_21.G = '0'
    Guide_w03_08_21.aleft = '-1'
    Guide_w03_08_21.aright = '-1'
    Guide_w03_08_21.atop = '-1'
    Guide_w03_08_21.abottom = '-1'
    Guide_w03_08_21.wavy = '0'
    Guide_w03_08_21.wavy_z = '0'
    Guide_w03_08_21.wavy_tb = '0'
    Guide_w03_08_21.wavy_lr = '0'
    Guide_w03_08_21.chamfers = '0'
    Guide_w03_08_21.chamfers_z = '0'
    Guide_w03_08_21.chamfers_lr = '0'
    Guide_w03_08_21.chamfers_tb = '0'
    Guide_w03_08_21.nelements = '1'
    Guide_w03_08_21.nu = '0'
    Guide_w03_08_21.phase = '0'
    Guide_w03_08_21.reflect = '"NULL"'
    
    # Comp instance Arm81, placement and parameters
    Arm81 = instr.add_component('Arm81','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_21', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_21')
    
    
    # Comp instance Guide_w03_08_22, placement and parameters
    Guide_w03_08_22 = instr.add_component('Guide_w03_08_22','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm81', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm81')
    
    Guide_w03_08_22.w1 = '0.07144'
    Guide_w03_08_22.h1 = '0.06250'
    Guide_w03_08_22.w2 = '0.06512'
    Guide_w03_08_22.h2 = '0.06031'
    Guide_w03_08_22.l = '2.0'
    Guide_w03_08_22.R0 = '0.99'
    Guide_w03_08_22.Qc = '0.0219'
    Guide_w03_08_22.alpha = '6.07'
    Guide_w03_08_22.m = '1.0'
    Guide_w03_08_22.W = '0.003'
    Guide_w03_08_22.nslit = '1'
    Guide_w03_08_22.d = '0.0005'
    Guide_w03_08_22.mleft = '3.5'
    Guide_w03_08_22.mright = '3.5'
    Guide_w03_08_22.mtop = '3.5'
    Guide_w03_08_22.mbottom = '3.5'
    Guide_w03_08_22.nhslit = '1'
    Guide_w03_08_22.G = '0'
    Guide_w03_08_22.aleft = '-1'
    Guide_w03_08_22.aright = '-1'
    Guide_w03_08_22.atop = '-1'
    Guide_w03_08_22.abottom = '-1'
    Guide_w03_08_22.wavy = '0'
    Guide_w03_08_22.wavy_z = '0'
    Guide_w03_08_22.wavy_tb = '0'
    Guide_w03_08_22.wavy_lr = '0'
    Guide_w03_08_22.chamfers = '0'
    Guide_w03_08_22.chamfers_z = '0'
    Guide_w03_08_22.chamfers_lr = '0'
    Guide_w03_08_22.chamfers_tb = '0'
    Guide_w03_08_22.nelements = '1'
    Guide_w03_08_22.nu = '0'
    Guide_w03_08_22.phase = '0'
    Guide_w03_08_22.reflect = '"NULL"'
    
    # Comp instance Arm82, placement and parameters
    Arm82 = instr.add_component('Arm82','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_22', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_22')
    
    
    # Comp instance Guide_w03_08_23, placement and parameters
    Guide_w03_08_23 = instr.add_component('Guide_w03_08_23','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm82', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm82')
    
    Guide_w03_08_23.w1 = '0.06511'
    Guide_w03_08_23.h1 = '0.06031'
    Guide_w03_08_23.w2 = '0.05772'
    Guide_w03_08_23.h2 = '0.05784'
    Guide_w03_08_23.l = '2.0'
    Guide_w03_08_23.R0 = '0.99'
    Guide_w03_08_23.Qc = '0.0219'
    Guide_w03_08_23.alpha = '6.07'
    Guide_w03_08_23.m = '1.0'
    Guide_w03_08_23.W = '0.003'
    Guide_w03_08_23.nslit = '1'
    Guide_w03_08_23.d = '0.0005'
    Guide_w03_08_23.mleft = '3.5'
    Guide_w03_08_23.mright = '3.5'
    Guide_w03_08_23.mtop = '3.5'
    Guide_w03_08_23.mbottom = '3.5'
    Guide_w03_08_23.nhslit = '1'
    Guide_w03_08_23.G = '0'
    Guide_w03_08_23.aleft = '-1'
    Guide_w03_08_23.aright = '-1'
    Guide_w03_08_23.atop = '-1'
    Guide_w03_08_23.abottom = '-1'
    Guide_w03_08_23.wavy = '0'
    Guide_w03_08_23.wavy_z = '0'
    Guide_w03_08_23.wavy_tb = '0'
    Guide_w03_08_23.wavy_lr = '0'
    Guide_w03_08_23.chamfers = '0'
    Guide_w03_08_23.chamfers_z = '0'
    Guide_w03_08_23.chamfers_lr = '0'
    Guide_w03_08_23.chamfers_tb = '0'
    Guide_w03_08_23.nelements = '1'
    Guide_w03_08_23.nu = '0'
    Guide_w03_08_23.phase = '0'
    Guide_w03_08_23.reflect = '"NULL"'
    
    # Comp instance Arm83, placement and parameters
    Arm83 = instr.add_component('Arm83','Arm', AT=['0', '0', '2.0 + 0.001'], AT_RELATIVE='Guide_w03_08_23', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_23')
    
    
    # Comp instance Guide_w03_08_24, placement and parameters
    Guide_w03_08_24 = instr.add_component('Guide_w03_08_24','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm83', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm83')
    
    Guide_w03_08_24.w1 = '0.05772'
    Guide_w03_08_24.h1 = '0.05784'
    Guide_w03_08_24.w2 = '0.04878'
    Guide_w03_08_24.h2 = '0.05507'
    Guide_w03_08_24.l = '2.0'
    Guide_w03_08_24.R0 = '0.99'
    Guide_w03_08_24.Qc = '0.0219'
    Guide_w03_08_24.alpha = '6.07'
    Guide_w03_08_24.m = '1.0'
    Guide_w03_08_24.W = '0.003'
    Guide_w03_08_24.nslit = '1'
    Guide_w03_08_24.d = '0.0005'
    Guide_w03_08_24.mleft = '3.5'
    Guide_w03_08_24.mright = '3.5'
    Guide_w03_08_24.mtop = '3.5'
    Guide_w03_08_24.mbottom = '3.5'
    Guide_w03_08_24.nhslit = '1'
    Guide_w03_08_24.G = '0'
    Guide_w03_08_24.aleft = '-1'
    Guide_w03_08_24.aright = '-1'
    Guide_w03_08_24.atop = '-1'
    Guide_w03_08_24.abottom = '-1'
    Guide_w03_08_24.wavy = '0'
    Guide_w03_08_24.wavy_z = '0'
    Guide_w03_08_24.wavy_tb = '0'
    Guide_w03_08_24.wavy_lr = '0'
    Guide_w03_08_24.chamfers = '0'
    Guide_w03_08_24.chamfers_z = '0'
    Guide_w03_08_24.chamfers_lr = '0'
    Guide_w03_08_24.chamfers_tb = '0'
    Guide_w03_08_24.nelements = '1'
    Guide_w03_08_24.nu = '0'
    Guide_w03_08_24.phase = '0'
    Guide_w03_08_24.reflect = '"NULL"'
    
    # Comp instance Arm84, placement and parameters
    Arm84 = instr.add_component('Arm84','Arm', AT=['0', '0', '2.0 + 0.002'], AT_RELATIVE='Guide_w03_08_24', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_24')
    
    
    # Comp instance Guide_w03_08_25, placement and parameters
    Guide_w03_08_25 = instr.add_component('Guide_w03_08_25','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm84', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm84')
    
    Guide_w03_08_25.w1 = '0.04877'
    Guide_w03_08_25.h1 = '0.05507'
    Guide_w03_08_25.w2 = '0.03988'
    Guide_w03_08_25.h2 = '0.05262'
    Guide_w03_08_25.l = '1.5894'
    Guide_w03_08_25.R0 = '0.99'
    Guide_w03_08_25.Qc = '0.0219'
    Guide_w03_08_25.alpha = '6.07'
    Guide_w03_08_25.m = '1.0'
    Guide_w03_08_25.W = '0.003'
    Guide_w03_08_25.nslit = '1'
    Guide_w03_08_25.d = '0.0005'
    Guide_w03_08_25.mleft = '3.5'
    Guide_w03_08_25.mright = '3.5'
    Guide_w03_08_25.mtop = '3.5'
    Guide_w03_08_25.mbottom = '3.5'
    Guide_w03_08_25.nhslit = '1'
    Guide_w03_08_25.G = '0'
    Guide_w03_08_25.aleft = '-1'
    Guide_w03_08_25.aright = '-1'
    Guide_w03_08_25.atop = '-1'
    Guide_w03_08_25.abottom = '-1'
    Guide_w03_08_25.wavy = '0'
    Guide_w03_08_25.wavy_z = '0'
    Guide_w03_08_25.wavy_tb = '0'
    Guide_w03_08_25.wavy_lr = '0'
    Guide_w03_08_25.chamfers = '0'
    Guide_w03_08_25.chamfers_z = '0'
    Guide_w03_08_25.chamfers_lr = '0'
    Guide_w03_08_25.chamfers_tb = '0'
    Guide_w03_08_25.nelements = '1'
    Guide_w03_08_25.nu = '0'
    Guide_w03_08_25.phase = '0'
    Guide_w03_08_25.reflect = '"NULL"'
    
    # Comp instance Arm85, placement and parameters
    Arm85 = instr.add_component('Arm85','Arm', AT=['0', '0', '1.5894 + 0.001'], AT_RELATIVE='Guide_w03_08_25', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_25')
    
    
    # Comp instance Guide_w03_08_26, placement and parameters
    Guide_w03_08_26 = instr.add_component('Guide_w03_08_26','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm85', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm85')
    
    Guide_w03_08_26.w1 = '0.03988'
    Guide_w03_08_26.h1 = '0.05262'
    Guide_w03_08_26.w2 = '0.02782'
    Guide_w03_08_26.h2 = '0.04991'
    Guide_w03_08_26.l = '1.5894'
    Guide_w03_08_26.R0 = '0.99'
    Guide_w03_08_26.Qc = '0.0219'
    Guide_w03_08_26.alpha = '6.07'
    Guide_w03_08_26.m = '1.0'
    Guide_w03_08_26.W = '0.003'
    Guide_w03_08_26.nslit = '1'
    Guide_w03_08_26.d = '0.0005'
    Guide_w03_08_26.mleft = '3.5'
    Guide_w03_08_26.mright = '3.5'
    Guide_w03_08_26.mtop = '3.5'
    Guide_w03_08_26.mbottom = '3.5'
    Guide_w03_08_26.nhslit = '1'
    Guide_w03_08_26.G = '0'
    Guide_w03_08_26.aleft = '-1'
    Guide_w03_08_26.aright = '-1'
    Guide_w03_08_26.atop = '-1'
    Guide_w03_08_26.abottom = '-1'
    Guide_w03_08_26.wavy = '0'
    Guide_w03_08_26.wavy_z = '0'
    Guide_w03_08_26.wavy_tb = '0'
    Guide_w03_08_26.wavy_lr = '0'
    Guide_w03_08_26.chamfers = '0'
    Guide_w03_08_26.chamfers_z = '0'
    Guide_w03_08_26.chamfers_lr = '0'
    Guide_w03_08_26.chamfers_tb = '0'
    Guide_w03_08_26.nelements = '1'
    Guide_w03_08_26.nu = '0'
    Guide_w03_08_26.phase = '0'
    Guide_w03_08_26.reflect = '"NULL"'
    
    # Comp instance Arm86, placement and parameters
    Arm86 = instr.add_component('Arm86','Arm', AT=['0', '0', '1.5894 + 0.003'], AT_RELATIVE='Guide_w03_08_26', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_08_26')
    
    
    # Comp instance Guide_w03_09_01, placement and parameters
    Guide_w03_09_01 = instr.add_component('Guide_w03_09_01','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm86', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm86')
    
    Guide_w03_09_01.w1 = '0.02779'
    Guide_w03_09_01.h1 = '0.04991'
    Guide_w03_09_01.w2 = '0.02258'
    Guide_w03_09_01.h2 = '0.04900'
    Guide_w03_09_01.l = '0.6 -0.1'
    Guide_w03_09_01.R0 = '0.99'
    Guide_w03_09_01.Qc = '0.0219'
    Guide_w03_09_01.alpha = '6.07'
    Guide_w03_09_01.m = '1.0'
    Guide_w03_09_01.W = '0.003'
    Guide_w03_09_01.nslit = '1'
    Guide_w03_09_01.d = '0.0005'
    Guide_w03_09_01.mleft = '3.5'
    Guide_w03_09_01.mright = '3.5'
    Guide_w03_09_01.mtop = '3.5'
    Guide_w03_09_01.mbottom = '3.5'
    Guide_w03_09_01.nhslit = '1'
    Guide_w03_09_01.G = '0'
    Guide_w03_09_01.aleft = '-1'
    Guide_w03_09_01.aright = '-1'
    Guide_w03_09_01.atop = '-1'
    Guide_w03_09_01.abottom = '-1'
    Guide_w03_09_01.wavy = '0'
    Guide_w03_09_01.wavy_z = '0'
    Guide_w03_09_01.wavy_tb = '0'
    Guide_w03_09_01.wavy_lr = '0'
    Guide_w03_09_01.chamfers = '0'
    Guide_w03_09_01.chamfers_z = '0'
    Guide_w03_09_01.chamfers_lr = '0'
    Guide_w03_09_01.chamfers_tb = '0'
    Guide_w03_09_01.nelements = '1'
    Guide_w03_09_01.nu = '0'
    Guide_w03_09_01.phase = '0'
    Guide_w03_09_01.reflect = '"NULL"'
    
    # Comp instance Arm87_WindowPreMChopper, placement and parameters
    Arm87_WindowPreMChopper = instr.add_component('Arm87_WindowPreMChopper','Arm', AT=['0', '0', '0.51 + 1e-6'], AT_RELATIVE='Guide_w03_09_01', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_w03_09_01')
    
    
    # Comp instance M1, placement and parameters
    M1 = instr.add_component('M1','DiskChopper', AT=['0', '0', '0.02'], AT_RELATIVE='Arm87_WindowPreMChopper', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm87_WindowPreMChopper')
    
    M1.theta_0 = 'theta_M'
    M1.radius = '0.35'
    M1.yheight = '0.04900'
    M1.nu = 'Freq_M'
    M1.nslit = '1'
    M1.jitter = '0'
    M1.delay = 'M1_Delay'
    M1.isfirst = '0'
    M1.n_pulse = '1'
    M1.abs_out = '1'
    M1.phase = '0'
    M1.xwidth = '0'
    M1.verbose = '1'
    
    # Comp instance TOF_M, placement and parameters
    TOF_M = instr.add_component('TOF_M','TOF_monitor', AT=['0', '0', '0.000000001'], AT_RELATIVE='M1', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M1')
    
    TOF_M.nt = '1000'
    TOF_M.filename = '"TOF_M"'
    TOF_M.xmin = '-0.05'
    TOF_M.xmax = '0.05'
    TOF_M.ymin = '-0.05'
    TOF_M.ymax = '0.05'
    TOF_M.xwidth = '0'
    TOF_M.yheight = '0'
    TOF_M.tmin = '252.78 * ( lambda_min -0.2 ) * Distance_M1'
    TOF_M.tmax = '252.78 * ( lambda_min + 0.2 ) * Distance_M1'
    TOF_M.dt = '1.0'
    TOF_M.restore_neutron = '1'
    TOF_M.nowritefile = '0'
    
    # Comp instance M2, placement and parameters
    M2 = instr.add_component('M2','DiskChopper', AT=['0', '0', '0.006'], AT_RELATIVE='TOF_M', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='TOF_M')
    
    M2.theta_0 = 'theta_M'
    M2.radius = '0.35'
    M2.yheight = '0.04900'
    M2.nu = '- Freq_M'
    M2.nslit = '1'
    M2.jitter = '0'
    M2.delay = 'M2_Delay'
    M2.isfirst = '0'
    M2.n_pulse = '1'
    M2.abs_out = '1'
    M2.phase = '0'
    M2.xwidth = '0'
    M2.verbose = '1'
    
    # Comp instance Lambda_M, placement and parameters
    Lambda_M = instr.add_component('Lambda_M','L_monitor', AT=['0', '0', '0.001'], AT_RELATIVE='M2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='M2')
    
    Lambda_M.nL = '1000'
    Lambda_M.filename = '"Lambda_M"'
    Lambda_M.nowritefile = '0'
    Lambda_M.xmin = '-0.05'
    Lambda_M.xmax = '0.05'
    Lambda_M.ymin = '-0.05'
    Lambda_M.ymax = '0.05'
    Lambda_M.xwidth = '0'
    Lambda_M.yheight = '0'
    Lambda_M.Lmin = 'lambda_min -0.8'
    Lambda_M.Lmax = 'lambda_min + 0.8'
    Lambda_M.restore_neutron = '1'
    
    # Comp instance Arm88_WindowPostMChopper, placement and parameters
    Arm88_WindowPostMChopper = instr.add_component('Arm88_WindowPostMChopper','Arm', AT=['0', '0', 'dist_m'], AT_RELATIVE='Arm87_WindowPreMChopper', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm87_WindowPreMChopper')
    
    
    # Comp instance Arm89_Windows_Monitor, placement and parameters
    Arm89_Windows_Monitor = instr.add_component('Arm89_Windows_Monitor','Arm', AT=['0', '0', '0.0001'], AT_RELATIVE='Arm88_WindowPostMChopper', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm88_WindowPostMChopper')
    
    
    # Comp instance Guide_final_straight, placement and parameters
    Guide_final_straight = instr.add_component('Guide_final_straight','Guide_gravity', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm89_Windows_Monitor', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm89_Windows_Monitor')
    
    Guide_final_straight.w1 = '0.02258'
    Guide_final_straight.h1 = '0.049'
    Guide_final_straight.w2 = '0.02258'
    Guide_final_straight.h2 = '0.049'
    Guide_final_straight.l = '0.30'
    Guide_final_straight.R0 = '0.99'
    Guide_final_straight.Qc = '0.0219'
    Guide_final_straight.alpha = '6.07'
    Guide_final_straight.m = '1.0'
    Guide_final_straight.W = '0.003'
    Guide_final_straight.nslit = '1'
    Guide_final_straight.d = '0.0005'
    Guide_final_straight.mleft = '3.5'
    Guide_final_straight.mright = '3.5'
    Guide_final_straight.mtop = '3.5'
    Guide_final_straight.mbottom = '3.5'
    Guide_final_straight.nhslit = '1'
    Guide_final_straight.G = '0'
    Guide_final_straight.aleft = '-1'
    Guide_final_straight.aright = '-1'
    Guide_final_straight.atop = '-1'
    Guide_final_straight.abottom = '-1'
    Guide_final_straight.wavy = '0'
    Guide_final_straight.wavy_z = '0'
    Guide_final_straight.wavy_tb = '0'
    Guide_final_straight.wavy_lr = '0'
    Guide_final_straight.chamfers = '0'
    Guide_final_straight.chamfers_z = '0'
    Guide_final_straight.chamfers_lr = '0'
    Guide_final_straight.chamfers_tb = '0'
    Guide_final_straight.nelements = '1'
    Guide_final_straight.nu = '0'
    Guide_final_straight.phase = '0'
    Guide_final_straight.reflect = '"NULL"'
    
    # Comp instance Arm91_Windows_Monitor, placement and parameters
    Arm91_Windows_Monitor = instr.add_component('Arm91_Windows_Monitor','Arm', AT=['0', '0', '0.3 + 0.03'], AT_RELATIVE='Guide_final_straight', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_final_straight')
    
    
    # Comp instance Guide_Final, placement and parameters
    Guide_Final = instr.add_component('Guide_Final','Guide_gravity', AT=['0.0', '0.0', '1e-06'], AT_RELATIVE='Arm91_Windows_Monitor', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm91_Windows_Monitor')
    
    Guide_Final.w1 = '0.02258'
    Guide_Final.h1 = '0.0490'
    Guide_Final.w2 = '0.0203'
    Guide_Final.h2 = '0.0450'
    Guide_Final.l = '0.914'
    Guide_Final.R0 = '0.99'
    Guide_Final.Qc = '0.0219'
    Guide_Final.alpha = '6.07'
    Guide_Final.m = '1.0'
    Guide_Final.W = '0.003'
    Guide_Final.nslit = '1'
    Guide_Final.d = '0.0005'
    Guide_Final.mleft = '3.5'
    Guide_Final.mright = '3.5'
    Guide_Final.mtop = '3.5'
    Guide_Final.mbottom = '3.5'
    Guide_Final.nhslit = '1'
    Guide_Final.G = '0'
    Guide_Final.aleft = '-1'
    Guide_Final.aright = '-1'
    Guide_Final.atop = '-1'
    Guide_Final.abottom = '-1'
    Guide_Final.wavy = '0'
    Guide_Final.wavy_z = '0'
    Guide_Final.wavy_tb = '0'
    Guide_Final.wavy_lr = '0'
    Guide_Final.chamfers = '0'
    Guide_Final.chamfers_z = '0'
    Guide_Final.chamfers_lr = '0'
    Guide_Final.chamfers_tb = '0'
    Guide_Final.nelements = '1'
    Guide_Final.nu = '0'
    Guide_Final.phase = '0'
    Guide_Final.reflect = '"NULL"'
    
    # Comp instance EndOfGuide, placement and parameters
    EndOfGuide = instr.add_component('EndOfGuide','Arm', AT=['0', '0', '0.914 + 0.0001'], AT_RELATIVE='Guide_Final', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Guide_Final')
    
    
    # Comp instance Arm_Sample, placement and parameters
    Arm_Sample = instr.add_component('Arm_Sample','Arm', AT=['0', '0', '0.2'], AT_RELATIVE='EndOfGuide', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='EndOfGuide')
    
    
    # Comp instance PSD_Out, placement and parameters
    PSD_Out = instr.add_component('PSD_Out','PSD_monitor', AT=['0', '0', '1e-06'], AT_RELATIVE='Arm_Sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Arm_Sample')
    
    PSD_Out.nx = '110'
    PSD_Out.ny = '110'
    PSD_Out.filename = '"PSD_AtSample.psd"'
    PSD_Out.xmin = '-0.01'
    PSD_Out.xmax = '0.01'
    PSD_Out.ymin = '-0.03'
    PSD_Out.ymax = '0.03'
    PSD_Out.xwidth = '0'
    PSD_Out.yheight = '0'
    PSD_Out.restore_neutron = '0'
    PSD_Out.nowritefile = '0'
    
    # Comp instance Lambda_Sample, placement and parameters
    Lambda_Sample = instr.add_component('Lambda_Sample','L_monitor', AT=['0', '0', '0.000000001'], AT_RELATIVE='PSD_Out', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='PSD_Out')
    
    Lambda_Sample.nL = '1000'
    Lambda_Sample.filename = '"Lambda_Sample"'
    Lambda_Sample.nowritefile = '0'
    Lambda_Sample.xmin = '-0.05'
    Lambda_Sample.xmax = '0.05'
    Lambda_Sample.ymin = '-0.05'
    Lambda_Sample.ymax = '0.05'
    Lambda_Sample.xwidth = '0'
    Lambda_Sample.yheight = '0'
    Lambda_Sample.Lmin = 'lambda_min -1.2'
    Lambda_Sample.Lmax = 'lambda_min + 1.2'
    Lambda_Sample.restore_neutron = '1'
    
    # Comp instance PSD_Out_small, placement and parameters
    PSD_Out_small = instr.add_component('PSD_Out_small','PSD_monitor', AT=['0', '0', '1e-06'], AT_RELATIVE='Lambda_Sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Lambda_Sample')
    
    PSD_Out_small.nx = '110'
    PSD_Out_small.ny = '110'
    PSD_Out_small.filename = '"PSD_AtSample_small.psd"'
    PSD_Out_small.xmin = '-0.005'
    PSD_Out_small.xmax = '0.005'
    PSD_Out_small.ymin = '-0.005'
    PSD_Out_small.ymax = '0.005'
    PSD_Out_small.xwidth = '0'
    PSD_Out_small.yheight = '0'
    PSD_Out_small.restore_neutron = '0'
    PSD_Out_small.nowritefile = '0'
    
    # Comp instance PSD_Out_bck, placement and parameters
    PSD_Out_bck = instr.add_component('PSD_Out_bck','PSD_monitor', AT=['0', '0', '1e-06'], AT_RELATIVE='PSD_Out_small', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='PSD_Out_small')
    
    PSD_Out_bck.nx = '110'
    PSD_Out_bck.ny = '110'
    PSD_Out_bck.filename = '"PSD_AtSample_bck.psd"'
    PSD_Out_bck.xmin = '-0.01'
    PSD_Out_bck.xmax = '-0.005'
    PSD_Out_bck.ymin = '0.005'
    PSD_Out_bck.ymax = '0.01'
    PSD_Out_bck.xwidth = '0'
    PSD_Out_bck.yheight = '0'
    PSD_Out_bck.restore_neutron = '0'
    PSD_Out_bck.nowritefile = '0'
    
    # Comp instance Div_Mon_Sample, placement and parameters
    Div_Mon_Sample = instr.add_component('Div_Mon_Sample','Divergence_monitor', AT=['0', '0', '1e-06'], AT_RELATIVE='PSD_Out_bck', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='PSD_Out_bck')
    
    Div_Mon_Sample.nh = '50'
    Div_Mon_Sample.nv = '50'
    Div_Mon_Sample.filename = '"Div_Mon_Sample.pos"'
    Div_Mon_Sample.xmin = '-0.05'
    Div_Mon_Sample.xmax = '0.05'
    Div_Mon_Sample.ymin = '-0.05'
    Div_Mon_Sample.ymax = '0.05'
    Div_Mon_Sample.nowritefile = '0'
    Div_Mon_Sample.xwidth = '0.1'
    Div_Mon_Sample.yheight = '0.1'
    Div_Mon_Sample.maxdiv_h = '5'
    Div_Mon_Sample.maxdiv_v = '5'
    Div_Mon_Sample.restore_neutron = '1'
    Div_Mon_Sample.nx = '0'
    Div_Mon_Sample.ny = '0'
    Div_Mon_Sample.nz = '1'
    
    # Comp instance Hdiv_lambda_end, placement and parameters
    Hdiv_lambda_end = instr.add_component('Hdiv_lambda_end','Monitor_nD', AT=['0', '0', '0.00000001'], AT_RELATIVE='Div_Mon_Sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Div_Mon_Sample')
    
    Hdiv_lambda_end.user1 = '""'
    Hdiv_lambda_end.user2 = '""'
    Hdiv_lambda_end.user3 = '""'
    Hdiv_lambda_end.xwidth = '0'
    Hdiv_lambda_end.yheight = '0'
    Hdiv_lambda_end.zdepth = '0'
    Hdiv_lambda_end.xmin = '-0.05'
    Hdiv_lambda_end.xmax = '0.05'
    Hdiv_lambda_end.ymin = '-0.05'
    Hdiv_lambda_end.ymax = '0.05'
    Hdiv_lambda_end.zmin = '0'
    Hdiv_lambda_end.zmax = '0'
    Hdiv_lambda_end.bins = '0'
    Hdiv_lambda_end.min = '-1e40'
    Hdiv_lambda_end.max = '1e40'
    Hdiv_lambda_end.restore_neutron = '0'
    Hdiv_lambda_end.radius = '0'
    Hdiv_lambda_end.options = '"lambda bins=19 limits=[2 20]; hdiv bins=80 limits[-4.0 4.0]"'
    Hdiv_lambda_end.filename = '"Hdivx_lambda_end.dat"'
    Hdiv_lambda_end.geometry = '"NULL"'
    Hdiv_lambda_end.nowritefile = '0'
    Hdiv_lambda_end.username1 = '"NULL"'
    Hdiv_lambda_end.username2 = '"NULL"'
    Hdiv_lambda_end.username3 = '"NULL"'
    Hdiv_lambda_end.tsplit = '0'
    Hdiv_lambda_end.adaptive_target = '0'
    
    # Comp instance Vdiv_lambda_end, placement and parameters
    Vdiv_lambda_end = instr.add_component('Vdiv_lambda_end','Monitor_nD', AT=['0', '0', '0.00000001'], AT_RELATIVE='Hdiv_lambda_end', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Hdiv_lambda_end')
    
    Vdiv_lambda_end.user1 = '""'
    Vdiv_lambda_end.user2 = '""'
    Vdiv_lambda_end.user3 = '""'
    Vdiv_lambda_end.xwidth = '0'
    Vdiv_lambda_end.yheight = '0'
    Vdiv_lambda_end.zdepth = '0'
    Vdiv_lambda_end.xmin = '-0.05'
    Vdiv_lambda_end.xmax = '0.05'
    Vdiv_lambda_end.ymin = '-0.05'
    Vdiv_lambda_end.ymax = '0.05'
    Vdiv_lambda_end.zmin = '0'
    Vdiv_lambda_end.zmax = '0'
    Vdiv_lambda_end.bins = '0'
    Vdiv_lambda_end.min = '-1e40'
    Vdiv_lambda_end.max = '1e40'
    Vdiv_lambda_end.restore_neutron = '0'
    Vdiv_lambda_end.radius = '0'
    Vdiv_lambda_end.options = '" lambda bins=19 limits=[2 20] ; vdiv bins=80 limits[-4.0 4.0] "'
    Vdiv_lambda_end.filename = '"Vdivy_lambda_end.dat"'
    Vdiv_lambda_end.geometry = '"NULL"'
    Vdiv_lambda_end.nowritefile = '0'
    Vdiv_lambda_end.username1 = '"NULL"'
    Vdiv_lambda_end.username2 = '"NULL"'
    Vdiv_lambda_end.username3 = '"NULL"'
    Vdiv_lambda_end.tsplit = '0'
    Vdiv_lambda_end.adaptive_target = '0'
    
    # Comp instance HPSD_lambda_end, placement and parameters
    HPSD_lambda_end = instr.add_component('HPSD_lambda_end','Monitor_nD', AT=['0', '0', '0.00000001'], AT_RELATIVE='Vdiv_lambda_end', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Vdiv_lambda_end')
    
    HPSD_lambda_end.user1 = '""'
    HPSD_lambda_end.user2 = '""'
    HPSD_lambda_end.user3 = '""'
    HPSD_lambda_end.xwidth = '0'
    HPSD_lambda_end.yheight = '0'
    HPSD_lambda_end.zdepth = '0'
    HPSD_lambda_end.xmin = '-0.05'
    HPSD_lambda_end.xmax = '0.05'
    HPSD_lambda_end.ymin = '-0.05'
    HPSD_lambda_end.ymax = '0.05'
    HPSD_lambda_end.zmin = '0'
    HPSD_lambda_end.zmax = '0'
    HPSD_lambda_end.bins = '0'
    HPSD_lambda_end.min = '-1e40'
    HPSD_lambda_end.max = '1e40'
    HPSD_lambda_end.restore_neutron = '0'
    HPSD_lambda_end.radius = '0'
    HPSD_lambda_end.options = '" lambda bins=19 limits=[2 20] ; y bins=80 limits[-4.0 4.0] "'
    HPSD_lambda_end.filename = '"height_lambda_end.dat"'
    HPSD_lambda_end.geometry = '"NULL"'
    HPSD_lambda_end.nowritefile = '0'
    HPSD_lambda_end.username1 = '"NULL"'
    HPSD_lambda_end.username2 = '"NULL"'
    HPSD_lambda_end.username3 = '"NULL"'
    HPSD_lambda_end.tsplit = '0'
    HPSD_lambda_end.adaptive_target = '0'
    
    # Comp instance WPSD_lambda_end, placement and parameters
    WPSD_lambda_end = instr.add_component('WPSD_lambda_end','Monitor_nD', AT=['0', '0', '0.00000001'], AT_RELATIVE='HPSD_lambda_end', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='HPSD_lambda_end')
    
    WPSD_lambda_end.user1 = '""'
    WPSD_lambda_end.user2 = '""'
    WPSD_lambda_end.user3 = '""'
    WPSD_lambda_end.xwidth = '0'
    WPSD_lambda_end.yheight = '0'
    WPSD_lambda_end.zdepth = '0'
    WPSD_lambda_end.xmin = '-0.05'
    WPSD_lambda_end.xmax = '0.05'
    WPSD_lambda_end.ymin = '-0.05'
    WPSD_lambda_end.ymax = '0.05'
    WPSD_lambda_end.zmin = '0'
    WPSD_lambda_end.zmax = '0'
    WPSD_lambda_end.bins = '0'
    WPSD_lambda_end.min = '-1e40'
    WPSD_lambda_end.max = '1e40'
    WPSD_lambda_end.restore_neutron = '0'
    WPSD_lambda_end.radius = '0'
    WPSD_lambda_end.options = '" lambda bins=19 limits=[2 20] ; x bins=80 limits[-4.0 4.0] "'
    WPSD_lambda_end.filename = '"width_lambda_end.dat"'
    WPSD_lambda_end.geometry = '"NULL"'
    WPSD_lambda_end.nowritefile = '0'
    WPSD_lambda_end.username1 = '"NULL"'
    WPSD_lambda_end.username2 = '"NULL"'
    WPSD_lambda_end.username3 = '"NULL"'
    WPSD_lambda_end.tsplit = '0'
    WPSD_lambda_end.adaptive_target = '0'
    
    # Comp instance Lambda_Sample_Single, placement and parameters
    Lambda_Sample_Single = instr.add_component('Lambda_Sample_Single','L_monitor', AT=['0', '0', '0.00000001'], AT_RELATIVE='WPSD_lambda_end', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='WPSD_lambda_end')
    
    Lambda_Sample_Single.nL = '1000'
    Lambda_Sample_Single.filename = '"Lambda_Sample_Single"'
    Lambda_Sample_Single.nowritefile = '0'
    Lambda_Sample_Single.xmin = '-0.05'
    Lambda_Sample_Single.xmax = '0.05'
    Lambda_Sample_Single.ymin = '-0.05'
    Lambda_Sample_Single.ymax = '0.05'
    Lambda_Sample_Single.xwidth = '0'
    Lambda_Sample_Single.yheight = '0'
    Lambda_Sample_Single.Lmin = 'lambda_min -0.1'
    Lambda_Sample_Single.Lmax = 'lambda_min + 0.1'
    Lambda_Sample_Single.restore_neutron = '1'
    
    # Comp instance TOF_Sample, placement and parameters
    TOF_Sample = instr.add_component('TOF_Sample','TOF_monitor', AT=['0', '0', '0.00000001'], AT_RELATIVE='Lambda_Sample_Single', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Lambda_Sample_Single')
    
    TOF_Sample.nt = '1000'
    TOF_Sample.filename = '"TOF_Sample"'
    TOF_Sample.xmin = '-0.05'
    TOF_Sample.xmax = '0.05'
    TOF_Sample.ymin = '-0.05'
    TOF_Sample.ymax = '0.05'
    TOF_Sample.xwidth = '0'
    TOF_Sample.yheight = '0'
    TOF_Sample.tmin = '252.78 * ( lambda_min ) * ( 160.0514 ) -0.5 * 1e6 / Freq_M'
    TOF_Sample.tmax = '252.78 * ( lambda_min ) * ( 160.0514 ) + 0.5 * 1e6 / Freq_M'
    TOF_Sample.dt = '1.0'
    TOF_Sample.restore_neutron = '1'
    TOF_Sample.nowritefile = '0'
    
    # Comp instance tof, placement and parameters
    tof = instr.add_component('tof','Monitor_nD', AT=['0', '0', '0.00000001'], AT_RELATIVE='TOF_Sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='TOF_Sample')
    
    tof.user1 = '""'
    tof.user2 = '""'
    tof.user3 = '""'
    tof.xwidth = '0.3'
    tof.yheight = '0.3'
    tof.zdepth = '0'
    tof.xmin = '0'
    tof.xmax = '0'
    tof.ymin = '0'
    tof.ymax = '0'
    tof.zmin = '0'
    tof.zmax = '0'
    tof.bins = '0'
    tof.min = '-1e40'
    tof.max = '1e40'
    tof.restore_neutron = '0'
    tof.radius = '0'
    tof.options = '"t bins 500 limits [0, 0.4]"'
    tof.filename = '"time.dat"'
    tof.geometry = '"NULL"'
    tof.nowritefile = '0'
    tof.username1 = '"NULL"'
    tof.username2 = '"NULL"'
    tof.username3 = '"NULL"'
    tof.tsplit = '1'
    tof.adaptive_target = '1'
    
    # Comp instance TOF_Sample_AllLambda, placement and parameters
    TOF_Sample_AllLambda = instr.add_component('TOF_Sample_AllLambda','TOF_monitor', AT=['0', '0', '0.00000001'], AT_RELATIVE='tof', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='tof')
    
    TOF_Sample_AllLambda.nt = '5000'
    TOF_Sample_AllLambda.filename = '"TOF_Sample_AllLambda"'
    TOF_Sample_AllLambda.xmin = '-0.05'
    TOF_Sample_AllLambda.xmax = '0.05'
    TOF_Sample_AllLambda.ymin = '-0.05'
    TOF_Sample_AllLambda.ymax = '0.05'
    TOF_Sample_AllLambda.xwidth = '0'
    TOF_Sample_AllLambda.yheight = '0'
    TOF_Sample_AllLambda.tmin = '252.78 * ( lambda_min -1.5 ) * ( 160.0514 )'
    TOF_Sample_AllLambda.tmax = '252.78 * ( lambda_min + 1.5 ) * ( 160.0514 )'
    TOF_Sample_AllLambda.dt = '1.0'
    TOF_Sample_AllLambda.restore_neutron = '1'
    TOF_Sample_AllLambda.nowritefile = '0'
    
    # Comp instance TOF_Sample_AllLambda_zoom, placement and parameters
    TOF_Sample_AllLambda_zoom = instr.add_component('TOF_Sample_AllLambda_zoom','TOF_monitor', AT=['0', '0', '0.00000001'], AT_RELATIVE='TOF_Sample_AllLambda', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='TOF_Sample_AllLambda')
    
    TOF_Sample_AllLambda_zoom.nt = '200'
    TOF_Sample_AllLambda_zoom.filename = '"TOF_Sample_AllLambda_zoom"'
    TOF_Sample_AllLambda_zoom.xmin = '-0.05'
    TOF_Sample_AllLambda_zoom.xmax = '0.05'
    TOF_Sample_AllLambda_zoom.ymin = '-0.05'
    TOF_Sample_AllLambda_zoom.ymax = '0.05'
    TOF_Sample_AllLambda_zoom.xwidth = '0'
    TOF_Sample_AllLambda_zoom.yheight = '0'
    TOF_Sample_AllLambda_zoom.tmin = '110600'
    TOF_Sample_AllLambda_zoom.tmax = '111000'
    TOF_Sample_AllLambda_zoom.dt = '1.0'
    TOF_Sample_AllLambda_zoom.restore_neutron = '1'
    TOF_Sample_AllLambda_zoom.nowritefile = '0'
    
    # Comp instance Sample, placement and parameters
    # Sample = instr.add_component('Sample','Incoherent', AT=['0', '0', '0.00000001'], AT_RELATIVE='TOF_Sample_AllLambda_zoom', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='TOF_Sample_AllLambda_zoom')
    
    # Sample.geometry = '0'
    # Sample.radius = '0.02'
    # Sample.xwidth = '0'
    # Sample.yheight = '0'
    # Sample.zdepth = '0'
    # Sample.thickness = '0'
    # Sample.target_x = '0'
    # Sample.target_y = '0'
    # Sample.target_z = '0'
    # Sample.focus_r = '0.02'
    # Sample.focus_xw = '0'
    # Sample.focus_yh = '0'
    # Sample.focus_aw = '0'
    # Sample.focus_ah = '0'
    # Sample.target_index = '1'
    # Sample.pack = '1'
    # Sample.p_interact = '1'
    # Sample.f_QE = '0'
    # Sample.gamma = '0'
    # Sample.Etrans = '0'
    # Sample.deltaE = '0'
    # Sample.sigma_abs = '5.08'
    # Sample.sigma_inc = '5.08'
    # Sample.Vc = '13.827'
    # Sample.concentric = '0'
    # Sample.order = '0'
    
    # Comp instance TOF_Detector, placement and parameters
    TOF_Detector = instr.add_component('TOF_Detector','TOF_monitor', AT=['0', '0', '3.5'], AT_RELATIVE='Sample', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='Sample')
    
    TOF_Detector.nt = '1000'
    TOF_Detector.filename = '"TOF_Detector"'
    TOF_Detector.xmin = '-0.05'
    TOF_Detector.xmax = '0.05'
    TOF_Detector.ymin = '-0.05'
    TOF_Detector.ymax = '0.05'
    TOF_Detector.xwidth = '0'
    TOF_Detector.yheight = '0'
    TOF_Detector.tmin = '252.78 * ( lambda_min ) * ( 163.5 ) -0.5 * 1e6 / Freq_M'
    TOF_Detector.tmax = '252.78 * ( lambda_min ) * ( 163.5 ) + 0.5 * 1e6 / Freq_M'
    TOF_Detector.dt = '1.0'
    TOF_Detector.restore_neutron = '1'
    TOF_Detector.nowritefile = '0'
    
    # Comp instance det_NDmonitor, placement and parameters
    det_NDmonitor = instr.add_component('det_NDmonitor','Monitor_nD', AT=['0', '0', '0.00000001'], AT_RELATIVE='TOF_Detector', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='TOF_Detector')
    
    det_NDmonitor.user1 = '""'
    det_NDmonitor.user2 = '""'
    det_NDmonitor.user3 = '""'
    det_NDmonitor.xwidth = '0'
    det_NDmonitor.yheight = '0'
    det_NDmonitor.zdepth = '0'
    det_NDmonitor.xmin = '-0.1'
    det_NDmonitor.xmax = '0.1'
    det_NDmonitor.ymin = '-0.1'
    det_NDmonitor.ymax = '0.1'
    det_NDmonitor.zmin = '0'
    det_NDmonitor.zmax = '0'
    det_NDmonitor.bins = '0'
    det_NDmonitor.min = '-1e40'
    det_NDmonitor.max = '1e40'
    det_NDmonitor.restore_neutron = '0'
    det_NDmonitor.radius = '0'
    det_NDmonitor.options = '"x bins=100 ybins=100"'
    #det_NDmonitor.options = '"mantid banana theta bins=221 limits=[-40, 140] y bins=136, neutron pixel min=0 t, list all neutrons"'
    det_NDmonitor.filename = '"det_NDmonitor.dat"'
    det_NDmonitor.geometry = '"NULL"'
    det_NDmonitor.nowritefile = '0'
    det_NDmonitor.username1 = '"NULL"'
    det_NDmonitor.username2 = '"NULL"'
    det_NDmonitor.username3 = '"NULL"'
    det_NDmonitor.tsplit = '0'
    det_NDmonitor.adaptive_target = '0'

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
    

    
    
    # Instruct McStasscript not to 'check everythng'
    instr.settings(checks=False)
    
    enable_pars = []

    for component in instr.component_list:
        if component.ROTATED_data == ["0.0", "0.0", "0.0"]:
            component.ROTATED_specified = False
    
        if component.component_name == "DiskChopper":
            parameter_name = "enable_" + component.name
            instr.add_parameter("int", parameter_name, value=1)
            component.set_WHEN(f"{parameter_name} == 1")
    
            enable_pars.append(parameter_name)
    
        if hasattr(component, "restore_neutron"):
            component.restore_neutron = 1

        if component.component_name == "Guide_gravity":
            component.set_parameters(G=9.82)

        # Removes parameters that are default anyway
        for par, default in component.parameter_defaults.items():
            value = getattr(component, par)
            try:
                default = float(default)
            except:
                continue
        
            try:
                value = float(value)
            except:
                continue
        
            if value == default:
                setattr(component, par, None)

    for par in enable_pars:
        instr.set_parameters({par: 1})
    
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


# end of generated Python code CSPEC_generated.py 
