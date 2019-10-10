/*
	Resolucao:
		Substituir as letras e encontrar o numero do telefone
		Pode tambem ser resolvido usando um map (arvore binaria)
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char num[50], *it;
    while (scanf("%s", &num) != EOF) {
        it = num;
        int tam = strlen(it), x = 0;
        while (x < tam) {
            if (*it == 'A' || *it == 'B' || *it == 'C')
                printf("2");
            else if (*it == 'D' || *it == 'E' || *it == 'F')
                printf("3");
            else if (*it == 'G' || *it == 'H' || *it == 'I')
                printf("4");
            else if (*it == 'J' || *it == 'K' || *it == 'L')
                printf("5");
            else if (*it == 'M' || *it == 'N' || *it == 'O')
                printf("6");
            else if (*it == 'P' || *it == 'Q' || *it == 'R' || *it == 'S')
                printf("7");
            else if (*it == 'T' || *it == 'U' || *it == 'V')
                printf("8");
            else if (*it == 'W' || *it == 'X' || *it == 'Y' || *it == 'Z')
                printf("9");
            else
                printf("%c", *it);
            ++it, ++x;
        }
        printf("\n");
    }
    return 0;
}
