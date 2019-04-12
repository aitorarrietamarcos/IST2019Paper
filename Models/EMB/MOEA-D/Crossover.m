%
% Copyright (c) 2015, Yarpiz (www.yarpiz.com)
% All rights reserved. Please read the "license.txt" for license terms.
%
% Project Code: YPEA124
% Project Title: Implementation of MOEA/D
% Muti-Objective Evolutionary Algorithm based on Decomposition
% Publisher: Yarpiz (www.yarpiz.com)
% 
% Developer: S. Mostapha Kalami Heris (Member of Yarpiz Team)
% 
% Contact Info: sm.kalami@gmail.com, info@yarpiz.com
%

function y1=Crossover(x1,x2)

    %alpha=rand(size(x1));
    testSuiteSize = size(x1,2);
    xoverPoint = randi(testSuiteSize);
    %y1=x1;%alpha.*x1+(1-alpha).*x2;
    %y2=x2;%alpha.*x2+(1-alpha).*x1;
    y1 = [x1(1:xoverPoint) x2(xoverPoint+1:testSuiteSize)];
    %y2 = [x2(1:xoverPoint) x1(xoverPoint+1:testSuiteSize)];
    
    
end