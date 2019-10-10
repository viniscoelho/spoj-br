/*
	Resolucao:
		Calcular a distancia percorrida dado o tempo decorrido
		e a velocidade media
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, t, v, soma = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> v;
        soma += t * v;
    }
    cout << soma;
    return 0;
}