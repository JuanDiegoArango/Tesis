
import numpy as np
import matplotlib.pyplot as plt


dt=float(1e-3)
tiempo=int(30/dt)
fuerzas=np.zeros(tiempo+1)
Kb_T=4.10
print tiempo

Ntot=1000
Na=Ntot
Nb=0

La0=0.75
Lb0=La0*7.0
La=La0
lp=1.2

def fuerza2(x,c):
    return (Kb_T/(4.0*lp))*((1.0-(x/c))**-2.0-1.0+4.0*(x/c))

def probabilidad_de_transicion(v,f,delta_X):
    return v*np.exp((delta_X*f)/(Kb_T))*dt

def nuevo_La(f,Numero):
    return (f/ka)+La0*Numero

def fuerza1(x,a):
    return ka*(x-a)

ka=50
kAB=float(5e-2)
kBA=(700.0)

delta_X_AB=0.5
delta_X_BA=-0.5

L_inicial=La0*Ntot

monomeros=np.ones(Ntot)
cambio_L=100.0
posicion_libre=0
cp=np.zeros(4)
t=1

Na=len(monomeros[monomeros==1])    
Nb=len(monomeros[monomeros==2])
NaT=np.zeros(tiempo)
NbT=np.zeros(tiempo)
tau=np.zeros(tiempo+1)


for j in range (0,tiempo):
    if (t==j):
        t=t*10
        print t
      
    L=L_inicial+cambio_L*(j*dt)
    
    p=np.random.uniform(size=2)
    pa=probabilidad_de_transicion(kAB,fuerzas[j],delta_X_AB)
    pb=probabilidad_de_transicion(kBA,fuerzas[j],delta_X_BA)  
  
    if (pb>p[0]) & ((Nb)>0) & (posicion_libre>0):
        posicion_libre=posicion_libre-1
        monomeros[posicion_libre]=1   

    
    if (pa>p[1]) & ((Na)>0):
        monomeros[posicion_libre]=2   
        posicion_libre=posicion_libre+1               

    Na=len(monomeros[monomeros==1])    
    Nb=len(monomeros[monomeros==2]) 
    
    NaT[j]=Na
    NbT[j]=Nb
    tau[j+1]=dt*j
 
    a=La0*Na
    b=Kb_T/(lp)
    c=Lb0*Nb
    
    if(Nb==0)&(Na==Ntot):
        
        fuerzas[j+1]=fuerza1(L,a)

    elif(Nb>0)&(Na<Ntot)&(Na>0)&(Nb<Ntot):
        
        cp[0]=4*(b+c*ka)
        cp[1]=-(c)*(8*c*ka+4*ka*(L-a)+9*b)
        cp[2]=(2*c**2)*(2*c*ka+4*ka*(L-a)+3*b)
        cp[3]=4*(c**3)*(ka)*(a-L)
        
        delta0=cp[1]**2.0-3.0*cp[0]*cp[2]
        delta1=2.0*cp[1]**3.0-9.0*cp[0]*cp[1]*cp[2]+27.0*(cp[0]**2.0)*(cp[3])
        discriminante=((delta1+((delta1**2.0-4.0*delta0**3.0)**(1.0/2.0)))*0.5)**(1.0/3.0)
        
        Lb=(-1.0/(3.0*cp[0]))*(cp[1]+discriminante+delta0/discriminante)
        fuerzas[j+1]=fuerza2(Lb,c)
        La=nuevo_La(fuerza2(Lb,c),Na)
        

    elif (Na==0)&(Nb==Ntot):
        c=Lb0*Ntot
        if(c==L):
            L=L+0.0001
        fuerzas[j+1]=fuerza2(c,L)



r=np.linspace(0,len(fuerzas),len(fuerzas))
plt.ylabel("Fuerza(pN)")
plt.xlabel("Elongacion(nM)")
plt.xlim(-1000,15000)
plt.plot(r,fuerzas)
plt.savefig("fuerza.pdf")




