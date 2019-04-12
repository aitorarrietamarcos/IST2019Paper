clear;
clc;
load('TCData.mat');

for i=1:size(TCData,2)
   DerivativeTC(i,1) = TCData(i).Derivative{1,1}(size(TCData(i).Derivative{1,1}, 1));
   DerivativeTC(i,2) = TCData(i).Derivative{1,2}(size(TCData(i).Derivative{1,2}, 1));
   DerivativeTC(i,3) = TCData(i).Derivative{1,3}(size(TCData(i).Derivative{1,3}, 1));
   DerivativeTC(i,4) = TCData(i).Derivative{1,4}(size(TCData(i).Derivative{1,4}, 1));
   DerivativeTC(i,5) = TCData(i).Derivative{1,5}(size(TCData(i).Derivative{1,5}, 1));
   DerivativeTC(i,6) = TCData(i).Derivative{1,6}(size(TCData(i).Derivative{1,6}, 1));
   DerivativeTC(i,7) = TCData(i).Derivative{1,7}(size(TCData(i).Derivative{1,7}, 1));
%    DerivativeTC(i,8) = TCData(i).Derivative{1,8}(size(TCData(i).Derivative{1,8}, 1));
%    DerivativeTC(i,9) = TCData(i).Derivative{1,9}(size(TCData(i).Derivative{1,9}, 1));
%    DerivativeTC(i,10) = TCData(i).Derivative{1,10}(size(TCData(i).Derivative{1,10}, 1));
%    DerivativeTC(i,11) = TCData(i).Derivative{1,11}(size(TCData(i).Derivative{1,11}, 1));
%    DerivativeTC(i,12) = TCData(i).Derivative{1,12}(size(TCData(i).Derivative{1,12}, 1));
%    DerivativeTC(i,13) = TCData(i).Derivative{1,13}(size(TCData(i).Derivative{1,13}, 1));
%    DerivativeTC(i,14) = TCData(i).Derivative{1,14}(size(TCData(i).Derivative{1,14}, 1));
%    DerivativeTC(i,15) = TCData(i).Derivative{1,15}(size(TCData(i).Derivative{1,15}, 1));
%    DerivativeTC(i,16) = TCData(i).Derivative{1,16}(size(TCData(i).Derivative{1,16}, 1));
%    DerivativeTC(i,17) = TCData(i).Derivative{1,17}(size(TCData(i).Derivative{1,17}, 1));
%    DerivativeTC(i,18) = TCData(i).Derivative{1,18}(size(TCData(i).Derivative{1,18}, 1));
%    DerivativeTC(i,19) = TCData(i).Derivative{1,19}(size(TCData(i).Derivative{1,19}, 1));
%    DerivativeTC(i,20) = TCData(i).Derivative{1,20}(size(TCData(i).Derivative{1,20}, 1));
%    DerivativeTC(i,21) = TCData(i).Derivative{1,21}(size(TCData(i).Derivative{1,21}, 1));
%    DerivativeTC(i,22) = TCData(i).Derivative{1,22}(size(TCData(i).Derivative{1,22}, 1));

   InfiniteTC(i,1) = TCData(i).Infinite{1,1}(size(TCData(i).Infinite{1,1}, 1));
   InfiniteTC(i,2) = TCData(i).Infinite{1,2}(size(TCData(i).Infinite{1,2}, 1));
   InfiniteTC(i,3) = TCData(i).Infinite{1,3}(size(TCData(i).Infinite{1,3}, 1));
   InfiniteTC(i,4) = TCData(i).Infinite{1,4}(size(TCData(i).Infinite{1,4}, 1));
   InfiniteTC(i,5) = TCData(i).Infinite{1,5}(size(TCData(i).Infinite{1,5}, 1));
   InfiniteTC(i,6) = TCData(i).Infinite{1,6}(size(TCData(i).Infinite{1,6}, 1));
   InfiniteTC(i,7) = TCData(i).Infinite{1,7}(size(TCData(i).Infinite{1,7}, 1));
