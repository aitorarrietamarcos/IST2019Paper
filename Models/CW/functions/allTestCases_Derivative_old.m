function [totalDerivative] = allTestCases_Derivative(activationArray,TCData)
    derivativeAllTestCases = zeros(1,length(TCData{1,1}.Derivative));
    newDerivative = zeros(1,length(TCData{1,1}.Derivative));
    for i = 1:length(TCData)
        for k = 1:length(TCData{1,i}.Derivative)
            derivativeAllTestCases(k) = derivativeAllTestCases(k) + TCData{1,i}.Derivative{1,k};
        end
        if(activationArray(i) == 1)
            for k = 1:length(TCData{1,i}.Derivative)
                newDerivative(k) = newDerivative(k) + TCData{1,i}.Derivative{1,k};
            end
        end
    end
    for i = 1:length(newDerivative)
        outDerivative(i) = newDerivative(i)/derivativeAllTestCases(i);
    end
    a = 0;
    for i = 1:length(outDerivative)
       a = a + outDerivative(i);
    end
    totalDerivative = a /length(outDerivative);
end

