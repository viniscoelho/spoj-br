#include <stdio.h>

int tv[1010][1010];

int main()
{
    int i, j, n, m, t = 1;
    for (scanf("%d %d", &m, &n); n + m != 0; scanf("%d %d", &m, &n))
    {
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                scanf("%d", &tv[i][j]);
        int a, b, x = 0, y = 0;
        for (scanf("%d %d", &a, &b); !(a == 0 && b == 0); scanf("%d %d", &a, &b))
        {
            x += a;
            y += b;
        }
        y = -y;

        printf("Teste %d\n", t++);
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                int p = (m + (i - y) % m) % m;
                int q = (n + (j - x) % n) % n;
                if (j == 0)
                    printf("%d", tv[p][q]);
                else
                    printf(" %d", tv[p][q]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
