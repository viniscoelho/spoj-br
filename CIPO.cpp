#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

int v, e;
int de, para, peso;

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
	int t = 1;
	while (cin >> v >> e)
	{
		cout << "Instancia " << t++ << "\n";
		queue<ii> pq_8977, pq_10923;
		unordered_map<int, int> cipo;
		int soma = 0;
		for (int i = 0; i < v; ++i)
		{
			pset[i].pai = i;
			pset[i].rank = 0;
		}
		for (int i = 0; i < e; i++)
		{
			cin >> de >> para >> peso;
			if (peso == 1235)
			{
				if (!isSameSet(de - 1, para - 1))
				{
					UnionSet(de - 1, para - 1);
					cipo.insert(mp(de - 1, 0));
					cipo.insert(mp(para - 1, 0));
					soma += 1235;
				}
			}
			if (peso == 8977)
				pq_8977.push(mp(de - 1, para - 1));
			if (peso == 10923)
				pq_10923.push(mp(de - 1, para - 1));
		}
		if (cipo.size() != v)
		{
			while (!pq_8977.empty())
			{
				int p = pq_8977.front().first;
				int q = pq_8977.front().second;
				pq_8977.pop();
				if (!isSameSet(p, q))
				{
					UnionSet(p, q);
					soma += 8977;
					cipo.insert(mp(p, 0));
					cipo.insert(mp(q, 0));
				}
				if (cipo.size() == v)
					break;
			}
		}
		if (cipo.size() != v)
		{
			while (!pq_10923.empty())
			{
				int p = pq_10923.front().first;
				int q = pq_10923.front().second;
				pq_10923.pop();
				if (!isSameSet(p, q))
				{
					UnionSet(p, q);
					cipo.insert(mp(p, 0));
					cipo.insert(mp(q, 0));
					soma += 10923;
				}
				if (cipo.size() == v)
					break;
			}
		}
		cout << soma << "\n\n";
	}
	return 0;
}