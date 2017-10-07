/*
	Resolucao:
		Uso de uma priority queue para determinar a posicao de cada pais
		na classificao de acordo com o numero de medalhas de
		ouro, prata e bronze nesta sequencia.
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(false);
    int m, n, o, p, b;
    cin >> n >> m;
    vector< vector<int> > ouro(n), prata(n), bronze(n);
    priority_queue< pair<ii, ii> > pq;
    for ( int i = 0; i < m; ++i ){
        cin >> o >> p >> b;
        ouro[o-1].push_back(1);
        prata[p-1].push_back(1);
        bronze[b-1].push_back(1);
    }
    for ( int i = 0; i < n; ++i )
        pq.push( mp( mp(ouro[i].size(), prata[i].size()), mp(bronze[i].size(), -(i+1)) ) );
    while ( !pq.empty() ){
		cout << -pq.top().second.second << " ";
		pq.pop();
    }
    return 0;
}
