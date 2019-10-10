/*
	Resolucao:
		Realizar um BFS a partir do ponto dado e contabilizar o
		maior numero de quadrados que e possivel pintar com aquela mesma cor
*/
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

bool visited[210];
bool graph[210][210];
int m, n, x, y, k, MAX = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n >> x >> y >> k;
	queue<iii> bfs;
	int a, b;
	bfs.push(mp(mp(x - 1, y - 1), 0));
	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
	}
	graph[x - 1][y - 1] = true;
	while (!bfs.empty())
	{
		int p = bfs.front().first.first;
		int q = bfs.front().first.second;
		int t = bfs.front().second;
		MAX++;
		bfs.pop();
		if (p + 1 < m && !graph[p + 1][q])
		{
			bfs.push(mp(mp(p + 1, q), t + 1));
			graph[p + 1][q] = true;
		}
		if (p + 1 < m && q + 1 < n && !graph[p + 1][q + 1])
		{
			bfs.push(mp(mp(p + 1, q + 1), t + 1));
			graph[p + 1][q + 1] = true;
		}
		if (q + 1 < n && !graph[p][q + 1])
		{
			bfs.push(mp(mp(p, q + 1), t + 1));
			graph[p][q + 1] = true;
		}
		if (p - 1 >= 0 && q + 1 < n && !graph[p - 1][q + 1])
		{
			bfs.push(mp(mp(p - 1, q + 1), t + 1));
			graph[p - 1][q + 1] = true;
		}
		if (p - 1 >= 0 && !graph[p - 1][q])
		{
			bfs.push(mp(mp(p - 1, q), t + 1));
			graph[p - 1][q] = true;
		}
		if (p - 1 >= 0 && q - 1 >= 0 && !graph[p - 1][q - 1])
		{
			bfs.push(mp(mp(p - 1, q - 1), t + 1));
			graph[p - 1][q - 1] = true;
		}
		if (q - 1 >= 0 && !graph[p][q - 1])
		{
			bfs.push(mp(mp(p, q - 1), t + 1));
			graph[p][q - 1] = true;
		}
		if (p + 1 < m && q - 1 >= 0 && !graph[p + 1][q - 1])
		{
			bfs.push(mp(mp(p + 1, q - 1), t + 1));
			graph[p + 1][q - 1] = true;
		}
	}
	cout << MAX;
	return 0;
}
