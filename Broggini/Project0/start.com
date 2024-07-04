%chk=tmp
%mem=100MW

#p hf/sto-3g opt freq

propane

 0 1
 c
 h    1 hc2
 c    1 cc3         2 cch3
 h    1 hc4         2 hch4          3 dih4
 h    1 hc5         2 hch5          3 dih5
 c    3 cc6         1 ccc6          2 dih6
 h    3 hc7         1 hcc7          6 dih7
 h    3 hc8         1 hcc8          6 dih8
 h    6 hc9         3 hcc9          1 dih9
 h    6 hc10        3 hcc10         9 dih10
 h    6 hc11        3 hcc11         9 dih11

hc2         1.089000
cc3         1.450000
cch3        109.471
hc4         1.089000
hch4        109.471
dih4        120.000
hc5         1.089000
hch5        109.471
dih5       -120.000
cc6         1.450000
ccc6        109.471
dih6        180.000
hc7         1.089000
hcc7        109.471
dih7        120.000
hc8         1.089000
hcc8        109.471
dih8        240.000
hc9         1.089000
hcc9        109.471
dih9        180.000
hc10        1.089000
hcc10       109.471
dih10       120.000
hc11        1.08900
hcc11       109.471
dih11       240.000

