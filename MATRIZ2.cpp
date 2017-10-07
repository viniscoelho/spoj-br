/*
	Resolucao:
		Gerar uma matriz de acordo com a formula dada
		e entao imprimir o valor da posicao a,b;
*/

#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    int a, b, p, q, n, r, s, x, y;
    cin >> n;
    cin >> p >> q >> r >> s >> x >> y;
    cin >> a >> b;
    long long resp = 0;
    for ( int i = 0; i < n; ++i )
        resp += (( p*a + q*(i+1) ) % x) * (( r*(i+1) + s*b ) % y);
    cout << resp;
    return 0;
}