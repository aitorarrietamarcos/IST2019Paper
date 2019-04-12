
clear;
clc;
load('TC_time.mat');
Init;
open 'CW_model';
ModelName = 'CW_model';
SignalBuilderName = 'Inputs';
SignalModel = [ModelName '/' SignalBuilderName];
TestObj = cvtest('CW_model');
TestObj.settings.mcdc = 1;
TestObj.settings.condition = 1;
TestObj.settings.decision = 1;
NTestCases = 1;


for x=1:NTestCases
    signalbuilder(SignalModel, 'activegroup',x);
    SimTime = time_testCases(x);
    cvdo{x} = cvsim(TestObj);
end

blk_handle = get_param('CW_model/CPSUT1','Handle')



% 
% %Hemendik aurrera fitness funciton-ean inplementatu beharko genuke:
% for i=1:5
%     if i==1
%         covdata = cvdo{i};
%     else
%         covdata = cvdo{i}+ covdata;
%     end
% end
% 
% 
% mcdcdata = mcdcinfo(covdata,blk_handle);
% conditiondata = conditioninfo(covdata,blk_handle);
% decisiondata = decisioninfo(covdata,blk_handle);
% 
% mcdcCoverage = mcdcdata(1)/mcdcdata(2);
% conditionCoverage = conditiondata(1)/conditiondata(2);
% decisionCoverage = decisiondata(1)/decisiondata(2);

