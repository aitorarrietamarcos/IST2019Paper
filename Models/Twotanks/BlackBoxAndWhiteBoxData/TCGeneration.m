clc;
clear;

modelname = 'Twotanks_Model_TCGen';
%% TestCase generation
if ~isfile("TC.mat")
    maxTime = 300;
    minTime = 100;
    stepSize = 0.1;
    interval = [-1 1];
   for i = 1:150
      TC(i).simTime = randi([minTime*10 maxTime*10], 1, 1)/10;
      TC(i).tank1_sensor_hi_height_m = (8 - 3.6).*rand(1,1) + 3.6; % Original val -> 5.0
      TC(i).tank1_sensor_lo_height_m = (3.5 - 1).*rand(1,1) + 1; % Original val -> 2.0
      TC(i).tank1_pump_flow_rate_m3s = interval(randi(numel(interval)))*((0.4 - 0.05).*rand(1,1) + 0.05); % Original val -> 0.2
      TC(i).tank1_valve_flow_rate_m3s = interval(randi(numel(interval)))*(0.3 - 0.05).*rand(1,1) + 0.05; % Original val -> 0.1
      TC(i).tank1_cross_section_area_m2 = (1.25 - 0.25).*rand(1,1) + 0.25; % Original val -> 1.0
      TC(i).tank2_sensor_hi_height_m = (4 - 2.25).*rand(1,1) + 2.5; % Original val -> 3.0
      TC(i).tank2_sensor_lo_height_m = (1.5 - 1).*rand(1,1) + 1; % Original val -> 1.0
      TC(i).tank2_sensor_md_height_m = TC(i).tank2_sensor_lo_height_m + ...
          ((TC(i).tank2_sensor_hi_height_m - TC(i).tank2_sensor_lo_height_m)/2);
      TC(i).tank2_p_valve_flow_rate_m3s = interval(randi(numel(interval)))*(0.3 - 0.02).*rand(1,1) + 0.02; % Original val -> 0.05
      TC(i).tank2_e_valve_flow_rate_m3s = interval(randi(numel(interval)))*(0.4 - 0.05).*rand(1,1) + 0.05; % Original val -> 0.2
      TC(i).tank2_cross_section_area_m2 = (3 - 0.5).*rand(1,1) + 0.5; % Original val -> 2.0
   end
    save("TC.mat", "TC");
    disp('Test cases created and saved');
else
    load("TC.mat");
    disp('Test cases loaded from mat file');
end

%% TestCase Execution
simStep = 0.005;

for i = 1:size(TC, 2)
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
    
    sim(modelname)
    TCData(i).Time = TC(i).simTime;
    TCData(i).Input{1} = tank1_sensor_hi_height_m;
    TCData(i).Input{2} = tank1_sensor_lo_height_m;
    TCData(i).Input{3} = tank1_pump_flow_rate_m3s;
    TCData(i).Input{4} = tank1_valve_flow_rate_m3s;
    TCData(i).Input{5} = tank1_cross_section_area_m2;
    TCData(i).Input{6} = tank2_sensor_hi_height_m;
    TCData(i).Input{7} = tank2_sensor_md_height_m;
    TCData(i).Input{8} = tank2_sensor_lo_height_m;
    TCData(i).Input{9} = tank2_p_valve_flow_rate_m3s;
    TCData(i).Input{10} = tank2_e_valve_flow_rate_m3s;
    TCData(i).Input{11} = tank2_cross_section_area_m2;
    
    TCData(i).Output{1} = Tank2Height;
    TCData(i).Output{2} = Tank2SensorHValue;
%     TCData(i).Output{3} = Tank2SensorHHeight;
%     TCData(i).Output{4} = Tank1CrossSec;
    TCData(i).Output{3} = Tank1Height;
%     TCData(i).Output{6} = Tank2CrossSec;
%     TCData(i).Output{7} = Tank1ValveFlow;
%     TCData(i).Output{8} = Tank1PumpFlow;
    TCData(i).Output{4} = Tank1SensorHValue;
    TCData(i).Output{5} = Tank1SensorLValue;
    TCData(i).Output{6} = Tank2SensorMValue;
    TCData(i).Output{7} = Tank2SensorLValue;
%     TCData(i).Output{13} = Pump_state;
%     TCData(i).Output{14} = Valve_state;
%     TCData(i).Output{15} = PValve_state;
%     TCData(i).Output{16} = EValve_state;
%     TCData(i).Output{17} = Tank1SensorHHeight;
%     TCData(i).Output{18} = Tank2SensorLHeight;
%     TCData(i).Output{19} = Tank1SensorLHeight;
%     TCData(i).Output{20} = Tank2SensorMHeight;
%     TCData(i).Output{21} = Tank2PValveFlow;
%     TCData(i).Output{22} = Tank2EValveFlow;
    
    TCData(i).Derivative{1} = Tank2Height_deriv;
    TCData(i).Derivative{2} = Tank2SensorHValue_deriv;
