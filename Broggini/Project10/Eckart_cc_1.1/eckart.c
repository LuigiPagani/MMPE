/******************************************************************************
 * August, 2011
 *
 * Daniela Polino
 * 
 * Eckart for macrocanonical rate constant
 * 
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include "SCT.h"

void reading_inputfile(FILE *fp);

int main(void) {

// Exact constants
//Speed of light in vacuum [m/s]
  pi=3.141592653589793;
  c_light = 299792458.0;
  c_light_cm_s = 29979245800.0;
  mu_perm = 4.0 *pi*1.0e-7; // Mag. constant or permeability of vacuum [N/A**2]
  permittivity = 1.0 /(mu_perm*c_light*c_light); // El.cons. or perm. of vacuum [F/m]


// CODATA_VERSION == 2006
// Recommended fundamental constants of physics and chemistry based on the 2006 adjustment
 
// Planck constant [J*s]
  h_planck = 6.62606896e-34;
  h_bar = h_planck/(2.0*pi); 
//Elementary charge [C]
  e_charge = 1.602176487e-19; 
//     ! Electron mass [kg]
  e_mass = 9.10938215e-31; 
 //     ! Proton mass [kg]
  p_mass = 1.672621637e-27;    
 //     ! Electron g factor [ ]
  e_gfactor = -2.0023193043622; 
 
//     ! Fine-structure constant
// !MK a_fine = 0.5 *mu_perm*c_light*e_charge**2/h_planck
  a_fine = 7.2973525376e-3 ;
//     ! Rydberg constant [1/m]
// !MK rydberg = 0.5 *e_mass*c_light*a_fine**2/h_planck
  rydberg = 10973731.568527 ;
//     ! Avogradro constant [1/mol]
  n_avogadro = 6.02214179e+23;  
//     ! Boltzmann constant [J/K]
  boltzmann = 1.3806504e-23 ;
//     ! Atomic mass unit [kg]; conversion factor [u] -> [kg]
  a_mass = 1.660538782e-27 ;
 //    ! Bohr radius [m]
// !MK a_bohr = a_fine/(4.0 *pi*rydberg)
  a_bohr = 0.52917720859e-10; 

//     ! Conversion factors
  massunit = a_mass/e_mass;                     //     ! [u] -> [a.u.]
  angstrom = 1.0e+10 *a_bohr;                   //     ! [Bohr] -> [Angstrom]
  bohr = 1.0 /angstrom;                         //     ! [Angstrom] -> [Bohr]
  seconds = 1.0 /(4.0 *pi*rydberg*c_light);     //     ! [a.u.] -> [s]
  femtoseconds = 1.0e+15 *seconds;              //     ! [a.u.] -> [fs]
  picoseconds = 1.0e+12 *seconds;               //     ! [a.u.] -> [ps]
  joule = 2.0 *rydberg*h_planck*c_light;        //     ! [a.u.] -> [J]
  kelvin = joule/boltzmann;                     //     ! [a.u.] -> [K]
  kjmol = 0.001 *joule*n_avogadro;              //     ! [a.u.] -> [kJ/mol]
  kcalmol = kjmol/4.184 ;                       //     ! [a.u.] -> [kcal/mol]
  pascal = joule/(a_bohr*a_bohr*a_bohr);        //     ! [a.u.] -> [Pa]
  bar = pascal/1.0e+5 ;                         //     ! [a.u.] -> [bar]
  atm = pascal/1.013250e+5;                     //     ! [a.u.] -> [atm]
  evolt = joule/e_charge;                       //     ! [a.u.] -> [eV]
  hertz = joule/h_planck;                       //     ! [a.u.] -> [Hz]
  vibfac = 5.0 *sqrt(kjmol)/(pi*a_bohr*c_light); // ! [a.u./Bohr**2] -> [1/cm] (wave numbers)
  wavenumbers = 0.02 *rydberg;                   //     ! [a.u.] -> [1/cm] (wave numbers)

 char filename[25];
 // FILE *fp, *results, *Trans_coeff, *potential;
 FILE *fp, *results, *Trans_coeff;
 // double ctest=100.;
 // double mu=a_mass*ctest;
 double mu=a_mass*1.0;
 
 if((results=fopen("results.out","w"))==NULL) {
    printf("********IMPOSSIBILE APRIRE IL FILE %s*************\n","results.out");
    exit(1);
  }

 /*
 if((potential=fopen("Pot.out","w"))==NULL) {
    printf("********IMPOSSIBILE APRIRE IL FILE %s*************\n","results.out");
    exit(1);
  }
 */
 if((Trans_coeff=fopen("Transmission_coeff.out","w"))==NULL) {
    printf("********IMPOSSIBILE APRIRE IL FILE %s*************\n","results.out");
    exit(1);
  }

 sprintf(filename,"Eckart_input_data.dat");


  if((fp=fopen(filename,"r"))==NULL){
    printf("main: IMPOSSIBILE APRIRE IL FILE: %s\nProgram now exit\n",filename);
    exit(1);
  }
  reading_inputfile (fp);
  fclose(fp);

  //Calcolo i parametri A, B, C, l

  double A,B,C,l;
  
  A= (Efor-Eback); //in kcal/mol
  
  B= (sqrt(Efor)+sqrt(Eback))*(sqrt(Efor)+sqrt(Eback)); //in kcal/mol
  
  //Converto Energie e frequenza in J e s-1

  Efor=Efor/kcalmol*joule;
  Eback= Eback /kcalmol*joule;
  ifreq=ifreq* c_light_cm_s;

  l= 1/ifreq*(sqrt(2*Efor*Eback/mu))*1/(sqrt(Efor)+sqrt(Eback)); // in m
 
  C= h_planck*h_planck/8./mu/(l*l);

  printf("\nA:%le   B:%le   C:%le   l:%le\n",A,B,C,l);
  double *Pot;

  Pot= (double*) malloc( npdim*sizeof(double) );
  

  double max_pot_xcoo;
  double max_pot_bohr;
  int sindex_max;


  max_pot_xcoo=l/2/pi*log((B+A)/(B-A)); //m
  max_pot_bohr=max_pot_xcoo/a_bohr; // bohr
  //  sindex_max=npdim/2 + max_pot_inds/a_bohr*npdim/2*npdim*int_step/2+0.5;
  sindex_max=max_pot_bohr/(npdim*int_step)*npdim+0.5;

  int shift_bohr = npdim/2 - sindex_max;
  double shift_m = shift_bohr*a_bohr*int_step; //m
  printf("max coo (m) =%le\n",max_pot_xcoo);
  printf("max coo (Bohr) =%le\n",max_pot_bohr);
  // printf("coo max is =%le\n",max_pot_inds);
  printf("index max is =%d\n",sindex_max);
  printf("shift is =%le\n",shift_m);
  printf("shift bohr is =%d\n",shift_bohr);
  

  //Calcolo il potenziale analitico con Approssimazione di Eckart

  double *s;
  double s_sh;
  s= (double*) malloc( npdim*sizeof(double) ); 

  for(i=0;i<npdim;i++){

    //    s=(i-sindex_max+1)*a_bohr*0.01;//step uguale a quello del codice SCT//(i-114) per portare il massimo in corrispondenza di s=0
    //    s[i]=(i-npdim/2)*a_bohr*int_step; //m
    s[i]=(i-sindex_max)*a_bohr*int_step-shift_m; //m
    s_sh = s[i]+(sindex_max)*a_bohr*int_step;//step per portare il massimo in corrispondenza di s=0 in m
    //    printf("s=%le\n",s);
    Pot[i]=A*exp(2*pi*s_sh/l)/(1+exp(2*pi*s_sh/l))+B*exp(2*pi*s_sh/l)/(1+exp(2*pi*s_sh/l))/(1+exp(2*pi*s_sh/l));    

  }
  
  /*
  for(i=0;i<npdim;i++){
    //    s=(i-sindex_max+1)*a_bohr*0.01;
    //    s=(i-100)*a_bohr*0.01;
    fprintf(potential,"%d\t %le %le\n",i,(s[i]- shift_m),Pot[i]);
  }
  */
  // exit(-1);
 

  /*
  int numdata;

  sprintf(filename,"read_pes.txt");
  
  fp=fopen(filename ,"r");

  fscanf(fp,"%d",&numdata);
  printf("num data %d\n", numdata);

  fclose(fp);
  exit(-1);
  */

  // convert pot in cm-1

  for(i=0;i<npdim;i++){
    Pot[i] = Pot[i]/kcalmol*joule/h_planck/c_light_cm_s;
    printf("step %d coord(m) %le coord (bohr) %le potential=%le\n",i,s[i],s[i]/a_bohr,Pot[i]);
  }
  
  //  exit(-1);

  int dim=(E_max-E_min)/step;
  printf("dim=%d\n",dim);
  E=Efor/c_light_cm_s/h_planck;
  int dim1=(E_max-E)/step;
  printf("dim1=%d\n",dim1);
  
  //Ricalcolo i coefficienti A, B

  
  A= (Efor-Eback); //in J

  B= (sqrt(Efor)+sqrt(Eback))*(sqrt(Efor)+sqrt(Eback)); //in J

  // l= 1/ifreq*(sqrt(2*Efor*Eback/mu))*1/(sqrt(Efor)+sqrt(Eback));

  //C= h_planck*h_planck/8/mu/(l*l);

  printf("\nA:%le   B:%le   C:%le   l:%le\n",A,B,C,l);


  //calcolo transmission coefficient funzione di E

  double alfa, beta, delta, Ej;
  double *Transmission_coeff_Ec;
  double *Transmission_coeff_Ia;

  Transmission_coeff_Ec= (double*) malloc( dim*sizeof(double) );
  Transmission_coeff_Ia= (double*) malloc( dim*sizeof(double) );

  for(i=0;i<dim;i++){
    Transmission_coeff_Ec[i]= 0.;
    Transmission_coeff_Ia[i]= 0.;
  }

  E=E_min;
  Ej=E_min*c_light_cm_s*h_planck;;

  printf("\nEstart in cm-1 and J e vector dimension per T_coeff: %d %le  %d\n",E,Ej, dim1);


  // Analytic Eckart solution


  for(i=0;i<dim;i++){
   
    alfa=0.5*sqrt(Ej/C);
    beta=0.5*sqrt((Ej-A)/C);
    delta=0.5*sqrt((B-C)/C);

    Transmission_coeff_Ec[i]=(cosh(2*pi*(alfa-beta))+cosh(2*pi*delta))/(cosh(2*pi*(alfa+beta))+cosh(2*pi*delta));
    Transmission_coeff_Ec[i]= 1-Transmission_coeff_Ec[i];

    //  printf("alfa(%d)=%le\tbeta(%d)=%le\tdelta(%d)=%le\tT_coeff(%d)=%le\n ",E,alfa,E,beta,E,delta,E,Transmission_coeff[i]);
    //    fprintf(Trans_coeff,"%d\t%le\n",E,Transmission_coeff_Ec[i]);
    E=E+step;
    Ej=E*c_light_cm_s*h_planck;

  }

  // Imaginary action integral

  int j,j_react,j_prod,iE0,iEstart;
  double thetaE;
  double* PEiai;
  PEiai = (double*) malloc( dim*sizeof(double) );

  //  double PEiai2;
  double mueff;

  //  mueff=ctest*p_mass; //mass of proton in Kg
  mueff=1.0*p_mass; //mass of proton in Kg

  iEstart=Pot[0]+0.5; // integration started from minimum reactant energy
  
  // E=1500.;

  iE0=Pot[npdim/2]+0.5;
  printf( "max energy is: %d \n", iE0);
  //  exit(-1);

  E=iEstart;

  for(i=0;i<dim;i++){
      PEiai[i]=0.;
    }

  //  fprintf(Trans_coeff,"E Trans_coeff_Ec Trans_coeff_Ia Trans_coeff_Ec/Trans_coeff_Ia\n");
  fprintf(Trans_coeff,"E Trans_coeff_Ec Trans_coeff_Ia \n");

  for(i=iEstart;i<dim;i++){

    // turning point identification

    j_react=0;
    j_prod=0;

    for (j=0;j<npdim; j++){
      if ( (Pot[j]< E) &&  (Pot[j+1]>E)) { j_react=j; }
      if ( (Pot[npdim-j]< E) &&  (Pot[npdim-j-1]>E)) { j_prod=npdim-j; }
    }

    //    printf("E is: %d   j_react is: %d the potential is : %le \n",E,j_react,Pot[j_react]);
    // printf("E is: %d   j_prod is: %d the potential is : %le \n",E,j_prod,Pot[j_prod]);

    // imaginary action integral


    if(E < iE0){
      thetaE=0.;
      for (j=j_react;j<j_prod; j++){
	//thetaE=thetaE+2*pi/h_planck*(sqrt(2*mueff*fabs(E-Pot[j])*c_light_cm_s*h_planck))*a_bohr*int_step;
	thetaE=thetaE+2*pi/h_planck*((sqrt(2*mueff*fabs(E-Pot[j])*c_light_cm_s*h_planck))+(sqrt(2*mueff*fabs(E-Pot[j+1])*c_light_cm_s*h_planck)))/2.*a_bohr*int_step;
      }

       PEiai[i]=1./(1.+exp(2*thetaE));
      //      PEiai[i]=1./exp(2*thetaE);


    //    if((j_react==0) && (j_prod==0)) { PEiai=1.; }
    //    PEiai2=1./exp(2*thetaE);
    }

    else if((E > iE0) && (E< 2*iE0)){
      PEiai[i]=1.-PEiai[2*iE0-i];
      //PEiai[i]=2*PEiai[iE0]-PEiai[2*iE0-i];
      //      PEiai[i]=1.;
    }

    else{
      PEiai[i]=0.5;
    }
      
    Transmission_coeff_Ia[i]= PEiai[i];
    //    fprintf(Trans_coeff,"%d\t%le\t%le\t%le\n",E,Transmission_coeff_Ec[i],Transmission_coeff_Ia[i],Transmission_coeff_Ec[i]/Transmission_coeff_Ia[i]);
    fprintf(Trans_coeff,"%d\t%le\t%le\n",E,Transmission_coeff_Ec[i],Transmission_coeff_Ia[i]);

    E=E+step;

  }

  //calcolo qtunn a diverse T


  double T;
  double den,num_Ec,num_Ia;
  double qtunn_Ec;
  double qtunn_Ia;
  //  double inv;
  printf("Temperature[K]\t qtunn_Ia\t    qtunn_Ec\t  \n");
  fprintf(results,"Temperature[K]\t qtunn_Ia\t    qtunn_Ec\t  \n");
  //  fprintf(results, "Temperature[K]\t qtunn\n");

  for(T=T_start;T<T_end;T=T+deltaT){
    
    //inv=h_planck*c_light_cm_s/boltzmann/T;
    //  printf("inv=%lf\n",inv);
    
    den=0.;
    num_Ec=0.;
    num_Ia=0.;
    
    Ej=Efor;
    for(i=0; i<dim1; i++){
      den=den + exp(-Ej/boltzmann/T);
      Ej=Ej+(step*h_planck*c_light_cm_s);
    }
    
    Ej=E_min*h_planck*c_light_cm_s;
    for(i=0; i<dim; i++){
      
      num_Ia=num_Ia + Transmission_coeff_Ia[i]*exp(-Ej/boltzmann/T);
      num_Ec=num_Ec + Transmission_coeff_Ec[i]*exp(-Ej/boltzmann/T);
      Ej=Ej+(step*h_planck*c_light_cm_s);
    }
    
    qtunn_Ia=num_Ia/den;
    qtunn_Ec=num_Ec/den;

    //    printf("%.1f\t%le\t%le\t%le\t%le\n",T,num,den,qtunn_Ia,qtunn_Ec);
    printf("%.1f\t      %le \t  %le  \n",T,qtunn_Ia,qtunn_Ec);
    fprintf(results,"%.1f\t      %le \t  %le  \n",T,qtunn_Ia,qtunn_Ec);
    
    //    fprintf(results,"%.0f\t%.0f\t%le\n",T,T-273,qtunn);
    
  }
  return 0;
}

