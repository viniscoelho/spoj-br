#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAXV 1010
#define COLOR 0

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<string, string> ss;
typedef pair<int, ss> iss;

vector<list<int>> graph(MAXV);

int visited[MAXV], v = 1, ans, resp, q, t;

void BFS(int u)
{
	queue<ii> bfs;
	bfs.push(mp(u, 0));
	list<int>::iterator it;
	visited[u] = v;
	while (!bfs.empty())
	{
		int x = bfs.front().first, y = bfs.front().second;
		bfs.pop();
		for (it = graph[x].begin(); it != graph[x].end(); it++)
		{
			if (visited[*it] != v)
			{
				visited[*it] = v;
				if (y + 1 > ans)
				{
					ans = y + 1;
					q = u, t = *it;
				}
				bfs.push(mp(*it, y + 1));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, p = 0;
	ans = 0;
	cin >> n;
	string a, b;
	unordered_map<string, int> geneal;
	unordered_map<int, string> bib;
	pair<unordered_map<string, int>::iterator, bool> ret;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> a >> b;
		ret = geneal.insert(mp(a, p));
		if (ret.second)
			p++;
		x = geneal[a];
		bib.insert(mp(geneal[a], a));

		ret = geneal.insert(mp(b, p));
		if (ret.second)
			p++;
		y = geneal[b];
		bib.insert(mp(geneal[b], b));
		graph[x].pb(y);
		graph[y].pb(x);
	}
	for (int i = 0; i < p; ++i)
	{
		BFS(i);
		v++;
	}
	if (bib[q].compare(bib[t]) < 0)
		cout << bib[q] << " " << bib[t] << " " << ans << "\n";
	else
		cout << bib[t] << " " << bib[q] << " " << ans << "\n";
	return 0;
}
