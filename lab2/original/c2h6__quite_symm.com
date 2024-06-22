%chk=tmp
%mem=100MB
#p B3LYP/6-31+g(d,p) opt freq pop=full gfinput

c2h6_symm

0 1
c
c   1 cc2     
h    1 hc3         2 hcc3      
h    1 hc4         2 hcc4          3 dih4   
h    1 hc5         2 hcc5          3 dih5   
h    2 hc6         1 hcc6          3 dih6   
h    2 hc7         1 hcc7          6 dih7   
h    2 hc8         1 hcc8          6 dih8   
 
cc2         1.50000
hc3         1.1000
hcc3        109.5
hc4         1.100
hcc4        109.5
dih4        240.000
hc5         1.100
hcc5        109.5
dih5        120.000
hc6         1.10
hcc6        109.5
dih6        125.000
hc7         1.1000
hcc7        109.5
dih7        120.000
hc8         1.1000
hcc8        109.5
dih8        240.000
 
 
