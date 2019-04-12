function [out] = fitnessFunctionOutputEuclidean(activationArray)
    popSize = size(activationArray, 1); %Population size
    numObj = 2; %Number of objetives
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
    [euclidean] = totalOutputEuclidean(activationArray, length(TCD{1}.Output));
    out(1) = time/total_time;
    out(2) = 1-euclidean;
end
