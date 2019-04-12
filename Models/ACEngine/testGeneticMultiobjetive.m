restoredefaultpath;
clear;
clc;
close all;
addpath functions
addpath functions/pareto_HV
addpath data
load('FDC_DATA.mat');
global TCD;
TCD = test_case;
clear test_case
%% White-Box or Black-Box fitness functions definition
% Uncomment this to execute black box testing

global nInputs
nInputs = 4;
global nOutputs
nOutputs = 1;
global inputE
for i = 1:nInputs
    inputE{i} = load(sprintf('data/inputEuclidean_%i.mat', i));
end

global OutputE
for i = 1:nOutputs
    OutputE{i} = load(sprintf('data/OutputEuclidean_%i.mat', i));
end
fitness = {@(a) fitnessFunctionDerivative(a); @(a) fitnessFunctionInfinite(a); ...
    @(a) fitnessFunctionInstability(a); @(a) fitnessFunctionInputEuclidean(a); ...
    @(a) fitnessFunctionOutputEuclidean(a); @(a) fitnessFunctionMinMax(a); ...
    @(a) fitnessFunctionDerivative_Infinite(a); @(a) fitnessFunctionDerivative_Instability(a); ...
    @(a) fitnessFunctionDerivative_InputEuclidean(a); @(a) fitnessFunctionDerivative_OutputEuclidean(a);...
    @(a) fitnessFunctionDerivative_MinMax(a); @(a) fitnessFunctionInfinite_Instability(a);...
    @(a) fitnessFunctionInfinite_InputEuclidean(a); @(a) fitnessFunctionInfinite_OutputEuclidean(a);...
    @(a) fitnessFunctionInfinite_MinMax(a); @(a) fitnessFunctionInstability_InputEuclidean(a); ...
    @(a) fitnessFunctionInstability_OutputEuclidean(a); @(a) fitnessFunctionInstability_MinMax(a); ...
    @(a) fitnessFunctionInputEuclidean_OutputEuclidean(a); @(a) fitnessFunctionInputEuclidean_MinMax(a); ...
    @(a) fitnessFunctionOutputEuclidean_MinMax(a)};
FitnessName = {"Time/Derivative", "Time/Infinite", "Time/Instability", "Time/InputEuclidean", "Time/OutputEuclidean", "Time/MinMax",...
    "Time/Derivative/Infinite", "Time/Derivative/Instability", "Time/Derivative/InputEuclidean", "Time/Derivative/OutputEuclidean", "Time/Derivative/MinMax"...
    "Time/Infinite/Instability", "Time/Infinite/InputEuclidean", "Time/Infinite/OutputEuclidean", "Time/Infinite/MinMax","Time/Instability/InputEuclidean"...
    "Time/Instability/OutputEuclidean", "Time/Instability/MinMax","Time/InputEuclidean/OutputEuclidean", "Time/InputEuclidean/MinMax", "Time/OutputEuclidean/MinMax"};

% Uncomment this to execute white box testing
% global system;
% system = 'CL_pi_testExecution';
% global data_objects;
% [test_objects, data_objects] = cvload('AC_testData');
% open 'CL_pi_testExecution.slx'
% fitness = {@(a) fitnessFunction_cc(a); @(a) fitnessFunction_dc(a);@(a) fitnessFunction_mcdc(a)};
% FitnessName = {"Time/CC", "Time/DC", "Time/MCDC"};

%% Genetic algorithm definitions
nRuns = 50;
popSize = 100;
maxGen = 250;

nvar = length(TCD);
options = optimoptions(@gamultiobj, 'PopulationType','bitstring', 'PopulationSize', popSize, 'MaxGenerations', maxGen);
algorithm = "NSGA-II";

%% Iterations
k = 1;
for nFitness = 1:length(fitness)
    for iteration = 1:nRuns
        tic;
        objetives = FitnessName{nFitness};
        [x, fval, exitflag, output,population, scores] = ...
            gamultiobj(fitness{nFitness}, nvar, [],[],[],[],[], [], options);
        time = toc;
        for i = 1:size(x,1)
            [out] = fitnessFunctionTime_detectedMutants(x(i, :));
            ms_time(i,:) = out(1:2);
            results_overall(i,:) = out;
        end
        for mm=1:size(results_overall,1)
            G(mm,1) = results_overall(mm,1);
            G(mm,2) = results_overall(mm,2);
        end
        % Approximation of Pareto set
        P=paretofront(G);
        % Hypervolume
        r = [1 1];
        hv=hypervolume(G(P,:),r,100000);
        [maxValue_Ms, posMax_Ms] = min(G(P,2));
        secondPareto = G(P,:);
        maxValue_Tet = secondPareto(posMax_Ms,1);
        results_table(k,:) = table(algorithm, iteration, objetives, time, hv,...
            mean(G(:,1)), 1-mean(G(:,2)), max(G(:,1)), 1-min(G(:,2)), min(G(:,1)), 1-max(G(:,2)),...
            mean(G(P,1)), 1-mean(G(P,2)), max(G(P,1)), 1-min(G(P,2)), min(G(P,1)), 1-max(G(P,2)),...
            1-maxValue_Ms, maxValue_Tet, size(G,1), size(G(P,:), 1));
        k = k+1;
		G = [];
        P = [];
        secondPareto = [];
        results_overall = [];
        ms_time = [];
    end
end

%% Save to xlsx file
results_table.Properties.VariableNames = {'Algorithm', 'nIteration','Objetives',...
    'RunningTime', 'HyperVolume','MeanTestExecTime_firstPareto', 'MeanDetectedMutants_firstPareto', ...
    'MaxTestExecTime_firstPareto', 'MaxDetectedMutants_firstPareto','MinTestExecTime_firstPareto', ...
    'MinDetectedMutants_firstPareto', 'MeanTestExecTime_secondPareto', 'MeanDetectedMutants_secondPareto', ...
    'MaxTestExecTime_secondPareto', 'MaxDetectedMutants_secondPareto','MinTestExecTime_secondPareto', ...
    'MinDetectedMutants_secondPareto', 'MaxMS_val_secondPareto', 'MaxTET_val_secondPareto',...
    'nSolutions_firstPareto', 'nSolutions_secondPareto'};
writetable(results_table, 'resultsExec_nsga2.xlsx');