%    InfiniteTC(i,8) = TCData(i).Infinite{1,8}(size(TCData(i).Infinite{1,8}, 1));
%    InfiniteTC(i,9) = TCData(i).Infinite{1,9}(size(TCData(i).Infinite{1,9}, 1));
%    InfiniteTC(i,10) = TCData(i).Infinite{1,10}(size(TCData(i).Infinite{1,10}, 1));
%    InfiniteTC(i,11) = TCData(i).Infinite{1,11}(size(TCData(i).Infinite{1,11}, 1));
%    InfiniteTC(i,12) = TCData(i).Infinite{1,12}(size(TCData(i).Infinite{1,12}, 1));
%    InfiniteTC(i,13) = TCData(i).Infinite{1,13}(size(TCData(i).Infinite{1,13}, 1));
%    InfiniteTC(i,14) = TCData(i).Infinite{1,14}(size(TCData(i).Infinite{1,14}, 1));
%    InfiniteTC(i,15) = TCData(i).Infinite{1,15}(size(TCData(i).Infinite{1,15}, 1));
%    InfiniteTC(i,16) = TCData(i).Infinite{1,16}(size(TCData(i).Infinite{1,16}, 1));
%    InfiniteTC(i,17) = TCData(i).Infinite{1,17}(size(TCData(i).Infinite{1,17}, 1));
%    InfiniteTC(i,18) = TCData(i).Infinite{1,18}(size(TCData(i).Infinite{1,18}, 1));
%    InfiniteTC(i,19) = TCData(i).Infinite{1,19}(size(TCData(i).Infinite{1,19}, 1));
%    InfiniteTC(i,20) = TCData(i).Infinite{1,20}(size(TCData(i).Infinite{1,20}, 1));
%    InfiniteTC(i,21) = TCData(i).Infinite{1,21}(size(TCData(i).Infinite{1,21}, 1));
%    InfiniteTC(i,22) = TCData(i).Infinite{1,22}(size(TCData(i).Infinite{1,22}, 1));
   
   
   InstabilityTC(i,1) = CalculateInstability(TCData(i).Output{1});
   InstabilityTC(i,2) = CalculateInstability(TCData(i).Output{2});
   InstabilityTC(i,3) = CalculateInstability(TCData(i).Output{3});
   InstabilityTC(i,4) = CalculateInstability(TCData(i).Output{4});
   InstabilityTC(i,5) = CalculateInstability(TCData(i).Output{5});
   InstabilityTC(i,6) = CalculateInstability(TCData(i).Output{6});
   InstabilityTC(i,7) = CalculateInstability(TCData(i).Output{7});
%    InstabilityTC(i,8) = CalculateInstability(TCData(i).Output{8});
%    InstabilityTC(i,9) = CalculateInstability(TCData(i).Output{9});
%    InstabilityTC(i,10) = CalculateInstability(TCData(i).Output{10});
%    InstabilityTC(i,11) = CalculateInstability(TCData(i).Output{11});
%    InstabilityTC(i,12) = CalculateInstability(TCData(i).Output{12});
%    InstabilityTC(i,13) = CalculateInstability(TCData(i).Output{13});
%    InstabilityTC(i,14) = CalculateInstability(TCData(i).Output{14});
%    InstabilityTC(i,15) = CalculateInstability(TCData(i).Output{15});
%    InstabilityTC(i,16) = CalculateInstability(TCData(i).Output{16});
%    InstabilityTC(i,17) = CalculateInstability(TCData(i).Output{17});
%    InstabilityTC(i,18) = CalculateInstability(TCData(i).Output{18});
%    InstabilityTC(i,19) = CalculateInstability(TCData(i).Output{19});
%    InstabilityTC(i,20) = CalculateInstability(TCData(i).Output{20});
%    InstabilityTC(i,21) = CalculateInstability(TCData(i).Output{21});
%    InstabilityTC(i,22) = CalculateInstability(TCData(i).Output{22});

   MinMaxTC(i,1) = TCData(i).Maxmin{1,1}(size(TCData(i).Maxmin{1,1}, 1));
   MinMaxTC(i,2) = TCData(i).Maxmin{1,2}(size(TCData(i).Maxmin{1,2}, 1));
   MinMaxTC(i,3) = TCData(i).Maxmin{1,3}(size(TCData(i).Maxmin{1,3}, 1));
   MinMaxTC(i,4) = TCData(i).Maxmin{1,4}(size(TCData(i).Maxmin{1,4}, 1));
   MinMaxTC(i,5) = TCData(i).Maxmin{1,5}(size(TCData(i).Maxmin{1,5}, 1));
   MinMaxTC(i,6) = TCData(i).Maxmin{1,6}(size(TCData(i).Maxmin{1,6}, 1));
   MinMaxTC(i,7) = TCData(i).Maxmin{1,7}(size(TCData(i).Maxmin{1,7}, 1));
