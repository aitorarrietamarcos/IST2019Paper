clear;
clc;
[GAFile,GAFile_txt,GAFile_raw] = xlsread('GA_results_50.xlsx');
[RSFile,RSFile_txt,RSFile_raw] = xlsread('RS_results_50.xlsx');
% [WBFile,WBFile_txt,WBFile_raw] = xlsread('GA_resultsWhiteBox_50.xlsx');

folder = {'W_MS_TET'};
% RuningTime ->3; HV -> 4; MEANTET_P1 -> 5; MEANMS_P1 -> 6;
% MAXTET_P1 -> 7; MAXMS_P1 -> 8; MINTET_P1 -> 9; MINMS_P1 -> 10;
% MEANTET_P2 -> 11; MEANMS_P2 -> 12; MAXTET_P2 -> 13; MAXMS_P2 -> 14; 
% MINTET_P2 ->15; MINMS_P2 -> 16; MAXMSVAL_P2 -> 17; MAXTETVAL_P2 -> 18;

Dir =  strcat('', folder(1));
Dir = Dir{1};

%% MEANTET_P2 VALUES (5)
ColumnMetric = 5;
GA_c1_MEANTET = GAFile(1:50,ColumnMetric); % Derivative
GA_c2_MEANTET = GAFile(51:100,ColumnMetric); % Derivative - Infinite
GA_c3_MEANTET = GAFile(101:150,ColumnMetric); %Derivative - InputEuclidean
GA_c4_MEANTET = GAFile(151:200,ColumnMetric); %Derivative - Instability
GA_c5_MEANTET = GAFile(201:250,ColumnMetric); %Derivative - MinMax
GA_c6_MEANTET = GAFile(251:300, ColumnMetric); %Infinite - OutputEuclidean

GA_c7_MEANTET = GAFile(301:350,ColumnMetric); %Infinite
GA_c8_MEANTET = GAFile(351:400,ColumnMetric); %Infinite - InputEuclidean
GA_c9_MEANTET = GAFile(401:450,ColumnMetric); %Infinite - Instability
GA_c10_MEANTET = GAFile(451:500,ColumnMetric); %Infinite - MinMax
GA_c11_MEANTET = GAFile(501:550,ColumnMetric); %Infinite - OutputEuclidean

GA_c12_MEANTET = GAFile(551:600,ColumnMetric); %InputEuclidean
GA_c13_MEANTET = GAFile(601:650,ColumnMetric); %InputEuclidean - MinMax
GA_c14_MEANTET = GAFile(651:700,ColumnMetric); %InputEuclidean - OutputEuclidean

GA_c15_MEANTET = GAFile(701:750,ColumnMetric); %Instability
GA_c16_MEANTET = GAFile(751:800,ColumnMetric); %Instability - InputEuclidean
GA_c17_MEANTET = GAFile(801:850,ColumnMetric); %Instablity - MinMax
GA_c18_MEANTET = GAFile(851:900,ColumnMetric); %Instability - OutputEuclidean

GA_c19_MEANTET = GAFile(901:950,ColumnMetric); %MinMax
GA_c20_MEANTET = GAFile(951:1000,ColumnMetric); %MinMax - OutputEuclidean
GA_c21_MEANTET = GAFile(1001:1050,ColumnMetric); %OutputEuclidean

RS_c1_MEANTET = RSFile(1:50,ColumnMetric); % Derivative
RS_c2_MEANTET = RSFile(51:100,ColumnMetric); % Derivative - Infinite
RS_c3_MEANTET = RSFile(101:150,ColumnMetric); %Derivative - InputEuclidean
RS_c4_MEANTET = RSFile(151:200,ColumnMetric); %Derivative - Instability
RS_c5_MEANTET = RSFile(201:250,ColumnMetric); %Derivative - MinMax
RS_c6_MEANTET = RSFile(251:300, ColumnMetric); %Infinite - OutputEuclidean

