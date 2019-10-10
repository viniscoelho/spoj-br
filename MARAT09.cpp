/*
	Resolucao:
		Verificar se o corredor consegue completar a maratona
		Se a diferenca entre cada um dos postos de agua for
		menor ou igual a distancia que ele consegue percorrer,
		e possivel completar a maratona
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    bool flag = true;
    int x, soma = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x - soma <= m)
            soma = x;
        else
            flag = false;
    }
    if (42195 - soma > m)
        flag = false;
    if (flag)
        cout << "S";
    else
        cout << "N";
    return 0;
}