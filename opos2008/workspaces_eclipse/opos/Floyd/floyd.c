#include <stdlib.h>
#include <stdio.h>

#define NO_CONNECTAT -1

//Estructures de dades
typedef struct distancia DISTANCIA;

struct distancia {
	int dist;
	int nodeAnterior;
};

void mostrarGraf(int pesos[],int nnodes);

void floyd(int pesos[],int nnodes);

void mostrarDistancies(DISTANCIA distancies[], int nnodes);

int main(int argc, char **argv) {

	//Iniciar el graf
	//Paràmetres:
	//argv[1]= nº de nodes
	//Per cada node la seva llista d'adjacències (pesos als veins) parella: vei distancia
	//nnodes vegades:
	// argv[2] pes node vei 1
	// argv[3] pes node vei 2
	// argv[4] pes node vei 3
	// ...
	
	int nnodes,i,j;
	
	int *pesos;
	
	if (argc<5) {
		printf("El nombre de paràmetres mínim és 4(2 nodes). Utilitza: %s nnodes pes1 pes2 pes3 ",argv[0]);
	}
		
	
	nnodes=atoi(argv[1]);
	
	pesos=(int*) malloc(sizeof(int)*nnodes*nnodes);
	
	//Els nodes que no estan connectats, es guarden amb un -1
	for (i = 0; i < nnodes; ++i) {
		for (j = 0; j < nnodes; ++j) {
			pesos[i*nnodes+j]=atoi(argv[3+nnodes*i+j]);
		}
	}
	
	printf("Node inicial:%d\n",nodeinicial);
	//mostrarGrafInicial
	mostrarGraf(pesos,nnodes);
	
	floyd(pesos,nnodes);
	
	free(pesos);
	exit(0);
}
	
void floyd(int pesos[],int nnodes) {
	int i,j,k;

	//Crear i Iniciar vector distàncies
	DISTANCIA *distancies; //On guardarem el resultat de l'agorismes de Dijkstra
	distancies=(DISTANCIA*) malloc(sizeof(DISTANCIA)*nnodes);

	
	for (k = 0; k < nnodes; ++k) {
		distancies[i].dist=pesos[nodeinicial*nnodes+k];
		for (i = 0; i < nnodes; ++i) {
				//Per cada node
				printf ("\nIteracio:%d\n",i);
				for (j = 0; j < nnodes; ++j) { //Per cada vei de cada node
					
					printf("i=%d,j=%d\n",i,j);
					printf("Anàlisi de la distància entre %d i %d passant per %d\n",nodeinicial,j,i);
					
					if (pesos[i*nnodes+j]!=NO_CONNECTAT) { //Només veins
						/*
						printf("pes de i=%d a j=%d:%d --> pesos[i*nnodes+j]=%d \n",i,j,pesos[i*nnodes+j],pesos[i*nnodes+j]);
						printf("distancies[j=%d].dist=%d\n",j,distancies[j].dist);
						printf("distancies[i=%d].dist=%d\n",i,distancies[i].dist);
						printf("pesos[i*nnodes+j]=%d\n",distancies[j].dist+pesos[i*nnodes+j]);
						*/
						if (distancies[j].dist>(distancies[i].dist+pesos[i*nnodes+j])) {
							//Actualitzar distancia i node anterior
							distancies[j].dist=distancies[i].dist+pesos[i*nnodes+j];
							distancies[j].nodeAnterior=i;
						}
					}
					else {
						printf("%d no és vei de %d\n",j,i);
					}
				}
				mostrarGraf(pesos,nnodes);
				printf ("\n");
				printf ("\n");
			}
	}
	
	//Mostrar resultat
}

void mostrarGraf(int pesos[],int nnodes) {
	int i,j;
	
	for (i = 0; i < nnodes; ++i) {
		for (j = 0; j < nnodes; ++j) {
			printf("%d ",pesos[i*nnodes+j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
