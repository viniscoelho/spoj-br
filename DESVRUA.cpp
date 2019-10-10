#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAXV 1010

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi S;
int V, E, dfs_parent[MAXV], dfs_low[MAXV], dfs_num[MAXV], visited[MAXV];
int ans, counter, flag, ok;

vector<list<int>> directed(MAXV), undirected(MAXV);

struct no
{
	int pai, rank;
};

typedef struct no UJoin;

UJoin pset[MAXV];

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

void initialize()
{
	for (int i = 0; i < V; ++i)
	{
		pset[i].pai = i;
		pset[i].rank = visited[i] = 0;
		dfs_parent[i] = dfs_low[i] = dfs_num[i] = 0;
		directed[i].clear();
		undirected[i].clear();
	}
}

void tarjan(int u)
{
	dfs_low[u] = dfs_num[u] = counter++;
	S.pb(u);
	visited[u] = true;
	list<int>::iterator li;
	for (li = directed[u].begin(); li != directed[u].end(); ++li)
	{
		if (!dfs_num[*li])
			tarjan(*li);
		if (visited[*li])
			dfs_low[u] = min(dfs_low[u], dfs_low[*li]);
	}
	if (dfs_low[u] == dfs_num[u])
	{
		int resp = 0;
		while (1)
		{
			int vertex = S.back();
			S.pop_back();
			resp++;
			if (u == vertex)
				break;
		}
		if (resp == V)
			flag = true;
	}
}

void PointBridge(int u)
{
	list<int>::iterator i;
	dfs_low[u] = dfs_num[u] = counter++;
	for (i = undirected[u].begin(); i != undirected[u].end(); ++i)
	{
		if (!dfs_num[*i])
		{
			ans++;
			dfs_parent[*i] = u;
			PointBridge(*i);
			if (dfs_low[*i] > dfs_num[u])
				if (isSameSet(u, *i))
					ok = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[*i]);
		}
		else if (*i != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[*i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int a, b, t;
	while (cin >> V >> E)
	{
		initialize();
		ans = counter = flag = ok = counter = 0;
		cin >> a >> b >> t;
		for (int i = 0; i < E - 1; ++i)
		{
			cin >> a >> b >> t;
			directed[a - 1].pb(b - 1);
			undirected[a - 1].pb(b - 1);
			undirected[b - 1].pb(a - 1);
			if (t == 2)
				directed[b - 1].pb(a - 1);
			else
				UnionSet(b - 1, a - 1);
		}
		tarjan(0);
		if (flag)
			cout << "-\n";
		else
		{
			for (int i = 0; i < V; ++i)
				dfs_low[i] = dfs_num[i] = 0;
			counter = 0;
			PointBridge(0);
			if (ans != V)
				cout << "*\n";
			else
			{
				if (ok)
					cout << "2\n";
				else
					cout << "1\n";
			}
		}
	}
	return 0;
}