RS_c7_MEANTET = RSFile(301:350,ColumnMetric); %Infinite
RS_c8_MEANTET = RSFile(351:400,ColumnMetric); %Infinite - InputEuclidean
RS_c9_MEANTET = RSFile(401:450,ColumnMetric); %Infinite - Instability
RS_c10_MEANTET = RSFile(451:500,ColumnMetric); %Infinite - MinMax
RS_c11_MEANTET = RSFile(501:550,ColumnMetric); %Infinite - OutputEuclidean

RS_c12_MEANTET = RSFile(551:600,ColumnMetric); %InputEuclidean
RS_c13_MEANTET = RSFile(601:650,ColumnMetric); %InputEuclidean - MinMax
RS_c14_MEANTET = RSFile(651:700,ColumnMetric); %InputEuclidean - OutputEuclidean

RS_c15_MEANTET = RSFile(701:750,ColumnMetric); %Instability
RS_c16_MEANTET = RSFile(751:800,ColumnMetric); %Instability - InputEuclidean
RS_c17_MEANTET = RSFile(801:850,ColumnMetric); %Instablity - MinMax
RS_c18_MEANTET = RSFile(851:900,ColumnMetric); %Instability - OutputEuclidean

RS_c19_MEANTET = RSFile(901:950,ColumnMetric); %MinMax
RS_c20_MEANTET = RSFile(951:1000,ColumnMetric); %MinMax - OutputEuclidean
RS_c21_MEANTET = RSFile(1001:1050,ColumnMetric); %OutputEuclidean - MinMax

% WB_c1_MEANTET = WBFile(1:50,ColumnMetric); % CC
% WB_c2_MEANTET = WBFile(51:100,ColumnMetric); % DC
% WB_c3_MEANTET = WBFile(101:150,ColumnMetric); %MCDC

%% MEANTET_P2 VALUES (6)
ColumnMetric = 6;
GA_c1_MEANMS = GAFile(1:50,ColumnMetric); % Derivative
GA_c2_MEANMS = GAFile(51:100,ColumnMetric); % Derivative - Infinite
GA_c3_MEANMS = GAFile(101:150,ColumnMetric); %Derivative - InputEuclidean
GA_c4_MEANMS = GAFile(151:200,ColumnMetric); %Derivative - Instability
GA_c5_MEANMS = GAFile(201:250,ColumnMetric); %Derivative - MinMax
GA_c6_MEANMS = GAFile(251:300, ColumnMetric); %Infinite - OutputEuclidean

GA_c7_MEANMS = GAFile(301:350,ColumnMetric); %Infinite
GA_c8_MEANMS = GAFile(351:400,ColumnMetric); %Infinite - InputEuclidean
GA_c9_MEANMS = GAFile(401:450,ColumnMetric); %Infinite - Instability
GA_c10_MEANMS = GAFile(451:500,ColumnMetric); %Infinite - MinMax
GA_c11_MEANMS = GAFile(501:550,ColumnMetric); %Infinite - OutputEuclidean

GA_c12_MEANMS = GAFile(551:600,ColumnMetric); %InputEuclidean
GA_c13_MEANMS = GAFile(601:650,ColumnMetric); %InputEuclidean - MinMax
GA_c14_MEANMS = GAFile(651:700,ColumnMetric); %InputEuclidean - OutputEuclidean

GA_c15_MEANMS = GAFile(701:750,ColumnMetric); %Instability
GA_c16_MEANMS = GAFile(751:800,ColumnMetric); %Instability - InputEuclidean
GA_c17_MEANMS = GAFile(801:850,ColumnMetric); %Instablity - MinMax
GA_c18_MEANMS = GAFile(851:900,ColumnMetric); %Instability - OutputEuclidean

