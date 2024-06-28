%chk=tmp

#p B3LYP/6-31+g(d,p) opt out=wfn

etano

0 1
C1
C2 1 d1
H3 1 d2 2 a1
H4 1 d3 2 a2 3 t1
H5 1 d4 2 a3 3 t2
H6 2 d5 1 a4 3 t3
H7 2 d6 1 a5 6 t4
H8 2 d7 1 a6 6 t5

d1=1.4
d2=1.1
d3=1.1
d4=1.1
d5=1.1
d6=1.1
d7=1.1
a1=109.
a2=109.
a3=109.
a4=109.
a5=109.
a6=109.
t1=120.
t2=-120.
t3=60.
t4=120.
t5=-120.

ethene.wfn



