/*
	Resolucao:
		Verificar se o grafo e bi-colorivel
*/

#include <algorithm>
#include <iostream>
#define MAXV 110

using namespace std;

int V, E;

bool graph[MAXV][MAXV];
int color[MAXV];

void inicializa()
{
    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++)
            graph[i][j] = graph[j][i] = false;
        graph[i][i] = false;
    }
}

bool solve(int vertex, int c)
{
    color[vertex] = 1 - c;
    for (int i = 0; i < V; i++)
        if (graph[i][vertex]) {
            if (color[i] == -1)
                if (!solve(i, 1 - c))
                    return false;
                else if (color[i] == color[vertex])
                    return false;
        }
    return true;
}

bool graph_is_bicolorable()
{
    for (int i = 0; i < V; i++)
        color[i] = -1;
    for (int i = 0; i < V; i++)
        if (color[i] == -1)
            if (!solve(i, 0))
                return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int a, b, t, p = 1;
    while (cin >> V >> E) {
        cout << "Instancia " << p++ << "\n";
        inicializa();
        for (int i = 0; i < E; ++i) {
            cin >> a >> b;
            graph[a - 1][b - 1] = true;
            graph[b - 1][a - 1] = true;
        }
        if (graph_is_bicolorable())
            cout << "sim\n\n";
        else
            cout << "nao\n\n";
    }
    return 0;
}
