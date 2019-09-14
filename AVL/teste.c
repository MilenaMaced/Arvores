#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int opcao;
    no * arvore=NULL;

    while(1==1) {
        scanf("%d", &opcao);
        switch(opcao) {
            int n;
            int flag;

            case 1:
                scanf("%d", &n);
                arvore = inserir(arvore, n, &flag);        
                break;
            
            case 2:
                preorder(arvore);
                printf("\n");                    
                break;

            case 3:
                scanf("%d", &n);
                arvore = remover(arvore, n, &flag);
                break;
            
            case 999:
                exit(0);
        }    
    }
}
