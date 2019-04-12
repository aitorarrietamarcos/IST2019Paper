function [totalInstability] = allTestCases_Instability_old(activationArray,TCData)
    instabilityAllTestCases = zeros(1,length(TCData{1,1}.Instability));
    newInstability = zeros(1,length(TCData{1,1}.Instability));
    for i = 1:length(TCData)

        for k = 1:length(TCData{1,i}.Instability)
            instabilityAllTestCases(k) = instabilityAllTestCases(k) + TCData{1,i}.Instability{1,k};
        end
        if(activationArray(i) == 1)
            for k = 1:length(TCData{1,i}.Instability)
                newInstability(k) = newInstability(k) + TCData{1,i}.Instability{1,k};
            end
        end
    end
    for i = 1:length(newInstability)
        outInstability(i) = newInstability(i)/instabilityAllTestCases(i);
    end
    a = 0;
    for i = 1:length(outInstability)
       a = a + outInstability(i);
    end
    totalInstability = a /length(outInstability);
end

