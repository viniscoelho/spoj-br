#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define MAXV 1010
#define INF 0x3f3f3f3f

using namespace std;

typedef long long int64;
typedef pair<int, int64> ii;
typedef vector<int> vi;
const double EPS = 1e-10;

int V, resp, ok = 1;
vector<vi> graph;
vi topo;
int degree[MAXV], res[MAXV], weight[MAXV], memo[MAXV][MAXV], visited[MAXV][MAXV];

void topoSort(){
	topo.clear();
	queue<int> bfs;
	for ( int i = 0; i < V; ++i ) if ( !degree[i] ) bfs.push(i);
	while ( !bfs.empty() ) {
		int v = bfs.front();
		bfs.pop(), topo.pb(v);
		vector<int>::iterator it;
		for ( it = graph[v].begin(); it != graph[v].end(); it++ ){
			degree[*it]--;
			if ( !degree[*it] ) bfs.push(*it);
		}
	}
	reverse(topo.begin(), topo.end());
}

void solve( int v, int pos ){
	if ( memo[v][pos] == ok ) return;
	memo[v][pos] = ok;
	for ( int i = pos; i < topo.size(); i++ ){
		if ( visited[topo[i]][v] == ok ){
			res[topo[i]] = max(res[topo[i]], res[v] + weight[topo[i]]);
			solve(topo[i], i+1);
			resp = max(resp, res[topo[i]]);
		}
	}
}

int main(){
	int p, q, to;
	while ( scanf("%d", &V) && V ){
		graph.resize(V);
		resp = -1;
		for ( int i = 0; i < V; ++i ){
			scanf("%d %d", &weight[i], &p);
			res[i] = weight[i];
			degree[i] = p;
			resp = max(resp, res[i]);
			for ( int j = 0; j < p; ++j ){
				scanf("%d", &to);
				visited[to-1][i] = ok;
				graph[to-1].pb(i);
			}
		}
		topoSort();
		for ( int i = 0; i < V; ++i ) solve(topo[i], i);
		printf("%d\n", resp);
		graph.clear(), ok++;
	}
    return 0;
}
