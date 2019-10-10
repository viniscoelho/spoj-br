#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, k = 1, m, n, aux = 0;
	while (scanf("%d", &n) != EOF)
	{
		char rep[21], nome[21];
		int aux = 0;
		for (i = 0; i < n; i++)
		{
			scanf(" %s %d", &nome, &m);
			if (i == 0)
			{
				strcpy(rep, nome);
				aux = m;
			}
			else if (strcmp(nome, rep) > 0 && aux > m)
			{
				strcpy(rep, nome);
				aux = m;
			}
			else if (strcmp(rep, nome) > 0 && aux > m)
			{
				strcpy(rep, nome);
				aux = m;
			}
			else if (strcmp(nome, rep) > 0 && aux == m)
			{
				strcpy(rep, nome);
				aux = m;
			}
		}
		printf("Instancia %d\n%s\n\n", k++, rep);
	}
	return 0;
}
