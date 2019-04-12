% 
% Copyright (c) 2016, Yarpiz (www.yarpiz.com)
% All rights reserved. Please read the "license.txt" for license terms.
% 
% Project Code: YPEA126
% Project Title: Non-dominated Sorting Genetic Algorithm III (NSGA-III)
% Publisher: Yarpiz (www.yarpiz.com)
% 
% Implemented by: S. Mostapha Kalami Heris, PhD (member of Yarpiz Team)
% 
% Contact Info: sm.kalami@gmail.com, info@yarpiz.com
% 
% Base Reference Paper:
% K. Deb and H. Jain, "An Evolutionary Many-Objective Optimization Algorithm 
% Using Reference-Point-Based Nondominated Sorting Approach, Part I: Solving
% Problems With Box Constraints,"
% in IEEE Transactions on Evolutionary Computation,
% vol. 18, no. 4, pp. 577-601, Aug. 2014.
% 
% Reference Papaer URL: http://doi.org/10.1109/TEVC.2013.2281535
% 

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
    %[indistance] = totalInputEuclidean(x, length(TCD{1}.Input));
    %[outdistance] = totalOutputEuclidean(x, length(TCD{1}.Output));

    z=[cost  (1 - discontinuity) (1 - infinity) (1 - instability) ...
        (1 - minmax) (1 - indistance) (1 - outdistance)]';

end