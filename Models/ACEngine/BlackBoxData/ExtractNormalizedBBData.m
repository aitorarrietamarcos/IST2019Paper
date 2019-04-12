clear;
clc;
load('blackboxdata120testcases.mat');
nTestCases = 120;
nOutputs = 1;
nInputs = 4;

for i=1:nTestCases
   DerivativeTC(i,1)=TCData{i}.Derivative(1);
%   DerivativeTC(i,2)=TCData{i}.Derivative(2);
   InfiniteTC(i,1)= TCData{i}.Infinite(1);
 %  InfiniteTC(i,2)= TCData{i}.Infinite(2);
   InstabilityTC(i,1) = CalculateInstability(TCData{i}.Output{1});
 %  InstabilityTC(i,2) = CalculateInstability(TCData{i}.Output{2});
   MinMax(i,1)= TCData{i}.MaxMin(1);
 %  MinMax(i,2)= TCData{i}.MaxMin(2);
end

maxROutput = 0;
minROutput = 399999999999999;
maxNumberOfIterationsOutput = 0;

for i= 1:nTestCases
    for j = 1:nOutputs
        if(max(TCData{i}.Output{j}) > maxROutput)
            maxROutput = max(TCData{i}.Output{j});
        end
        if((length(TCData{i}.Output{j})) > maxNumberOfIterationsOutput)
            maxNumberOfIterationsOutput = (length(TCData{i}.Output{j}));
        end
        if(min(TCData{i}.Output{j}) < minROutput)
            minROutput = min(TCData{i}.Output{j});
        end
    end
end

maxRInput = 0;
minRInput = 399999999999999;
maxNumberOfIterationsInput = 0;
for i= 1:nTestCases
    for j = 1:nInputs
        if(max(TCData{i}.Input{j}) > maxRInput)
            maxRInput = max(TCData{i}.Input{j});
        end
        if(max(length(TCData{i}.Input{j})) > maxNumberOfIterationsInput)
            maxNumberOfIterationsInput = max(length(TCData{i}.Input{j}));
        end
        if(min(TCData{i}.Input{j}) < minRInput)
            minRInput = min(TCData{i}.Input{j});
        end
    end
end
% maxNumberOfIterationsOutput2 = maxNumberOfIterationsOutput1
for i=1:nTestCases
   for j=i:nTestCases
      Output1EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData{i}.Output{1}, TCData{j}.Output{1},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output1EuclideanDistance(j,i) = Output1EuclideanDistance(i,j);
      
      %Output2EuclideanDistance(i,j) = ...
      %CalculateEuclideanDistance(TCData{i}.Output{1}, TCData{j}.Output{1},maxROutput,minROutput,maxNumberOfIterationsOutput);
      %Output2EuclideanDistance(j,i) = Output2EuclideanDistance(i,j);
      
      Input1EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData{i}.Input{1}, TCData{j}.Input{1},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input1EuclideanDistance(j,i) = Input1EuclideanDistance(i,j);
      
      Input2EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData{i}.Input{2}, TCData{j}.Input{2},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input2EuclideanDistance(j,i) = Input2EuclideanDistance(i,j);
      
      Input3EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData{i}.Input{3}, TCData{j}.Input{3},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input3EuclideanDistance(j,i) = Input3EuclideanDistance(i,j);
      
      Input4EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData{i}.Input{4}, TCData{j}.Input{4},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input4EuclideanDistance(j,i) = Input4EuclideanDistance(i,j);
      
      
   end    
end

xlswrite('OutputEuclidean.xlsx',Output1EuclideanDistance, 'Output1');
%xlswrite('OutputEuclidean.xlsx',Output2EuclideanDistance, 'Output2');
xlswrite('InputEuclidean.xlsx',Input1EuclideanDistance, 'Input1');
xlswrite('InputEuclidean.xlsx',Input2EuclideanDistance, 'Input2');
xlswrite('InputEuclidean.xlsx',Input3EuclideanDistance, 'Input3');
xlswrite('InputEuclidean.xlsx',Input4EuclideanDistance, 'Input4');
%xlswrite('InputEuclidean.xlsx',Input5EuclideanDistance, 'Input5');

% xlswrite('Anti-patterns.xlsx',InfiniteTC, 'Infinite');
% xlswrite('Anti-patterns.xlsx',DerivativeTC, 'Derivative');
% xlswrite('Anti-patterns.xlsx',InstabilityTC, 'Instability');
for(i=1:nTestCases)
    if(max(InfiniteTC(:,1))~=0)
        InfiniteTCN(i,1) = InfiniteTC(i,1)/max(InfiniteTC(:,1));
    else
        InfiniteTCN(i,1) = InfiniteTC(i,1);
    end
%     if(max(InfiniteTC(:,2))~=0)
%         InfiniteTCN(i,2) = InfiniteTC(i,2)/max(InfiniteTC(:,2));
%     else
%         InfiniteTCN(i,2) = InfiniteTC(i,2);
%     end
    if(max(DerivativeTC(:,1))~=0)
        DerivativeTCN(i,1) = DerivativeTC(i,1)/max(DerivativeTC(:,1));
    else
        DerivativeTCN(i,1) = DerivativeTC(i,1);
    end
%     if(max(DerivativeTC(:,2))~=0)
%         DerivativeTCN(i,2) = DerivativeTC(i,2)/max(DerivativeTC(:,2));
%     else
%         DerivativeTCN(i,2) = DerivativeTC(i,2);
%     end
    if(max(InstabilityTC(:,1))~=0)
        InstabilityTCN(i,1) = InstabilityTC(i,1)/max(InstabilityTC(:,1));
    else
        InstabilityTCN(i,1) = InstabilityTC(i,1);
    end
%     if(max(InstabilityTC(:,2))~=0)
%         InstabilityTCN(i,2) = InstabilityTC(i,2)/max(InstabilityTC(:,2));
%     else
%         InstabilityTCN(i,2) = InstabilityTC(i,2);
%     end
    if(max(MinMax(:,1))~=0)
        MinMaxTCN(i,1) = MinMax(i,1)/max(MinMax(:,1));
    else
        MinMaxTCN(i,1) = MinMax(i,1);
    end
%     if(max(MinMax(:,2))~=0)
%         MinMaxTCN(i,2) = MinMax(i,2)/max(MinMax(:,2));
%     else
%         MinMaxTCN(i,2) = MinMax(i,2);
%     end
end

for(i= 1:nTestCases)
    InfiniteTCN_Total(i,1) = mean(InfiniteTCN(i,:));
    DerivativeTCN_Total(i,1) = mean(DerivativeTCN(i,:));
    InstabilityTCN_Total(i,1) = mean(InstabilityTCN(i,:));
    MinMaxTCN_Total(i,1)=mean(MinMaxTCN(i,:));
end
xlswrite('Anti-patternsNormalized.xlsx',InfiniteTCN, 'Infinite');
xlswrite('Anti-patternsNormalized.xlsx',DerivativeTCN, 'Derivative');
xlswrite('Anti-patternsNormalized.xlsx',InstabilityTCN, 'Instability');
xlswrite('Anti-patternsNormalized_Total.xlsx',InfiniteTCN_Total, 'Infinite');
xlswrite('Anti-patternsNormalized_Total.xlsx',DerivativeTCN_Total, 'Derivative');
xlswrite('Anti-patternsNormalized_Total.xlsx',InstabilityTCN_Total, 'Instability');
xlswrite('Anti-patternsNormalized_Total.xlsx',MinMaxTCN_Total, 'MinMax');

