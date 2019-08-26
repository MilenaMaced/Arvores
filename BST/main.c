#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "bst.c"
#include "bst.h"

int main(int argc, int argv []){
	int opcoes,n;	

/*
	while(1==1){
		printf("\n1.Inserir \n2.Exibir Pre-order \n3.Exibir In-order\n4.Exibir Pos-order\n6.Deletar\n999.Sair\n");
		scanf("%d",&opcoes);

		switch (opcoes){
		case 1:
			scanf("%d",&n);
		 	raiz = inserir(raiz,n);
			break;
		case 2:
			pre_order(raiz);
			break;
		case 3:
			in_order(raiz);
			break;
		case 4:
			pos_order(raiz);
			break;
		case 5:
			scanf("%d",&n);
			remover(raiz,n);
			break;
		case 6:
			
			break;

		case 999:
			exit(0);
		default:
			printf("Fim\n");
			break;	
		}
		
	}
*/		

	NO * raiz;
	raiz = NULL;
	raiz = inserir(raiz,8);
	raiz = inserir(raiz,3);
	raiz = inserir(raiz,1);
	raiz = inserir(raiz,6);
	raiz = inserir(raiz,4);
	raiz = inserir(raiz,7);
	raiz = inserir(raiz,10);
	raiz = inserir(raiz,14);
	raiz = inserir(raiz,13);
	raiz = inserir(raiz,12);

	antecessor(raiz,8,raiz);

	/*
	printf("PRE_ORDER:\n");
	pre_order(raiz);	

	
	printf("IN_ORDER:\n");
	
	
	printf("POS_ORDER:\n");
	pos_order(raiz);

	//buscarElemento(raiz,14);
	remover(raiz,6);
	printf("Pre_ORDER:\n");
	pre_order(raiz);
	maiorElemento(raiz);
	menorElemento(raiz);
	printf("%d",alturaArvore(raiz));
	//NO * novo=(NO*)malloc(sizeof(NO));
	
	//paiElemento(raiz,6,raiz);
	//in_order(raiz);

	antecessor(raiz,9,raiz);
*/
	return 0;

}
