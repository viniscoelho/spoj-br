/*
	Resolucao:
		O objetivo e obter o maior valor arrecadado pela bolsa
		A solucao e fazer duas filas de prioridade, colocando os maiores
		valores no topo no caso de compra, e os menores no topo, em caso de venda
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#define mp make_pair
#define pb push_back
#define MAX 220

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef unsigned long long int64;

int n;

const int INF = 0x3f3f3f3f;

int main()
{
	while (scanf("%d", &n) && n)
	{
		priority_queue<double> c, v;
		char opc;
		double qtd, ans = 0;
		while (n--)
		{
			scanf(" %c %lf", &opc, &qtd);
			if (opc == 'C')
			{
				if (v.empty())
					c.push(qtd);
				else
				{
					if (qtd + v.top() >= 0.0)
					{
						ans += (qtd + v.top());
						v.pop();
					}
					else
						c.push(qtd);
				}
			}
			else
			{
				if (c.empty())
					v.push(-qtd);
				else
				{
					if (c.top() - qtd >= 0.0)
					{
						ans += (c.top() - qtd);
						c.pop();
					}
					else
						v.push(-qtd);
				}
			}
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
