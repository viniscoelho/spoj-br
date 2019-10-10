/*
	Resolucao:
		Verificar qual a maior cadeia alimentar pode ser
		obtida. Basta aplicar o algoritmo de tarjan que retornara
		a maior componente fortemente conexa
*/

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAXV 5000

using namespace std;

typedef vector<int> vi;

vector<list<int>> graph(MAXV);
vi S;
int visited[MAXV], dfs_low[MAXV], dfs_num[MAXV];
int counter, m, n, MAX;

void tarjan(int u)
{
    dfs_low[u] = dfs_num[u] = counter++;
    S.pb(u);
    visited[u] = 1;
    list<int>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i) {
        if (!dfs_num[*i])
            tarjan(*i);
        if (visited[*i])
            dfs_low[u] = min(dfs_low[u], dfs_low[*i]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        int resp = 0;
        while (1) {
            int vertex = S.back();
            S.pop_back();
            resp++;
            if (u == vertex)
                break;
        }
        MAX = max(MAX, resp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    string nature, a, b;
    while (cin >> m >> n && m + n) {
        for (int i = 0; i < m; ++i) {
            dfs_num[i] = dfs_low[i] = visited[i] = 0;
            graph[i].clear();
        }
        unordered_map<string, int> chain;
        int t = 0;
        for (int i = 0; i < m; ++i) {
            cin >> nature;
            chain.insert(mp(nature, t++));
        }
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            graph[chain[a]].pb(chain[b]);
            graph[chain[b]].pb(chain[a]);
        }
        counter = 0, MAX = 1;
        for (int k = 0; k < m; k++)
            if (!dfs_num[k])
                tarjan(k);
        cout << MAX << "\n";
    }
    return 0;
}
