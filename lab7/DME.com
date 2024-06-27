%mem=48GB
%NProcShared=48
#p B3LYP/6-31+g(d,p) opt(internal) nosym freq NMR=GIAO

DME

0 1
 o
 c   1 co2
 c    1 co3         2 coc3
 h    3 hc4         1 hco4          2 dih4
 h    3 hc5         1 hco5          4 dih5
 h    3 hc6         1 hco6          4 dih6
 h    2 hc7         1 hco7          3 dih7
 h    2 hc8         1 hco8          7 dih8
 h    2 hc9         1 hco9          7 dih9

co2         1.400000
co3         1.400000
coc3        109.471
hc4         1.089000
hco4        109.471
dih4        180.000
hc5         1.089000
hco5        109.471
dih5        120.000
hc6         1.089000
hco6        109.471
dih6        240.000
hc7         1.089000
hco7        109.471
dih7        180.000
hc8         1.089000
hco8        109.471
dih8        120.000
hc9         1.089000
hco9        109.471
dih9        240.000


