#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


double int_step,step, Efor, Eback, ifreq,T_start,T_end,deltaT;
int  E_max, E_min, E,i,npdim;

double     pi;
double     c_light;
double     c_light_cm_s;
// Magnetic constant or permeability of vacuum [N/A**2]
double     mu_perm ; 

// Electric constant or permittivity of vacuum [F/m]
double     permittivity; 
//_VERSION == 2006
// Recommended fundamental constants of physics
// and chemistry based on the 2006 adjustment
 
// Planck constant [J*s]
double     h_planck;
double     h_bar; 
//Elementary charge [C]
double     e_charge; 

//     ! Electron mass [kg]
double     e_mass; 
 
//     ! Proton mass [kg]
double     p_mass;    
 
//     ! Electron g factor [ ]
double     e_gfactor; 
 
//     ! Fine-structure constant
// !MK a_fine = 0.5 *mu_perm*c_light*e_charge**2/h_planck
double     a_fine ;

//     ! Rydberg constant [1/m]
// !MK rydberg = 0.5 *e_mass*c_light*a_fine**2/h_planck
double     rydberg ;
 
//     ! Avogradro constant [1/mol]
double     n_avogadro; 
 
//     ! Boltzmann constant [J/K]
double     boltzmann  ;

//     ! Atomic mass unit [kg]; conversion factor [u] -> [kg]
double     a_mass  ;
 
//    ! Bohr radius [m]
// !MK a_bohr = a_fine/(4.0 *pi*rydberg)
double     a_bohr ; 

 
//     ! Conversion factors
 
//     ! [u] -> [a.u.]
double     massunit;
 
//     ! [Bohr] -> [Angstrom]
double angstrom;
 
//     ! [Angstrom] -> [Bohr]
double bohr ;
 
//     ! [a.u.] -> [s]
double seconds;
 
//     ! [a.u.] -> [fs]
double femtoseconds;
 
//     ! [a.u.] -> [ps]
double picoseconds;
 
//     ! [a.u.] -> [J]
double joule;
 
//     ! [a.u.] -> [K]
double kelvin;
 
//     ! [a.u.] -> [kJ/mol]
double kjmol ;
 
//     ! [a.u.] -> [kcal/mol]
double kcalmol ;
 
//     ! [a.u.] -> [Pa]
double pascal ;
 
//     ! [a.u.] -> [bar]
double bar  ;
 
//     ! [a.u.] -> [atm]
double atm; 
 
//     ! [a.u.] -> [eV]
double evolt;
 
//     ! [a.u.] -> [Hz]
double hertz;
 
//     ! [a.u./Bohr**2] -> [1/cm] (wave numbers)
double vibfac;
 
//     ! [a.u.] -> [1/cm] (wave numbers)
double wavenumbers;
 
/*

double ***Hessian;
double **positions;
double **gradient;
double *CM_x,*CM_y, *CM_z;
double ***I;
double ***v, **eigen;
double *lambda;

//double **L;
//double **D1;
typedef struct {
  char atom_name;
  double atomic_mass;
  double *ext_coord_x;
  double *ext_coord_y;
  double *ext_coord_z;
  double ext_coord_x_bohr;
  double ext_coord_y_bohr;
  double ext_coord_z_bohr;
  double *grad_x;
  double *grad_y;
  double *grad_z;
  double force_x_old;
  double force_y_old;
  double force_z_old;
  double velocity_x;
  double velocity_y;
  double velocity_z;
  double vib_velocity_x;
  double vib_velocity_y;
  double vib_velocity_z;
  double LRot1x;
  double LRot1y;
  double LRot1z;
  double LRot2x;
  double LRot2y;
  double LRot2z;
  double LRot3x;
  double LRot3y;
  double LRot3z;
  double LTr1x;
  double LTr1y;
  double LTr1z;
  double LTr2x;
  double LTr2y;
  double LTr2z;
  double LTr3x;
  double LTr3y;
  double LTr3z;


}atom_struct;

atom_struct* atoms_data;

typedef struct {
  double distance;
  int atom1;
  int atom2;
}bond_struct;

bond_struct* bonds_data;

typedef struct {
  double angle_value;
  int atom1;
  int atom2;
  int atom3;

}bond_angle_struct;

bond_angle_struct* bond_angle;

typedef struct {
  double angle_value;
  int atom1;
  int atom2;
  int atom3;
  int atom4;

}dihedral_angle_struct;

dihedral_angle_struct* dihedral_angle;

typedef struct {
  double positions;
  double velocities;
  char name;

}internal_coordinates_struct;

internal_coordinates_struct* internal_coordinates;

*/