%    MinMaxTC(i,8) = TCData(i).Maxmin{1,8}(size(TCData(i).Maxmin{1,8}, 1));
%    MinMaxTC(i,9) = TCData(i).Maxmin{1,9}(size(TCData(i).Maxmin{1,9}, 1));
%    MinMaxTC(i,10) = TCData(i).Maxmin{1,10}(size(TCData(i).Maxmin{1,10}, 1));
%    MinMaxTC(i,11) = TCData(i).Maxmin{1,11}(size(TCData(i).Maxmin{1,11}, 1));
%    MinMaxTC(i,12) = TCData(i).Maxmin{1,12}(size(TCData(i).Maxmin{1,12}, 1));
%    MinMaxTC(i,13) = TCData(i).Maxmin{1,13}(size(TCData(i).Maxmin{1,13}, 1));
%    MinMaxTC(i,14) = TCData(i).Maxmin{1,14}(size(TCData(i).Maxmin{1,14}, 1));
%    MinMaxTC(i,15) = TCData(i).Maxmin{1,15}(size(TCData(i).Maxmin{1,15}, 1));
%    MinMaxTC(i,16) = TCData(i).Maxmin{1,16}(size(TCData(i).Maxmin{1,16}, 1));
%    MinMaxTC(i,17) = TCData(i).Maxmin{1,17}(size(TCData(i).Maxmin{1,17}, 1));
%    MinMaxTC(i,18) = TCData(i).Maxmin{1,18}(size(TCData(i).Maxmin{1,18}, 1));
%    MinMaxTC(i,19) = TCData(i).Maxmin{1,19}(size(TCData(i).Maxmin{1,19}, 1));
%    MinMaxTC(i,20) = TCData(i).Maxmin{1,20}(size(TCData(i).Maxmin{1,20}, 1));
%    MinMaxTC(i,21) = TCData(i).Maxmin{1,21}(size(TCData(i).Maxmin{1,21}, 1));
%    MinMaxTC(i,22) = TCData(i).Maxmin{1,22}(size(TCData(i).Maxmin{1,22}, 1));
end

maxROutput = 0;
minROutput = 399999999999999;
maxNumberOfIterationsOutput = 0;

for i= 1:size(TCData,2)
    for j = 1:size(TCData(i).Output,2)
        if(max(TCData(i).Output{j}) > maxROutput)
            maxROutput = max(TCData(i).Output{j});
        end
        if((length(TCData(i).Output{j})) > maxNumberOfIterationsOutput)
            maxNumberOfIterationsOutput = (length(TCData(i).Output{j}));
        end
        if(min(TCData(i).Output{j}) < minROutput)
            minROutput = min(TCData(i).Output{j});
        end
    end
end

maxRInput = 0;
minRInput = 399999999999999;
maxNumberOfIterationsInput = 0;
for i= 1:size(TCData,2)
    for j = 1:size(TCData(i).Input,2)
        if(max(TCData(i).Input{j}) > maxRInput)
            maxRInput = max(TCData(i).Input{j});
        end
        if(max(length(TCData(i).Input{j})) > maxNumberOfIterationsInput)
            maxNumberOfIterationsInput = max(length(TCData(i).Input{j}));
        end
        if(min(TCData(i).Input{j}) < minRInput)
            minRInput = min(TCData(i).Input{j});
        end
    end
end

