function [totalInputEuclidean] = totalInputEuclidean(activationArray, nInputs)
global inputE
    for i = 1:nInputs
%         if ~exist(sprintf('data/inputEuclidean_%i.mat', i))
%             inputEuclidean = xlsread('BlackBoxAndWhiteBoxData/ExcelResults/InputEuclidean.xlsx', i);
%             save(sprintf('data/inputEuclidean_%i.mat', i),'inputEuclidean');
%         else
%             load(sprintf('data/inputEuclidean_%i.mat', i));
%         end
        outInputEuclidean(i) = calculateEuclidean(activationArray, inputE{i}.inputEuclidean);
    end
    a = 0;
    for i = 1:length(outInputEuclidean)
       a = a + outInputEuclidean(i);
    end
    totalInputEuclidean = a /length(outInputEuclidean);
end

