red=12
#p B3LYP/6-31+g(d,p) opt(internal) nosym freq NMR=GIAO

tetrametilsilano

0 1
si
 c   1 csi2
 c    1 csi3        2 csic3
 h    2 hc4         1 hcsi4         3 dih4
 h    2 hc5         1 hcsi5         4 dih5
 h    2 hc6         1 hcsi6         4 dih6
 h    3 hc7         1 hcsi7         2 dih7
 h    3 hc8         1 hcsi8         7 dih8
 h    3 hc9         1 hcsi9         7 dih9
 c    1 csi10       3 csic10        2 dih10
 h   10 hc11        1 hcsi11        3 dih11
 h   10 hc12        1 hcsi12       11 dih12
 h   10 hc13        1 hcsi13       11 dih13
 c    1 csi14      10 csic14        3 dih14
 h   14 hc15        1 hcsi15       10 dih15
 h   14 hc16        1 hcsi16       15 dih16
 h   14 hc17        1 hcsi17       15 dih17

csi2        1.850000
csi3        1.850000
csic3       109.471
hc4         1.089000
hcsi4       109.471
dih4        120.000
hc5         1.089000
hcsi5       109.471
dih5        120.000
hc6         1.089000
hcsi6       109.471
dih6        240.000
hc7         1.089000
hcsi7       109.471
dih7        180.000
hc8         1.089000
hcsi8       109.471
dih8        120.000
hc9         1.089000
hcsi9       109.471
dih9        240.000
csi10       1.850000
csic10      109.471
dih10       180.000
hc11        1.089000
hcsi11      109.471
dih11       180.000
hc12        1.089000
hcsi12      109.471
dih12       120.000
hc13        1.089000
hcsi13      109.471
dih13       240.000
csi14       1.850000
csic14       95.000
dih14       115.000
hc15        1.089000
hcsi15      109.471
dih15       180.000
hc16        1.089000
hcsi16      109.471
dih16       120.000
hc17        1.089000
hcsi17      109.471
dih17       240.000



