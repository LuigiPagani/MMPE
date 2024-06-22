memory, 50, m
nosym

geometry={angstrom
C1
H2 1 d1
H3 1 d1 2 a1 
H4 1 d1 2 a1 3 t1
H5 1 d1 2 a1 3 t2
}

d1 = 1.
a2 = 109.5
t1 = 120.
t2 = -120.

basis=3-21G
hf 
put,molden,molpro.molden