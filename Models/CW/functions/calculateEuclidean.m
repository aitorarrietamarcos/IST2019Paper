function [outEuclidean] = calculateEuclidean(activationArray, euclideanTable)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
    NTC = 0;
    outEuclidean = 0;
    for i = 1:length(activationArray)
        if(activationArray(i) ~= 0)
            NTC = NTC + 1;
        end
    end
    if(NTC > 1)
        for i = 1:length(activationArray)
            if(activationArray(i) == 1)
                for j = 1:length(activationArray)
                    if(activationArray(j) == 1)
                        outEuclidean = outEuclidean + abs(euclideanTable(i,i) - euclideanTable(i,j));
                    end
                end
            end
        end
        outEuclidean = outEuclidean/(133*((133-1)/2));
    else
        outEuclidean = 0;
    end
end

