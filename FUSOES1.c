/*
	Resolucao:
		Uso de grafos, conceito de union-join
		Verificar se dois bancos pertencem ao mesmo conjunto.
*/

#include <stdio.h>

typedef struct no {
       int pai;
       int rank;
}Tno;

Tno pset[100100];

void Link (int x, int y){
	if ( pset[x].rank > pset[y].rank ) pset[y].pai = x;
	else{
		pset[x].pai = y;
		if ( pset[x].rank == pset[y].rank )
			pset[y].rank = pset[y].rank+1;
	}
}

int findSet ( int x ){
	while ( pset[x].pai != x )
		x = pset[x].pai;
	return x;	
}

void UnionSet ( int x, int y ){
	Link ( findSet(x), findSet(y) );
}

bool isSameSet ( int x, int y ){
	return findSet(x) == findSet(y);
}

int main(){
    int i, n, m, x, y;
	char c;
    scanf("%d %d", &n, &m);
    inicializa(n);
    for ( i = 0; i < m; ++i ){
        scanf(" %c", &c);
        if ( c == 'F' ){
			scanf("%d %d", &x, &y);
			unionSet(x-1, y-1);
        }
        else{
			scanf("%d %d", &x, &y);
			if ( findSet(x-1) == findSet(y-1) ) printf("S\n");
			else printf("N\n");
        }
    }
    return 0;
}
