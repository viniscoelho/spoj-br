/*
	Resolucao:
		Verificar se e possivel chegar em todos os pontos do grafo
		utilizando um DFS. Se sim, imprimir "normal"; caso contrario
		"falha"
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <list>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int m, n, s = 0;
int graph[110][110], visited = 1;
int visitado[110];

void runDFS( int u ){
	int i;
	for ( i = 0; i < m; i++ )
		if ( graph[u][i] == visited && visitado[i] != visited ){
			visitado[i] = visited, s++;
            runDFS(i);
		}
}

int main(){
	ios::sync_with_stdio(false);
	int de, para, t = 1;
	while ( cin >> m >> n && m + n ){
		cout << "Teste " << t++ << "\n";
		for ( int i = 0; i < n; ++i ){
			cin >> de >> para;
			graph[de-1][para-1] = visited;
			graph[para-1][de-1] = visited;
		}
		s = 0;
		runDFS(0);
		if ( s == m ) cout << "normal\n\n";
		else cout << "falha\n\n";
		visited++;
	}
	return 0;
}
