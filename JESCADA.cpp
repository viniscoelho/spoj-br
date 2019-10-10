/*
	Resolucao:
		Contabilizar o tempo que a escada ficou ligada depois de p pessoas
		andarem nela
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int p, t, sum = 0, aux = 0;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> t;
        if (t >= aux)
            sum += 10;
        else
            sum += t + 10 - aux;
        aux = t + 10;
    }
    cout << sum;
    return 0;
}
