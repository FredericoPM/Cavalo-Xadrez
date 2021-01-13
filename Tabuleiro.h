#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIMENSAO 8
/*======================================================*/
void start_tabuleiro(int mat[][8]){
	for(int i=0;i<DIMENSAO;i++)
		for(int j=0; j<DIMENSAO;j++)
			mat[i][j] = 0;
}
/*======================================================*/
void att_tabuleiro(Cavalo c, char status, int mat[][8]){
	if(status == 'R'){
		mat[c.x][c.y] = 2;
	}else{
		mat[c.x][c.y] = 1;
	}
}
/*======================================================*/
void print_tabuleiro(int mat[][8]){
	for(int i=0;i<DIMENSAO;i++){
		for(int j=0; j<DIMENSAO;j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}
/*======================================================*/
bool checa_tabuleiro(int mat[][8]){
	int aux = 0;
	for(int i=0;i<DIMENSAO;i++)
		for(int j=0; j<DIMENSAO;j++)
			if(mat[i][j]==1) aux++;

	return aux == 64;
}