/*
	Resolucao:
		Contabiliza o numero de notas comecando da nota de maior valor
		As demais sao contabilizadas a partir do restante de dinheiro
*/

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int v, n = 1;
    for ( cin >> v; v != 0; cin >> v ){
        int i = 0, j = 0, k = 0, l = 0, div = 0, aux = 0;
        div = v/50;
        aux = v;
        if ( div >= 1 ){
			i = div;
			aux -= 50*i;
        }
        div = aux/10;
        if ( div >= 1 ){
			j = div;
			aux -= 10*j;
        }
        div = aux/5;
        if ( div >= 1 ){
			k = div;
			aux -= 5*k;
        }
        div = aux;
        if ( div >= 1 ){
			l = div;
			aux -= l;
        }
        cout << "Teste " << n++ << "\n";
        cout << i << " " << j << " " <<  k << " " << l << "\n\n";
    }
    return 0;
}
