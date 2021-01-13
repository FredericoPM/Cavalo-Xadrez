#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula{
	Cavalo dado;
	struct Celula *ant;
}Celula;

typedef struct{
	Celula *topo;
	int tam;
}Pilha;
/*===================================================================*/
Pilha new_p(){
	Pilha p;
	p.topo = NULL;
	p.tam = 0;
	return p;
}
/*===================================================================*/
bool is_empty(Pilha p){
	return p.tam == 0;
}
/*===================================================================*/
void push(Pilha *p, Cavalo dado){

	Celula *nova_cel = (Celula*)malloc(sizeof(Celula));

	nova_cel->dado = dado;
	nova_cel->ant = p->topo;

	p->topo = nova_cel;

	p->tam++;
}
/*===================================================================*/
Cavalo pull(Pilha *p){
	if(!is_empty(*p)){
		Celula *removida = p->topo;
		Cavalo dado = removida->dado;

		p->topo = p->topo->ant;

		free(removida);

		p->tam--;

		return dado;
	}
}
/*===================================================================*/
void print_Pilha(Pilha p){
	Celula *aux = p.topo;
	if(!is_empty(p)){
		do{
			printf("%d", aux->dado.x+1);
			switch(aux->dado.y){
				case 0:
					printf("A\n");
				break;
				case 1:
					printf("B\n");
				break;
				case 2:
					printf("C\n");
				break;
				case 3:
					printf("D\n");
				break;
				case 4:
					printf("E\n");
				break;
				case 5:
					printf("F\n");
				break;
				case 6:
					printf("G\n");
				break;
				case 7:
					printf("H\n");
				break;
			}
			aux = aux->ant;
		}while(aux != NULL);
	}
}