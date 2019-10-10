/*
	Resolucao:
		Obter a soma da maior sequencia positiva
		Caso nao haja, imprimir "Losing streak"
*/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int aposta[10100];

int main()
{
    ios::sync_with_stdio(false);
    int n, x, y;
    for (cin >> n; n != 0; cin >> n) {
        for (int i = 0; i < n; ++i)
            cin >> aposta[i];
        int b = -1, e = -1, j;
        int MAX = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            if (aposta[i] >= 0) {
                int soma = 0;
                for (j = i; soma >= 0 && j < n; ++j) {
                    soma += aposta[j];
                    if (soma >= MAX) {
                        MAX = soma;
                        pq.push(MAX);
                    }
                }
            }
        }
        if (pq.empty() || pq.top() <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << pq.top() << ".\n";
    }
    return 0;
}
