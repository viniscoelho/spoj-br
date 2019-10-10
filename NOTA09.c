#include <stdio.h>

int main()
{
    int nota;
    scanf("%d", &nota);
    if (nota == 0)
        printf("E");
    else if (nota >= 1 && nota <= 35)
        printf("D");
    else if (nota >= 36 && nota <= 60)
        printf("C");
    else if (nota >= 61 && nota <= 85)
        printf("B");
    else
        printf("A");
    return 0;
}
