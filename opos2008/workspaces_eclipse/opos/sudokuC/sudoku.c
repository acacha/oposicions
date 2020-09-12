#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MAX_FILES
 #define MAX_FILES 9
 #define MAX_COLUMNES 9
#endif

#ifndef TRUE
 #define TRUE 1
 #define FALSE 0
#endif

typedef int boolean;

typedef struct quadre QUADRE;

struct quadre{
 int posicio; // Les posicions van de la 0 (1,1) a la 80 (9,9) passant per 7 (1,9) i 8 (2,1)
 int valor; // Els valors són 0 si no hi ha cap valor o de 1-9.
};

void sudoku(int posicio,QUADRE valorsinicials[], int nvalorsinicials, int tauler[]);

boolean esValorInicial(int posicio,QUADRE valorsinicials[], int nvalorsinicials);

boolean esValorValid(int valor,int posicio,int tauler[]);

void mostrarSolucio(int tauler[],QUADRE valorsinicials[],int nvalorsinicials);

int main(int argc, char **argv) {
	
	int POSICIO_MAXIMA= MAX_FILES*MAX_COLUMNES;
	
	int tauler[POSICIO_MAXIMA];
	QUADRE *valorsinicials;
	int i,k,j, nvalors_inicials;
	
	if (argc<2) {
		printf("S'ha d'especificar com a mínim un paràmetre: %s valorsinicials\n",argv[0]);
		exit(1);
	}
	
	nvalors_inicials= atoi (argv[1]);
	
	valorsinicials= (QUADRE*) malloc(sizeof(QUADRE)*nvalors_inicials);
	
	if (argc!=(2+nvalors_inicials*3)) {
		printf("S'han d'especificar 3 valors/paràmetres (posició x i y + valor) per cada valor inicial\n");
		exit(0);		
	}
	
	for (i = 0; i < nvalors_inicials; ++i) {
		valorsinicials[i].posicio=atoi(argv[2+i*3])*MAX_COLUMNES+atoi(argv[3+i*3]); //posicio=fila*nquadresxcolumna+columna
		valorsinicials[i].valor=atoi(argv[4+i*3]);
	}
	
	//iniciar el tauler:
	for (k = 0; k < POSICIO_MAXIMA; ++k) {
		tauler[k]=0;
	}
	
	//Colocar els valors inicials
	for (j = 0; j < nvalors_inicials; ++j) {
		int pos= valorsinicials[j].posicio;
		tauler[pos]=valorsinicials[j].valor;
	}
	
	printf("Sudoku a resoldre:\n");
	mostrarSolucio(tauler,valorsinicials,nvalors_inicials);
	sleep(5);
	
	sudoku(0,valorsinicials,nvalors_inicials, tauler);
	
	free(valorsinicials);
	
	exit(0);
}

void sudoku(int posicio,QUADRE valorsinicials[], int nvalorsinicials, int tauler[]){
	//Declaració de variables
	int i;

	int POSICIO_MAXIMA= MAX_FILES*MAX_COLUMNES;
	
	//Saltar els valors que ja ens venen donats
	if (esValorInicial(posicio, valorsinicials, nvalorsinicials)) {
		//Condició final
		if (posicio==POSICIO_MAXIMA-1) {
			//Solució.
			mostrarSolucio(tauler,valorsinicials,nvalorsinicials);
		}
		sudoku(posicio+1,valorsinicials,nvalorsinicials,tauler);
		return;
	}
	
	//Valors possibles 1-9
	for (i = 1; i < 10; ++i) {
		if (esValorValid(i,posicio,tauler)) {
			tauler[posicio]=i;
			//Condició final
			if (posicio==POSICIO_MAXIMA-1) {
				//Solució.
				mostrarSolucio(tauler,valorsinicials,nvalorsinicials);
			}
			sudoku(posicio+1,valorsinicials,nvalorsinicials,tauler);
			//Si arriba aquí és que el valor era valid però no porta a una solució
			tauler[posicio]=0;
		}
		//Si arriba a qui és que no hi ha cap valor que sigui possible. No fem res--> desfa 
		//la pila de crides a la funció sudoku
	}
}

boolean esValorInicial(int posicio,QUADRE valorsinicials[], int nvalorsinicials){
	int i;
	for (i = 0; i < nvalorsinicials; ++i) {
		if (valorsinicials[i].posicio==posicio)
			return TRUE;
	}
	return FALSE;
}

boolean esValorValid(int valor,int posicio,int tauler[]){
	
	//Obtenir valors de fila i columna per a la posició donada
	
	int fila,columna,i,j,k,l;
	int nquadre33Horizontal,nquadre33Vertical;

    fila=posicio/MAX_COLUMNES;
    columna=posicio%MAX_COLUMNES;
    
    //Buscar si hi ha alguna fila amb el mateix valor
    for (i = 0; i < MAX_FILES; ++i) {
		if (valor==tauler[MAX_COLUMNES*fila+i]) {
			return FALSE;
		}
	}
    //Buscar si hi ha alguna columna amb el mateix valor
    for (j = 0; j < MAX_FILES; ++j) {
    	if (valor==tauler[columna+j*MAX_FILES]) {
    		return FALSE;
    	}
    }
    
    //Buscar si hi ha algun quadre amb el mateix valor dins del subquadre 3x3
    nquadre33Horizontal=columna/3;
    nquadre33Vertical=fila/3;    
    for (k = 0; k < 3; ++k) {
		for (l = 0; l < 3; ++l) {
			int fila=k+nquadre33Vertical*3;
			int columna=l+nquadre33Horizontal*3;
			if (valor==tauler[fila*MAX_COLUMNES+columna]) {
				return FALSE;
			}
		}
	}   
    
    return TRUE;
}

void mostrarSolucio(int tauler[],QUADRE valorsinicials[],int nvalorsinicials){
	int i,j,posicio;
	for (i = 0; i < MAX_COLUMNES; ++i) {
		for (j = 0; j < MAX_FILES; ++j) {
			posicio=i*MAX_COLUMNES+j;
			//Si és valor inicial pintar en negreta (només vàlid en Linux)
			if (esValorInicial(posicio,valorsinicials,nvalorsinicials)) {
				printf("\033[1m%d\033[0m ",tauler[i*MAX_COLUMNES+j]);
			}
			else {
				printf("%d ",tauler[i*MAX_COLUMNES+j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
