#p B3LYP/6-31+g** opt out=wfn

benzene

0 1
 c
 c   1 cc2     
 c    2 cc3         1 ccc3      
 c    3 cc4         2 ccc4          1 dih4   
 c    4 cc5         3 ccc5          2 dih5   
 c    5 cc6         4 ccc6          3 dih6   
 h    2 hc7         1 hcc7          3 dih7   
 h    3 hc8         2 hcc8          4 dih8   
 h    4 hc9         3 hcc9          5 dih9   
 h    5 hc10        4 hcc10         3 dih10  
 h    6 hc11        5 hcc11         4 dih11  
 h    1 hc12        2 hcc12         3 dih12  
 
cc2         1.400000
cc3         1.400000
ccc3        120.000
cc4         1.400000
ccc4        120.000
dih4          0.000
cc5         1.400000
ccc5        120.000
dih5          0.000
cc6         1.400000
ccc6        120.000
dih6          0.000
hc7         1.089000
hcc7        120.000
dih7        180.000
hc8         1.089000
hcc8        120.000
dih8        180.000
hc9         1.089000
hcc9        120.000
dih9        180.000
hc10        1.089000
hcc10       120.000
dih10       180.000
hc11        1.089000
hcc11       120.000
dih11       180.000
hc12        1.089000
hcc12       109.471
dih12       180.000
 
benzene.wfn


 
