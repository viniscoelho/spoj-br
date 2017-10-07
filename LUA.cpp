/*
	Resolucao:
		Calcular a menor e a maior temperatura
		A ideia e calcular em O(n), senao da tempo limite.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main ( ){
    ios::sync_with_stdio(false);
    int n = -1, m = -1, k = 1;
    for ( cin >> n >> m; n != 0 || m != 0; cin >> n >> m ){
		int dados[n], maior, menor, soma = 0;
		for ( int i = 0; i < n; ++i ){
			cin >> dados[i];
			if ( i < m ) soma += dados[i];
		}
		maior = menor = soma;
		for ( int j = 1; j < n; ++j ){
			if ( j+m-1 < n ) soma = soma - dados[j-1] + dados[j+m-1];
			maior = max( maior, soma );
			menor = min( menor, soma );
		}
		cout << "Teste " << k++ << "\n";
		cout << menor/m << " " << maior/m << "\n\n";
    }    
    return 0;
}