function [totalInfinite] = allTestCases_Infinite_old(activationArray,TCData)
    infiniteAllTestCases = zeros(1,length(TCData{1,1}.Infinite));
    newInfinite = zeros(1,length(TCData{1,1}.Infinite));
    for i = 1:length(TCData)
        for k = 1:length(TCData{1,i}.Infinite)
            infiniteAllTestCases(k) = infiniteAllTestCases(k) + TCData{1,i}.Infinite(k);
        end
        if(activationArray(i) == 1)
            for k = 1:length(TCData{1,i}.Infinite)
                newInfinite(k) = newInfinite(k) + TCData{1,i}.Infinite(k);
            end
        end
    end
    for i = 1:length(newInfinite)
        outInfinite(i) = newInfinite(i)/infiniteAllTestCases(i);
    end
    a = 0;
    for i = 1:length(outInfinite)
       a = a + outInfinite(i);
    end
    totalInfinite = a /length(outInfinite);
end

