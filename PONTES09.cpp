#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

const int MAXV = 1010;
const int INF = 0x3f3f3f3f;
int dist[MAXV];
bool visited[MAXV];

int main()
{
    ios::sync_with_stdio(false);
    int m, n, de, para, custo;
    cin >> m >> n;
    vector<list<ii>> grafo(MAXV);
    for (int i = 0; i < n; ++i) {
        cin >> de >> para >> custo;
        grafo[de].push_back(make_pair(para, custo));
        grafo[para].push_back(make_pair(de, custo));
    }
    for (int i = 0; i < m + 2; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<ii> pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0;

    ii atual;
    list<ii>::iterator it;

    while (!pq.empty()) {
        atual = pq.top();
        pq.pop();
        int custo = -atual.first;
        int v = atual.second;
        if (visited[v])
            continue;
        visited[v] = true;
        for (it = grafo[v].begin(); it != grafo[v].end(); ++it) {
            if (dist[it->first] > custo + it->second) {
                dist[it->first] = custo + it->second;
                pq.push(make_pair(-dist[it->first], it->first));
            }
        }
    }
    cout << dist[m + 1];
    return 0;
}
