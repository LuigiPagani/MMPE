%chk=tmp
%mem=100MB
#p B3LYP/6-31+g(d,p) opt pop=full gfinput

metano

0 1
C1
H2 1 d1
H3 1 d2 2 a1
H4 1 d3 2 a2 3 t1
H5 1 d4 2 a3 3 t2

d1=1.09
a1=109.
t1=120.
d2=1.03
a2=110.
t2=-120.
d3=1.05
d4=1.1
a3=109.




