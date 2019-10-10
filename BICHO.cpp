/*
	Resolucao:
		Gera o premio do apostador de acordo com a pontuacao dada
		pelo exercicio.
*/

#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <iomanip>
#define pb push_back
#define mp make_pair

using namespace std;

struct no
{
	int pai;
	int rank;
};

typedef struct no UJoin;
typedef pair<int, int> ii;

UJoin pset[100];

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
	double v;
	int n, s;
	pset[0].pai = pset[0].rank = 0;
	for (int i = 1; i < 100; i += 4)
	{
		for (int j = i; j < i + 3; j++)
		{
			pset[j].pai = j;
			pset[j + 1].pai = j + 1;
			pset[j].rank = pset[j + 1].rank = 0;
			UnionSet(j, j + 1);
		}
	}
	UnionSet(99, 0);
	while (cin >> v >> n >> s && v + n + s)
	{
		if ((n % 10000) + 100000 == (s % 10000) + 100000)
			cout << fixed << setprecision(2) << v * 3000 << "\n";
		else if ((n % 1000) + 10000 == (s % 1000) + 10000)
			cout << fixed << setprecision(2) << v * 500 << "\n";
		else if ((n % 100) + 1000 == (s % 100) + 1000)
			cout << fixed << setprecision(2) << v * 50 << "\n";
		else if (isSameSet(n % 100, s % 100))
			cout << fixed << setprecision(2) << v * 16 << "\n";
		else
			cout << "0.00\n";
	}
	return 0;
}
