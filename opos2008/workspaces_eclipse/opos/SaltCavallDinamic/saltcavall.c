#include <stdlib.h>
#include <stdio.h>


#ifndef MAX_FILES
 #define MAX_FILES 8
 #define MAX_COLUMNES 8
#endif

#ifndef TRUE
 #define TRUE 1
 #define FALSE 0
#endif

typedef int boolean;

typedef struct posicio POSICIO;

struct posicio{
 int x;
 int y;
};

boolean posiciovalida(POSICIO pos);
//void saltcavall(POSICIO *pos,int num_posicio,POSICIO *recorregut[],int tauler[][MAX_COLUMNES]);

void saltcavall(POSICIO pos, int num_posicio, POSICIO recorregut[], int tauler[][MAX_COLUMNES]);

void mostrarsolucio(POSICIO *recorregut[]);

void mostrarsolucio1(POSICIO recorregut[]);

void mostrarsolucio2(POSICIO recorregut[],int files, int columnes);

void visualitza(int files,int columnes,int *p);

void visualitza2(int files,int columnes,int *p);

int main(int argc, char **argv) {
	//inicialització
	int x,y,num_posicio;
	
	//Paràmetres
	// argv[1] --> x inicial
	// argv[2] --> y inicial
	
	// argv[3] --> files del quadrat
	// argv[4] --> columnes del quadrat
	
	POSICIO pos_inicial;
	
	
	POSICIO recorregut[MAX_FILES*MAX_COLUMNES];
	//struct posicio recorregut[MAX_FILES*MAX_COLUMNES];
	
	//Inicialitza recorregut:
	
	int k;
	for (k = 0; k < MAX_FILES*MAX_COLUMNES; ++k) {
			recorregut[k].x=-1;
			recorregut[k].y=-1;	
	}
		
	int tauler[MAX_FILES][MAX_COLUMNES];
	
	for (x = 0; x < MAX_FILES; ++x) {
		for (y = 0; y < MAX_COLUMNES; ++y) {
			tauler[x][y]=-1;
		}
	}
	
	pos_inicial.x=atoi(argv[1]);
	pos_inicial.y=atoi(argv[2]);
	
	num_posicio=0;
	
	saltcavall(pos_inicial,num_posicio,&recorregut[0],tauler);
		
	//mostrarsolucio2(recorregut,1,5);

	/*
	visualitza2(MAX_FILES,MAX_COLUMNES,&tauler[0][0]);
	
	recorregut[0].x=1;
	recorregut[0].y=1;
	
	recorregut[1].x=2;
	recorregut[1].y=2;
	
	recorregut[2].x=3;
	recorregut[2].y=3;
	
	recorregut[3].x=3;
	recorregut[3].y=3;
	
	recorregut[4].x=4;
	recorregut[4].y=4;
	
	int k;
	for (k = 0; k < 5; ++k) {
		printf("(%d,%d) ",recorregut[k].x,recorregut[k].y);	
	}
	printf("\n");*/
	
	return 0;
}

void saltcavall(POSICIO pos, int num_posicio, POSICIO recorregut[], int tauler[][MAX_COLUMNES]) {
	//Afegir la posicio a recorregut
	int x= pos.x;
	int y= pos.y;
	recorregut[num_posicio].x = x;
	recorregut[num_posicio].y = y;
	
	tauler[x][y]=num_posicio;
	printf("num_posicio:%d\n",num_posicio);
	visualitza2(MAX_FILES,MAX_COLUMNES,&tauler[0][0]);
	printf("\n");
	printf("\n");
	//Condició frontera
	
	if(num_posicio==(MAX_FILES*MAX_COLUMNES -1)) {
		//Solució
		mostrarsolucio2(recorregut,MAX_FILES, MAX_COLUMNES);
	}
		
	//Posicions següents
	POSICIO next_pos;
	int j;
	for (j = 0; j < 8; ++j) {
		switch (j) {
			case 0:
				next_pos.x=pos.x+2;
				next_pos.y=pos.y-1;
				break;
			case 1:
				next_pos.x=pos.x+2;
				next_pos.y=pos.y+1;			
				break;
			case 2:
				next_pos.y=pos.y+2;
				next_pos.x=pos.x-1;										
				break;
			case 3:
				next_pos.y=pos.y+2;
				next_pos.x=pos.x+1;			
				break;
			case 4:
				next_pos.x=pos.x-2;
				next_pos.y=pos.y+1;										
				break;
			case 5:
				next_pos.x=pos.x-2;
				next_pos.y=pos.y-1;							
				break;
			case 6:
				next_pos.y=pos.y-2;
				next_pos.x=pos.x+1;									
				break;
			case 7:
				next_pos.y=pos.y-2;
				next_pos.x=pos.x-1;										
				break;
			default:
				break;
		}
		if (posiciovalida(next_pos) && tauler[next_pos.x][next_pos.y]==-1) {
			saltcavall(next_pos,num_posicio+1,recorregut,tauler);
		    //si arriba aquí és que el possible no era bó --> Desfer
			recorregut[num_posicio+1].x = -1;
			recorregut[num_posicio+1].y = -1;
			tauler[next_pos.x][next_pos.y]=-1;
		}
	}
}

/*
void mostrarsolucio1(const struct posicio *recorregut) {
 int i;
 for (i = 0; i < (MAX_FILES*MAX_COLUMNES); ++i) {
  printf("(%d,%d) ",recorregut[i]->x,recorregut[i]->y);
 }
}*/


void mostrarsolucio1(POSICIO recorregut[]) {
 int i;
 for (i = 0; i < (MAX_FILES*MAX_COLUMNES); ++i) {
  printf("(%d,%d) ",recorregut[i].x,recorregut[i].y);
 }
 printf("\n");
}

void mostrarsolucio2(POSICIO recorregut[],int files, int columnes) {
 int i;
 for (i = 0; i < (files*columnes); ++i) {
  printf("(%d,%d) ",recorregut[i].x,recorregut[i].y);
 }
 printf("\n");
}

void mostrarsolucio(POSICIO* recorregut[]) {
 int i;
 for (i = 0; i < (MAX_FILES*MAX_COLUMNES); ++i) {
	printf("(%d,%d) ",recorregut[i]->x,recorregut[i]->y);
 }
}

boolean posiciovalida(POSICIO pos) {
	if ((pos.x>=0)&&(pos.x<8)&&(pos.y>=0)&&(pos.y<8))
		return TRUE;
	else
		return FALSE;
}

/* SUBRUTINA QUE VISUALITZA UNA MATRIU */
void visualitza(int files,int columnes,int *p) {
 int i=0;
 int j=0;
 for (i=0;i<files;i++) {
  for(j=0;j<columnes;j++) {
   printf("\t%d",*p);
    if((i!=files) && (j!=columnes)) {
     p++;
    }
   }
  printf("\n");
 }
}

void visualitza2(int files, int columnes,int *p) {
  int i;
  int j;
  for(i=0; i<files; i++) {
   for(j=0; j<columnes; j++) {
	printf("\t%d",p[i*columnes+j]);
   }
  printf("\n");
  }
 }
/*
void visualitza2(int files,int columnes,int (*p)[col],)
{
 int* q = *p;
 for(int i=0;i<row;i++) {
  for(int j=0;j<col;j++) {
   cout << *q << endl;
 q++;
 }
 }
}
*/

