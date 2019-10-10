/*
	Resolucao:
		Problema modelado para fluxo maximo. O algoritmo utilizado foi o de Edmonds-Karp, modificado
		para realizar uma busca em profundidade no grafo
		A chave desse problema e modelar o grafo: cria-se dois vertices, s e t, que e o inicio e final.
		O fluxo a ser bombeado e no sentido dos soldados para os cavalos, ou seja, o objetivo e descobrir o
		numero maximo de soldados que podem montar os cavalos
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAX 220

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef unsigned long long int64;

const int INF = 0x3f3f3f3f;

int a, b, m, n, k, mf, f, s, t;
int visited[MAX], p[MAX], cap[MAX][MAX], check = 1;
vector<list<int>> graph(MAX);

void initialize()
{
    for (int i = 0; i <= t; ++i) {
        for (int j = i; j <= t; ++j)
            cap[i][j] = cap[j][i] = 0;
        cap[i][i] = 0;
        graph[i].clear();
    }
}

void augment(int v, int minEdge)
{
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, cap[p[v]][v]));
        cap[p[v]][v] -= f;
        cap[v][p[v]] += f;
    }
}

void DFS(int u)
{
    if (u == t)
        return;
    list<int>::iterator v;
    for (v = graph[u].begin(); v != graph[u].end(); ++v)
        if (visited[*v] != check && cap[u][*v] > 0) {
            visited[*v] = check;
            p[*v] = u;
            DFS(*v);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    int inst = 1;
    while (cin >> m >> n >> k) {
        cout << "Instancia " << inst++ << "\n";
        s = m + n, t = m + n + 1;
        mf = 0;
        initialize();
        for (int i = 0; i < max(m, n); ++i) {
            if (i < m)
                cin >> cap[i][t];
            if (i < n)
                cap[s][i + m] = 1;
            graph[i].pb(t);
            graph[s].pb(i + m);
        }
        for (int i = 0; i < k; ++i) {
            cin >> a >> b;
            cap[b + m - 1][a - 1] = 1;
            graph[b + m - 1].pb(a - 1);
            graph[a - 1].pb(b + m - 1);
        }
        while (1) {
            for (int i = 0; i <= t; ++i)
                p[i] = -1;
            f = 0;
            DFS(s);
            check++;
            augment(t, INF);
            if (f == 0)
                break;
            mf += f;
        }
        cout << mf << "\n\n";
    }
    return 0;
}