
function z=MOP2(x)
    global TCD

    time = 0;
    total_time = 0;
    for i = 1:length(TCD)
        total_time = total_time + TCD{i}.Time;
        if(x(i) == 1)
            time = time + TCD{i}.Time;
        end
    end
    
    cost = time/total_time;
    [discontinuity] = allTestCases_Derivative(x);
    [infinity] = allTestCases_Infinite(x);
    [instability] = allTestCases_Instability(x);
    [minmax] = allTestCases_MaxMin(x);
    % [indistance] = totalInputEuclidean(x, size(TCD{1}.Input, 2));
    % [outdistance] = totalOutputEuclidean(x, size(TCD{1}.Output, 2));

    z=[cost  (1 - instability) (1 - discontinuity) (1 - infinity)  ...
        (1 - minmax) (1 - indistance) (1 - outdistance)]';
end