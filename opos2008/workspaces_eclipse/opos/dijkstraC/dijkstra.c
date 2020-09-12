#include <stdlib.h>;


//Estructures de dades

typedef struct distancia DISTANCIA;

struct distancia {
	int dist;
	int nodeAnterior;
};

typedef struct aresta ARESTA;

struct aresta {
	int nodevei;
	int pes;
};

int main(int argc, char **argv) {

	//Iniciar el graf
	//Paràmetres:
	//argv[1]= nº de nodes
	//Per cada node la seva llista d'adjacències (pesos als veins) parella: vei distancia
	//argv[2]=nº de node inicial
	//argv[3]= nº de veins del primer node. Els veins estan ordenats
	//argv[3] vegades:
	// argv[4] nº node vei 1
	// argv[5] pes node vei 2
	// argv[6] nº node vei 2
	// argv[7] pes node vei 2
	// ...
	
	int nodeinicial,nnodes,i,nveins,count;
	DISTANCIA *distancies; //On guardarem el resultat de l'agorismes de Dijkstra
	ARESTA *veins;
	
	nnodes=atoi(argv[1]);
	nodeinicial=atoi(argv[2]);
	
	distancies=(DISTANCIA*) malloc(sizeof(DISTANCIA)*nnodes);
	
	count=0;
	for (i = 0; i < nnodes; ++i) {
		//Obtenir el nº de veins
		nveins=argv[3+count];
		veins=(ARESTA*) malloc(sizeof(ARESTA)*nveins);
		count=count+(nveins*2)+1;
	}
	
	
	
	
	free=(DISTANCIA*);
	
}

void mostrarGraf() {
	
}


