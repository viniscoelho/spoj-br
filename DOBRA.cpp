/*
	Resolucao:
		Formula fechada;
		O numero de dobraduras e dado por (pow(2, n) + 1)*(pow(2, n) + 1)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int k = 1;
    double n;
    for (cin >> n; n != -1.0; cin >> n)
    {
        int x = (int)pow(2, n) + 1;
        x *= x;
        cout << "Teste " << k++ << "\n";
        cout << x << "\n\n";
    }
    return 0;
}
