function [out] = fitnessFunctionDerivative_Infinite(activationArray)
    popSize = size(activationArray, 1); %Population size
    numObj = 3; %Number of objetives
    global TCD;    
    total_time = 0;
    time = 0;
    for i = 1:length(TCD)
        total_time = total_time +  TCD(i).Time;
        if(activationArray(i) == 1)
            time = time +  TCD(i).Time;
        end
    end
    out = zeros(popSize, numObj);
    [derivative] = allTestCases_Derivative(activationArray);
    [infinite] = allTestCases_Infinite(activationArray);
    out(1) = time/total_time;
    out(2) = 1-derivative;
    out(3) = 1-infinite;
end