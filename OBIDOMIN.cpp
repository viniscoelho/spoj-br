/*
	Resolucao:
		Verificar se o grafo e conexo e se possui caminho euleriano
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#define pb push_back

using namespace std;

vector< list<int> > graph(7);
bool visitado[7];

void runDFS( int u ){
	list<int>::iterator i;
	for ( i = graph[u].begin(); i != graph[u].end(); i++ )
		if ( !visitado[*i] ){
			visitado[*i] = true;
			runDFS(*i);
		}
}

bool has_EulerianPath( int n ){
	if ( n == 1 ) return true;
	int edges = 0, b = 0;
	for ( int i = 0; i < 7; ++i ){
		visitado[i] = false;
		if ( graph[i].size() % 2 == 1 ) edges++;
	}
	while ( graph[b].size() == 0 ) b++;
	runDFS(b);
	for ( int i = 0; i < 7; ++i )
		if ( graph[i].size() > 0 && !visitado[i] ) return false;
		if ( edges > 2 ) return false;
	return true;
}

int main (){
    ios::sync_with_stdio(false);
    int f, x, y, t = 1;
    for ( cin >> f; f != 0; cin >> f ){
        for ( int i = 0; i < f; ++i ){
            cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        if ( !has_EulerianPath( f ) ) cout << "Teste " << t++ << "\nnao\n\n";
        else cout << "Teste " << t++ << "\nsim\n\n";
        for ( int i = 0; i < f; ++i ) graph[i].clear();
    }
    return 0;
}
