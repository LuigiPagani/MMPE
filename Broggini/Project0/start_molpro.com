memory=50MW
nosym
geometry={angstrom
   c1
   c2    c1 rcc1
   c3    c2 rcc2  c1 acc1
   h4    c1 rch1  c2 ahc1  c3 b1
   h5    c1 rch2  c2 ahc2  h4 b2
   h6    c1 rch3  c2 ahc3  h4 b3
   h7    c2 rch4  c1 ahc4  c3 b4
   h8    c2 rch5  c1 ahc5  c3 b5
   h9    c3 rch6  c2 ahc6  c1 b6
   h10   c3 rch7  c2 ahc7  h9 b7
   h11   c3 rch8  c2 ahc8  h9 b8
}
  RCC1                           =    1.5000000000000000
  RCC2                           =    1.5000000000000000
  RCH1                           =    1.0800000000000000
  RCH2                           =    1.0800000000000000
  RCH3                           =    1.0800000000000000
  RCH4                           =    1.0800000000000000
  RCH5                           =    1.0800000000000000
  RCH6                           =    1.0800000000000000
  RCH7                           =    1.0800000000000000
  RCH8                           =    1.0800000000000000
  ACC1                           =    109.47239999999999
  AHC1                           =    109.46899999999999
  AHC2                           =    109.47150000000001
  AHC3                           =    109.47150000000001
  AHC4                           =    109.47150000000001
  AHC5                           =    109.47150000000001
  AHC6                           =    109.47150000000001
  AHC7                           =    109.47150000000001
  AHC8                           =    109.47150000000001
  B1                             =    119.99690000000000
  B2                             =    120.000699999999
  B3                             =   -120.000699999999
  B4                             =    120.000699999999
  B5                             =   -120.000699999999
  B6                             =    120.000699999999
  B7                             =    120.000699999999
  B8                             =   -120.000699999999


 !closed shell input
  basis=cc-pvdz

  hf
!{multi;closed, 10;occ, 16;wf, 26,1,0;state,1  ;maxiter,40}
put,molden,molpro.molden

