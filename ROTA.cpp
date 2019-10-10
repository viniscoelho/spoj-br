#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
#include <set>
#define mp make_pair
#define pb push_back
#define MAXV 110
#define color 0

using namespace std;
using namespace tr1;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

int V, A;
vector<list<ii>> graph(MAXV);
int visited[MAXV], adj[MAXV][MAXV], v = 1, num = 1;
map<ii, int> tree;
viii arb;

void DFS(int u)
{
	list<ii>::iterator it;
	for (it = graph[u].begin(); it != graph[u].end(); it++)
	{
		if (visited[it->first] != v)
		{
			visited[it->first] = v;
			arb.pb(mp(tree[mp(u, it->first)], mp(u, it->first)));
			DFS(it->first);
		}
	}
}

void runDFS(int u, int z)
{
	list<ii>::iterator it;
	for (it = graph[u].begin(); it != graph[u].end(); it++)
	{
		if (it->second != z && visited[it->first] != v)
		{
			num++;
			visited[it->first] = v;
			runDFS(it->first, z);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> V >> A && V + A)
	{
		cin.ignore();
		unordered_map<string, int> rota;
		unordered_map<int, string> bib;
		string a, b;
		arb.clear(), tree.clear();
		for (int i = 0; i < V; ++i)
		{
			cin >> a;
			graph[i].clear();
			rota.insert(mp(a, i));
			bib.insert(mp(i, a));
		}
		for (int i = 0; i < A; ++i)
		{
			cin >> a >> b;
			graph[rota[b]].pb(mp(rota[a], i));
			tree.insert(mp(mp(rota[b], rota[a]), i));
		}
		visited[0] = v;
		DFS(0);
		v++;
		sort(arb.begin(), arb.end());
		bool flag = false;
		for (int k = 0; k < arb.size(); ++k)
		{
			visited[0] = v;
			runDFS(0, arb[k].first);
			if (num != V)
			{
				cout << bib[arb[k].second.second] << " " << bib[arb[k].second.first] << "\n";
				flag = true;
			}
			num = 1, v++;
		}
		if (!flag)
			cout << "Nenhuma\n";
		cout << "\n";
		num = 1;
	}
	return 0;
}
