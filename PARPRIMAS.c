#include <stdio.h>

int main()
{
    int j;
    char p[20], aux = 0;
    while (scanf("%c", &aux) != EOF) {
        int i = 0, l = 0, n = 0;
        do {
            p[l] = aux;
            l++;
        } while (scanf("%c", &aux) && aux != '\n' && aux != ' ');
        if (l >= 1 && l <= 20) {
            for (j = 0; j < l; j++) {
                if (p[j] >= 65 && p[j] <= 90)
                    n += p[j] - 38;
                if (p[j] >= 97 && p[j] <= 122)
                    n += p[j] - 96;
            }
            for (j = 2; j <= n / 2; j++)
                if (n % j == 0)
                    i++;
            if (i != 0)
                printf("It is not a prime word.\n");
            else
                printf("It is a prime word.\n");
        }
    }
    return 0;
}