% maxNumberOfIterationsOutput2 = maxNumberOfIterationsOutput1
for i=1:size(TCData,2)
   for j=i:size(TCData,2)
      Output1EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{1}, TCData(j).Output{1},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output1EuclideanDistance(j,i) = Output1EuclideanDistance(i,j);
      
      Output2EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{2}, TCData(j).Output{2},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output2EuclideanDistance(j,i) = Output2EuclideanDistance(i,j);
      
      Output3EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{3}, TCData(j).Output{3},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output3EuclideanDistance(j,i) = Output3EuclideanDistance(i,j);
      
      Output4EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{4}, TCData(j).Output{4},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output4EuclideanDistance(j,i) = Output4EuclideanDistance(i,j);
      
      Output5EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{5}, TCData(j).Output{5},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output5EuclideanDistance(j,i) = Output5EuclideanDistance(i,j);
      
      Output6EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{6}, TCData(j).Output{6},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output6EuclideanDistance(j,i) = Output6EuclideanDistance(i,j);
      
      Output7EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Output{7}, TCData(j).Output{7},maxROutput,minROutput,maxNumberOfIterationsOutput);
      Output7EuclideanDistance(j,i) = Output7EuclideanDistance(i,j);
      
      Input1EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{1}, TCData(j).Input{1},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input1EuclideanDistance(j,i) = Input1EuclideanDistance(i,j);
      
      Input2EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{2}, TCData(j).Input{2},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input2EuclideanDistance(j,i) = Input2EuclideanDistance(i,j);
      
      Input3EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{3}, TCData(j).Input{3},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input3EuclideanDistance(j,i) = Input3EuclideanDistance(i,j);
      
      Input4EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{4}, TCData(j).Input{4},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input4EuclideanDistance(j,i) = Input4EuclideanDistance(i,j);
      
      Input5EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{5}, TCData(j).Input{5},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input5EuclideanDistance(j,i) = Input5EuclideanDistance(i,j);
      
      Input6EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{6}, TCData(j).Input{6},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input6EuclideanDistance(j,i) = Input6EuclideanDistance(i,j);
      
      Input7EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{7}, TCData(j).Input{7},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input7EuclideanDistance(j,i) = Input7EuclideanDistance(i,j);
      
      Input8EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{8}, TCData(j).Input{8},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input8EuclideanDistance(j,i) = Input8EuclideanDistance(i,j);
      
      Input9EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{9}, TCData(j).Input{9},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input9EuclideanDistance(j,i) = Input9EuclideanDistance(i,j);
      
      Input10EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{10}, TCData(j).Input{10},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input10EuclideanDistance(j,i) = Input10EuclideanDistance(i,j);
      
      Input11EuclideanDistance(i,j) = ...
      CalculateEuclideanDistance(TCData(i).Input{11}, TCData(j).Input{11},maxRInput,minRInput,maxNumberOfIterationsInput);
      Input11EuclideanDistance(j,i) = Input11EuclideanDistance(i,j);
   end    
end

xlswrite('ExcelResults/OutputEuclidean.xlsx',Output1EuclideanDistance, 'Output1');
xlswrite('ExcelResults/OutputEuclidean.xlsx',Output2EuclideanDistance, 'Output2');
xlswrite('ExcelResults/OutputEuclidean.xlsx',Output3EuclideanDistance, 'Output3');
xlswrite('ExcelResults/OutputEuclidean.xlsx',Output4EuclideanDistance, 'Output4');
xlswrite('ExcelResults/OutputEuclidean.xlsx',Output5EuclideanDistance, 'Output5');
xlswrite('ExcelResults/OutputEuclidean.xlsx',Output6EuclideanDistance, 'Output6');
xlswrite('ExcelResults/OutputEuclidean.xlsx',Output7EuclideanDistance, 'Output7');

xlswrite('ExcelResults/InputEuclidean.xlsx',Input1EuclideanDistance, 'Input1');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input2EuclideanDistance, 'Input2');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input3EuclideanDistance, 'Input3');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input4EuclideanDistance, 'Input4');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input5EuclideanDistance, 'Input5');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input6EuclideanDistance, 'Input6');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input7EuclideanDistance, 'Input7');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input8EuclideanDistance, 'Input8');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input9EuclideanDistance, 'Input9');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input10EuclideanDistance, 'Input10');
xlswrite('ExcelResults/InputEuclidean.xlsx',Input11EuclideanDistance, 'Input11');