%     TCData(i).Derivative{3} = Tank2SensorHHeight_deriv;
%     TCData(i).Derivative{4} = Tank1CrossSec_deriv;
    TCData(i).Derivative{3} = Tank1Height_deriv;
%     TCData(i).Derivative{6} = Tank2CrossSec_deriv;
%     TCData(i).Derivative{7} = Tank1ValveFlow_deriv;
%     TCData(i).Derivative{8} = Tank1PumpFlow_deriv;
    TCData(i).Derivative{4} = Tank1SensorHValue_deriv;
    TCData(i).Derivative{5} = Tank1SensorLValue_deriv;
    TCData(i).Derivative{6} = Tank2SensorMValue_deriv;
    TCData(i).Derivative{7} = Tank2SensorLValue_deriv;
%     TCData(i).Derivative{13} = Pump_state_deriv;
%     TCData(i).Derivative{14} = Valve_state_deriv;
%     TCData(i).Derivative{15} = PValve_state_deriv;
%     TCData(i).Derivative{16} = EValve_state_deriv;
%     TCData(i).Derivative{17} = Tank1SensorHHeight_deriv;
%     TCData(i).Derivative{18} = Tank2SensorLHeight_deriv;
%     TCData(i).Derivative{19} = Tank1SensorLHeight_deriv;
%     TCData(i).Derivative{20} = Tank2SensorMHeight_deriv;
%     TCData(i).Derivative{21} = Tank2PValveFlow_deriv;
%     TCData(i).Derivative{22} = Tank2EValveFlow_deriv;

    TCData(i).Infinite{1} = Tank2Height_infinite;
    TCData(i).Infinite{2} = Tank2SensorHValue_infinite;
%     TCData(i).Infinite{3} = Tank2SensorHHeight_infinite;
%     TCData(i).Infinite{4} = Tank1CrossSec_infinite;
    TCData(i).Infinite{3} = Tank1Height_infinite;
%     TCData(i).Infinite{6} = Tank2CrossSec_infinite;
%     TCData(i).Infinite{7} = Tank1ValveFlow_infinite;
%     TCData(i).Infinite{8} = Tank1PumpFlow_infinite;
    TCData(i).Infinite{4} = Tank1SensorHValue_infinite;
    TCData(i).Infinite{5} = Tank1SensorLValue_infinite;
    TCData(i).Infinite{6} = Tank2SensorMValue_infinite;
    TCData(i).Infinite{7} = Tank2SensorLValue_infinite;
%     TCData(i).Infinite{13} = Pump_state_infinite;
%     TCData(i).Infinite{14} = Valve_state_infinite;
%     TCData(i).Infinite{15} = PValve_state_infinite;
%     TCData(i).Infinite{16} = EValve_state_infinite;
%     TCData(i).Infinite{17} = Tank1SensorHHeight_infinite;
%     TCData(i).Infinite{18} = Tank2SensorLHeight_infinite;
%     TCData(i).Infinite{19} = Tank1SensorLHeight_infinite;
%     TCData(i).Infinite{20} = Tank2SensorMHeight_infinite;
%     TCData(i).Infinite{21} = Tank2PValveFlow_infinite;
%     TCData(i).Infinite{22} = Tank2EValveFlow_infinite;
    
    TCData(i).Maxmin{1} = Tank2Height_maxmin;
    TCData(i).Maxmin{2} = Tank2SensorHValue_maxmin;
%     TCData(i).Maxmin{3} = Tank2SensorHHeight_maxmin;
%     TCData(i).Maxmin{4} = Tank1CrossSec_maxmin;
    TCData(i).Maxmin{3} = Tank1Height_maxmin;
%     TCData(i).Maxmin{6} = Tank2CrossSec_maxmin;
%     TCData(i).Maxmin{7} = Tank1ValveFlow_maxmin;
%     TCData(i).Maxmin{8} = Tank1PumpFlow_maxmin;
    TCData(i).Maxmin{4} = Tank1SensorHValue_maxmin;
    TCData(i).Maxmin{5} = Tank1SensorLValue_maxmin;
    TCData(i).Maxmin{6} = Tank2SensorMValue_maxmin;
    TCData(i).Maxmin{7} = Tank2SensorLValue_maxmin;
%     TCData(i).Maxmin{13} = Pump_state_maxmin;
%     TCData(i).Maxmin{14} = Valve_state_maxmin;
%     TCData(i).Maxmin{15} = PValve_state_maxmin;
%     TCData(i).Maxmin{16} = EValve_state_maxmin;
%     TCData(i).Maxmin{17} = Tank1SensorHHeight_maxmin;
%     TCData(i).Maxmin{18} = Tank2SensorLHeight_maxmin;
%     TCData(i).Maxmin{19} = Tank1SensorLHeight_maxmin;
%     TCData(i).Maxmin{20} = Tank2SensorMHeight_maxmin;
%     TCData(i).Maxmin{21} = Tank2PValveFlow_maxmin;
%     TCData(i).Maxmin{22} = Tank2EValveFlow_maxmin;

    i
end

save("TCData.mat", "TCData");

