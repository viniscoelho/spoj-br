/*
	Resolucao:
		Verificar se em algum momento a capacidade do elevador
		foi excedida.
*/

#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    int n, c, s, e, total = 0;
    bool flag = false;
    cin >> n >> c;
    for ( int i = 0; i < n; ++i ){
        cin >> s >> e;
        total += e-s;
        if ( total > c ) flag = true;
    }
    if ( flag ) cout << "S";
    else cout << "N";
    return 0;
}
