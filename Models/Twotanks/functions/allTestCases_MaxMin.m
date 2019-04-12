function [totalMinMax] = allTestCases_MaxMin(activationArray)
    if ~exist('data/minMax.mat')
        minMax = xlsread('BlackBoxAndWhiteBoxData/ExcelResults/Anti-patternsNormalized_Total.xlsx', 'MinMax');
        save('data/minMax.mat', 'minMax');
    else
        load('data/minMax.mat');
    end
    newMinMax = 0;
    allMinMax = 0;
    for k = 1:length(activationArray)
            allMinMax = allMinMax + minMax(k);
        if(activationArray(k) == 1)
            newMinMax = newMinMax + minMax(k);
        end
    end
    totalMinMax = newMinMax/allMinMax;
end