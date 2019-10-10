/*
	Resolucao:
		Divide um numero recursivamente ate um tamanho k
		e retorna o numero de partes divididas
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

int n, k;

int divide(double num, int qtd)
{
    if (num <= k)
        return 1;
    return divide(ceil(num / 2), qtd + 1) + divide(floor(num / 2), qtd + 1);
}

int main()
{
    while (scanf("%d %d", &n, &k) && n + k) {
        if (n < k)
            printf("1\n");
        else if (k == 1)
            printf("%d\n", n);
        else {
            double num = n;
            printf("%d\n", divide(num, 0));
        }
    }
    return 0;
}
