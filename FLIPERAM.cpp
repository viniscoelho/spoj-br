/*
	Resolucao:
		Ordenar as entradas do maior para o menor
		e imprimir as m melhores pontuacoes
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    int m, n, aux;
    cin >> n >> m;
    vector<int> x(n);
    if (m <= n) {
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x.begin(), x.end(), comp);
    }
    for (int i = 0; i < m; ++i)
        cout << x[i] << "\n";
    return 0;
}
