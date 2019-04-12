clear;
clc;
load('TC_time.mat');
Init;
open 'CW_model';
TestObj = 'CW_model';
SignalBuilderName = 'Inputs';
SignalModel = [TestObj '/' SignalBuilderName];
x = input('Select which test case has to be executed (number from 1 to 150)\n');
if(x > 0 && x < 151)
    signalbuilder(SignalModel, 'activegroup',x);
    SimTime = time_testCases(x);
    sim(TestObj);
end