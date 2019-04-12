function [EuclideanDistance] = CalculateEuclideanDistance(sg1,sg2,maxsig,minsig,maxnumberofiterations)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    sum = 0;
    for i=1:min(size(sg1,1),size(sg2,1))
        sum=(sg1(i)-sg2(i))^2+ sum;
    end
    EuclideanDistance=(sqrt(sum))/(sqrt(maxnumberofiterations+1)*(maxsig-minsig));
end

%EMB output max = 8.4813e+05 min -2.5407e+7