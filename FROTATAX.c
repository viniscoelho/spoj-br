/*
	Resolucao:
		Calcula qual combustivel e mais economico
*/

#include <stdio.h>

int main()
{
    float a, g, ka, kg;
    scanf("%f %f %f %f", &a, &g, &ka, &kg);
    if (a / ka >= g / kg)
        printf("G");
    else if (g / kg > a / ka)
        printf("A");
    return 0;
}
