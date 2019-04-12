function x = Mutation(x,mu)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
 testSuiteSize=numel(x);
    for ii=1:testSuiteSize
       if mu >=rand 
           x(ii)= ~ x(ii);
       end
    end
end

