/*
	Resolucao:
		Realizar um bfs partindo de cada ponto
		e determinar a menor distancia entre as maiores
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int visited[110][110];
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	int n, x, y, t = 1;
	for (cin >> n; n != 0; cin >> n)
	{
		queue<ii> bfs;
		vector<list<int>> grafo(110);
		list<int>::iterator it;
		int MAX, MAXD = INF, visitado = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
				visited[i][j] = visited[j][i] = 0;
			visited[i][i] = 0;
		}
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> y;
			grafo[x - 1].push_back(y - 1);
			grafo[y - 1].push_back(x - 1);
		}
		cout << "Teste " << t++ << "\n";
		if (n == 1)
			cout << "1\n\n";
		else
		{
			for (int k = 0; k < n; ++k)
			{
				int d = -1;
				bfs.push(mp(0, k));
				while (!bfs.empty())
				{
					int c = bfs.front().first;
					int a = bfs.front().second;
					bfs.pop();
					d = max(d, c);
					for (it = grafo[a].begin(); it != grafo[a].end(); ++it)
						if (visited[a][*it] != visitado)
						{
							visited[a][*it] = visitado;
							bfs.push(mp(c + 1, *it));
						}
				}
				if (d < MAXD)
				{
					MAXD = d;
					MAX = k + 1;
				}
				visitado++;
			}
			cout << MAX << "\n\n";
		}
	}
	return 0;
}
