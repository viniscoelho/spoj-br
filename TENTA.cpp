/*
	Resolucao:
		Calcular todas as permutacoes entre os numeros dados
		Primeiramente, ordena-se os numeros e utiliza uma funcao da lib
		algorithm 'next_permutation', que gera todas as permutacoes entre
		esses numeros
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int n;
    for ( scanf("%d", &n); n != 0; scanf("%d", &n) ){
        vector<ll> tenta;
        ll x;
        for ( int i = 0; i < n; ++i ){
            scanf("%lld", &x);
            tenta.push_back(x);
        }
        sort(tenta.begin(), tenta.end());
        do{
			for ( int i = 0; i < n; ++i )
				printf("%lld ", tenta[i]);
			printf("\n");
        } while ( next_permutation ( tenta.begin(), tenta.end()) );
        printf("\n");
    }
    return 0;
}
