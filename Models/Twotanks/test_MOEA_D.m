restoredefaultpath;
clear;
clc;
close all;
addpath BlackBoxAndWhiteBoxData
addpath MOEA-D
addpath MOEA-D/functions
addpath MOEA-D/functions/pareto_HV
addpath MOEA-D/data

load('TCData.mat');

global TCD;
TCD = TCData;
clear TCData

global inputE
for i = 1:length(TCD(1).Input)
    inputE{i} = load(sprintf('data/inputEuclidean_%i.mat', i));
end

global OutputE
for i = 1:length(TCD(1).Output)
    OutputE{i} = load(sprintf('data/OutputEuclidean_%i.mat', i));
end

%% Genetic algorithm definitions
nRuns = 50;
popSize = 100;
maxGen = 250;

nvar = length(TCD);
algorithm = "MOEA-D";

%% Iterations
for iteration = 1:nRuns
    tic;
    [x] = moead();
    time = toc;
    for i = 1:size(x,1)
        [out] = fitnessFunctionTime_detectedMutants(x(i).Position);
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
    results_table(iteration,:) = table(algorithm, iteration, time, hv,...
        mean(G(:,1)), 1-mean(G(:,2)), max(G(:,1)), 1-min(G(:,2)), min(G(:,1)), 1-max(G(:,2)),...
        mean(G(P,1)), 1-mean(G(P,2)), max(G(P,1)), 1-min(G(P,2)), min(G(P,1)), 1-max(G(P,2)),...
        1-maxValue_Ms, maxValue_Tet, size(G,1), size(G(P,:), 1));
    G = [];
    P = [];
    secondPareto = [];
    results_overall = [];
    ms_time = [];
end


%% Save to xlsx file
results_table.Properties.VariableNames = {'Algorithm', 'nIteration',...
    'RunningTime', 'HyperVolume','MeanTestExecTime_firstPareto', 'MeanDetectedMutants_firstPareto', ...
    'MaxTestExecTime_firstPareto', 'MaxDetectedMutants_firstPareto','MinTestExecTime_firstPareto', ...
    'MinDetectedMutants_firstPareto', 'MeanTestExecTime_secondPareto', 'MeanDetectedMutants_secondPareto', ...
    'MaxTestExecTime_secondPareto', 'MaxDetectedMutants_secondPareto','MinTestExecTime_secondPareto', ...
    'MinDetectedMutants_secondPareto', 'MaxMS_val_secondPareto', 'MaxTET_val_secondPareto',...
    'nSolutions_firstPareto', 'nSolutions_secondPareto'};
writetable(results_table, 'resultsExec_moead_seeded.xlsx');
