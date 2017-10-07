/*
	Resolucao:
		Alroritmo de grafos, floyd-warshall
		Armazena para cada instancia de k o valor em uma matriz tridimensional
		As queries sao calculadas em O(1)
*/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
int grafo[110][110][110];

int main(){
    int a, m, n, de, para, custo, q, t = 1;
    while ( scanf("%d %d", &n, &m) != EOF ){
		printf("Instancia %d\n", t++);
		for ( int k = 0; k <= n; ++k )
			for ( int i = k; i <= n; ++i ){
				for ( int j = i; j <= n; ++j )
					grafo[k][i][j] = grafo[k][j][i] = INF;
				grafo[k][i][i] = 0;
			}
		for ( int i = 0; i < m; ++i ){
			scanf("%d %d %d", &de, &para, &custo);
			grafo[0][de][para] = min(custo, grafo[0][de][para]);
			grafo[1][de][para] = min(custo, grafo[1][de][para]);
		}
		for ( int k = 1; k <= n; ++k )
			for ( int i = 1; i <= n; ++i )
				for ( int j = 1; j <= n; ++j ){
					if ( grafo[k][i][k] != INF && grafo[k][k][j] != INF )
						grafo[k][i][j] = min(grafo[k][i][j], grafo[k][i][k] + grafo[k][k][j]);
					if ( k+1 <= n ) grafo[k+1][i][j] = grafo[k][i][j];
				}
		scanf("%d", &q);
		for ( int x = 0; x < q; ++x ){
			scanf("%d %d %d", &de, &para, &a);
			if ( grafo[a][de][para] != INF ) printf("%d\n", grafo[a][de][para]);
			else printf("-1\n");
		}
		printf("\n");
    }
    return 0;
}
