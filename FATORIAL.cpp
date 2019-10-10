/*
	Resolucao:
		Memorizacao do ultimo digito de cada fatorial
		Remove os zeros do final e pega os 6 ultimos digitos do numero restante
		usando modulo por 100000
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long long prev = 1;
int resp[1000010];

void fatorial()
{
    for (int i = 1; i <= 1000000; ++i) {
        long long number = prev * i, n;
        while (number % 10 == 0)
            number = number / 10;
        n = number % 100000;
        prev = n;
        resp[i] = number % 10;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    long long str, i = 1;
    fatorial();
    while (cin >> str) {
        cout << "Instancia " << i++ << "\n";
        cout << resp[str] << "\n";
    }
    return 0;
}
