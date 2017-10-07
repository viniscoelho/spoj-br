/*
	Resolucao:
		Determinar o numero de consultas que podem ser realizadas sem que
		o horario choque
*/
#include <vector>
#include <iostream>
#include <algorithm>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(false);
    int n, x1, x2;
    cin >> n;
    vector<ii> dent;
    vector<ii>::iterator it, resp;
    int cont = 0;
    for ( int i = 0; i < n; ++i ){
        cin >> x1 >> x2;
        dent.pb( mp( x2, x1 ) );
    }
    sort( dent.begin(), dent.end() );
    it = dent.begin();
    while ( it != dent.end() ){
		cont++;
		resp = it++;
		while ( it != dent.end() && resp->first > it->second ) it++;
    }
    cout << cont;
    return 0;
}
