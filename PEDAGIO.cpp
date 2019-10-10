#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXV 60
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int dist[MAXV];
int c, e, l, p;
bool visited[MAXV];
vector<list<ii>> graph(MAXV);

void dijkstra()
{
    for (int i = 0; i < c; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<ii> pq;
    pq.push(mp(0, l - 1));
    dist[l - 1] = 0;

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
}

int main()
{
    ios::sync_with_stdio(false);
    int t = 1, de, para, custo;
    while (cin >> c >> e >> l >> p && c + e + l + p) {
        cout << "Teste " << t++ << "\n";
        for (int i = 0; i < c; ++i)
            graph[i].clear();
        for (int i = 0; i < e; ++i) {
            cin >> de >> para;
            graph[de - 1].pb(mp(para - 1, 1));
            graph[para - 1].pb(mp(de - 1, 1));
        }
        dijkstra();
        int count = 0;
        for (int i = 0; i < c; ++i) {
            if (dist[i] != INF && dist[i] > 0 && dist[i] <= p)
                if (!count) {
                    cout << i + 1;
                    count++;
                } else
                    cout << " " << i + 1;
        }
        cout << "\n\n";
    }
    return 0;
}
