function [totalOutputEuclidean] = totalOutputEuclidean(activationArray,nOutputs)
global OutputE;
    for i = 1:nOutputs
%         if ~exist(sprintf('data/OutputEuclidean_%i.mat', i))
%             OutputEuclidean = xlsread('OutputEuclidean.xlsx', i);
%             save(sprintf('data/OutputEuclidean_%i.mat', i),'OutputEuclidean');
%         else
%             load(sprintf('data/OutputEuclidean_%i.mat', i));
%         end
        outOutputEuclidean(i) = calculateEuclidean(activationArray, OutputE{i}.OutputEuclidean);
    end
    a = 0;
    for i = 1:length(outOutputEuclidean)
       a = a + outOutputEuclidean(i);
    end
    totalOutputEuclidean = a /length(outOutputEuclidean);
end
