clear;
clc;
open 'Twotanks_Model';
%TestObj = 'CC_Model';
load('TC.mat');

TestObj = cvtest('Twotanks_Model');

TestObj.settings.mcdc = 1;
TestObj.settings.condition = 1;
TestObj.settings.decision = 1;
NTestCases = 150;
%x = input('Select which test case has to be executed (number from 1 to 150)\n');
for i=1:size(TC, 2)
    simTime = TC(i).simTime;
    tank1_sensor_hi_height_m_in = TC(i).tank1_sensor_hi_height_m;
    tank1_sensor_lo_height_m_in = TC(i).tank1_sensor_lo_height_m;
    tank1_pump_flow_rate_m3s_in =  TC(i).tank1_pump_flow_rate_m3s;
    tank1_valve_flow_rate_m3s_in = TC(i).tank1_valve_flow_rate_m3s;
    tank1_cross_section_area_m2_in = TC(i).tank1_cross_section_area_m2;
    tank2_sensor_hi_height_m_in = TC(i).tank2_sensor_hi_height_m;
    tank2_sensor_md_height_m_in = TC(i).tank2_sensor_md_height_m;
    tank2_sensor_lo_height_m_in = TC(i).tank2_sensor_lo_height_m;
    tank2_p_valve_flow_rate_m3s_in = TC(i).tank2_p_valve_flow_rate_m3s;
    tank2_e_valve_flow_rate_m3s_in = TC(i).tank2_e_valve_flow_rate_m3s;
    tank2_cross_section_area_m2_in = TC(i).tank2_cross_section_area_m2;
    
    cvdo{i} = cvsim(TestObj);
    i
end

cvsave('WhiteBoxCov_2017b', cvdo{ :});
