#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#define mp make_pair
#define pb push_back
#define MAXV 210
#define COLOR 0

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<string, string> ss;
typedef pair<ss, int> ssi;

vector< list<int> > graph(MAXV);

int visited[MAXV], v = 1, num = 0, e;
bool flag;

void BFS ( int u ){
	list<int>::iterator it;
	queue<ii> bfs;
	bfs.push( mp(u, 0) );
	bool ok = false;
	while ( !bfs.empty() ){
		int x = bfs.front().first, y = bfs.front().second;
		bfs.pop();
		for ( it = graph[x].begin(); it != graph[x].end(); ++it )
			if ( visited[*it] != v ){
				if ( *it != e ){
					num = max(y+1, num);
					bfs.push( mp(*it, y+1) );
					visited[*it] = v;
				}
				else{
					num = max(y+1, num);
					ok = flag = true;
					break;
				}
			}
		if ( ok ) break;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, p, t = 1;
	while ( cin >> n && n ){
		cout << "Teste " << t++ << "\n";
		cin.ignore();
		string mat;
		map<string, int> erdos;
		pair<map<string, int>::iterator, bool> ret;
		vector<ss> resp;
		int qtd = 0;
		flag = false, e = -1;
		for ( int i = 0; i < n; ++i ){
			getline(cin, mat);
			int pos = 0, x;
			vector<int> monta;
			while ( pos < mat.size()-1 ){
				string a, b;
				while ( pos < mat.size()-1 && mat[pos] != ',' )
					a += mat[pos++];
				pos += 2;
				b = a.substr( 3, a.size() );
				ret = erdos.insert( mp( a, qtd ) );
				if ( ret.second ){
					resp.pb( mp(b, a) );
					qtd++;
				}
				if ( a.compare("P. Erdos") == 0 ) e = erdos[a];
				x = erdos[a];
				monta.pb(x);
			}
			for ( int i = 0; i < monta.size(); ++i )
				for ( int j = i+1; j < monta.size(); ++j ){
					graph[monta[i]].pb(monta[j]);
					graph[monta[j]].pb(monta[i]);
				}
			if ( monta.size() == 1 ) graph[monta[0]].pb(monta[0]);
		}
		sort(resp.begin(), resp.end());
		for ( int i = 0; i < resp.size(); ++i ){
			int y = erdos[resp[i].second];
			if ( y != e ){
				visited[y] = v;
				BFS(y);
				if ( flag ) cout << resp[i].second << ": " << num << "\n";
				else cout << resp[i].second << ": infinito\n";
				v++, num = 0, flag = false;
			}
		}
		cout << "\n";
		for ( int i = 0; i < qtd; ++i ) graph[i].clear();
	}
	return 0;
}

