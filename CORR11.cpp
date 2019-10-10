/*
	Resolucao:
		Ordenar os carros de acordo com o menor tempo
		Os carros com os 3 menores tempo sao impressos,
		do menor tempo para o maior
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    int m, n, x;
    cin >> n >> m;
    priority_queue<ii> corrida;
    for (int i = 0; i < n; ++i)
    {
        int soma = 0;
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            soma += x;
        }
        corrida.push(ii(-soma, i + 1));
    }
    int cont = 0;
    while (cont < 3)
    {
        cout << corrida.top().second << "\n";
        corrida.pop();
        cont++;
    }
    return 0;
}
