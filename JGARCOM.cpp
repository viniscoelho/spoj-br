/*
	Resolucao:
		Determinar o numero de copos quebrados
		Verificando se tem mais do que copos na bandeja
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int b, l, c, sum = 0;
    cin >> b;
    for (int i = 0; i < b; ++i) {
        cin >> l >> c;
        if (l > c)
            sum += c;
    }
    cout << sum;
    return 0;
}
