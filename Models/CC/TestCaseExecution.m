clear;
clc;
Configurations;
open 'CC_Model';
TestObj = 'CC_Model';
load('TestCases.mat');

x = input('Select which test case has to be executed (number from 1 to 150)\n');
if(x > 0 && x < 151)
    time = 0:TestCase{x}.Time;
    
    Enable = timeseries(TestCase{x}.Input{1}, time);
    Brake = timeseries(TestCase{x}.Input{2}, time);
    Set = timeseries(TestCase{x}.Input{3}, time);
    Speed = timeseries(TestCase{x}.Input{4}, time);
    Inc = timeseries(TestCase{x}.Input{5}, time);
    Dec = timeseries(TestCase{x}.Input{6}, time);
    SimTime = TestCase{x}.Time;
    sim(TestObj);
end
