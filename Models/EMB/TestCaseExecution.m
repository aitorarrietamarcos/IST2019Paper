clear;
clc;
EMB_Initialize;

load('TestCases.mat');
x = input('Select which test case has to be executed (number from 1 to 150)\n');
open 'EMB';
TestObj = 'EMB';

if(x > 0 && x < 151)
    time = 0:(0.000005):(TestCase{x}.Time);
    Brake = timeseries(TestCase{x}.Input, time);
    SimTime = TestCase{x}.Time;
    sim(TestObj);
end