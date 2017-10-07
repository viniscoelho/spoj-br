/*
	Resolucao:
		Verificar se e possivel chegar um ponto para qualquer outro ponto
		do grafo. Basta verificar se todos vertices estao na mesma componente fortemente
		conexa. Imprimir "S" se sim; "N" caso contrario.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <cstdio>
#define mp make_pair
#define pb push_back
#define MAX 3010
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector< list<int> > graph(MAX);

int m, n, counter, flag;
int visited[MAX], dfs_low[MAX], dfs_num[MAX];

vi S;

void tarjan( int u ){
	dfs_low[u] = dfs_num[u] = counter++;
	S.pb(u);
	visited[u] = true;
	list<int>::iterator li;
	for ( li = graph[u].begin(); li != graph[u].end(); ++li ){
		if ( !dfs_num[*li] ) tarjan(*li);
		if ( visited[*li] )
			dfs_low[u] = min( dfs_low[u], dfs_low[*li] );
	}
	if ( dfs_low[u] == dfs_num[u] ){
		int resp = 0;
        while ( 1 ){
			int vertex = S.back(); S.pop_back();
			resp++;
			if ( u == vertex ) break;
        }
        if ( resp == m ) flag = true;
	}
}

int main(){
	ios::sync_with_stdio(false);
    int de, para, t = 1;
    while ( cin >> m >> n && m + n ){
		flag = false;
		if ( t > 1 ) cout << "\n";
		cout << "Teste " << t++ << "\n";
		for ( int i = 0; i < m; ++i ){
			dfs_num[i] = dfs_low[i] = visited[i] = 0;
			graph[i].clear();
		}
		for ( int i = 0; i < n; ++i ){
			cin >> de >> para;
			graph[de-1].pb(para-1);
		}
		counter = 0;
		tarjan(0);
		if ( flag ) cout << "S\n";
		else cout << "N\n";
    }
       
    return 0;
}
