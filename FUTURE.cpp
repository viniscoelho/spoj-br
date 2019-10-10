#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAX 150
#define MAXV 21000
#define INF 1000000000000000LL

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef pair<ii, int64> ii_64;
typedef pair<int64, int> ii64;
const double EPS = 1e-10;

struct aresta
{
    int a, b;
    int64 c;
};

struct edge
{
    int u, v, next;
    int64 cost, flow;
    edge(int u = 0, int v = 0, int next = 0, int64 cost = 0, int64 flow = 0) : u(u), v(v), next(next), cost(cost), flow(flow) {}
};

int V, E, A;
int64 f, sp, dist[MAX], p[MAX], prv[MAXV];
bool visited[MAX];
vector<edge> graph(MAXV);
vector<aresta> edges(MAXV);

void addEdge(int u, int v, int64 c, int64 f)
{
    graph[A] = edge(u, v, prv[u], c, f);
    prv[u] = A++;
    graph[A] = edge(v, u, prv[v], -c, 0);
    prv[v] = A++;
}

void augment(int v, int64 minEdge)
{
    for (int i = p[v]; i != -1; i = p[graph[i].u])
        minEdge = min(minEdge, graph[i].flow);

    for (int i = p[v]; i != -1; i = p[graph[i].u])
    {
        graph[i].flow -= minEdge;
        graph[i ^ 1].flow += minEdge;
    }
    f = minEdge;
}

bool dijkstra(int s, int t)
{
    for (int i = 0; i <= V + 1; ++i)
    {
        dist[i] = INF;
        p[i] = -1;
        visited[i] = false;
    }
    queue<int> q;
    dist[s] = 0;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = prv[u]; i != -1; i = graph[i].next)
        {
            int v = graph[i].v;
            if (graph[i].flow && dist[u] + graph[i].cost < dist[v])
            {
                dist[v] = dist[u] + graph[i].cost;
                p[v] = i;
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        visited[u] = false;
    }
    sp = dist[t];
    return sp != INF;
}

int main()
{
    int t = 1;
    int64 d, k;
    while (scanf("%d %d", &V, &E) != EOF)
    {
        if (t > 1)
            printf("\n");
        printf("Instancia %d\n", t++);
        A = 0;
        for (int i = 0; i <= V + 1; ++i)
            prv[i] = -1;
        for (int i = 0; i < E; ++i)
            scanf("%d %d %lld", &edges[i].a, &edges[i].b, &edges[i].c);
        scanf("%lld %lld", &d, &k);
        addEdge(0, 1, 0, d);
        addEdge(V, V + 1, 0, d);
        for (int i = 0; i < E; ++i)
        {
            addEdge(edges[i].a, edges[i].b, edges[i].c, k);
            addEdge(edges[i].b, edges[i].a, edges[i].c, k);
        }
        int64 maxFlow = 0, resp = 0;
        while (dijkstra(0, V + 1))
        {
            f = 0;
            augment(V + 1, INF);
            maxFlow += f;
            resp += sp * f;
            if (maxFlow == d)
                break;
        }
        if (maxFlow != d)
            printf("impossivel\n");
        else
            printf("%lld\n", resp);
    }
    return 0;
}
