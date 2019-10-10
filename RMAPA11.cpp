#include <iostream>
#include <queue>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define MAXV 550

using namespace std;
using namespace tr1;

int v, e;
int de, para, peso;

struct no
{
	int pai;
	int rank;
};

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef struct no UJoin;

UJoin pset[MAXV];
vector<iii> graph;

void Link(int x, int y)
{
	if (pset[x].rank > pset[y].rank)
		pset[y].pai = x;
	else
	{
		pset[x].pai = y;
		if (pset[x].rank == pset[y].rank)
			pset[y].rank = pset[y].rank + 1;
	}
}

int findSet(int x)
{
	while (pset[x].pai != x)
		x = pset[x].pai;
	return x;
}

void UnionSet(int x, int y)
{
	Link(findSet(x), findSet(y));
}

bool isSameSet(int x, int y)
{
	return findSet(x) == findSet(y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> v >> e;
	int soma = 0;
	unordered_map<int, int> umap;
	for (int i = 0; i < v; ++i)
	{
		pset[i].pai = i;
		pset[i].rank = 0;
	}
	for (int i = 0; i < e; i++)
	{
		cin >> de >> para >> peso;
		graph.pb(mp(peso, mp(de - 1, para - 1)));
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < e; ++i)
	{
		if (!isSameSet(graph[i].second.first, graph[i].second.second))
		{
			UnionSet(graph[i].second.first, graph[i].second.second);
			soma += graph[i].first;
			umap.insert(mp(graph[i].second.first, 0));
			umap.insert(mp(graph[i].second.second, 0));
		}
		if (umap.size() == v)
			break;
	}
	cout << soma;
	return 0;
}
