function [totalInstability] = allTestCases_Instability(activationArray)
    if ~exist('data/instability.mat')
        instability = xlsread('BlackBoxAndWhiteBoxData/ExcelResults/Anti-patternsNormalized_Total.xlsx', 'Instability');
        save('data/instability.mat', 'instability');
    else
        load('data/instability.mat');
    end
    newInst = 0;
    allInst = 0;
    for k = 1:length(activationArray)
        allInst = allInst + instability(k);
        if(activationArray(k) == 1)
            newInst = newInst + instability(k);
        end
    end
    totalInstability = newInst/allInst;
end



