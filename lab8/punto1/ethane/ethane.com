#p B3LYP/6-31g** opt out=wfn

ethane

0 1
 c
 c   1 cc2     
 h    1 hc3         2 hcc3      
 h    1 hc4         2 hcc4          3 dih4   
 h    1 hc5         2 hcc5          3 dih5   
 h    2 hc6         1 hcc6          3 dih6   
 h    2 hc7         1 hcc7          6 dih7   
 h    2 hc8         1 hcc8          6 dih8   
 
cc2         1.450000
hc3         1.089000
hcc3        109.471
hc4         1.089000
hcc4        109.471
dih4        300.000
hc5         1.089000
hcc5        109.471
dih5        100.000
hc6         1.089000
hcc6        109.471
dih6        180.000
hc7         1.089000
hcc7        109.471
dih7        120.000
hc8         1.089000
hcc8        109.471
dih8        240.000
 
ethane.wfn



