/*
	Resolucao:
		Conta o numero de minas adjacentes e ela inclusive
		e imprime a resposta
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define MAX 500
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef long long int64;

const int INF = 0x3f3f3f3f;

int resp[60];

int a, b, i, n;

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (a == 1) {
            resp[i]++;
            if (i - 1 >= 0)
                resp[i - 1]++;
            if (i + 1 < n)
                resp[i + 1]++;
        }
    }
    for (i = 0; i < n; ++i)
        printf("%d\n", resp[i]);

    return 0;
}
