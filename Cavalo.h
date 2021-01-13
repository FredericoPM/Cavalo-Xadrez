#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
	Posiveis movimentos
		0- Disponivel/Não visitado
		1- Ja visitado ou Indisponivel
		2- Visitado em tentativas anteriores
*/
typedef struct{
	int x, y;
	int movimentos[8];
}Cavalo;
/*======================================================*/
void movimenta(int *x, int *y, int op){
	switch(op){
			case 0:
				*x+=1;
				*y+=2;
			break;

			case 1:
				*x+=1;
				*y-=2;
			break;

			case 2:
				*x-=1;
				*y+=2;
			break;

			case 3:
				*x-=1;
				*y-=2;
			break;

			case 4:
				*x+=2;
				*y+=1;
			break;

			case 5:
				*x+=2;
				*y-=1;
			break;

			case 6:
				*x-=2;
				*y+=1;
			break;

			case 7:
				*x-=2;
				*y-=1;
			break;

		}
}
/*======================================================*/
void start_mov(int mat[][8], Cavalo *c){
	int x, y;
	for(int i=0;i<8;i++){

		x = c->x;
		y = c->y;

		movimenta(&x, &y, i);

		if(y < 0 || x < 0 || y >= 8 || x >= 8)
			c->movimentos[i] = 1;
		else
			if(c->movimentos[i] != 3)
				c->movimentos[i] = mat[x][y];
		
	}
}

void reset_mov(Cavalo *c){
	for(int i=0;i<8;i++)
		c->movimentos[i]=0;
}

/*======================================================*/
void att_mov(int op, Cavalo *c){
	c->movimentos[op] = 3;
}
/*======================================================*/
int escolhe_mov(Cavalo *c, int mat[][8]){
	int op = -1;
	int x;
	int y;
	for(int i=0; i< 2; i++){
		for(int j=0; j<8;j++){

			x = c->x;
			y = c->y;
			movimenta(&x, &y, j);

			if(i == 0 && c->movimentos[j] == 0 && mat[x][y] == 0)
				op = j;
			else if(i == 1 && c->movimentos[j] == 2 && mat[x][y] == 2)
				op = j;
		}
	}

	if(op != -1)
		att_mov(op, c);

	return op;
}
/*======================================================*/
void print_Cavalo(Cavalo c){
	printf("%d - %d\n", c.x, c.y);
	for(int i=0;i<8;i++)
		printf("%d  ", c.movimentos[i]);
	printf("\n");
}