void reading_inputfile(FILE *fp){

char buffer[200];




 // Leggo energia reazione diretta E1
  if(!feof(fp)) {
    fscanf(fp,"%s %lf",buffer,&Efor);
    printf("Forward activation Energy:      %lf\n", Efor);
    if(Efor<0) {
      printf("the Forward activation Energy cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }
   

   // Leggo energia reazione inversa E-1
  if(!feof(fp)) {
    fscanf(fp,"%s %lf",buffer,&Eback);
    printf("Backward activation Energy:      %lf\n", Eback);
    if(Eback<0) {
      printf("the backward activation energy cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }

  // Leggo valore assoluto frequenza immaginaria
  if(!feof(fp)) {
    fscanf(fp,"%s %lf",buffer,&ifreq);
    printf("Imaginary Frequency:      %lf\n", ifreq);
    if(Eback<0) {
      printf("the imaginary frequency cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }


// Leggo temperatura iniziale finale e il deltaT
  if(!feof(fp)) {
    fscanf(fp,"%s %lf %lf %lf",buffer,&T_start,&T_end,&deltaT);
    printf("Temp_start:      %lf\n", T_start);
    printf("Temp_end:      %lf\n", T_end); 
    printf("deltaT:      %lf\n", deltaT);

    if(Eback<0) {
      printf("the imaginary frequency cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }

  // Leggo lo step del potenziale
  if(!feof(fp)) {
    fscanf(fp,"%s %lf",buffer,&int_step);
    printf("integration step for potential:      %lf\n", int_step);
    if(step<0) {
      printf("the integration step cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }
  
  
  // Leggo il numero di steps totali
  if(!feof(fp)) {
    fscanf(fp,"%s %d",buffer,&npdim);
    printf("Potential Points NUMBER:      %d\n", npdim);
    if(step<0) {
      printf("the number of potential vector points cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }


  if(!feof(fp)) {
    fscanf(fp,"%s %lf",buffer,&step);
    printf("STEP NUMBER:      %lf\n", step);
    if(step<0) {
      printf("the number of step cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }

 // Leggo il valore minimo di E
  if(!feof(fp)) {
    fscanf(fp,"%s %d",buffer,&E_min);
    printf("E min:      %d\n", E_min);
    if(step<0) {
      printf("the number of step cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }
 // Leggo il valore massimo di E
  if(!feof(fp)) {
    fscanf(fp,"%s %d",buffer,&E_max);
    printf("E max:      %d\n", E_max);
    if(step<0) {
      printf("the number of step cannot be negative\n"
	     "Change the value and restart the program\n"
	     "the program will be stopped now\n");
      exit(0);
    }
  } else {
    printf("Data file error\nthe program will be stopped now\n");
    exit(0);
  }


}
