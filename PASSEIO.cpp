#include <iostream>
#include <algorithm>

using namespace std;

bool conexao[155][155];
int pontos[155], max_p[155];

int max_tam( int i, int p ){
    int aux;
    if ( max_p[i] == 0 ){
		for ( int j = 0; j < p; ++j ){
			if ( conexao[i][j] ){
				aux = max_tam(j, p) + 1;
				if ( aux > max_p[i] ) max_p[i] = aux;
			}
		}
    }
    return max_p[i];
}

int main(){
    ios::sync_with_stdio(false);
    int p, l, b, x, y, t = 1;
    for ( cin >> p >> l >> b; p != 0 && l != 0 && b != 0; cin >> p >> l >> b ){
        cout << "Teste " << t++ << endl;
        for ( int i = 0; i < p; ++i )
            cin >> pontos[i];
        for ( int i = 0; i < p; ++i ){
            for ( int j = i; j < p; ++j )
                conexao[i][j] = conexao[j][i] = false;
            conexao[i][i] = false;
            max_p[i] = 0;
        }
        for ( int i = 0; i < l; ++i ){
            cin >> x >> y;
            if ( pontos[x-1] - pontos[y-1] > 0 ) conexao[x-1][y-1] = true;
        }
        cout << max_tam(b-1, p) << "\n\n";
    }
    return 0;
}
