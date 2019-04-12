clear;
clc;
[GAFile,GAFile_txt,GAFile_raw] = xlsread('GA_results_50.xlsx');
[RSFile,RSFile_txt,RSFile_raw] = xlsread('RS_results_50.xlsx');
% [WBFile,WBFile_txt,WBFile_raw] = xlsread('GA_resultsWhiteBox_50.xlsx');
% for ColumnMetric=3:18
ColumnMetric = 4;
    folder = {'RunningTime'; 'HV';'MEANTET_P1'; 'MEANMS_P1'; 'MAXTET_P1';...
        'MAXMS_P1'; 'MINTET_P1'; 'MINMS_P1'; 'MEANTET_P2'; 'MEANMS_P2'; ...
        'MAXTET_P2'; 'MAXMS_P2'; 'MINTET_P2'; 'MINMS_P2'; 'MAXMSVAL_P2'; ...
        'MAXTETVAL_P2'};
    % RuningTime ->3; HV -> 4; MEANTET_P1 -> 5; MEANMS_P1 -> 6;
    % MAXTET_P1 -> 7; MAXMS_P1 -> 8; MINTET_P1 -> 9; MINMS_P1 -> 10;
    % MEANTET_P2 -> 11; MEANMS_P2 -> 12; MAXTET_P2 -> 13; MAXMS_P2 -> 14; 
    % MINTET_P2 ->15; MINMS_P2 -> 16; MAXMSVAL_P2 -> 17; MAXTETVAL_P2 -> 18;

    Dir =  strcat('', folder(ColumnMetric-2));
    Dir = Dir{1};

    GA_c1 = GAFile(1:50,ColumnMetric);      % Derivative
    GA_c2 = GAFile(51:100,ColumnMetric);    % Derivative - Infinite
    GA_c3 = GAFile(101:150,ColumnMetric);   % Derivative - InputEuclidean
    GA_c4 = GAFile(151:200,ColumnMetric);   % Derivative - Instability
    GA_c5 = GAFile(201:250,ColumnMetric);   % Derivative - MinMax
    GA_c6 = GAFile(251:300, ColumnMetric);  % Derivative - OutputEuclidean

    GA_c7 = GAFile(301:350,ColumnMetric);   % Infinite
    GA_c8 = GAFile(351:400,ColumnMetric);   % Infinite - InputEuclidean
    GA_c9 = GAFile(401:450,ColumnMetric);   % Infinite - Instability
    GA_c10 = GAFile(451:500,ColumnMetric);  % Infinite - MinMax
    GA_c11 = GAFile(501:550,ColumnMetric);  % Infinite - OutputEuclidean

    GA_c12 = GAFile(551:600,ColumnMetric);  % InputEuclidean
    GA_c13 = GAFile(601:650,ColumnMetric);  % InputEuclidean - MinMax
    GA_c14 = GAFile(651:700,ColumnMetric);  % InputEuclidean - OutputEuclidean

    GA_c15 = GAFile(701:750,ColumnMetric);  % Instability
    GA_c16 = GAFile(751:800,ColumnMetric);  % Instability - InputEuclidean
    GA_c17 = GAFile(801:850,ColumnMetric);  % Instablity - MinMax
    GA_c18 = GAFile(851:900,ColumnMetric);  % Instability - OutputEuclidean

    GA_c19 = GAFile(901:950,ColumnMetric);  % MinMax
    GA_c20 = GAFile(951:1000,ColumnMetric); % MinMax - OutputEuclidean
    GA_c21 = GAFile(1001:1050,ColumnMetric);% OutputEuclidean


    Avg(1,1) = sum(GA_c1)/50;
    Avg(2,1) = sum(GA_c2)/50;
    Avg(3,1) = sum(GA_c3)/50;
    Avg(4,1) = sum(GA_c4)/50;
    Avg(5,1) = sum(GA_c5)/50;
    Avg(6,1) = sum(GA_c6)/50;
    Avg(7,1) = sum(GA_c7)/50;
    Avg(8,1) = sum(GA_c8)/50;
    Avg(9,1) = sum(GA_c9)/50;
    Avg(10,1) = sum(GA_c10)/50;
    Avg(11,1) = sum(GA_c11)/50;
    Avg(12,1) = sum(GA_c12)/50;
    Avg(13,1) = sum(GA_c13)/50;
    Avg(14,1) = sum(GA_c14)/50;
    Avg(15,1) = sum(GA_c15)/50;
    Avg(16,1) = sum(GA_c16)/50;
    Avg(17,1) = sum(GA_c17)/50;
    Avg(18,1) = sum(GA_c18)/50;
    Avg(19,1) = sum(GA_c19)/50;
    Avg(20,1) = sum(GA_c20)/50;
    Avg(21,1) = sum(GA_c21)/50;

    medn(1,1) = median(GA_c1);
    medn(2,1) = median(GA_c2);
    medn(3,1) = median(GA_c3);
    medn(4,1) = median(GA_c4);
    medn(5,1) = median(GA_c5);
    medn(6,1) = median(GA_c6);
    medn(7,1) = median(GA_c7);
    medn(8,1) = median(GA_c8);
    medn(9,1) = median(GA_c9);
    medn(10,1) = median(GA_c10);
    medn(11,1) = median(GA_c11);
    medn(12,1) = median(GA_c12);
    medn(13,1) = median(GA_c13);
    medn(14,1) = median(GA_c14);
    medn(15,1) = median(GA_c15);
    medn(16,1) = median(GA_c16);
    medn(17,1) = median(GA_c17);
    medn(18,1) = median(GA_c18);
    medn(19,1) = median(GA_c19);
    medn(20,1) = median(GA_c20);
    medn(21,1) = median(GA_c21);

    RS_c1 = RSFile(1:50,ColumnMetric);      % Derivative
    RS_c2 = RSFile(51:100,ColumnMetric);    % Derivative - Infinite
    RS_c3 = RSFile(101:150,ColumnMetric);   % Derivative - InputEuclidean
    RS_c4 = RSFile(151:200,ColumnMetric);   % Derivative - Instability
    RS_c5 = RSFile(201:250,ColumnMetric);   % Derivative - MinMax
    RS_c6 = RSFile(251:300, ColumnMetric);  % Infinite - OutputEuclidean

    RS_c7 = RSFile(301:350,ColumnMetric);   % Infinite
    RS_c8 = RSFile(351:400,ColumnMetric);   % Infinite - InputEuclidean
    RS_c9 = RSFile(401:450,ColumnMetric);   % Infinite - Instability
    RS_c10 = RSFile(451:500,ColumnMetric);  % Infinite - MinMax
    RS_c11 = RSFile(501:550,ColumnMetric);  % Infinite - OutputEuclidean

    RS_c12 = RSFile(551:600,ColumnMetric);  % InputEuclidean
    RS_c13 = RSFile(601:650,ColumnMetric);  % InputEuclidean - MinMax
    RS_c14 = RSFile(651:700,ColumnMetric);  % InputEuclidean - OutputEuclidean

    RS_c15 = RSFile(701:750,ColumnMetric);  % Instability
    RS_c16 = RSFile(751:800,ColumnMetric);  % Instability - InputEuclidean
    RS_c17 = RSFile(801:850,ColumnMetric);  % Instablity - MinMax
    RS_c18 = RSFile(851:900,ColumnMetric);  % Instability - OutputEuclidean

    RS_c19 = RSFile(901:950,ColumnMetric);  % MinMax
    RS_c20 = RSFile(951:1000,ColumnMetric); % MinMax - OutputEuclidean
    RS_c21 = RSFile(1001:1050,ColumnMetric);% OutputEuclidean - MinMax

    RSAvg(1,1) = sum(RS_c1)/50;
    RSAvg(2,1) = sum(RS_c2)/50;
    RSAvg(3,1) = sum(RS_c3)/50;
    RSAvg(4,1) = sum(RS_c4)/50;
    RSAvg(5,1) = sum(RS_c5)/50;
    RSAvg(6,1) = sum(RS_c6)/50;
    RSAvg(7,1) = sum(RS_c7)/50;
    RSAvg(8,1) = sum(RS_c8)/50;
    RSAvg(9,1) = sum(RS_c9)/50;
    RSAvg(10,1) = sum(RS_c10)/50;
    RSAvg(11,1) = sum(RS_c11)/50;
    RSAvg(12,1) = sum(RS_c12)/50;
    RSAvg(13,1) = sum(RS_c13)/50;
    RSAvg(14,1) = sum(RS_c14)/50;
    RSAvg(15,1) = sum(RS_c15)/50;
    RSAvg(16,1) = sum(RS_c16)/50;
    RSAvg(17,1) = sum(RS_c17)/50;
    RSAvg(18,1) = sum(RS_c18)/50;
    RSAvg(19,1) = sum(RS_c19)/50;
    RSAvg(20,1) = sum(RS_c20)/50;
    RSAvg(21,1) = sum(RS_c21)/50;

    medn_RS(1,1) = median(RS_c1);
    medn_RS(2,1) = median(RS_c2);
    medn_RS(3,1) = median(RS_c3);
    medn_RS(4,1) = median(RS_c4);
    medn_RS(5,1) = median(RS_c5);
    medn_RS(6,1) = median(RS_c6);
    medn_RS(7,1) = median(RS_c7);
    medn_RS(8,1) = median(RS_c8);
    medn_RS(9,1) = median(RS_c9);
    medn_RS(10,1) = median(RS_c10);
    medn_RS(11,1) = median(RS_c11);
    medn_RS(12,1) = median(RS_c12);
    medn_RS(13,1) = median(RS_c13);
    medn_RS(14,1) = median(RS_c14);
    medn_RS(15,1) = median(RS_c15);
    medn_RS(16,1) = median(RS_c16);
    medn_RS(17,1) = median(RS_c17);
    medn_RS(18,1) = median(RS_c18);
    medn_RS(19,1) = median(RS_c19);
    medn_RS(20,1) = median(RS_c20);
    medn_RS(21,1) = median(RS_c21);

%     WB_c1 = WBFile(1:50,ColumnMetric); % CC
%     WB_c2 = WBFile(51:100,ColumnMetric); % DC
%     WB_c3 = WBFile(101:150,ColumnMetric); %MCDC
% 
%     WBAvg(1,1) = sum(WB_c1)/50;
%     WBAvg(2,1) = sum(WB_c2)/50;
%     WBAvg(3,1) = sum(WB_c3)/50;
% 
%     medn_WB(1,1) = median(WB_c1);
%     medn_WB(2,1) = median(WB_c2);
%     medn_WB(3,1) = median(WB_c3);

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

%     % WB
%     fid = fopen([Dir '/WB_c1.txt'],'wt');
%     fprintf(fid,'%f\n',WB_c1);
%     fclose(fid);
% 
%     fid = fopen([Dir '/WB_c2.txt'],'wt');
%     fprintf(fid,'%f\n',WB_c2);
%     fclose(fid);
% 
%     fid = fopen([Dir '/WB_c3.txt'],'wt');
%     fprintf(fid,'%f\n',WB_c3);
%     fclose(fid);
% end
