clear;
clc;
[MOEADFile,MOEADFile_txt,MOEADFile_raw] = xlsread('MOEAD_results_50.xlsx');
[NSGA3File,RSFile_txt,RSFile_raw] = xlsread('NSGAIII_results_50.xlsx');
% [WBFile,WBFile_txt,WBFile_raw] = xlsread('GA_resultsWhiteBox_50.xlsx');
% for ColumnMetric=3:18
ColumnMetric = 3;
folder = {'RunningTime'; 'HV'; 'MEANTET_P1'; 'MEANMS_P1'; 'MAXTET_P1';...
    'MAXMS_P1'; 'MINTET_P1'; 'MINMS_P1'; 'MEANTET_P2'; 'MEANMS_P2'; ...
    'MAXTET_P2'; 'MAXMS_P2'; 'MINTET_P2'; 'MINMS_P2'; 'MAXMSVAL_P2'; ...
    'MAXTETVAL_P2'};
% RuningTime ->2; HV -> 3; MEANTET_P1 -> 4; MEANMS_P1 -> 5;
% MAXTET_P1 -> 6; MAXMS_P1 -> 7; MINTET_P1 -> 8; MINMS_P1 -> 9;
% MEANTET_P2 -> 10; MEANMS_P2 -> 11; MAXTET_P2 -> 12; MAXMS_P2 -> 13; 
% MINTET_P2 ->14; MINMS_P2 -> 15; MAXMSVAL_P2 -> 16; MAXTETVAL_P2 -> 17;
Dir =  strcat('', folder(ColumnMetric-1));
Dir = Dir{1};

MOEAD_c1 = MOEADFile(1:50,ColumnMetric);

MOEAD_Avg = sum(MOEAD_c1)/50;
MOEAD_medn = median(MOEAD_c1);

NSGA3_c1 = NSGA3File(1:50,ColumnMetric);

NSGA3_Avg = sum(NSGA3_c1)/50;
NSGA3_medn(1,1) = median(NSGA3_c1);

%Create txt files for R
fid = fopen([Dir '/MOEAD.txt'],'wt');
fprintf(fid,'%f\n',MOEAD_c1);
fclose(fid);

% RS
fid = fopen([Dir '/NSGA3.txt'],'wt');
fprintf(fid,'%f\n',NSGA3_c1);
fclose(fid);

