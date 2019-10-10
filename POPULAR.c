#include <stdio.h>

int main()
{
	int n, i, j;
	while (scanf("%d", &n) && n)
	{
		int f = 0, pop[n][n], s[n];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &pop[i][j]);
		for (j = 0; j < n; j++)
		{
			s[j] = 0;
			for (i = 0; i < n; i++)
				s[j] += pop[i][j];
		}
		for (j = 0; j < n; j++)
			if (f < s[j])
				f = s[j];
		printf("%d\n", f);
	}
	return 0;
}
