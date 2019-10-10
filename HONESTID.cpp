#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define N 10010
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, N) for (int i = 0; i < N; ++i)

using namespace std;

bool X1[N], X2[N], base[N];
int n, m, k, ok = 1;
int cor[N], maxcor[N], previ[N], visited[N], x[N], y[N];
vector<int> g[N];

typedef struct no
{
	int pai;
	int rank;
} Tno;

vector<Tno> pset(N);

void inicializa()
{
	for (int i = 0; i < n; i++)
	{
		pset[i].pai = i;
		pset[i].rank = 0;
	}
}

void link(int x, int y)
{
	if (pset[x].rank > pset[y].rank)
		pset[y].pai = x;
	else
	{
		pset[x].pai = y;
		if (pset[x].rank == pset[y].rank)
			pset[y].rank++;
	}
}

int findSet(int x)
{
	if (pset[x].pai != x)
		pset[x].pai = findSet(pset[x].pai);
	return (pset[x].pai);
}

void unionSet(int x, int y)
{
	link(findSet(x), findSet(y));
}

bool isSameSet(int x, int y)
{
	return findSet(x) == findSet(y);
}

int BFS()
{
	REP(i, m)
	if (X1[i] && X2[i]) return i;
	REP(i, m)
	previ[i] = -1;
	queue<int> bfs;
	REP(i, m)
	if (X1[i])
	{
		bfs.push(i);
		visited[i] = ok;
	}
	while (!bfs.empty())
	{
		int v = bfs.front();
		bfs.pop();
		REP(j, g[v].size())
		{
			int u = g[v][j];
			if (visited[u] == ok)
				continue;
			previ[u] = v;
			if (X2[u])
				return u;
			bfs.push(u);
			visited[u] = ok;
		}
	}
	return -1;
}

int matroid_intersection()
{
	REP(i, m)
	base[i] = false;
	int res;
	for (res = 0; true; res++)
	{
		REP(i, m)
		g[i].clear();
		REP(i, 1)
		if (base[i])
		{
			inicializa();
			REP(j, m)
			if (base[j] && i != j) unionSet(x[j], y[j]);
			REP(j, m)
			if (!base[j] && !isSameSet(x[j], y[j])) g[i].pb(j);
			REP(j, m)
			if (!base[j])
			{
				maxcor[cor[i]]++;
				if (maxcor[cor[j]] >= 1)
					g[j].pb(i);
				maxcor[cor[i]]--;
			}
		}
		inicializa();
		REP(i, m)
		if (base[i]) unionSet(x[i], y[i]);
		REP(i, m)
		{
			X1[i] = X2[i] = false;
			if (!base[i])
			{
				if (!isSameSet(x[i], y[i]))
					X1[i] = true;
				if (maxcor[cor[i]] >= 1)
					X2[i] = true;
			}
		}
		int v = BFS();
		if (v == -1)
			break;
		while (true)
		{
			maxcor[cor[v]] += (base[v] ? 1 : -1);
			base[v] = !base[v];
			if (X1[v])
				break;
			v = previ[v];
		}
	}
	return res;
}

int main()
{
	int test = 1;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		REP(i, k)
		maxcor[i] = 1;
		REP(i, m)
		{
			scanf("%d %d %d", &x[i], &y[i], &cor[i]);
			x[i]--;
			y[i]--;
			cor[i]--;
		}
		printf("Instancia %d\n", test++);
		if (matroid_intersection() == n - 1)
			printf("sim\n\n");
		else
			printf("nao\n\n");
	}
	return 0;
}
