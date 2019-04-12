clear;
clc;
[MOEADFile,MOEADFile_txt,MOEADFile_raw] = xlsread('MOEAD_results_50.xlsx');
[NSGA3File,RSFile_txt,RSFile_raw] = xlsread('NSGAIII_results_50.xlsx');
% [WBFile,WBFile_txt,WBFile_raw] = xlsread('GA_resultsWhiteBox_50.xlsx');

folder = {'W_MS_TET'};
% RuningTime ->2; HV -> 3; MEANTET_P1 -> 4; MEANMS_P1 -> 5;
% MAXTET_P1 -> 6; MAXMS_P1 -> 7; MINTET_P1 -> 8; MINMS_P1 -> 9;
% MEANTET_P2 -> 10; MEANMS_P2 -> 11; MAXTET_P2 -> 12; MAXMS_P2 -> 13; 
% MINTET_P2 ->14; MINMS_P2 -> 15; MAXMSVAL_P2 -> 16; MAXTETVAL_P2 -> 17;

Dir =  strcat('', folder(1));
Dir = Dir{1};

%% MEANTET_P2 VALUES (4)
ColumnMetric = 4;
MOEAD_c1_MEANTET = MOEADFile(1:50,ColumnMetric);
NSGA3_c1_MEANTET = NSGA3File(1:50,ColumnMetric);

%% MEANTET_P2 VALUES (5)
ColumnMetric = 5;
MOEAD_c1_MEANMS = MOEADFile(1:50,ColumnMetric);
NSGA3_c1_MEANMS = NSGA3File(1:50,ColumnMetric);

%% Normalization

MOEAD_c1 = (MOEAD_c1_MEANMS + (1 - MOEAD_c1_MEANTET))/2;
NSGA3_c1 = (NSGA3_c1_MEANMS + (1 - NSGA3_c1_MEANTET))/2;

%% AVERAGE CALC
avgGA = mean(MOEAD_c1);
avgRS = mean(NSGA3_c1);

%% SAVE INTO TEXT FILES
%Create txt files for R
fid = fopen([Dir '/MOEAD.txt'],'wt');
fprintf(fid,'%f\n',MOEAD_c1);
fclose(fid);

% RS
fid = fopen([Dir '/NSGA3.txt'],'wt');
fprintf(fid,'%f\n',NSGA3_c1);
fclose(fid);