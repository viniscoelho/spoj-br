/*
	Resolucao:
		Verificar se a bola cabe na caixa dado o diametro
		da bola
*/

#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    int bola, h, l, c;
    cin >> bola;
    cin >> h >> l >> c;
    if ( bola <= h && bola <= l && bola <= c ) cout << "S";
    else cout << "N";
    return 0;
}