/*
	Resolucao:
		Descobrir qual a maior distancia que pode-se percorrer na arvore
		Realizar dois BFS para isso
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

int visited[1000000];
int d, t, m, n, v = 1, MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    vector<list<int>> graph(t);
    queue<ii> bfs;
    for (int i = 0; i < t - 1; ++i) {
        cin >> m >> n;
        if (bfs.empty())
            bfs.push(mp(0, m - 1));
        graph[m - 1].pb(n - 1);
        graph[n - 1].pb(m - 1);
    }
    list<int>::iterator i;
    while (!bfs.empty()) {
        ii a = bfs.front();
        bfs.pop();
        if (MAX < a.first) {
            MAX = a.first;
            d = a.second;
        }
        visited[a.second] = v;
        for (i = graph[a.second].begin(); i != graph[a.second].end(); i++)
            if (visited[*i] != v) {
                bfs.push(mp(a.first + 1, *i));
                visited[*i] = v;
            }
    }
    bfs.push(mp(0, d));
    MAX = 0;
    v++;
    while (!bfs.empty()) {
        ii a = bfs.front();
        bfs.pop();
        MAX = max(a.first, MAX);
        visited[a.second] = v;
        for (i = graph[a.second].begin(); i != graph[a.second].end(); i++)
            if (visited[*i] != v) {
                bfs.push(mp(a.first + 1, *i));
                visited[*i] = v;
            }
    }
    cout << MAX;
    return 0;
}
