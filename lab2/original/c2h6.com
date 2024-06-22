%chk=tmp
%mem=100MB
#p B3LYP/6-31+g(d,p) opt freq pop=full gfinput

c2h6

0 1
C1
C2 1 d1
H3 1 d2 2 a1
H4 2 d2 1 a1 3 t1
H5 1 d2 2 a1 4 t2
H6 2 d2 1 a1 5 t3
H7 1 d2 2 a1 6 t4
H8 2 d2 1 a1 7 t5

d1=1.5
d2=1.1
a1=109.5
t1=180.
t2=60.
t3=-60.
t4=180.
t5=60.
