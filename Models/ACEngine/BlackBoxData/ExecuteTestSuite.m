Init;
%Init_Variability;
open 'CL_pi_testExecution';
ModelName = 'CL_pi_testExecution';
TestObj = cvtest('CL_pi_testExecution');
TestObj.settings.mcdc = 1;
TestObj.settings.condition = 1;
TestObj.settings.decision = 1;

for i=1:120
    TestOrder = [i]; %Add test order
    cvdo{i} = cvsim(TestObj);  
 %   sim(ModelName);
%     TCData{i}.Derivative(1) =  Derivative1(size(Derivative1,1));
%     TCData{i}.Infinite(1) =  Infinite1(size(Infinite1,1));
%     TCData{i}.Instability(1) = CalculateInstability(Output1);
%     TCData{i}.MaxMin(1) = MaxMin1(size(MaxMin1,1));
%     TCData{i}.Output{1} =  Output1;
%     TCData{i}.Input{1} =  StimuliInput1;
%     TCData{i}.Input{2} =  StimuliInput2;
%     TCData{i}.Input{3} =  StimuliInput3;
%     TCData{i}.Input{4} =  StimuliInput4;
%     TCData{i}.Time = time(size(time,1));
    
end

blk_handle = get_param('CL_pi_testExecution/System','Handle');

% 
% %Hemendik aurrera fitness funciton-ean inplementatu beharko genuke:
for i=1:120
    %if i==1
        %covdata = cvdo{i};
    %else
        covdata = cvdo{i}+ covdata;
    %end
end

% 
% mcdcdata = mcdcinfo(covdata,blk_handle);
% conditiondata = conditioninfo(covdata,blk_handle);
% decisiondata = decisioninfo(covdata,blk_handle);
% 
% mcdcCoverage = mcdcdata(1)/mcdcdata(2);
% conditionCoverage = conditiondata(1)/conditiondata(2);
% decisionCoverage = decisiondata(1)/decisiondata(2);
