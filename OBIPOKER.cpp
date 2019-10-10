#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

int main()
{
	ios::sync_with_stdio(false);
	int n, m, t = 1;
	cin >> n;
	while (n--)
	{
		cout << "Teste " << t++ << "\n";
		map<int, int> poker;
		map<int, int>::iterator mpi;
		pair<map<int, int>::iterator, bool> ret;
		for (int j = 0; j < 5; ++j)
		{
			cin >> m;
			ret = poker.insert(mp(m, 1));
			if (!ret.second)
				poker[m]++;
		}
		int x, y, caso = 7, atual = 0;
		for (int i = 0; i < 7; ++i)
		{
			int tri = 0, par = 0, straight = 0;
			bool flag = false;
			for (mpi = poker.begin(); mpi != poker.end(); mpi++)
			{
				if (mpi->second == 4)
				{
					x = mpi->first;
					caso = 2;
					break;
				}
				else
				{
					if (mpi->second == 3)
					{
						x = mpi->first;
						tri++;
					}
					else if (mpi->second == 2)
					{
						if (par == 1)
						{
							x = mpi->first;
							par++;
						}
						else
						{
							y = mpi->first;
							par++;
						}
					}
					else if (atual == 0)
						atual = mpi->first;
					else if (mpi->first == atual + 1)
					{
						straight++;
						atual = mpi->first;
					}
				}
				if (straight == 4)
					flag = true;
			}
			if (caso != 7)
				break;
			else if (tri == 1 && par == 1)
			{
				caso = 3;
				break;
			}
			else if (tri == 1 && par == 0)
			{
				caso = 4;
				break;
			}
			else if (tri == 0 && par == 2)
			{
				caso = 5;
				break;
			}
			else if (tri == 0 && par == 1)
			{
				caso = 6;
				break;
			}
			else if (flag)
			{
				caso = 1;
				break;
			}
		}

		switch (caso)
		{
		case 1:
			cout << poker.begin()->first + 200 << "\n\n";
			break;
		case 2:
			cout << x + 180 << "\n\n";
			break;
		case 3:
			cout << x + 160 << "\n\n";
			break;
		case 4:
			cout << x + 140 << "\n\n";
			break;
		case 5:
			cout << 3 * max(x, y) + 2 * min(x, y) + 20 << "\n\n";
			break;
		case 6:
			cout << y << "\n\n";
			break;
		case 7:
			cout << "0\n\n";
			break;
		}
	}

	return 0;
}
