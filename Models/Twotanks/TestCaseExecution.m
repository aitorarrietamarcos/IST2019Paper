clear;
clc;
addpath 'BlackBoxAndWhiteBoxData';
open 'Twotanks_Model';
TestObj = 'Twotanks_Model';
load('TC.mat');

x = input('Select which test case has to be executed (number from 1 to 150)\n');
if(x > 0 && x < 151)
   simTime = TC(x).simTime;
    tank1_sensor_hi_height_m_in = TC(x).tank1_sensor_hi_height_m;
    tank1_sensor_lo_height_m_in = TC(x).tank1_sensor_lo_height_m;
    tank1_pump_flow_rate_m3s_in =  TC(x).tank1_pump_flow_rate_m3s;
    tank1_valve_flow_rate_m3s_in = TC(x).tank1_valve_flow_rate_m3s;
    tank1_cross_section_area_m2_in = TC(x).tank1_cross_section_area_m2;
    tank2_sensor_hi_height_m_in = TC(x).tank2_sensor_hi_height_m;
    tank2_sensor_md_height_m_in = TC(x).tank2_sensor_md_height_m;
    tank2_sensor_lo_height_m_in = TC(x).tank2_sensor_lo_height_m;
    tank2_p_valve_flow_rate_m3s_in = TC(x).tank2_p_valve_flow_rate_m3s;
    tank2_e_valve_flow_rate_m3s_in = TC(x).tank2_e_valve_flow_rate_m3s;
    tank2_cross_section_area_m2_in = TC(x).tank2_cross_section_area_m2;
    
    sim(TestObj)
end
