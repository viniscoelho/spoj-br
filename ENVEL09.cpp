/*
	Resolucao:
		Manter um array que contenha o numero de rotulos
		A resposta e o menor numero de rotulos, ou seja, o numero
		de envelopes que ele pode enviar
*/

#include <iostream>
#include <algorithm>

using namespace std;

int envelope[1010], MIN = 0x3f3f3f3f; 

int main(){
    ios::sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m;
    for ( int i = 0; i < n; ++i ){
        cin >> x;
        envelope[x-1]++;
    }
    for ( int i = 0; i < m; ++i ) MIN = min( MIN, envelope[i] );
    cout << MIN;
    return 0;   
}
