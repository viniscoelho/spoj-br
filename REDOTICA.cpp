#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int v, a;

struct no
{
	int pai;
	int rank;
};

typedef struct no Tno;
vector<Tno> pset;

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

void inicializa()
{
	pset.resize(v);
	for (int i = 0; i < v; i++)
	{
		pset[i].pai = i;
		pset[i].rank = 0;
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
	Link(findSet(x), findSet(y));
}

typedef struct aresta
{
	int de, para, peso;
} Taresta;

bool menor(const Taresta &a, const Taresta &b)
{
	if (a.peso < b.peso)
		return true;
	else if (a.peso == b.peso)
		if (a.para == b.para)
			return (a.de < b.de);
		else
			return (a.para < b.para);
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int de, para, peso;
	int j = 1;
	for (cin >> v >> a; v != 0 && a != 0; cin >> v >> a)
	{
		vector<Taresta> grafo(a);
		vector<Taresta> agm;
		int total = 0, resto = 0;
		for (int i = 0; i < a; i++)
		{
			cin >> de >> para >> peso;
			if (de < para)
			{
				grafo[i].de = de - 1;
				grafo[i].para = para - 1;
				grafo[i].peso = peso;
			}
			else
			{
				grafo[i].de = para - 1;
				grafo[i].para = de - 1;
				grafo[i].peso = peso;
			}
		}
		sort(grafo.begin(), grafo.end(), menor);
		inicializa();
		vector<Taresta>::iterator it;
		for (it = grafo.begin(); it != grafo.end(); it++)
		{
			if (findSet(it->de) != findSet(it->para))
			{
				unionSet(it->de, it->para);
				Taresta aux;
				aux.de = it->de;
				aux.para = it->para;
				aux.peso = it->peso;
				agm.push_back(aux);
			}
		}
		sort(agm.begin(), agm.end(), menor);
		cout << "Teste " << j++ << "\n";
		for (it = agm.begin(); it != agm.end(); it++)
			cout << it->de + 1 << " " << it->para + 1 << "\n";
		cout << "\n";
	}
	return 0;
}
