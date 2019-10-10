#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
#include <cmath>
#include <queue>
#define mp make_pair

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

char bat[110][110];
int emb[10000], visited[110][110], v = 1;

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c = -1, d, w, z;
	cin >> a >> b;
	queue<ii> bfs, bfsAux;
	map<int, int> ship;

	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
		{
			cin >> bat[i][j];
			if (bat[i][j] == '#')
				bfsAux.push(mp(i, j));
		}
	while (!bfsAux.empty())
	{
		int x = bfsAux.front().first, y = bfsAux.front().second;
		bfsAux.pop();
		if (visited[x][y] != v)
		{
			bfs.push(mp(x, y));
			visited[x][y] = v;
			c++;
		}
		while (!bfs.empty())
		{
			int i = bfs.front().first;
			int j = bfs.front().second;
			ship.insert(mp((i + 1) * max(a, b) + j + 1, c));
			emb[c]++;
			bfs.pop();
			if (i + 1 < a && bat[i + 1][j] == '#' && visited[i + 1][j] != v)
			{
				bfs.push(mp(i + 1, j));
				visited[i + 1][j] = v;
			}
			if (i - 1 >= 0 && bat[i - 1][j] == '#' && visited[i - 1][j] != v)
			{
				bfs.push(mp(i - 1, j));
				visited[i - 1][j] = v;
			}
			if (j + 1 < b && bat[i][j + 1] == '#' && visited[i][j + 1] != v)
			{
				bfs.push(mp(i, j + 1));
				visited[i][j + 1] = v;
			}
			if (j - 1 >= 0 && bat[i][j - 1] == '#' && visited[i][j - 1] != v)
			{
				bfs.push(mp(i, j - 1));
				visited[i][j - 1] = v;
			}
		}
	}
	cin >> d;
	int ans = 0;
	for (int i = 0; i < d; ++i)
	{
		cin >> w >> z;
		int pos = w * max(a, b) + z;
		if (bat[w - 1][z - 1] == '#')
		{
			emb[ship[pos]]--;
			if (emb[ship[pos]] == 0)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
