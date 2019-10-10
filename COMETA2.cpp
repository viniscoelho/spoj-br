/*
	Resolucao:
		Divide o ano dado pelo numero de anos que o cometa passa (76)
		Multiplica por 76 esse numero e soma 10 ao resultado, resultando em um ano
		que o cometa passa
		Imprime um resultado que seja diferente do ano dado.
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int ano, sum = 0;
    cin >> ano;
    int m = ano / 76;
    sum = m * 76 + 10;
    if (sum <= ano)
        sum += 76;
    cout << sum;
    return 0;
}
