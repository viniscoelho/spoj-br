#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAXV 100100

using namespace std;

typedef vector<int> vi;
typedef pair<int, string> is;
typedef unsigned long long int64;

typedef struct no {
    int64 to, cost;
    no(int64 to = 0, int64 cost = 0)
        : to(to)
        , cost(cost)
    {
    }
} ii;

vector<vector<ii>> graph;

int nodedad[MAXV], treesize[MAXV], chain[MAXV], chainleader[MAXV];
int cchain;
int64 acc[MAXV];

void BFS()
{
    queue<ii> bfs;
    bfs.push(ii(1, 0));
    while (!bfs.empty()) {
        ii atual = bfs.front();
        bfs.pop();
        acc[atual.to - 1] = atual.cost;
        for (int i = 0; i < graph[atual.to].size(); ++i) {
            int dest = graph[atual.to][i].to;
            bfs.push(ii(dest, atual.cost + graph[atual.to][i].cost));
        }
    }
}

void explore(int x, int dad)
{
    if (nodedad[x] != -1)
        return;
    nodedad[x] = dad;
    treesize[x] = 1;
    for (int i = 0; i < graph[x].size(); ++i) {
        if (graph[x][i].to != dad) {
            explore(graph[x][i].to, x);
            treesize[x] += treesize[graph[x][i].to];
        }
    }
}

void heavy_light(int x, int dad, int k, int p)
{
    if (p == 0) {
        k = cchain++;
        chainleader[k] = x;
    }
    chain[x] = k;
    int mx = -1;
    for (int i = 0; i < graph[x].size(); ++i)
        if (graph[x][i].to != dad && (mx == -1 || treesize[graph[x][i].to] > treesize[graph[x][mx].to]))
            mx = i;
    if (mx != -1)
        heavy_light(graph[x][mx].to, x, k, p + 1);
    for (int i = 0; i < graph[x].size(); ++i)
        if (graph[x][i].to != dad && i != mx)
            heavy_light(graph[x][i].to, x, -1, 0);
}

int lca(int a, int b)
{
    while (chain[a] != chain[b]) {
        if (treesize[chainleader[chain[a]]] >= treesize[chainleader[chain[b]]])
            b = nodedad[chainleader[chain[b]]];
        else
            a = nodedad[chainleader[chain[a]]];
    }
    if (treesize[a] < treesize[b])
        return b;
    return a;
}

int main()
{
    int de, para, custo, m, n;
    while (scanf("%d", &m) && m) {
        graph.resize(m + 1);
        for (int i = 0; i <= m; ++i) {
            nodedad[i] = nodedad[i + 1] = -1;
            acc[i] = chain[i] = 0;
        }

        for (int i = 1; i < m; ++i) {
            scanf("%d %d", &para, &custo);
            graph[para + 1].pb(ii(i + 1, custo));
        }
        cchain = 0;
        explore(1, 0);
        heavy_light(1, 0, -1, 0);
        BFS();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &de, &para);
            int l = lca(de + 1, para + 1);
            if (i == 0)
                printf("%llu", acc[de] + acc[para] - 2 * acc[l - 1]);
            else
                printf(" %llu", acc[de] + acc[para] - 2 * acc[l - 1]);
        }
        printf("\n");
        graph.clear();
    }
    return 0;
}
