Init;
%Init_Variability;
TCvsMutants = zeros(120,10);
ModelName = 'MutantsModel3.slx';
for i=1:120
    TestOrder = [i]; %Add test order
    i
    sim(ModelName);
    TCvsMutants(i,1)= mutant1(size(mutant1,1));
    TCvsMutants(i,2)= mutant2(size(mutant1,1));
    TCvsMutants(i,3)= mutant3(size(mutant1,1));
    TCvsMutants(i,4)= mutant4(size(mutant1,1));
    TCvsMutants(i,5)= mutant5(size(mutant1,1));
    TCvsMutants(i,6)= mutant6(size(mutant1,1));
    TCvsMutants(i,7)= mutant7(size(mutant1,1));
    TCvsMutants(i,8)= mutant8(size(mutant1,1));
    TCvsMutants(i,9)= mutant9(size(mutant1,1));
    TCvsMutants(i,10)= mutant10(size(mutant1,1));
    
    
    
end