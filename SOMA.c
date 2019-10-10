#include <stdio.h>

int main()
{
    int n, i, x, saida = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        saida += x;
    }
    printf("%d", saida);
    return 0;
}
