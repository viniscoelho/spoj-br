#include <iostream>
#include <queue>
#include <map>
#define mp make_pair
#define pb push_back

using namespace std;

int m, n, a, b;

struct no
{
	int pai;
	int rank;
};

typedef struct no UJoin;
typedef pair<int, int> ii;

UJoin pset[1010];

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
	cin >> m >> n;
	map<int, int> mapa;
	for (int i = 0; i < m; ++i)
	{
		pset[i].pai = i;
		pset[i].rank = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		UnionSet(a - 1, b - 1);
	}
	for (int i = 0; i < m; ++i)
		mapa.insert(mp(findSet(i), 0));
	cout << mapa.size();

	return 0;
}
