#include "rb.h"
#include <stdlib.h>
#include <stdio.h>

void inserir(no ** raiz,tipo_dado valor){
    no * temp, *pai, *novo;
    temp = *raiz;
    pai = NULL;
    
    while(temp!=NULL){
        
        pai = temp;

        if(valor> temp->valor){
            temp = temp->dir;
        }
        else{
            temp = temp->esq;
        }
    }
    novo = (no*)malloc(sizeof(struct no));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->c = VERMELHO;
    novo->pai = pai;

    if(*raiz!=NULL){
        if(valor>pai->valor){
            pai->dir = novo;
        }
        else{
            pai->esq = novo;
        }
    }
    else{
        *raiz = novo;
    }
    ajustar(novo,raiz);

}
int cor(no *no){
    if(no==NULL || no->c==PRETO)
        return PRETO;
    else
        return VERMELHO;
}
int eh_raiz(no* no){
    if(no->pai == NULL)
        return 1;
    else
        return 0;
}

int eh_esquerdo(no* no){
    if(no == no->pai->esq)
        return 1;
    else
        return 0;
}
int eh_direito(no*no){
    if(!eh_esquerdo(no)){
        return 1;
    }
	else{
        return 0;
    }

}
no* tio(no*no){
    if(eh_esquerdo(no->pai)){
        return no->pai->pai->dir;
    }
    else{
        return no->pai->pai->esq;
    }
}
void preorder(no* raiz){
    if(raiz == NULL) ;
    else {
        if(raiz->c == PRETO){
            printf("P");
    		printf("\x1b[30m[%d]\x1b[0m", raiz->valor);
        }
		else{
            printf("V");
    		printf("\x1b[31m[%d]\x1b[0m", raiz->valor);            
        }
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}
void rotacao_simples_esquerda(no **raiz,no  *n){

    no * p = n->pai->pai;
    no * u = n->pai;
    no * t2 = u->esq;

    p->dir = t2;
    if(t2!=NULL){
        t2->pai = p;
    }
    u->esq = p;

    u->c = PRETO;
    p->c =VERMELHO;

    
    u->pai = p->pai;
    if(p->pai!=NULL){
        if(eh_esquerdo(p)){
            p->pai->esq = u;
        }
		else{
            p->pai->dir = u;
        }
    }
    else{
        u->pai=NULL;
        *raiz = u;
    }
    p->pai = u;
}  
void rotacao_simples_direita(no ** raiz, no *n){
    no * p = n->pai->pai;
    no * u = n->pai;
    no * t2 = u->dir;

    p->esq = t2;
    if(t2!=NULL){
        t2->pai = p;
    }
    u->dir = p;

    u->c = PRETO; 
    p->c = VERMELHO;

    u->pai = p->pai;
    if(p->pai!=NULL){
        if(eh_esquerdo(p)){
            p->pai->esq = u;
        }
		else{
            p->pai->dir = u;
        }
    }
    else{
        u->pai=NULL;
        *raiz = u;
    }
    p->pai = u;
}
void rotacao_dupla_esquerda(no ** raiz, no* n){

    no * p = n->pai->pai;
    no * u = n->pai;
    no * v = n;
    no * t2 = v->esq;
    no * t3 = v->dir;
    
    //Rotacao simple direita
    u->esq = t2;
    if(t2!=NULL){
       t2->pai = u;
    }
    v->dir = u;
    u->pai = v;

    //Rotacao a  esquerda

    p->dir = t3;
    if(t3!=NULL){
        t3->pai = p;
    }
    v->esq = p;
    v->pai = p->pai;


    v->c = PRETO;
    p->c = VERMELHO;

   	if(p->pai!=NULL){
        if(eh_esquerdo(p)){
            p->pai->esq = v;
        }
		else{
            p->pai->dir = v;
        }
    }
    else{
        v->pai=NULL;
        *raiz = v;
    }
    p->pai = v;
}
void rotacao_dupla_direita(no ** raiz, no* n){

    no * p = n->pai->pai;
    no * u = n->pai;
    no * v = n;
    no * t2 = v->esq;
    no * t3 = v->dir;
    
    //Rotacao simple direita
    u->dir = t2;
    if(t2!=NULL){
       t2->pai = u;
    }
    v->esq = u;
    u->pai = v;

    //Rotacao a  esquerda

    p->esq = t3;
    if(t3!=NULL){
        t3->pai = p;
    }
    v->dir = p;
    v->pai = p->pai;


    v->c = PRETO;
    p->c = VERMELHO;

    if(p->pai!=NULL){
        if(eh_esquerdo(p)){
            p->pai->esq = v;
        }else{
            p->pai->dir = v;
        }
    }
    else{
        v->pai=NULL;
        *raiz = v;
    }
    p->pai = v;
}

void ajustar(no* n, no** raiz){
    if(eh_raiz(n)){
        n->c = PRETO;
        return;
    }
    if(n->pai->c == VERMELHO){
        if(cor(tio(n))==VERMELHO){
            n->pai->c = PRETO;
            tio(n)->c = PRETO;
            n->pai->pai->c = VERMELHO;
            ajustar(n->pai->pai,raiz);
            return; 
        } 
    	else if(eh_direito(n)&&eh_direito(n->pai)){
            rotacao_simples_esquerda(raiz,n);
            return;
        }
      	else if(eh_esquerdo(n)&&eh_esquerdo(n->pai)){
            rotacao_simples_direita(raiz,n);
            return;
        }
      	else if(eh_esquerdo(n)&&eh_direito(n->pai)){
            rotacao_dupla_esquerda(raiz,n);
            return;
        }
     	else if(eh_direito(n)&&eh_esquerdo(n->pai)){
            rotacao_dupla_direita(raiz,n);
            return;
        }
    }
}

int eh_nulo(no* valor){
	return (valor->pai != NULL && valor->valor == 0  && valor->esq == NULL && valor->dir == NULL && valor->c == DUPLO_PRETO);
}

int maior_valor(no* raiz) {
	if(raiz == NULL){
		return -1;
	}
	if(raiz->dir == NULL){
		return raiz->valor;
	}
	else{
		return maior_valor(raiz->dir);
	}
}

void remover(int valor, no **raiz) {
	no *temp, *pai;
    temp = *raiz;
    pai = NULL;
	
	while(temp != NULL && temp->valor != valor) {
        pai = temp;
        if(valor > temp->valor) {
           	temp = temp->dir;
        } 
		else {
        	temp = temp->esq;
        }
    }
    if(temp == NULL){
        return ;
	}

    if(temp->esq != NULL && temp->dir != NULL) {
        temp->valor = maior_valor(temp->esq);
        remover(temp->valor, &temp->esq);
        return;
    }
    if(temp->esq != NULL && temp->dir == NULL) {
       	temp->valor = temp->esq->valor;
        temp->c = PRETO;
		remover(temp->valor, &temp->esq);
		return;
    }
    if(temp->dir != NULL && temp->esq == NULL) {
       	temp->valor = temp->dir->valor;
        temp->c = PRETO;
		remover(temp->valor, &temp->dir);
		return;
    }
	if(temp->c == VERMELHO) {
        if(eh_esquerdo(temp)) {
            temp->pai->esq = NULL;
        } 
		else {
            temp->pai->dir = NULL;  
        }
        return ;          
    }

	temp->valor = 0;
	temp->c = DUPLO_PRETO;		
    
	if(eh_esquerdo(temp)) {
        temp->pai->esq = NULL;
    }
	else {
        temp->pai->dir = NULL;
    }
	
	reajustar(raiz, temp);
}


void reajustar(no ** raiz, no * n) {
    //Caso 1 - duplo preto é raiz
    if(eh_raiz(n)) {
		*raiz = NULL;	
	}
	else{
        n->c = PRETO;
    }
    return;

    //Caso 2
    if(eh_esquerdo(n)){
		if(eh_nulo(n)){
			if(n->pai->c == PRETO && n->pai->dir->c == VERMELHO && n->pai->dir->dir->c == PRETO && n->pai->dir->esq->c == PRETO){			
				 caso2(raiz, n);		
			    }	
		    }
	    return;			
    }
	//Caso 2 simetrico
	if(eh_direito(n)){
		if(eh_nulo(n)){
			if(n->pai->c == PRETO && n->pai->esq->c == VERMELHO && n->pai->esq->esq->c == PRETO && n->pai->esq->dir->c == PRETO){
				caso2_simetrico(raiz, n);
			}
		}
		return;
	}

    //Caso 3
    if(eh_esquerdo(n)){
		if(eh_nulo(n)){
			if(n->pai->c == PRETO && n->pai->dir->c == PRETO && n->pai->dir->dir->c == PRETO && n->pai->dir->esq->c == PRETO){
				caso3(raiz,n);
			}	
		}
		return;
    	}

	//Caso 3 simetrico
	if(eh_direito(n)){
		if(eh_nulo(n)){
			if(n->pai->c == PRETO && n->pai->esq->c == PRETO && n->pai->esq->esq->c == PRETO && n->pai->esq->dir->c == PRETO){
				caso3_simetrico(raiz, n);
			}	
		}
		return;
    	}


    //Caso 4
    if(eh_esquerdo(n)){
		if(eh_nulo(n)){
			if(n->pai->c == VERMELHO && n->pai->dir->c == PRETO && n->pai->dir->dir->c == PRETO && n->pai->dir->esq->c == PRETO){
				caso4(raiz, n);			
			}
		}
		return;
    }

	//Caso 4 simetrico
	if(eh_direito(n)){
		if(eh_nulo(n)){
			if(n->pai->c == VERMELHO && n->pai->esq->c == PRETO && n->pai->esq->esq->c == PRETO && n->pai->esq->dir->c == PRETO){
				caso4_simetrico(raiz, n);
			}
		}
		return;
    }

    //Caso 5
    if(eh_esquerdo(n)){
   		if(eh_nulo(n)){
			if(n->pai->dir->c == PRETO && n->pai->dir->esq->c == VERMELHO && n->pai->dir->dir->c == PRETO){
				caso5(raiz, n);
			}
		}
		return;
    }

	//Caso 5 simetrico
    if(eh_direito(n)){
   		if(eh_nulo(n)){
			if(n->pai->esq->c == PRETO && n->pai->esq->dir->c == VERMELHO && n->pai->esq->esq->c == PRETO){
				caso5_simetrico(raiz, n);
			}
		}
		return;
    }
	
    //Caso 6
    if(eh_esquerdo(n)){
		if(eh_nulo(n)){
			if(n->pai->dir->c == PRETO && n->pai->dir->dir->c == VERMELHO){
				caso6(raiz, n);
			}
		}
		return;
   	}

	//Caso 6 simetrico
    if(eh_direito(n)){
		if(eh_nulo(n)){
			if(n->pai->esq->c == PRETO && n->pai->esq->esq->c == VERMELHO){
				caso6_simetrico(raiz, n);
			}
		}
		return;
   	}
}

void caso2(no ** raiz, no * n){
	no  *p,*aux;
	p = n->pai;
	aux = p->dir;
	
	int posicao_pivo_esq = eh_esquerdo(p);
	
	p->dir = aux->esq;
	aux->esq = p;
	
	aux->pai = p->pai;
	
	if(p->dir != NULL){
		p->dir->pai = p;
	}	
	p->pai = aux;

	p->c = VERMELHO;
	aux->c = PRETO;
	
	if(eh_raiz(aux)){
		*raiz = aux;
	}
	else{
		if(posicao_pivo_esq){
			aux->pai->esq = aux;
		}
		else{
			aux->pai->dir = aux;
		}
	}
}

void caso2_simetrico(no ** raiz, no * n){
	no  *p,*aux;
	p = n->pai;
	aux = p->esq;
	
	int posicao_pivo_esq = eh_direito(p);
	
	p->esq = aux->dir;
	aux->dir = p;
	
	aux->pai = p->pai;
	
	if(p->esq != NULL){
		p->esq->pai = p;
	}
		p->pai = aux;

	p->c = VERMELHO;
	aux->c = PRETO;
	
	if(eh_raiz(aux)){
		*raiz = aux;
	}
	else{
		if(posicao_pivo_esq){
			aux->pai->esq = aux;
		}
		else{
			aux->pai->dir = aux;
		}
	}	
}

void caso3(no ** raiz, no * n){
	if(n->dir == NULL && n->esq == NULL){
		n->c = VERMELHO;
	}
	else{
		n->c = PRETO;
	}
	n->pai->c = DUPLO_PRETO;
	n->pai->dir->c = VERMELHO;	
}

void caso3_simetrico(no** raiz, no* n){
	if(n->dir == NULL && n->esq == NULL){
		n->c = VERMELHO;
	}
	else{
		n->c = PRETO;
	}
	n->pai->c = DUPLO_PRETO;
	n->pai->esq->c = VERMELHO;
}

void caso4(no ** raiz, no * n){
	if(n->dir == NULL && n->esq == NULL){
		n->c = VERMELHO;
	}
	else{
		n->c = PRETO;
	}	
	n->pai->c = PRETO;
	n->pai->dir->c = VERMELHO;
}

void caso4_simetrico(no** raiz, no* n){
	if(n->dir == NULL && n->esq == NULL){
		n->c = VERMELHO;
	}
	else{
		n->c = PRETO;
	}
	n->pai->c = PRETO;
	n->pai->esq->c = VERMELHO;
}

void caso5(no ** raiz, no* n){
	no* p,*aux;
	p = n->pai;
	aux = p->dir;
	
	p->dir = aux->esq;
	aux->esq =aux->esq->dir;
	p->dir->dir = aux;
	
	p->dir->pai = p;
	p->dir->dir->pai = p->dir;

	p->dir->c = PRETO;
	p->dir->dir->c = VERMELHO;
}

void caso5_simetrico(no ** raiz, no* n){
	no* p,*aux;
	p = n->pai;
	aux = p->esq;
	
	p->esq = aux->dir;
	aux->dir = aux->dir->esq;
	p->esq->esq = aux;
	
	p->esq->pai = p;
	p->esq->esq->pai = p->esq;
	
	p->esq->c = PRETO;
	p->esq->esq->c = VERMELHO;
}

void caso6(no** raiz, no* n){
	no* p,*aux;
	p = n->pai;
	aux = p->dir;
		
	int posicao_pivo_esq = eh_esquerdo(p);
	
	p->dir = aux->esq;
	aux->esq = p;
	aux->pai = p->pai;
	
	if(p->dir!=NULL){
		p->dir->pai = p;
	}
	p->pai = aux;
	
	aux->c = p->c;
	p->c = PRETO;
	aux->dir->c = PRETO;
	if(n->dir == NULL && n->esq == NULL){
		p->esq->c = VERMELHO;
	}
	else{
		p->esq->c = PRETO;
	}
	

	if(eh_raiz(aux)){
		*raiz = aux;	
	}
	else{
		if(posicao_pivo_esq){
			aux->pai->esq = aux;
		}
		else{
			aux->pai->dir = aux;
		}
	}
}

void caso6_simetrico(no** raiz, no* n){
	no *p,*aux;
	p = n->pai;
	aux = p->esq;
	
	int posicao_pivo_esq = eh_esquerdo(p);
	
	p->esq = aux->dir;
	aux->dir = p;
	
	aux->pai = p->pai;
	
	if(p->esq!=NULL){
		p->esq->pai = p;
	}

	p->pai = aux;

	aux->c = p->c;
	p->c = PRETO;
	aux->esq->c = PRETO;
	
	if(n->dir == NULL && n->esq == NULL){
		p->dir->c = VERMELHO;
	}
	else{
		p->dir->c = PRETO;
	}
	if(eh_raiz(aux)){		
		*raiz = aux;		
	}
	else{
		if(posicao_pivo_esq){
			aux->pai->esq = aux;
		}
		else{
			aux->pai->dir = aux;
		}
	}
}