for i=1:size(TCData,2)
    if(max(InfiniteTC(:,1))~=0)
        InfiniteTCN(i,1) = InfiniteTC(i,1)/max(InfiniteTC(:,1));
    else
        InfiniteTCN(i,1) = InfiniteTC(i,1);
    end
    if(max(InfiniteTC(:,2))~=0)
        InfiniteTCN(i,2) = InfiniteTC(i,2)/max(InfiniteTC(:,2));
    else
        InfiniteTCN(i,2) = InfiniteTC(i,2);
    end
    if(max(InfiniteTC(:,3))~=0)
        InfiniteTCN(i,3) = InfiniteTC(i,3)/max(InfiniteTC(:,3));
    else
        InfiniteTCN(i,3) = InfiniteTC(i,3);
    end
    if(max(InfiniteTC(:,4))~=0)
        InfiniteTCN(i,4) = InfiniteTC(i,4)/max(InfiniteTC(:,4));
    else
        InfiniteTCN(i,4) = InfiniteTC(i,4);
    end
    if(max(InfiniteTC(:,5))~=0)
        InfiniteTCN(i,5) = InfiniteTC(i,5)/max(InfiniteTC(:,5));
    else
        InfiniteTCN(i,5) = InfiniteTC(i,5);
    end
    if(max(InfiniteTC(:,6))~=0)
        InfiniteTCN(i,6) = InfiniteTC(i,6)/max(InfiniteTC(:,6));
    else
        InfiniteTCN(i,6) = InfiniteTC(i,6);
    end
    if(max(InfiniteTC(:,7))~=0)
        InfiniteTCN(i,7) = InfiniteTC(i,7)/max(InfiniteTC(:,7));
    else
        InfiniteTCN(i,7) = InfiniteTC(i,7);
    end
    
    if(max(DerivativeTC(:,1))~=0)
        DerivativeTCN(i,1) = DerivativeTC(i,1)/max(DerivativeTC(:,1));
    else
        DerivativeTCN(i,1) = DerivativeTC(i,1);
    end
    if(max(DerivativeTC(:,2))~=0)
        DerivativeTCN(i,2) = DerivativeTC(i,2)/max(DerivativeTC(:,2));
    else
        DerivativeTCN(i,2) = DerivativeTC(i,2);
    end
    if(max(DerivativeTC(:,3))~=0)
        DerivativeTCN(i,3) = DerivativeTC(i,3)/max(DerivativeTC(:,3));
    else
        DerivativeTCN(i,3) = DerivativeTC(i,3);
    end
    if(max(DerivativeTC(:,4))~=0)
        DerivativeTCN(i,4) = DerivativeTC(i,4)/max(DerivativeTC(:,4));
    else
        DerivativeTCN(i,4) = DerivativeTC(i,4);
    end
    if(max(DerivativeTC(:,5))~=0)
        DerivativeTCN(i,5) = DerivativeTC(i,5)/max(DerivativeTC(:,5));
    else
        DerivativeTCN(i,5) = DerivativeTC(i,5);
    end
    if(max(DerivativeTC(:,6))~=0)
        DerivativeTCN(i,6) = DerivativeTC(i,6)/max(DerivativeTC(:,6));
    else
        DerivativeTCN(i,6) = DerivativeTC(i,6);
    end
    if(max(DerivativeTC(:,7))~=0)
        DerivativeTCN(i,7) = DerivativeTC(i,7)/max(DerivativeTC(:,7));
    else
        DerivativeTCN(i,7) = DerivativeTC(i,7);
    end
    
    if(max(InstabilityTC(:,1))~=0)
        InstabilityTCN(i,1) = InstabilityTC(i,1)/max(InstabilityTC(:,1));
    else
        InstabilityTCN(i,1) = InstabilityTC(i,1);
    end
    if(max(InstabilityTC(:,2))~=0)
        InstabilityTCN(i,2) = InstabilityTC(i,2)/max(InstabilityTC(:,2));
    else
        InstabilityTCN(i,2) = InstabilityTC(i,2);
    end
    if(max(InstabilityTC(:,3))~=0)
        InstabilityTCN(i,3) = InstabilityTC(i,3)/max(InstabilityTC(:,3));
    else
        InstabilityTCN(i,3) = InstabilityTC(i,3);
    end
    if(max(InstabilityTC(:,4))~=0)
        InstabilityTCN(i,4) = InstabilityTC(i,4)/max(InstabilityTC(:,4));
    else
        InstabilityTCN(i,4) = InstabilityTC(i,4);
    end
    if(max(InstabilityTC(:,5))~=0)
        InstabilityTCN(i,5) = InstabilityTC(i,5)/max(InstabilityTC(:,5));
    else
        InstabilityTCN(i,5) = InstabilityTC(i,5);
    end
    if(max(InstabilityTC(:,6))~=0)
        InstabilityTCN(i,6) = InstabilityTC(i,6)/max(InstabilityTC(:,6));
    else
        InstabilityTCN(i,6) = InstabilityTC(i,6);
    end
    if(max(InstabilityTC(:,7))~=0)
        InstabilityTCN(i,7) = InstabilityTC(i,7)/max(InstabilityTC(:,7));
    else
        InstabilityTCN(i,7) = InstabilityTC(i,7);
    end
    
    if(max(MinMaxTC(:,1))~=0)
        MinMaxTCN(i,1) = MinMaxTC(i,1)/max(MinMaxTC(:,1));
    else
        MinMaxTCN(i,1) = MinMaxTC(i,1);
    end
    if(max(MinMaxTC(:,2))~=0)
        MinMaxTCN(i,2) = MinMaxTC(i,2)/max(MinMaxTC(:,2));
    else
        MinMaxTCN(i,2) = MinMaxTC(i,2);
    end
    if(max(MinMaxTC(:,3))~=0)
        MinMaxTCN(i,3) = MinMaxTC(i,3)/max(MinMaxTC(:,3));
    else
        MinMaxTCN(i,3) = MinMaxTC(i,3);
    end
    if(max(MinMaxTC(:,4))~=0)
        MinMaxTCN(i,4) = MinMaxTC(i,4)/max(MinMaxTC(:,4));
    else
        MinMaxTCN(i,4) = MinMaxTC(i,4);
    end
    if(max(MinMaxTC(:,5))~=0)
        MinMaxTCN(i,5) = MinMaxTC(i,5)/max(MinMaxTC(:,5));
    else
        MinMaxTCN(i,5) = MinMaxTC(i,5);
    end
    if(max(MinMaxTC(:,6))~=0)
        MinMaxTCN(i,6) = MinMaxTC(i,6)/max(MinMaxTC(:,6));
    else
        MinMaxTCN(i,6) = MinMaxTC(i,6);
    end
    if(max(MinMaxTC(:,7))~=0)
        MinMaxTCN(i,7) = MinMaxTC(i,7)/max(MinMaxTC(:,7));
    else
        MinMaxTCN(i,7) = MinMaxTC(i,7);
    end
end

for i= 1:size(TCData,2)
    InfiniteTCN_Total(i,1) = mean(InfiniteTCN(i,:));
    DerivativeTCN_Total(i,1) = mean(DerivativeTCN(i,:));
    InstabilityTCN_Total(i,1) = mean(InstabilityTCN(i,:));
    MinMaxTCN_Total(i,1)=mean(MinMaxTCN(i,:));
end

% xlswrite('Anti-patternsNormalized.xlsx',InfiniteTCN, 'Infinite');
% xlswrite('Anti-patternsNormalized.xlsx',DerivativeTCN, 'Derivative');
% xlswrite('Anti-patternsNormalized.xlsx',InstabilityTCN, 'Instability');
xlswrite('ExcelResults/Anti-patternsNormalized_Total.xlsx',InfiniteTCN_Total, 'Infinite');
xlswrite('ExcelResults/Anti-patternsNormalized_Total.xlsx',DerivativeTCN_Total, 'Derivative');
xlswrite('ExcelResults/Anti-patternsNormalized_Total.xlsx',InstabilityTCN_Total, 'Instability');
xlswrite('ExcelResults/Anti-patternsNormalized_Total.xlsx',MinMaxTCN_Total, 'MinMax');

