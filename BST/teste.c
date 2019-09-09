#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "bst.h"

int main(int argc, int argv []){
	int opcoes,n;	
	NO *raiz ;
	raiz = NULL;

	NO * novo;		
	while(1==1){
		novo=NULL;
		scanf("%d",&opcoes);
		switch (opcoes){

		case 2:
			scanf("%d",&n);
		 	raiz = inserir(raiz,n);
			break;

		case 1:
			pre_order(raiz);
			break;

		case 3:
			in_order(raiz);
			break;

		case 4:
			pos_order(raiz);
			break;

		case 8:
			scanf("%d",&n);
			remover(raiz,n);
			break;

		case 6:	
			maiorElemento(raiz);		
			break;
		case 7:
			menorElemento(raiz);
			break;
		case 5:
			printf("%d",alturaArvore(raiz));
			break;

		case 9:
			novo = inserir(novo,-1);
			scanf("%d",&n);
			paiElemento(raiz,n,novo);
			break;

		case 10:
			novo = inserir(novo,-1);
			scanf("%d",&n);
			printf("[%d]",sucessor(raiz,n,novo));
			break;

		case 11:
			novo = inserir(novo,-1);
			scanf("%d",&n);
			printf("[%d]",antecessor(raiz,n,novo));
			break;
		case 999:
			exit(0);
		default:
			break;	
		}
	
	}
	return 0;

}
