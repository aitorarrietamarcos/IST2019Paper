function [totalDerivative] = allTestCases_Derivative(activationArray)
    if ~exist('data/derivative.mat')
        derivative = xlsread('BBDataNorm/Anti-patternsNormalized_Total.xlsx', 'Derivative');
        save('data/derivative.mat', 'derivative');
    else
        load('data/derivative.mat');
    end
    newDerivative = 0;
    allDerivatives = 0;
    for k = 1:length(activationArray)
            allDerivatives = allDerivatives + derivative(k);
        if(activationArray(k) == 1)
            newDerivative = newDerivative + derivative(k);
        end
    end
    totalDerivative = newDerivative/allDerivatives;
end

