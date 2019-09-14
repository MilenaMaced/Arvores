#ifndef AVL_H
#define AVL_H

typedef  int  tipo_dado;

typedef struct no {
    int fb;
    tipo_dado valor;
    struct no *esq, *dir;
} no;

no * inserir (no* raiz, tipo_dado elemento, int *cresceu);


no* rotacao_simples_direita(no* pivo);
no* rotacao_simples_esquerda(no* p);
no* rotacao_simples_esquerda_caso_remocao(no *p);
no* rotacao_simples_direita_caso_remocao(no *p);
no * rotacao_dupla_direita(no *p);
no * rotacao_dupla_esquerda(no* p);

no* rotacionar(no* pivo);

void preorder(no* raiz);
void inorder(no* raiz);
void posorder(no* raiz);

no* remover(no* arvore, tipo_dado elemento, int *diminui);

#endif
