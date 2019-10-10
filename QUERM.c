#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j = 1, n;
    while (scanf("%d", &n) && n) {
        int v[n];
        for (i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for (i = 0; i < n; i++)
            if (v[i] == i + 1)
                printf("Teste %d\n%d\n\n", j++, v[i]);
    }
    return 0;
}
