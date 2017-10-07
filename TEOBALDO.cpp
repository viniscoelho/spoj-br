/*
	Resolucao:
		Verifica se Teobaldo consegue chegar ao seu destino realizando multiplicacao
		de matrizes. Se depois de n iteracoes o destino = 'true', entao Teobaldo
		pode viajar.
*/


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <map>
#include <bitset>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

const int INF = 0x3f3f3f3f;

int num;

bool travel[110][110], teoa[110], teob[110];

int main(){
    ios::sync_with_stdio(false);
	int a, b, m, n, s, e, d;
	while ( cin >> m >> n && m + n ){
		for ( int i = 0; i < m; ++i ){
			for ( int j = i; j < m; ++j )
				travel[i][j] = travel[j][i] = false;
			travel[i][i] = false;
			teoa[i] = teob[i] = false;
		}
		for ( int i = 0; i < n; ++i ){
			cin >> a >> b;
			travel[a-1][b-1] = travel[b-1][a-1] = true;
		}
		cin >> s >> e >> d;
		teob[s-1] = true;
		for ( int k = 0; k < d; ++k ){
			for ( int i = 0; i < m; ++i ){
				for ( int j = 0; j < m; ++j )
					teoa[i] |= (teob[j] & travel[j][i]);
			}
			for ( int i = 0; i < m; ++i ){
				teob[i] = teoa[i];
				teoa[i] = false;
			}
		}
		if ( teob[e-1] ) cout << "Yes, Teobaldo can travel.\n";
		else cout << "No, Teobaldo can not travel.\n";
	}
    return 0;
}