GA_c19_MEANMS = GAFile(901:950,ColumnMetric); %MinMax
GA_c20_MEANMS = GAFile(951:1000,ColumnMetric); %MinMax - OutputEuclidean
GA_c21_MEANMS = GAFile(1001:1050,ColumnMetric); %OutputEuclidean

RS_c1_MEANMS = RSFile(1:50,ColumnMetric); % Derivative
RS_c2_MEANMS = RSFile(51:100,ColumnMetric); % Derivative - Infinite
RS_c3_MEANMS = RSFile(101:150,ColumnMetric); %Derivative - InputEuclidean
RS_c4_MEANMS = RSFile(151:200,ColumnMetric); %Derivative - Instability
RS_c5_MEANMS = RSFile(201:250,ColumnMetric); %Derivative - MinMax
RS_c6_MEANMS = RSFile(251:300, ColumnMetric); %Infinite - OutputEuclidean

RS_c7_MEANMS = RSFile(301:350,ColumnMetric); %Infinite
RS_c8_MEANMS = RSFile(351:400,ColumnMetric); %Infinite - InputEuclidean
RS_c9_MEANMS = RSFile(401:450,ColumnMetric); %Infinite - Instability
RS_c10_MEANMS = RSFile(451:500,ColumnMetric); %Infinite - MinMax
RS_c11_MEANMS = RSFile(501:550,ColumnMetric); %Infinite - OutputEuclidean

RS_c12_MEANMS = RSFile(551:600,ColumnMetric); %InputEuclidean
RS_c13_MEANMS = RSFile(601:650,ColumnMetric); %InputEuclidean - MinMax
RS_c14_MEANMS = RSFile(651:700,ColumnMetric); %InputEuclidean - OutputEuclidean

RS_c15_MEANMS = RSFile(701:750,ColumnMetric); %Instability
RS_c16_MEANMS = RSFile(751:800,ColumnMetric); %Instability - InputEuclidean
RS_c17_MEANMS = RSFile(801:850,ColumnMetric); %Instablity - MinMax
RS_c18_MEANMS = RSFile(851:900,ColumnMetric); %Instability - OutputEuclidean

RS_c19_MEANMS = RSFile(901:950,ColumnMetric); %MinMax
RS_c20_MEANMS = RSFile(951:1000,ColumnMetric); %MinMax - OutputEuclidean
RS_c21_MEANMS = RSFile(1001:1050,ColumnMetric); %OutputEuclidean - MinMax

% WB_c1_MEANMS = WBFile(1:50,ColumnMetric); % CC
% WB_c2_MEANMS = WBFile(51:100,ColumnMetric); % DC
% WB_c3_MEANMS = WBFile(101:150,ColumnMetric); %MCDC

%% Normalization

GA_c1 = (GA_c1_MEANMS + (1 - GA_c1_MEANTET))/2;
GA_c2 = (GA_c2_MEANMS + (1 - GA_c2_MEANTET))/2;
GA_c3 = (GA_c3_MEANMS + (1 - GA_c3_MEANTET))/2;
GA_c4 = (GA_c4_MEANMS + (1 - GA_c4_MEANTET))/2;
GA_c5 = (GA_c5_MEANMS + (1 - GA_c5_MEANTET))/2;
GA_c6 = (GA_c6_MEANMS + (1 - GA_c6_MEANTET))/2;
GA_c7 = (GA_c7_MEANMS + (1 - GA_c7_MEANTET))/2;
GA_c8 = (GA_c8_MEANMS + (1 - GA_c8_MEANTET))/2;
GA_c9 = (GA_c9_MEANMS + (1 - GA_c9_MEANTET))/2;
GA_c10 = (GA_c10_MEANMS + (1 - GA_c10_MEANTET))/2;
GA_c11 = (GA_c11_MEANMS + (1 - GA_c11_MEANTET))/2;
GA_c12 = (GA_c12_MEANMS + (1 - GA_c12_MEANTET))/2;
GA_c13 = (GA_c13_MEANMS + (1 - GA_c13_MEANTET))/2;
GA_c14 = (GA_c14_MEANMS + (1 - GA_c14_MEANTET))/2;
GA_c15 = (GA_c15_MEANMS + (1 - GA_c15_MEANTET))/2;
GA_c16 = (GA_c16_MEANMS + (1 - GA_c16_MEANTET))/2;
GA_c17 = (GA_c17_MEANMS + (1 - GA_c17_MEANTET))/2;
GA_c18 = (GA_c18_MEANMS + (1 - GA_c18_MEANTET))/2;
GA_c19 = (GA_c19_MEANMS + (1 - GA_c19_MEANTET))/2;
GA_c20 = (GA_c20_MEANMS + (1 - GA_c20_MEANTET))/2;
GA_c21 = (GA_c21_MEANMS + (1 - GA_c21_MEANTET))/2;

