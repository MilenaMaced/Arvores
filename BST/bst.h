
#ifndef BST_H
#define BST_H


typedef struct no{
	int valor;
	struct no *esq;
	struct no *dir;
	
}NO;

NO *criar_no(int valor);
NO *inserir(NO *raiz, int valor);
NO *pre_order(NO *arvore);
NO *in_order(NO *arvore);
NO *pos_order(NO *arvore);
NO *remover(NO *arvore, int valor);
void maiorElemento(NO* arvore);
void menorElemento(NO* arvore);
int MAX(int valorA, int valorB);
int altura(NO* arvore);
int alturaArvore(NO* arvore);
NO *paiElemento(NO* arvore,int valor,NO *novo);
int antecessor(NO* arvore,int valor,NO *arv);
int sucessor(NO * arvore,int valor, NO *arv);

#endif


