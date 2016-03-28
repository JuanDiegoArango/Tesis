//
//  Catch-Bond.c
//  
//
//  Created by Juan Diego Arango on 3/27/16.
//
//

#include "Catch-Bond.h"
#include <math.h>
#include <stdlib.h>
void salir_de_estado(int estado,double f);
void cambiar_de_estado(int estado, double f);



bool main (double dt, int semilla, double fuerza ){

double Kb_T=4.1;
double dt;
double t=4.0
double tiempo=(int)t/dt;
double k10=6.01;
double k20=0.007;
double k12=0.21;
double k21=0.105;
double x10=1.37*0.1;
double x20=1.76*0.1;
double x12=8.58*0.1;
double x21=-4.2*0.1;
bool ruptura=false;



for( int i=0; i<=tiempo;i=i+1)
{
srand48(semilla);
p1=drand48();
p2=drand48();
    
    if (cambiar_de_estado(estado,fuerza)>p1)
    {
        if(estado ==2.0)
        {
            estado=1.0;
        }
        else if (estado ==1.0)
        {
            estado=2.0;
        }
    }
    
    if (salir_de_estado(estado,fuerza)>p2)
    {   ruptura=true;
        break;
    }

}

void salir_de_estado(int estado,double f)
{
    if (estado==1.0)
    {
        respuesta=k10*exp(x10*f/(Kb_T))*dt;
    }
    else if (estado==2.0)
    {
    
        respuesta=k20*exp(x20*f/(Kb_T))*dt;
    }
    return respuesta;
}



void cambiar_de_estado(int estado, double f)
{
    if (estado==2.0)
    {
        respuesta=k21*exp(x21*f/(Kb_T))*dt;
    }
    else if (estado==1.0)
    {
        respuesta=k12*exp(x12*f/(Kb_T))*dt;
    }
    return respuesta;
}


