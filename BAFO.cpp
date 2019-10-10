/*
	Resolucao:
		Soma o numero de figurinhas que cada um virou
		Quem virar mais, ganha o jogo
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int r, a, b, j = 1;
    for (cin >> r; r != 0; cin >> r) {
        int aldo = 0, beto = 0;
        for (int i = 0; i < r; i++) {
            cin >> a >> b;
            aldo = aldo + a;
            beto = beto + b;
        }
        cout << "Teste " << j++ << "\n";
        if (aldo > beto)
            cout << "Aldo\n\n";
        else
            cout << "Beto\n\n";
    }
    return 0;
}
