/*
	Resolucao:
		Converter um horario no sistema tradicional para o sistema
		decimal.
*/

#include <cmath>
#include <cstdio>

typedef long long int64;

int main()
{
    int h, m, s, c;
    while ( scanf("%2d %2d %2d %2d", &h, &m, &s, &c) != EOF )
    {
        int64 resp = h*360000 + m*6000 + s*100 + c;
        resp = (10000000*resp)/8640000;
        printf("%07lld\n", resp); /*Imprimir ate 7 casas, preencher com 0's a esquerda + double com precisao .0*/
    }
    return 0;
}