RS_c1 = (RS_c1_MEANMS + (1 - RS_c1_MEANTET))/2;
RS_c2 = (RS_c2_MEANMS + (1 - RS_c2_MEANTET))/2;
RS_c3 = (RS_c3_MEANMS + (1 - RS_c3_MEANTET))/2;
RS_c4 = (RS_c4_MEANMS + (1 - RS_c4_MEANTET))/2;
RS_c5 = (RS_c5_MEANMS + (1 - RS_c5_MEANTET))/2;
RS_c6 = (RS_c6_MEANMS + (1 - RS_c6_MEANTET))/2;
RS_c7 = (RS_c7_MEANMS + (1 - RS_c7_MEANTET))/2;
RS_c8 = (RS_c8_MEANMS + (1 - RS_c8_MEANTET))/2;
RS_c9 = (RS_c9_MEANMS + (1 - RS_c9_MEANTET))/2;
RS_c10 = (RS_c10_MEANMS + (1 - RS_c10_MEANTET))/2;
RS_c11 = (RS_c11_MEANMS + (1 - RS_c11_MEANTET))/2;
RS_c12 = (RS_c12_MEANMS + (1 - RS_c12_MEANTET))/2;
RS_c13 = (RS_c13_MEANMS + (1 - RS_c13_MEANTET))/2;
RS_c14 = (RS_c14_MEANMS + (1 - RS_c14_MEANTET))/2;
RS_c15 = (RS_c15_MEANMS + (1 - RS_c15_MEANTET))/2;
RS_c16 = (RS_c16_MEANMS + (1 - RS_c16_MEANTET))/2;
RS_c17 = (RS_c17_MEANMS + (1 - RS_c17_MEANTET))/2;
RS_c18 = (RS_c18_MEANMS + (1 - RS_c18_MEANTET))/2;
RS_c19 = (RS_c19_MEANMS + (1 - RS_c19_MEANTET))/2;
RS_c20 = (RS_c20_MEANMS + (1 - RS_c20_MEANTET))/2;
RS_c21 = (RS_c21_MEANMS + (1 - RS_c21_MEANTET))/2;

% WB_c1 = (WB_c1_MEANMS + (1 - WB_c1_MEANTET))/2;
% WB_c2 = (WB_c2_MEANMS + (1 - WB_c2_MEANTET))/2;
% WB_c3 = (WB_c3_MEANMS + (1 - WB_c3_MEANTET))/2;


%% AVERAGE CALC
avgGA(1) = mean(GA_c1);
avgGA(2) = mean(GA_c2);
avgGA(3) = mean(GA_c3);
avgGA(4) = mean(GA_c4);
avgGA(5) = mean(GA_c5);
avgGA(6) = mean(GA_c6);
avgGA(7) = mean(GA_c7);
avgGA(8) = mean(GA_c8);
avgGA(9) = mean(GA_c9);
avgGA(10) = mean(GA_c10);
avgGA(11) = mean(GA_c11);
avgGA(12) = mean(GA_c12);
avgGA(13) = mean(GA_c13);
avgGA(14) = mean(GA_c14);
avgGA(15) = mean(GA_c15);
avgGA(16) = mean(GA_c16);
avgGA(17) = mean(GA_c17);
avgGA(18) = mean(GA_c18);
avgGA(19) = mean(GA_c19);
avgGA(20) = mean(GA_c20);
avgGA(21) = mean(GA_c21);

