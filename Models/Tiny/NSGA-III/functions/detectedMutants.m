function [detectedMutantsArray, detectedMutantsP] = detectedMutants(activationArray)
    %UNTITLED Summary of this function goes here
    %   Detailed explanation goes here
    detectedMutantsArray = [];
    if ~exist('mutantsTable.mat')
        mutantsTable = readtable('MutantsMatrixTable.xlsx');
        save ('data/mutantsTable.mat', 'mutantsTable');
    else
        load mutantsTable.mat
    end
    mutantsTableArray = table2array(mutantsTable);
    k = 1;
    [a b] = size(mutantsTable);
    for i = 1:length(activationArray)
        if(activationArray(i) == 1)
            for j = 1:b
                if(mutantsTableArray(i,j) == 1)
                    detectedMutantsArray(k) = j;
                    k = k+1;
                end
            end
        end
    end
    detectedMutantsArray = unique(detectedMutantsArray);
    for i = 1:length(detectedMutantsArray)
        detectedMutantsArray(i) = str2double(mutantsTable.Properties.VariableNames{detectedMutantsArray(i)}(7:end));
    end
    detectedMutantsP = numel(detectedMutantsArray)/b;
end

