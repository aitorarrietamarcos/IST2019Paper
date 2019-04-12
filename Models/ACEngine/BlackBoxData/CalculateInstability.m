function Instability = CalculateInstability(sg)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    Instability = 0;
    for i=2:size(sg,1)
        Instability = abs(sg(i)-sg(i-1))+Instability;
    end

end

