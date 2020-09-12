#include <stdio.h>
#include <stdlib.h>

#ifndef NOUTILITZAT
 #define NOUTILITZAT 0
 #define UTILITZAT 1 
#endif
     
void buscar_suma(int nvalorsActual, int *valorsActuals,int nvalors,int *valors,int valorBuscat);   
 
int suma(int n,int *valorsActuals, int *valors);

void mostrarResultat(int n,int *valorsActuals, int *valors, int resultat);

int main (int argc, char *argv[]) {

 //argv[1] --> Conté el nombre de valors
 int nvalors=atoi(argv[1]);
 
 int *valors = (int*) calloc(nvalors,sizeof(int));
 
 int i;
 for(i=0; i<nvalors; i++) {
   valors[i]=atoi(argv[i+2]);
 }
 
 int valorbuscat=0;
 
 valorbuscat=atoi(argv[argc-1]);
 
 int *valorsActuals = (int*) calloc(nvalors,sizeof(int));
 int k;
 for(k=0; k<nvalors; k++) {
    valorsActuals[k]=NOUTILITZAT; //O indica que el valor no s'utilitza
 }
 valorsActuals[0]=UTILITZAT;
 buscar_suma(1,valorsActuals,nvalors,valors,valorbuscat);
 exit(0);
}

void buscar_suma(int nvalorsActual, int *valorsActuals,int nvalors,int *valors,int valorBuscat) {

 if (suma(nvalors,valorsActuals,valors)==valorBuscat) {
  //Solució
  mostrarResultat(nvalors,valorsActuals,valors,valorBuscat);
 }
 
 if (nvalorsActual!=nvalors) {
  
  //Esquerre--> El valorActual no s'utilitza
  valorsActuals[nvalorsActual-1]=NOUTILITZAT;
  valorsActuals[nvalorsActual]=UTILITZAT;
  buscar_suma(nvalorsActual+1,valorsActuals,nvalors,valors,valorBuscat);  
  
  //Dreta--> El valor actual s'utilitza
  valorsActuals[nvalorsActual-1]=UTILITZAT;
  valorsActuals[nvalorsActual]=UTILITZAT;
  buscar_suma(nvalorsActual+1,valorsActuals,nvalors,valors,valorBuscat);
   
 }
}

int suma(int n,int *valorsActuals, int *valors) {
 int acumulador=0;
 int i;
 for (i=0;i<n;i++) {
  if (valorsActuals[i]==UTILITZAT)
    acumulador=acumulador+valors[i];
 }
 return acumulador;
} 

void mostrarResultat(int n,int *valorsActuals, int *valors, int resultat) {
 int i;
 for (i=0;i<n;i++) {
  if (valorsActuals[i]==UTILITZAT) { 
   if (i!=(n-1)) 
    printf("%d+",valors[i]);  
   else
    printf("%d=%d\n",valors[i],resultat);
  }
 }    
}