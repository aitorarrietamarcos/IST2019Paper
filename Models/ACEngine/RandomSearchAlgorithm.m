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

%% Random Search definitions
nRuns = 1;%50;
popSize = 100;
maxGen = 250;
nvar = length(TCD);

VarSize = [1 nvar];
algorithm = "RS";
TestSuiteSize = 120;
nPop=100;
MaxIt = 250;

%% Iterations
k = 1;
for nFitness = 1:length(fitness)
    nFitness
    for iteration = 1:nRuns
        objetives = FitnessName{nFitness};
        % Activation array generation
        tic
        for i=1:(nPop*MaxIt)
            pop(i).Position=randi([0 1], 1, TestSuiteSize);
            pop(i).Cost=fitness{nFitness}(pop(i).Position);
        end
        for mm=1:size(pop,2)
            if(nFitness >= 7)
                G(mm,1) = pop(mm).Cost(1);
                G(mm,2) = pop(mm).Cost(2);
                G(mm,3) = pop(mm).Cost(3);
            else
                G(mm,1) = pop(mm).Cost(1);
                G(mm,2) = pop(mm).Cost(2);
            end
        end
        P=paretofront(G);
        time = toc;
        pos = 1;
        for j = 1:length(P)
           if(P(j,1) == 1)
               x(pos,:) = pop(1,j).Position;
               pos = pos+1;
           end
        end
        for i = 1:size(x,1)
            [out] = fitnessFunctionTime_detectedMutants(x(i, :));
            ms_time(i,:) = out(1:2);
            results_overall(i,:) = out;
        end
        for mm=1:size(results_overall,1)
            A(mm,1) = results_overall(mm,1);
            A(mm,2) = results_overall(mm,2);
        end
        P = [];
        % Approximation of Pareto set
        P=paretofront(A);
        % Hypervolume
        r = [1 1];
        hv=hypervolume(A(P,:),r,100000);
        [maxValue_Ms, posMax_Ms] = min(A(P,2));
        secondPareto = A(P,:);
        maxValue_Tet = secondPareto(posMax_Ms,1);
       results_table(k,:) = table(algorithm, iteration, objetives, time, hv,...
            mean(A(:,1)), 1-mean(A(:,2)), max(A(:,1)), 1-min(A(:,2)), min(A(:,1)), 1-max(A(:,2)),...
            mean(A(P,1)), 1-mean(A(P,2)), max(A(P,1)), 1-min(A(P,2)), min(A(P,1)), 1-max(A(P,2)),...
            1-maxValue_Ms, maxValue_Tet, size(A,1), size(A(P,:), 1));
        k = k+1;
        A = [];
		G = [];
        P = [];
        secondPareto = [];
        ms_time = [];
        results_overall = [];
        pop = [];
    end
    nFitness
end

%% Save to xlsx file
results_table.Properties.VariableNames = {'Algorithm', 'nIteration','Objetives',...
    'RunningTime', 'HyperVolume','MeanTestExecTime_firstPareto', 'MeanDetectedMutants_firstPareto', ...
    'MaxTestExecTime_firstPareto', 'MaxDetectedMutants_firstPareto','MinTestExecTime_firstPareto', ...
    'MinDetectedMutants_firstPareto', 'MeanTestExecTime_secondPareto', 'MeanDetectedMutants_secondPareto', ...
    'MaxTestExecTime_secondPareto', 'MaxDetectedMutants_secondPareto','MinTestExecTime_secondPareto', ...
    'MinDetectedMutants_secondPareto', 'MaxMS_val_secondPareto', 'MaxTET_val_secondPareto',...
    'nSolutions_firstPareto', 'nSolutions_secondPareto'};
writetable(results_table, 'Results/results_exec_rs_ACC_50iter.xlsx');