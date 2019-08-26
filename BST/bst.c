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
void maiorElemento(NO* arvore){
	while (arvore->dir!=NULL){
		arvore = arvore->dir;
	}
	printf("[%d]\n",arvore->valor);
}
void menorElemento(NO* arvore){
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
			printf("[%d]",novo->valor);
		}
	
	}
}

int antecessor(NO* arvore,int valor,NO* arv){
	if(arvore==NULL){
		return -1;
	}else if(arvore!=NULL){
		if(valor< arvore->valor){
			antecessor(arvore->esq,valor,arv);
		}
		else if(valor> arvore->valor){
			if (arvore->valor > arv->valor){
				arv->valor = arvore->valor;	
			}
			antecessor(arvore->dir,valor,arv);
		}else{
			if(arvore->esq == NULL){
				return arv->valor;
			}else {
				if(arv->valor > arvore->esq->valor){
					return arv->valor;
				}else{
					arvore =arvore->esq;
					while (arvore->dir!=NULL){
						arvore = arvore->dir;
					}
					return arvore->valor;
				}
			}
		}

	}
}
int sucessor(NO * arvore,int valor, NO *arv){
	if(arvore==NULL){
		return -1;
	}else{

		if(arv->valor < valor){
			arv->valor = arvore->valor;
		}
		if(valor<arvore->valor){
			if(arvore->valor < arv->valor){
				arv->valor = arvore->valor;
			}
			 sucessor(arvore->esq,valor,arv);
		}else if(valor>arvore->valor){
			sucessor(arvore->dir,valor,arv);
		}else{
			if(arvore->dir == NULL && arv->valor <= valor){
				return -1;
			}else if(arvore->dir == NULL){
				return arv->valor;
			}else if(arv->valor <= valor){
				arvore = arvore->dir;
				while (arvore->esq!=NULL){
					arvore = arvore->esq;
				}
				return arvore->valor;
			}else{
				if (arvore->dir->valor < arv->valor){
				arvore = arvore->dir;
					while (arvore->esq!=NULL){
						arvore = arvore->esq;
					}
				return arvore->valor;
				} else{
					return arv->valor;
				}
			}
		}
	}
}

