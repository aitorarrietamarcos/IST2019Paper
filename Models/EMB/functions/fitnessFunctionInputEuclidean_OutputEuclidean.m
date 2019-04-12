function [out] = fitnessFunctionInputEuclidean_OutputEuclidean(activationArray)
    popSize = size(activationArray, 1); %Population size
    numObj = 3; %Number of objetives
    global TCD;    
    time = 0;
    total_time = 0;
    for i = 1:length(TCD)
        total_time = total_time + TCD{i}.Time;
        if(activationArray(i) == 1)
            time = time + TCD{i}.Time;
        end
    end
    out = zeros(popSize, numObj);
    [euclidean_o] = totalOutputEuclidean(activationArray, size(TCD{1}.Output,2));
    [euclidean_i] = totalInputEuclidean(activationArray, size(TCD{1}.Input,2));
    out(1) = time/total_time;
    out(2) = 1-euclidean_i;
    out(3) = 1-euclidean_o;
end