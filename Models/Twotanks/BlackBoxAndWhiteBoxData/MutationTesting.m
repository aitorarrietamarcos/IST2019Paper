clc;
clear;

load("TC.mat")
load("TCData.mat")
Mutant_number = 34;
tic
for i = 1:size(TC, 2)
    for j = 1:Mutant_number
        modelname = sprintf("Mutants/Mutant%i", j);
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
        
        MutantData(i,j).Output{1} = Tank2Height;
        MutantData(i,j).Output{2} = Tank2SensorHValue;
%         MutantData(i,j).Output{3} = Tank2SensorHHeight;
%         MutantData(i,j).Output{4} = Tank1CrossSec;
        MutantData(i,j).Output{3} = Tank1Height;
%         MutantData(i,j).Output{6} = Tank2CrossSec;
%         MutantData(i,j).Output{7} = Tank1ValveFlow;
%         MutantData(i,j).Output{8} = Tank1PumpFlow;
        MutantData(i,j).Output{4} = Tank1SensorHValue;
        MutantData(i,j).Output{5} = Tank1SensorLValue;
        MutantData(i,j).Output{6} = Tank2SensorMValue;
        MutantData(i,j).Output{7} = Tank2SensorLValue;
%         MutantData(i,j).Output{13} = Pump_state;
%         MutantData(i,j).Output{14} = Valve_state;
%         MutantData(i,j).Output{15} = PValve_state;
%         MutantData(i,j).Output{16} = EValve_state;
%         MutantData(i,j).Output{17} = Tank1SensorHHeight;
%         MutantData(i,j).Output{18} = Tank2SensorLHeight;
%         MutantData(i,j).Output{19} = Tank1SensorLHeight;
%         MutantData(i,j).Output{20} = Tank2SensorMHeight;
%         MutantData(i,j).Output{21} = Tank2PValveFlow;
%         MutantData(i,j).Output{22} = Tank2EValveFlow;
    end
    i
end
toc

save("MutantData.mat", "MutantData");

for i = 1:Mutant_number
   for j = 1:size(TC, 2)
       if(isequal(MutantData(j,i).Output{1}, TCData(j).Output{1}) ...
           && isequal(MutantData(j,i).Output{2}, TCData(j).Output{2})  ...
           && isequal(MutantData(j,i).Output{3}, TCData(j).Output{3}) ...
           && isequal(MutantData(j,i).Output{4}, TCData(j).Output{4}) ...
           && isequal(MutantData(j,i).Output{5}, TCData(j).Output{5}) ...
           && isequal(MutantData(j,i).Output{6}, TCData(j).Output{6}) ...
           && isequal(MutantData(j,i).Output{7}, TCData(j).Output{7}))
           MutantMatrix(j,i) = 0;
       else
           MutantMatrix(j,i) = 1;
       end
   end
end

save('MutantMatrix.mat', 'MutantMatrix')
DATASETMutants = array2table(MutantMatrix);
%% Delete mutants that are never detected
[a b] = size(MutantMatrix);
k = 1;
index = [];
for i=1:b
    if(sum((MutantMatrix(:, i)))==0)
        index(k) = i;
        k = k+1;
    end
end
index = sort(index,'descend');
for i = 1:length(index)
    DATASETMutants(:,index(i)) = [];
end
%% Delete mutants that are always detected
[a b] = size(DATASETMutants);
k = 1;
index = [];
matrix = table2array(DATASETMutants);
for i=1:b
    if(sum(matrix(:, i))==150)
        index(k) = i;
        k = k+1;
    end
end
index = sort(index,'descend');
for i = 1:length(index)
    DATASETMutants(:,index(i)) = [];
end

%% Delete one of the equal detection mutants
names = DATASETMutants.Properties.VariableNames;
matrix = table2array(DATASETMutants);
DATASETMutants = array2table(matrix');
DATASETMutants.Properties.RowNames = names;

DATASETMutants = unique(DATASETMutants, 'stable');
names = DATASETMutants.Properties.RowNames;
matrix = table2array(DATASETMutants);
DATASETMutants = array2table(matrix');
DATASETMutants.Properties.VariableNames = names;

%% Write into a file
writetable(DATASETMutants,'ExcelResults/MutantsMatrixTable.xlsx')