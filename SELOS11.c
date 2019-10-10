#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	if (n < 4)
		printf("N");
	else
	{
		long long i = 2, flag = 1;
		while (i < sqrt(n))
		{
			if (n % i == 0)
			{
				printf("S");
				flag = 0;
				break;
			}
			i++;
		}
		if (flag)
			printf("N");
	}
	return 0;
}
