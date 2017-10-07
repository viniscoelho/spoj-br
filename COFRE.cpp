/*
	Resolucao:
		Contabiliza a diferenca entre os depositos em cada cofre
		E entao imprime a diferenca entre os cofres de Joaozinho e Zezinho, neste ordem
		para cada iteracao
*/

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, j, z, t = 1;
    for ( cin >> n; n != 0; cin >> n ){
        int aux[n], p = 0;
        for ( int i = 0; i < n; i++ ){
            cin >> j >> z;
            p += j - z;
            aux[i] = p;
        }
        cout << "Teste " <<  t++ << "\n";
        for ( int i = 0; i < n; i++ )
            cout << aux[i] << "\n";
        cout << "\n";
    }
    return 0;
}
