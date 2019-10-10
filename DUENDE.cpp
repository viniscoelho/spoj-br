/*
	Resolucao:
		Aplicacao do menor caminho utilizando o algoritmo de dijkstra
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

const int MAXV = 110;
const int INF = 0x3f3f3f3f;
int dist[MAXV];
bool visited[MAXV];

int main()
{
  ios::sync_with_stdio(false);
  int m, n, d;
  cin >> n >> m;
  int graph[n][m];
  vector<list<ii>> grafo(n * m);
  queue<int> saida;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      cin >> graph[i][j];
      if (graph[i][j] == 0)
        saida.push(m * i + j);
      if (graph[i][j] == 3)
        d = m * i + j;
    }
  /*
      A partir de uma lista de adjacencia, monta o grafo usando uma lista de adjacencia
      Inicio e saloes onde a magia do duende e sugada sao desconsiderados
    */
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (graph[i][j] != 2)
      {
        if (i + 1 < n && graph[i + 1][j] != 2 && graph[i + 1][j] != 3)
          grafo[m * i + j].push_back(mp(m * (i + 1) + j, 1));
        if (i - 1 >= 0 && graph[i - 1][j] != 2 && graph[i - 1][j] != 3)
          grafo[m * i + j].push_back(mp(m * (i - 1) + j, 1));
        if (j + 1 < m && graph[i][j + 1] != 2 && graph[i][j + 1] != 3)
          grafo[m * i + j].push_back(mp(m * i + j + 1, 1));
        if (j - 1 >= 0 && graph[i][j - 1] != 2 && graph[i][j - 1] != 3)
          grafo[m * i + j].push_back(mp(m * i + j - 1, 1));
      }
    }
  }

  for (int i = 0; i < n * m; ++i)
  {
    dist[i] = INF;
    visited[i] = false;
  }
  priority_queue<ii> pq;
  pq.push(make_pair(0, d));
  dist[d] = 0;

  ii atual;
  list<ii>::iterator it;

  while (!pq.empty())
  {
    atual = pq.top();
    pq.pop();
    int custo = -atual.first;
    int v = atual.second;
    if (visited[v])
      continue;
    visited[v] = true;
    for (it = grafo[v].begin(); it != grafo[v].end(); ++it)
    {
      if (dist[it->first] > custo + it->second)
      {
        dist[it->first] = custo + it->second;
        pq.push(make_pair(-dist[it->first], it->first));
      }
    }
  }
  int resp = INF;

  /*
      Aqui pega a saida cuja possui a menor distancia para o duende
    */

  while (!saida.empty())
  {
    resp = min(dist[saida.front()], resp);
    saida.pop();
  }
  cout << resp;
  return 0;
}
