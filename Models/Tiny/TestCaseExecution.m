clear;
clc;

open 'Tiny';
TestObj = 'Tiny';
load('TestCases.mat')

x = input('Select which test case has to be executed (number from 1 to 150)\n');
if(x > 0 && x < 151)
    time = 0:TestCase{x}.Time;
    
    Val1 = timeseries(TestCase{x}.Input{1}, time);
    Val2 = timeseries(TestCase{x}.Input{2}, time);
    Val3 = timeseries(TestCase{x}.Input{3}, time);
    SimTime = TestCase{x}.Time;
    sim(TestObj);
end
