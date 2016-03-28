//
//  Pilis.c
//  
//
//  Created by Juan Diego Arango on 3/26/16.
//
//

#include "Pilis.h"
#include <math.h>



//parametros
double dt; //este entra por parametro
double Kb_T=4.10;

//monomeros-entran por parametro
int Ntot;
int Na;
int Nb;
int posicion_libre;//parametro

//longitudes
double La0=0.75;
double Lb0=5.7;
double La=La0;
double lp=2.7;

//constante resorte
double ka=2.0;

// tasas de transicion
kAB=0.05;
kBA=700.0;

//distancias de transicion
double delta_X_AB=0.5;
double delta_X_BA=-0.5;

double a=La0*Na;
double b=Kb_T/(lp);
double c=Lb0*Nb;

//distancia inicial
double L_inicial=Na*La0+Nb*Lb0;

//arrays
double *monomeros= malloc( sizeof(double)*Ntot );
double *fuerzas= malloc( sizeof(double)*3);
double *cp= malloc( sizeof(double)*4);

cp[0]=4*(b+c*ka)
cp[1]=-(c)*(8*c*ka+4*ka*(L-a)+9*b)
cp[2]=(2*c**2)*(2*c*ka+4*ka*(L-a)+3*b)
cp[3]=4*(c**3)*(ka)*(a-L)

double delta0=cp[1]*cp[1]-3*cp[0]+cp[2]
double delta1=2*cp[1]*cp[1]*cp[1]-9*cp[0]*cp[1]*cp[2]+27*cp[0]*cp[0]*cp[3]
double C=pow(((delta1+sqrt(delta0*delta0-4*delta1*delta1*delta1))*0.5),1.0/3.0)
double Lb=-1.0/(3*cp[0])*(cp[1]+C+delta0/C)



//entra por parametro



for(int i=posicion_libre; i<Ntot;i=1+i)
{
    if (i<Ntot && posicion_libre<=i)
    {monomeros[i]=1;}
    
    else if (i<posicion_libre && 0<=i)
    {monomeros[i]=2}
    
}












double fuerza(x,c)
{
    return (Kb_T/(4.0*lp))*((1.0-(x/c))**-2.0-1.0+4.0*(x/c));
}


double probabilidad_de_transicion(v,f,delta_X)
{
    return v*exp((delta_X*f)/(Kb_T))*dt;
}


double nuevo_La(f,Numero)
{
    return (f/ka)+La0*Numero;
}


fuerzas=zeros(tiempo)