avgRS(1) = mean(RS_c1);
avgRS(2) = mean(RS_c2);
avgRS(3) = mean(RS_c3);
avgRS(4) = mean(RS_c4);
avgRS(5) = mean(RS_c5);
avgRS(6) = mean(RS_c6);
avgRS(7) = mean(RS_c7);
avgRS(8) = mean(RS_c8);
avgRS(9) = mean(RS_c9);
avgRS(10) = mean(RS_c10);
avgRS(11) = mean(RS_c11);
avgRS(12) = mean(RS_c12);
avgRS(13) = mean(RS_c13);
avgRS(14) = mean(RS_c14);
avgRS(15) = mean(RS_c15);
avgRS(16) = mean(RS_c16);
avgRS(17) = mean(RS_c17);
avgRS(18) = mean(RS_c18);
avgRS(19) = mean(RS_c19);
avgRS(20) = mean(RS_c20);
avgRS(21) = mean(RS_c21);

%% SAVE INTO TEXT FILES
%Create txt files for R
fid = fopen([Dir '/GA_c1.txt'],'wt');
fprintf(fid,'%f\n',GA_c1);
fclose(fid);

fid = fopen([Dir '/GA_c2.txt'],'wt');
fprintf(fid,'%f\n',GA_c2);
fclose(fid);

fid = fopen([Dir '/GA_c3.txt'],'wt');
fprintf(fid,'%f\n',GA_c3);
fclose(fid);

fid = fopen([Dir '/GA_c4.txt'],'wt');
fprintf(fid,'%f\n',GA_c4);
fclose(fid);

fid = fopen([Dir '/GA_c5.txt'],'wt');
fprintf(fid,'%f\n',GA_c5);
fclose(fid);

fid = fopen([Dir '/GA_c6.txt'],'wt');
fprintf(fid,'%f\n',GA_c6);
fclose(fid);

fid = fopen([Dir '/GA_c7.txt'],'wt');
fprintf(fid,'%f\n',GA_c7);
fclose(fid);

fid = fopen([Dir '/GA_c8.txt'],'wt');
fprintf(fid,'%f\n',GA_c8);
fclose(fid);

fid = fopen([Dir '/GA_c9.txt'],'wt');
fprintf(fid,'%f\n',GA_c9);
fclose(fid);

fid = fopen([Dir '/GA_c10.txt'],'wt');
fprintf(fid,'%f\n',GA_c10);
fclose(fid);

fid = fopen([Dir '/GA_c11.txt'],'wt');
fprintf(fid,'%f\n',GA_c11);
fclose(fid);

fid = fopen([Dir '/GA_c12.txt'],'wt');
fprintf(fid,'%f\n',GA_c12);
fclose(fid);

fid = fopen([Dir '/GA_c13.txt'],'wt');
fprintf(fid,'%f\n',GA_c13);
fclose(fid);

fid = fopen([Dir '/GA_c14.txt'],'wt');
fprintf(fid,'%f\n',GA_c14);
fclose(fid);

fid = fopen([Dir '/GA_c15.txt'],'wt');
fprintf(fid,'%f\n',GA_c15);
fclose(fid);

fid = fopen([Dir '/GA_c16.txt'],'wt');
fprintf(fid,'%f\n',GA_c16);
fclose(fid);

fid = fopen([Dir '/GA_c17.txt'],'wt');
fprintf(fid,'%f\n',GA_c17);
fclose(fid);

fid = fopen([Dir '/GA_c18.txt'],'wt');
fprintf(fid,'%f\n',GA_c18);
fclose(fid);

