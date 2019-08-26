#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


NO *criar_no(int valor){
	NO * novo = (NO *)malloc(sizeof(NO));
	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

NO *inserir(NO *raiz, int valor){
	
	if(raiz == NULL){
		return criar_no(valor); 	
	}else{
		if(valor > raiz->valor){
			raiz->dir = inserir(raiz->dir,valor);		
		}else{
			raiz->esq = inserir(raiz->esq,valor);		
		}
		return raiz;
	}
}
NO *pre_order(NO *arvore){

	if(arvore!=NULL){

		printf("[%d]",arvore->valor);
		pre_order(arvore->esq);
		pre_order(arvore->dir);
	}
}

NO *in_order(NO *arvore){

	if(arvore!=NULL){
		in_order(arvore->esq);
		printf("[%d]",arvore->valor);
		in_order(arvore->dir);

	}
}

NO *pos_order(NO *arvore){

	if(arvore!=NULL){
		pos_order(arvore->esq);
		pos_order(arvore->dir);
		printf("%d\n",arvore->valor);

	}	
}
/*
void buscarElemento(NO* arvore,int valor){
		if(arvore==NULL){
			return NULL;
		}
		if( valor==arvore->valor){
			printf("%d\n",arvore->valor);
		}else if(valor<arvore->valor){
			buscarElemento(arvore->esq,valor);
		}else if(valor>arvore->valor){
			buscarElemento(arvore->dir,valor);
		}	
}
*/
NO *remover(NO *arvore, int valor){
	if(arvore==NULL){
		return NULL;

	}else if(valor<arvore->valor){
		arvore->esq =remover(arvore->esq,valor);

	}else if(valor>arvore->valor){
		arvore->dir=remover(arvore->dir,valor);

	}else{
		NO * aux = arvore;
		
		//Sem filhos
		if(arvore->esq==NULL && arvore->dir==NULL){
			free(aux);
			arvore=NULL;	

		//Filhos a direita
		}else if(arvore->esq == NULL && arvore->dir!=NULL){
			arvore = arvore->dir ;
			free(aux);

		//Filhos a esquerda
		}else if(arvore->esq!=NULL && arvore->dir==NULL){
			arvore = arvore->esq;
			free(aux);

		//Dois filhos
		}else{
			NO * novo =arvore->esq;
			while(novo->dir!=NULL){
				novo = novo->dir;
			}
			arvore->valor = novo->valor;
			arvore->esq = remover(arvore->esq,novo->valor);
		}
				
	}
	return arvore;
}	
void *maiorElemento(NO* arvore){
	while (arvore->dir!=NULL){
		arvore = arvore->dir;
	}
	printf("[%d]\n",arvore->valor);
}
void *menorElemento(NO* arvore){
	while (arvore->esq!=NULL){
		arvore = arvore->esq;
	}
	printf("[%d]\n",arvore->valor);
}	
int MAX(int valorA, int valorB){
	if(valorA>valorB)
		return valorA;
	else
		return valorB;
		
}
int altura(NO* arvore){
	if(arvore==NULL)
		return 0;
	else
		return 1 + MAX(altura(arvore->esq),altura(arvore->dir));
}
int alturaArvore(NO* arv){
	return altura(arv)+1;
}

NO* paiElemento(NO* arvore,int valor,NO *novo){
	
	if(arvore==NULL){
		printf("-1");
	}else if(arvore!=NULL){
		if(valor > arvore->valor){
			novo->valor = arvore->valor;
			arvore->dir = paiElemento(arvore->dir,valor,novo);
		}else if(valor < arvore->valor){
			novo->valor = arvore->valor;
			arvore->esq = paiElemento(arvore->esq,valor,novo);
		}else{
			printf("%d\n",novo->valor);
		}
	
	}
}
int menor(NO* arv){
	while (arv->esq!=NULL){
		arv = arv->esq;
	}
	return (arv->valor);
}	

NO *antecessor(NO* arvore,int valor,NO* arv){

	/*if(valor==menor(arvore)){
		printf("-1");
		exit(0);
	
	}
	else*/ 
	if(arvore!=NULL){
		arvore->esq = antecessor(arvore->esq,valor,arv);
		if(arvore->valor==valor){
			printf("%d\n",arv->valor);
			exit(0);
		}
		arv->valor = arvore->valor;
		printf("Auxiliar  %d\n",arv->valor);				
		arvore->dir = antecessor(arvore->dir,valor,	arv);
	
	}
}

