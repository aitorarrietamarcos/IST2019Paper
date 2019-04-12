function [out] = fitnessFunction_cc(activationArray)
    popSize = size(activationArray, 1); %Population size
    numObj = 2; %Number of objetives
    global TCD;
    global system;
    global data_objects;

    total_time = 0;
    time = 0;
    for i = 1:length(TCD)
        total_time = total_time + TCD(i).Time;
        if(activationArray(i) == 1)
            time = time + TCD(i).Time;
        end
    end
    [cc] = getCc(activationArray, data_objects, system);
    out = zeros(popSize, numObj);
    out(1) = time/total_time;
    out(2) = 1-cc;
end