/*
	Resolucao:
		Verificar se a diagonal da caixa
		e maior ou igual a diametro da bola
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    double l, a, p, r;
    cin >> l >> a >> p >> r;
    double c1 = l * l + p * p;
    double d = sqrt(a * a + c1);
    if (d <= 2 * r)
        cout << "S";
    else
        cout << "N";
    return 0;
}