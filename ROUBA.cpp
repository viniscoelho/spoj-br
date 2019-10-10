#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <map>
#define mp make_pair
#define pb push_back
#define MAXV 10010

using namespace std;

typedef unsigned long long int64;
typedef pair<int, int> ii;

int c, j, p;

int main()
{
	ios::sync_with_stdio(false);
	int t = 0;
	while (cin >> c >> j && c + j)
	{
		if (t != 0)
			cout << "\n";
		t++;
		vector<list<int>> jog(MAXV);
		list<int>::iterator it;
		queue<int> card;
		map<int, int> descarte;
		int player = 0;
		for (int i = 0; i < c; ++i)
		{
			cin >> p;
			card.push(p);
			descarte.insert(mp(p, 0));
		}
		int tam = -1;
		while (!card.empty())
		{
			if (descarte[card.front()] > 0)
			{
				descarte[card.front()]--;
				jog[player].pb(card.front());
				jog[player].pb(card.front());
				tam = max(tam, (int)jog[player].size());
			}
			else
			{
				bool ok = false;
				for (int i = 0; i < j; ++i)
					if (i != player && card.front() == jog[i].back())
					{
						jog[player].splice(jog[player].end(), jog[i]);
						jog[player].pb(card.front());
						jog[i].clear();
						tam = max(tam, (int)jog[player].size());
						ok = true;
					}
				if (!ok)
				{
					if (card.front() == jog[player].back())
					{
						jog[player].pb(card.front());
						tam = max(tam, (int)jog[player].size());
					}
					else
					{
						player = (player + 1) % j;
						descarte[card.front()]++;
						tam = max(tam, (int)jog[player].size());
					}
				}
			}
			card.pop();
		}
		int cont = 0;
		for (int i = 0; i < j; ++i)
		{
			if (cont == 0 && tam == jog[i].size())
			{
				cout << jog[i].size() << " " << i + 1;
				cont++;
			}
			else if (cont > 0 && tam == jog[i].size())
				cout << " " << i + 1;
		}
	}
	return 0;
}
