import os
parent = os.path.dirname(os.getcwd())

benz_kwargs = {
    "Sqw_coh": '0',
    "Sqw_inc": f'"{parent}/data/benz_inc_test.sqw"',
}


let_kwargs = {
    "AT":['0', '0', '0'], 
    "AT_RELATIVE":'sample',
    "ROTATED":['0.0', '0.0', '0.0'], 
    "ROTATED_RELATIVE":'sample',
    "after": 'sample_Emon'
}


cspec_kwargs = {
    "AT":['0', '0', '0.00000001'],
    "AT_RELATIVE":'TOF_Sample_AllLambda_zoom',
    "ROTATED":['0.0', '0.0', '0.0'],
    "ROTATED_RELATIVE":'TOF_Sample_AllLambda_zoom',
    "name": 'Sample',
    "after": 'TOF_Sample_AllLambda_zoom'
}


trex_kwargs = {
    "AT":['0', '0', '0.015'],
    "AT_RELATIVE":'Sample_pos',
    "ROTATED":['0', '0', '0'],
    "ROTATED_RELATIVE":'Sample_pos',
    "name": 'Sample',
    "after": 'sample_monitor_lam'
}