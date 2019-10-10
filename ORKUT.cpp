/*
	Resolucao:
		Dada a lista de amigos e os amigos necessarios para
		ter amizada com tais, verificar se primeiramente existe
		algum deles que a restricao seja 0. Caso nao tenha, e impossivel.
		Caso tenha, verificar se e possivel pertencer ao mesmo conjunto dos
		demais.
*/

#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#define mp make_pair

using namespace std;

typedef struct no
{
	int pai;
	int rank;
} Tno;

vector<Tno> pset;
typedef pair<int, int> ii;
typedef pair<string, queue<string>> sqs;

void inicializa(int n)
{
	pset.resize(n);
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

int pegaPai(int x)
{
	while (pset[x].pai != x)
		x = pset[x].pai;
	return x;
}

bool isSameSet(int v, int w)
{
	return (pset[pegaPai(v)].pai == pset[pegaPai(w)].pai);
}

bool comp(pair<string, queue<string>> a, pair<string, queue<string>> b)
{
	return (a.second.size() > b.second.size());
}

int main()
{
	ios::sync_with_stdio(false);
	int n, r, q = 1;
	for (cin >> n; n != 0; cin >> n)
	{
		cout << "Teste " << q++ << "\n";
		cin.ignore();
		string resp, rest;
		map<string, int> amg;
		inicializa(n + 2);
		for (int i = 0; i < n; ++i)
		{
			cin >> resp;
			amg.insert(mp(resp, i + 1));
		}
		list<sqs> amigos;
		list<sqs>::reverse_iterator it;
		for (int i = 0; i < n; ++i)
		{
			queue<string> amizade;
			cin >> resp >> r;
			cin.ignore();
			for (int j = 0; j < r; ++j)
			{
				cin >> rest;
				amizade.push(rest);
			}
			amigos.push_back(mp(resp, amizade));
		}
		amigos.sort(comp);
		queue<string> friends;
		int s = amigos.size(), cont = 0;
		if ((amigos.rbegin()->second).size() == 0)
		{
			for (it = amigos.rbegin(); it != amigos.rend(); it++)
			{
				if (cont == s)
					break;
				queue<string> a, b;
				a = b = it->second;
				int amigo = amg[it->first];
				if (a.empty())
				{
					unionSet(0, amg[it->first]);
					friends.push(it->first);
					cont = 0;
					s--;
				}
				else
				{
					int tam = a.size(), resp = 0;
					while (!a.empty())
					{
						if (isSameSet(0, amg[a.front()]))
							resp++;
						a.pop();
					}
					if (tam == resp)
					{
						unionSet(0, amigo);
						friends.push(it->first);
						cont = 0;
						s--;
					}
					else
					{
						amigos.push_front(mp(it->first, b));
						cont++;
					}
				}
			}
			int count = 0;
			if (friends.size() == n)
			{
				while (!friends.empty())
				{
					if (count == 0)
					{
						cout << friends.front();
						count++;
					}
					else
						cout << " " << friends.front();
					friends.pop();
				}
				cout << "\n\n";
			}
			else
				cout << "impossivel\n\n";
		}
		else
			cout << "impossivel\n\n";
	}
	return 0;
}
