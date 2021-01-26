BST = readmatrix('BSTs.csv');
LL = readmatrix('LLs.csv');
HS = readmatrix('Hs.csv');

f1 = figure(1);
hold on;
plot(1:400,BST);
plot(1:400,LL);
plot(1:400,HS);
xlabel('Iteration');
ylabel('Time(Microseconds)');
title('Comparison of Search Times')
legend('BST','LL','Hash Table with Chaining');
hold off;








