#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXV 110
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int n, dist[MAXV];
bool visited[MAXV];
vector<list<ii>> graph(MAXV);

int dijkstra(int s, int t)
{
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<ii> pq;
    pq.push(mp(0, s));
    dist[s] = 0;

    list<ii>::iterator it;

    while (!pq.empty()) {
        ii atual = pq.top();
        pq.pop();
        int custo = -atual.first;
        int v = atual.second;
        if (visited[v])
            continue;
        visited[v] = true;
        for (it = graph[v].begin(); it != graph[v].end(); ++it) {
            if (dist[it->first] > custo + it->second) {
                dist[it->first] = custo + it->second;
                pq.push(mp(-dist[it->first], it->first));
            }
        }
    }
    return dist[t];
}

int main()
{
    ios::sync_with_stdio(false);
    int m, de, para, custo, p, c;
    for (cin >> n >> m; n + m; cin >> n >> m) {
        for (int i = 0; i < n; ++i)
            graph[i].clear();
        for (int i = 0; i < m; ++i) {
            cin >> de >> para >> custo;
            graph[de - 1].pb(mp(para - 1, custo));
        }
        cin >> p >> c;
        int resp = dijkstra(p - 1, c - 1);
        if (resp == INF)
            cout << "-1\n";
        else
            cout << resp << "\n";
    }
    return 0;
}
