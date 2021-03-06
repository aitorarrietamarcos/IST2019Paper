function [F1] = nsga3()
    % 
    % Copyright (c) 2016, Yarpiz (www.yarpiz.com)
    % All rights reserved. Please read the "license.txt" for license terms.
    % 
    % Project Code: YPEA126
    % Project Title: Non-dominated Sorting Genetic Algorithm III (NSGA-III)
    % Publisher: Yarpiz (www.yarpiz.com)
    % 
    % Implemented by: S. Mostapha Kalami Heris, PhD (member of Yarpiz Team)
    % 
    % Contact Info: sm.kalami@gmail.com, info@yarpiz.com
    % 
    % Base Reference Paper:
    % K. Deb and H. Jain, "An Evolutionary Many-Objective Optimization Algorithm 
    % Using Reference-Point-Based Nondominated Sorting Approach, Part I: Solving
    % Problems With Box Constraints,"
    % in IEEE Transactions on Evolutionary Computation,
    % vol. 18, no. 4, pp. 577-601, Aug. 2014.
    % 
    % Reference Papaer URL: http://doi.org/10.1109/TEVC.2013.2281535
    % 

    %% Problem Definition

    CostFunction = @(x) MOP2(x);  % Cost Function

    nVar = 5;    % Number of Decision Variables

    VarSize = [1 nVar]; % Size of Decision Variables Matrix

    %VarMin = -1;   % Lower Bound of Variables
    %VarMax = 1;   % Upper Bound of Variables

    % Number of Objective Functions
    %nObj = numel(CostFunction(unifrnd(VarMin, VarMax, VarSize)));
    NumberOfTestCases = 150;
    nObj = numel(CostFunction(randi([0 1],1,NumberOfTestCases)));
    %% NSGA-II Parameters

    % Generating Reference Points
    nDivision = 10;
    Zr = GenerateReferencePoints(nObj, nDivision);

    MaxIt = 250;  % Maximum Number of Iterations

    nPop = 100;  % Population Size

    pCrossover = 0.8;   %To adjust and check in paper    % Crossover Percentage
    nCrossover = 2*round(pCrossover*nPop/2); % Number of Parnets (Offsprings)

    pMutation = 0.5;       % Mutation Percentage
    nMutation = round(pMutation*nPop);  % Number of Mutants

    mu = 1/NumberOfTestCases;%0.02;     % Mutation Rate

    sigma = 0.1*(1-0); % Mutation Step Size


    %% Colect Parameters

    params.nPop = nPop;
    params.Zr = Zr;
    params.nZr = size(Zr,2);
    params.zmin = [];
    params.zmax = [];
    params.smin = [];

    %% Initialization

    disp('Staring NSGA-III ...');

    empty_individual.Position = [];
    empty_individual.Cost = [];
    empty_individual.Rank = [];
    empty_individual.DominationSet = [];
    empty_individual.DominatedCount = [];
    empty_individual.NormalizedCost = [];
    empty_individual.AssociatedRef = [];
    empty_individual.DistanceToAssociatedRef = [];

    pop = repmat(empty_individual, nPop, 1);
    for i = 1:nPop
        %pop(i).Position = randi([0 1],1,NumberOfTestCases);
%         if i<nPop*1
%             pop(i).Position=randi([0 1],1,NumberOfTestCases);
%         else
%              pop(i).Position=zeros(1,NumberOfTestCases);%randi([0 1],1,TestSuiteSize);
%         end
        for jj=1:NumberOfTestCases
           pop(i).Position(jj) =  rand<=i*nPop/(nPop*100);
        end
        pop(i).Cost = CostFunction(pop(i).Position);
    end

    % Sort Population and Perform Selection
    [pop, F, params] = SortAndSelectPopulation(pop, params);


    %% NSGA-II Main Loop

    for it = 1:MaxIt

        % Crossover
        %popc = repmat(empty_individual, nCrossover/2, 2);
        popc = repmat(empty_individual,nPop/2,2);
        for k = 1:nPop/2

            i1 = randi([1 nPop]);
            p1 = pop(i1);

            i2 = randi([1 nPop]);
            p2 = pop(i2);
            %perform crossover
            [popc(k, 1).Position, popc(k, 2).Position] = Crossover(p1.Position, p2.Position, pCrossover);
            %perform mutation
             popc(k, 1).Position=Mutate(popc(k, 1).Position, mu, sigma);
             popc(k, 2).Position=Mutate(popc(k, 2).Position, mu, sigma);

             popc(k, 1).Cost = CostFunction(popc(k, 1).Position);
             popc(k, 2).Cost = CostFunction(popc(k, 2).Position);



            popc(k, 1).Cost = CostFunction(popc(k, 1).Position);
            popc(k, 2).Cost = CostFunction(popc(k, 2).Position);


        end
        popc = popc(:);

    %     % Mutation
    %     popm = repmat(empty_individual, nMutation, 1);
    %     for k = 1:nMutation %To check this loop
    % 
    %         i = randi([1 nPop]);
    %         p = pop(i);
    % 
    %         popm(k).Position = Mutate(p.Position, mu, sigma);
    % 
    %         popm(k).Cost = CostFunction(popm(k).Position);
    % 
    %     end

        % Merge
        pop = [pop
               popc]; %#ok

        % Sort Population and Perform Selection
        [pop, F, params] = SortAndSelectPopulation(pop, params);

        % Store F1
        F1 = pop(F{1});

    %     % Show Iteration Information
    %     disp(['Iteration ' num2str(it) ': Number of F1 Members = ' num2str(numel(F1))]);
    % 
        % Plot F1 Costs
%         figure(1);
%         PlotCosts(F1);
    %     %pause(0.01);

    end

    %% Results

    % disp(['Final Iteration: Number of F1 Members = ' num2str(numel(F1))]);
    % disp('Optimization Terminated.');

end
