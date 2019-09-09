#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

no* rotacao_simples_direita(no* p) {

    no* u = p->esq;
    
    u->fb = 0;
    p->fb = 0;
    p->esq = u->dir;
    u->dir = p;
    
    return u;
}
no* rotacao_simples_esquerda(no* p){

    
    no * u = p->dir;
    
    u->fb = 0;
    p->fb = 0;
    p->dir = u->esq;
    u->esq = p;
    
    return u;
    
}
no* rotacao_simples_esquerda_caso_remocao(no *p){
    
    no * u = p->dir;
    
    u->fb = -1;
    p->fb = 1;
    p->dir = u->esq;
    u->esq = p;
    return u;
}

no* rotacao_simples_direita_caso_remocao(no *p){
    
    no* u = p->esq;
    
    u->fb = 1;
    p->fb = -1;
    p->esq = u->dir;
    u->dir = p;
    return u;
}
no * rotacao_dupla_direita(no *p){
    
    
    no * u = p->esq;
    no * v = u->dir;

    // Rotação à esquerda    
    u->dir = v->esq;
    v->esq = u;
    p->esq = v;
    
    //Rotação á direita
    p->esq=v->dir;
    v->dir = p;
    
    //Atualizando os fatores de balanço
    if(v->fb == 0){ 

        u->fb = 0;
        p->fb=0;
        v->fb=0;
    }
    else if(v->fb==-1){

        u->fb = 0;
        v->fb = 0;
        p->fb=1;

    }
    else {

        u->fb = -1;
        v->fb = 0;
        p->fb=0;

    }
     return v;
}

no * rotacao_dupla_esquerda(no* p){
    
    no * u = p->dir;
    no * v = u->esq;

    //Rotação Direita
    u->esq = v->dir;
    v->dir = u;
    p->dir = v;

    //Rotção esquerda
    p->dir = v->esq;
    v->esq = p;
    
    //Atualizando os fatores de balanço
    if(v->fb==0){  
        u->fb = 0;
        v->fb = 0;
        p->fb=0;
    
    }    
    else if(v->fb==-1){  

        u->fb = 1;
        v->fb = 0;
        p->fb= 0;
    }   
     else{  
        u->fb = 0;
        v->fb = 0;
        p->fb=-1;
    }
        return v;
}
//Rotações
no* rotacionar(no* p) {
    
    if(p->fb == -2 && p->esq->fb == -1) { 
        return rotacao_simples_direita(p);
    }
    else if(p->fb == 2 && p->dir->fb == 1) {
        return rotacao_simples_esquerda(p);
    }
    else if(p->fb== -2 && p->esq->fb == +1) {
        return rotacao_dupla_direita(p);
    }
    else if(p->fb== 2 && p->dir->fb == -1){
        return rotacao_dupla_esquerda(p); 
    }
    else if(p->fb == 2 && p->dir->fb == 0){
        return rotacao_simples_esquerda_caso_remocao(p);
    }
    else if(p->fb == -2 && p->esq->fb == 0){
        return rotacao_simples_direita_caso_remocao(p);
    }
}


no * inserir (no* raiz, tipo_dado elemento, int *cresceu){
    
    if(raiz == NULL) {
        no *novo = (no *) malloc(sizeof(struct no));
        novo->valor = elemento;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->fb = 0;
        *cresceu = 1;
        return novo;

    } 
    else {
        //Inserir lado direito
        if(elemento > raiz->valor) {
            raiz->dir = inserir(raiz->dir, elemento, cresceu);
            if(*cresceu) {
                switch(raiz->fb) {
                    case -1:
                        raiz->fb = 0;
                        *cresceu = 0;
                        break;
                    case 0:
                        raiz->fb = 1;
                        *cresceu = 1;
                        break;
                    case 1:
                        raiz->fb = 2;
                        *cresceu = 0;
                        return rotacionar(raiz);
                        break;
                    }

            }
                
           }
           else {
               
                //Inserir lado esquerdo
                raiz->esq = inserir(raiz->esq, elemento, cresceu);
                
                if(*cresceu) {
                    switch(raiz->fb) {
                        case -1: 
                            raiz->fb = -2;
                            *cresceu = 0;
                            return rotacionar(raiz);
                        case 0:
                            raiz->fb = -1;
                            *cresceu = 1;
                            break;
                        case 1:
                            raiz->fb = 0;
                            *cresceu = 0;
                            break;
                       }
                }
           }
           return raiz;
    }
}

//Imprimir a árvore
void preorder(no* raiz){
    if(raiz != NULL){
        printf("[%d, %d]", raiz->valor, raiz->fb);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}


void inorder(no* raiz){
    if(raiz == NULL) ;
    else {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(no* raiz){
    if(raiz == NULL) ;
    else {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}


no* remover(no* arvore, tipo_dado elemento, int *diminui) {
	
    if(arvore==NULL){
		return NULL;

	}
    else if(elemento<arvore->valor){
	
    	arvore->esq =remover(arvore->esq,elemento, diminui);
        if(*diminui) {
            switch(arvore->fb) {
                case -1:
                    arvore->fb = 0;
                    *diminui = 1;
                    break;
                case 0:
                    arvore->fb = 1;
                    *diminui = 0;
                    break;
                case 1:
                    arvore->fb = 2;
                    if(arvore->dir->fb==0){
                        *diminui = 0;
                    }
                    else{
                        *diminui = 1;
                    }
                    return rotacionar(arvore);
                    break;
            }

        }
            
	}
    else if(elemento>arvore->valor){
	
    	arvore->dir=remover(arvore->dir,elemento, diminui);
        if(*diminui) {
            switch(arvore->fb) {
                case -1: 
                    arvore->fb = -2;
                    if(arvore->esq->fb==0){
                        *diminui = 0;
                    }
                    else{
                        *diminui = 1;
                    }
                    return rotacionar(arvore);
            
                case 0:
                    arvore->fb = -1;
                    *diminui = 0;
                    break;
                case 1:
                    arvore->fb = 0;
                    *diminui = 1;
                    break;
            }
        }
	}
    else{
		no * aux = arvore;
        *diminui=1;
		
		//Sem filhos
		if(arvore->esq==NULL && arvore->dir==NULL){
			free(aux);
			arvore=NULL;
           
		//Filhos a direita
		}
        else if(arvore->esq == NULL && arvore->dir!=NULL){
			arvore = arvore->dir ;
			free(aux);
                
          
		//Filhos a esquerda
		}
        else if(arvore->esq!=NULL && arvore->dir==NULL){
		    arvore = arvore->esq;
		    free(aux);
            
                
        //Dois filhos
		}
        else{
			no * novo =arvore->esq;
			while(novo->dir!=NULL){
				novo = novo->dir;
			}
			arvore->valor = novo->valor;
			arvore->esq = remover(arvore->esq,novo->valor, diminui);
            if(*diminui) {
                switch(arvore->fb) {
                    case -1:
                        arvore->fb = 0;
                        *diminui = 1;
                        break;
                    case 0:
                        arvore->fb = 1;
                        *diminui = 0;
                        break;
                    case 1:
                        arvore->fb = 2;
                        if(arvore->dir->fb==0){
                            *diminui = 0;
                        }
                        else{
                            *diminui = 1;
                        }
                        return rotacionar(arvore);
                        break;
                    }
            }
            
		}
	}
	return arvore;
}	