/*
	Resolucao:
		Calcular qual corredor obteve o menos tempo entre todos.
*/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, x, y;
    cin >> n >> m;
    int menor = 0x3f3f3f3f, num = -1;
    for (int i = 0; i < n; ++i) {
        int soma = 0;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            soma += x;
        }
        if (soma < menor) {
            menor = soma;
            num = i + 1;
        }
    }
    cout << num;
    return 0;
}