fid = fopen([Dir '/GA_c19.txt'],'wt');
fprintf(fid,'%f\n',GA_c19);
fclose(fid);

fid = fopen([Dir '/GA_c20.txt'],'wt');
fprintf(fid,'%f\n',GA_c20);
fclose(fid);

fid = fopen([Dir '/GA_c21.txt'],'wt');
fprintf(fid,'%f\n',GA_c21);
fclose(fid);

% RS
fid = fopen([Dir '/RS_c1.txt'],'wt');
fprintf(fid,'%f\n',RS_c1);
fclose(fid);

fid = fopen([Dir '/RS_c2.txt'],'wt');
fprintf(fid,'%f\n',RS_c2);
fclose(fid);

fid = fopen([Dir '/RS_c3.txt'],'wt');
fprintf(fid,'%f\n',RS_c3);
fclose(fid);

fid = fopen([Dir '/RS_c4.txt'],'wt');
fprintf(fid,'%f\n',RS_c4);
fclose(fid);

fid = fopen([Dir '/RS_c5.txt'],'wt');
fprintf(fid,'%f\n',RS_c5);
fclose(fid);

fid = fopen([Dir '/RS_c6.txt'],'wt');
fprintf(fid,'%f\n',RS_c6);
fclose(fid);

fid = fopen([Dir '/RS_c7.txt'],'wt');
fprintf(fid,'%f\n',RS_c7);
fclose(fid);

fid = fopen([Dir '/RS_c8.txt'],'wt');
fprintf(fid,'%f\n',RS_c8);
fclose(fid);

fid = fopen([Dir '/RS_c9.txt'],'wt');
fprintf(fid,'%f\n',RS_c9);
fclose(fid);

fid = fopen([Dir '/RS_c10.txt'],'wt');
fprintf(fid,'%f\n',RS_c10);
fclose(fid);

fid = fopen([Dir '/RS_c11.txt'],'wt');
fprintf(fid,'%f\n',RS_c11);
fclose(fid);

fid = fopen([Dir '/RS_c12.txt'],'wt');
fprintf(fid,'%f\n',RS_c12);
fclose(fid);

fid = fopen([Dir '/RS_c13.txt'],'wt');
fprintf(fid,'%f\n',RS_c13);
fclose(fid);

fid = fopen([Dir '/RS_c14.txt'],'wt');
fprintf(fid,'%f\n',RS_c14);
fclose(fid);

fid = fopen([Dir '/RS_c15.txt'],'wt');
fprintf(fid,'%f\n',RS_c15);
fclose(fid);

fid = fopen([Dir '/RS_c16.txt'],'wt');
fprintf(fid,'%f\n',RS_c16);
fclose(fid);

fid = fopen([Dir '/RS_c17.txt'],'wt');
fprintf(fid,'%f\n',RS_c17);
fclose(fid);

fid = fopen([Dir '/RS_c18.txt'],'wt');
fprintf(fid,'%f\n',RS_c18);
fclose(fid);

fid = fopen([Dir '/RS_c19.txt'],'wt');
fprintf(fid,'%f\n',RS_c19);
fclose(fid);

fid = fopen([Dir '/RS_c20.txt'],'wt');
fprintf(fid,'%f\n',RS_c20);
fclose(fid);

fid = fopen([Dir '/RS_c21.txt'],'wt');
fprintf(fid,'%f\n',RS_c21);
fclose(fid);


% % WB
% fid = fopen([Dir '/WB_c1.txt'],'wt');
% fprintf(fid,'%f\n',WB_c1);
% fclose(fid);
% 
% fid = fopen([Dir '/WB_c2.txt'],'wt');
% fprintf(fid,'%f\n',WB_c2);
% fclose(fid);
% 
% fid = fopen([Dir '/WB_c3.txt'],'wt');
% fprintf(fid,'%f\n',WB_c3);
% fclose(fid);