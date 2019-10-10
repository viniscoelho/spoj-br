/*
	Resolucao:
		Verificar se a soma da diagonal principal e a da linha
		sao iguais.
		Se sim, e um quadrado magico
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, l = -1, d = 0, num;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int soma = 0;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            soma += num;
            if (i == j)
                d += num;
        }
        if (l == -1)
            l = soma;
        else if (l != soma) {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "0";
    else
        cout << d;
    return 0;
}