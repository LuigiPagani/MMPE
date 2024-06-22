%chk=tmp

#p B3LYP/6-31+g(d,p) opt

propano

0 1
C1
C2 1 d1
H3 1 d2 2 a1
H4 1 d3 2 a2 3 t1
H5 1 d4 2 a3 3 t2
H6 2 d5 1 a4 3 t3 !two hydrogens in the middle carbon
H7 2 d6 1 a5 6 t4
C8 2 d7 1 a6 7 t5 !diedrahal in order to have planar
H9 8 d8 2 a7 6 t6
H10 8 d9 2 a8 9 t7
H11 8 d10 2 a9 9 t8

d1=1.4
d2=1.1
d3=1.1
d4=1.1
d5=1.1
d6=1.1
d7=1.4
d8=1.1
d9=1.1
d10=1.1
a1=109.
a2=109.
a3=109.
a4=109.
a5=109.
a6=120. !not sure
a7=109.
a8=109.
a9=109.
t1=120.
t2=-120.
t3=60.
t4=120.
t5=109.
t6=-60.
t7=120.
t8=-120.



