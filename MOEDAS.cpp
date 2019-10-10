/*
	Resolucao:
		Fazer um BFS que gere todas as moedas. O BFS garante
		que todas moedas sejam geradas ate o valor correspondente
*/

#include <queue>
#include <iostream>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

bool visitado[50010];

int main()
{
	ios::sync_with_stdio(false);
	int m, n;
	while (cin >> m >> n && m)
	{
		queue<ii> moedas;
		int num[n], flag = 1;
		for (int i = 0; i <= m; ++i)
			visitado[i] = false;

		for (int i = 0; i < n; ++i)
		{
			cin >> num[i];
			visitado[num[i]] = true;
			moedas.push(mp(num[i], 1));
		}
		moedas.push(mp(0, 0));

		while (!moedas.empty() && flag == 1)
		{
			int f = moedas.front().first, f2 = moedas.front().second;
			moedas.pop();
			for (int j = 0; j < n; ++j)
			{
				if (num[j] + f == m && flag)
				{
					cout << f2 + 1 << "\n";
					flag = 0;
					break;
				}
				else if (num[j] + f < m && !visitado[num[j] + f])
				{
					moedas.push(mp(num[j] + f, f2 + 1));
					visitado[num[j] + f] = true;
				}
			}
		}
		if (flag)
			cout << "Impossivel\n";
	}
	return 0;
}
