/*
	Resolucao:
		Modelado para 2-Sat: A ideia e converter a entrada em duas componentes, por exemplo
		se a entrada for a->b, entao as duas componentes serao: !b || a e !a || b... e segue esse mesmo principio
		para os demais tipos de entrada. Depois, basta verificar se existe uma componente fortemente conexa que
		contem uma literal e sua negacao; se houver tal componente entao nao e possivel satisfazer as clausulas da entrada,
		caso contrario e possivel.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <tr1/unordered_map>
#define MAX 4000
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f

using namespace std;
using namespace tr1;

typedef pair<short, short> ii;
typedef pair<short, bool> ib;
typedef vector<short> vi;

short m, n, counter, flag, num;
short visited[MAX], dfs_low[MAX], dfs_num[MAX];
vector< list<short> > graph(MAX);
vi S;

void tarjan( short u ){
	dfs_low[u] = dfs_num[u] = counter++;
	visited[u] = 1;
	S.pb(u);
	list<short>::iterator li;
	for ( li = graph[u].begin(); li != graph[u].end(); ++li ){
		if ( !dfs_num[*li] ) tarjan(*li);
		if ( visited[*li] ) dfs_low[u] = min( dfs_low[u], dfs_low[*li] );
	}
	if ( dfs_low[u] == dfs_num[u] ){
		unordered_map<short, short> resp;
		pair<unordered_map<short, short>::iterator, bool> ret;
        while ( 1 ){
			short vertex = S.back(); S.pop_back(); visited[vertex] = 0;
			ret = resp.insert( mp(vertex%2000, 0) );
			if ( !ret.second ){
				flag = true;
				break;
			}
			if ( u == vertex ) break;
        }
	}
}

int main(){
    ios::sync_with_stdio(false);
    int t = 1;
	string food1, food2, vertex;
    while ( cin >> n ){
		counter = flag = num = 0;
		cout << "Instancia " << t++ << "\n";
		for ( short i = 0, j = 2000; i < 2*n; ++i, ++j ){
			dfs_num[i] = dfs_num[j] = 0;
			dfs_low[i] = dfs_low[j] = 0;
			graph[i].clear(); graph[j].clear();
		}
		unordered_map<string, ib> ref;
		pair<unordered_map<string, ib>::iterator, bool> ret;
		for ( short i = 0; i < n; ++i ){
			ib a, b;
			cin >> food1 >> food2;
			if ( food1[0] == '!' ){
				vertex = food1.substr( 1, food1.size() );
				ret = ref.insert( mp( vertex, mp(num+2000, false) ) );
				if ( ret.second ){
					a = mp( num+2000, false );
					num++;
				}
				else{
					a = ref[vertex];
					if ( a.second ){
						a.first += 2000;
						a.second = false;
					}
				}
			}
			else {
				ret = ref.insert( mp( food1, mp(num, true) ) );
				if ( ret.second ){
					a = mp( num, true );
					num++;
				}
				else{
					a = ref[food1];
					if ( !a.second ){
						a.first = a.first%2000;
						a.second = true;
					}
				}
			}
			
			if ( food2[0] == '!' ){
				vertex = food2.substr( 1, food2.size() );
				ret = ref.insert( mp( vertex, mp(num+2000, false) ) );
				if ( ret.second ){
					b = mp( num+2000, false );
					num++;
				}
				else{
					b = ref[vertex];
					if ( b.second ){
						b.first += 2000;
						b.second = false;
					}
				}
			}
			else {
				ret = ref.insert( mp( food2, mp(num, true) ) );
				if ( ret.second ){
					b = mp( num, true );
					num++;
				}
				else{
					b = ref[food2];
					if ( !b.second ){
						b.first = b.first%2000;
						b.second = true;
					}
				}
			}
			
			if ( a.second && b.second ){
				graph[a.first+2000].pb( b.first );
				graph[b.first+2000].pb( a.first );
			}
			else if ( a.second && !b.second ){
					graph[a.first+2000].pb( b.first );
					graph[b.first%2000].pb( a.first );
			}
			else if ( !a.second && b.second ){
					graph[a.first%2000].pb( b.first );
					graph[b.first+2000].pb( a.first );
			}
			else{
				graph[a.first%2000].pb( b.first );
				graph[b.first%2000].pb( a.first );
			}
		}
        for ( short i = 0; i < num; ++i )
			if ( !dfs_num[i] ){
				tarjan(i);
				if ( flag ) break;
			}
		if ( flag ) cout << "nao\n\n";
		else cout << "sim\n\n";
    }
       
    return 0;
}
