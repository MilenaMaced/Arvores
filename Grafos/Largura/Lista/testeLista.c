#include <stdio.h>
#include <stdlib.h>
#include "grafoLista.h"

int main(int argc, char * argv[]) {
	grafo g;
	char arquivo[15] = "grafo";

	criarGrafo(&g, arquivo);
	lerArquivo(&g);
	lerVertices(&g);
	lerArestas(&g);
	imprimirListaAdj(&g);
    
    //BUSCA EM LARGURA
	char v;
	scanf("%c", &v);
	vertice* vert = procurarVertice(&g, v);
	buscaLargura(&g, vert);
	exit(0);
}
