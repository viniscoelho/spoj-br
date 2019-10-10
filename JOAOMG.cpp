/*
	Resolucao:
		Verificar se o numero dado e um dos numeros de Kaprekar
*/

#include <cstdio>

bool joao[41002];

int main()
{
    int n;
    joao[1] = joao[9] = joao[45] = joao[55] = joao[99] = joao[297] = joao[703] = joao[999] = joao[2223] = joao[2728] = joao[4879] = true;
    joao[4950] = joao[5050] = joao[5292] = joao[7272] = joao[7777] = joao[9999] = joao[17344] = joao[22222] = joao[38962] = true;
    char ans[] = { 'N', 'S' };
    while (scanf("%d", &n) && n)
        printf("%d: %c\n", n, ans[joao[n]]);
    return 0;
}