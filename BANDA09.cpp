/*
	Resolucao:
		Gera todas as combinacoes entre o numero de musicos dado
		O conjunto que obtiver o maior numero de pontos e a solucao
*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstdio>
#define mp make_pair
#define pb push_back
#define MAXV 1010
#define COLOR 0

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int resp[3];
int musicos[MAXV][MAXV];

int main()
{
	ios::sync_with_stdio(false);
	int m, p, a, b, e;
	cin >> m >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> a >> b >> e;
		musicos[a - 1][b - 1] = musicos[b - 1][a - 1] = e;
	}
	int ans = -1;
	for (int k = 0; k < m - 2; k++)
	{
		for (int i = k + 1; i < m - 1; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				if (musicos[i][j] + musicos[i][k] + musicos[k][j] > ans)
				{
					ans = musicos[i][j] + musicos[i][k] + musicos[k][j];
					resp[0] = k + 1, resp[1] = i + 1, resp[2] = j + 1;
				}
			}
		}
	}
	cout << resp[0] << " " << resp[1] << " " << resp[2];
	return 0;
}
