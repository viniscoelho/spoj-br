#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char num[1010], aux;
	do
	{
		int i = 0, k = 0, resto = 0, tam = 1;
		scanf("%s", &num);
		aux = num[0];
		if (aux != '0' || strlen(num) > 1)
		{
			while (tam <= strlen(num))
			{
				k = num[i] - 48;
				if (i % 2 == 0)
				{
					resto += k;
					++tam;
				}
				else
				{
					resto -= k;
					++tam;
				}
				++i;
			}
			resto = abs(resto);
			if (resto % 11 == 0)
				printf("%s is a multiple of 11.\n", num);
			else
				printf("%s is not a multiple of 11.\n", num);
		}
	} while (aux != '0' || strlen(num) > 1);
	return 0;
}