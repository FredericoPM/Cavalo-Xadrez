#include "Cavalo.h"
#include "Pilha.h"
#include "Tabuleiro.h"

int main(){

	int Tabuleiro[DIMENSAO][DIMENSAO];
	start_tabuleiro(Tabuleiro);


	Pilha p = new_p();

	Cavalo c;
	/*
	Posicao inicial do cavalo
	*/
	c.x = 7;
	c.y = 2;
	/*
	*/
	start_mov(Tabuleiro, &c);

	att_tabuleiro(c, 'A', Tabuleiro);

	int op;

	while(!checa_tabuleiro(Tabuleiro)){
	//for(int i=0;i<5;i++){
		op = escolhe_mov(&c, Tabuleiro);

		if(op == -1){
			c = pull(&p);
			att_tabuleiro(c, 'R', Tabuleiro);
		}else{
			push(&p, c);

			movimenta(&c.x, &c.y, op);
			reset_mov(&c);
			start_mov(Tabuleiro, &c);

			att_tabuleiro(c, 'A', Tabuleiro);
		}
	}
	push(&p, c);
	printf("Pilha de movimentos (como é uma pilha o primeiro movimento a aparecer foi o ultimo a ser feito)\n");
	print_Pilha(p);
}