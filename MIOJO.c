#include <stdio.h>

int main()
{
    int t, a, b, i = 0, j = 0, aux = 0;
    scanf("%d %d %d", &t, &a, &b);
    while (aux != t && aux != -t) {
        aux = b * i - a * j;
        if (aux > 0)
            j++;
        else
            i++;
    }
    if (aux > 0)
        printf("%d", b * i);
    else
        printf("%d", a * j);
    return 0;
}
