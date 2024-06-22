%chk=tmp
%mem=100MB
#p B3LYP/6-31+g(d,p) opt freq pop=full gfinput

c3h8

0 1
C
X 1 1.0
C 1 rc 2 accx
C 1 rc 2 accx 3 180.0
H 1 rh1 2 ahcx 3 90.0
H 1 rh1 2 ahcx 3 -90.0
H 3 rh2 1 ah2 2 0.0
H 4 rh2 1 ah2 2 0.0
H 3 rh3 1 ah3 7 dh3
H 3 rh3 1 ah3 7 -dh3
H 4 rh3 1 ah3 8 dh3
H 4 rh3 1 ah3 8 -dh3

rc 1.5282
rh1 1.0872
rh2 1.0857
rh3 1.0866
accx 123.6047
ahcx 53.1376
ah2 111.3567
ah3 111.095
dh3 120.1122 
