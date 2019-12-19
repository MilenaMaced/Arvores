#ifndef RB_H
#define RB_H

enum cor {VERMELHO, PRETO, DUPLO_PRETO};

typedef  int  tipo_dado;

typedef struct no {
    enum cor c;
    tipo_dado valor;
    struct no *esq;
    struct no *dir;
    struct no *pai;
} no;

void inserir (no** raiz, tipo_dado elemento);
void ajustar(no* n, no** raiz);

int cor(no* no);
int eh_esquerdo(no* no);
int eh_raiz(no* no);
no* tio (no* n);

void preorder(no* raiz);

int eh_nulo(no* elemento);
int maior_elemento(no* raiz);

void remover(int elemento, no **raiz);
void reajustar(no ** raiz, no * n);

void caso2(no ** raiz, no * n);
void caso2_simetrico(no ** raiz, no * n);

void caso3(no ** raiz, no * n);
void caso3_simetrico(no ** raiz, no * n);

void caso4(no ** raiz, no * n);
void caso4_simetrico(no ** raiz, no * n);

void caso5(no ** raiz, no * n);
void caso5_simetrico(no ** raiz, no * n);

void caso6(no ** raiz, no * n);
void caso6_simetrico(no ** raiz, no * n);

#endif