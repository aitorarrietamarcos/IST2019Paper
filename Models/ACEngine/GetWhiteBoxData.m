clear;
clc;
open 'CL_pi_testExecution';
%TestObj = 'CC_Model';
load('FDC_DATA.mat');

TestObj = cvtest('CL_pi_testExecution');

TestObj.settings.mcdc = 1;
TestObj.settings.condition = 1;
TestObj.settings.decision = 1;

%x = input('Select which test case has to be executed (number from 1 to 150)\n');
for i=1:120
    TestOrder = [1]; %Add test order
    time = test_case(i).Time;
    cvdo{i} = cvsim(TestObj);
    i
end

cvsave('WhiteBoxCov_2017b', cvdo{ :});
