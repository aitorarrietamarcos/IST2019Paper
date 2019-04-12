function [totalInfinite] = allTestCases_Infinite(activationArray)
    if ~exist('data/infinite.mat')
        infinite = xlsread('BlackBoxAndWhiteBoxData/ExcelResults/Anti-patternsNormalized_Total.xlsx', 'Infinite');
        save('data/infinite.mat', 'infinite');
    else
        load('data/infinite.mat');
    end
    newInf = 0;
    allInf = 0;
    for k = 1:length(activationArray)
        allInf = allInf + infinite(k);
        if(activationArray(k) == 1)
            newInf = newInf + infinite(k);
        end
    end
    totalInfinite = newInf/allInf;
end
