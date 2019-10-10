/*
	Resolucao:
		Uso de uma priority queue para calcular o maior saldo de gols
		durante um maior periodo
*/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    int n, t = 1, x, y;
    for (cin >> n; n != 0; cin >> n)
    {
        cout << "Teste " << t++ << "\n";
        int pro[n], contra[n];
        for (int i = 0; i < n; ++i)
            cin >> pro[i] >> contra[i];
        int b = -1, e = -1, j;
        int MAX = 0;
        priority_queue<pair<ii, ii>> pq;
        for (int i = 0; i < n; ++i)
        {
            if (pro[i] - contra[i] >= 0)
            {
                int soma = 0;
                for (j = i; soma >= 0 && j < n; ++j)
                {
                    soma += pro[j] - contra[j];
                    if (soma >= MAX)
                    {
                        MAX = soma;
                        pq.push(make_pair(make_pair(MAX, j - i), make_pair(i + 1, j + 1)));
                    }
                }
            }
        }
        if (MAX == 0)
            cout << "nenhum\n\n";
        else
            cout << pq.top().second.first << " " << pq.top().second.second << "\n\n";
    }
    return 0;
}
