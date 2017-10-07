#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#define mp make_pair
#define pb push_back
#define MAXV 310

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, string> is;

bool visitado[MAXV];

int main(){
	ios::sync_with_stdio(false);
	int m, n;
	cin >> m;
	n = m;
	string a, b;
	priority_queue<is> truque;
	int acc = 0, ok = 0;
	while ( m-- ){
		cin >> a;
		if ( !ok && (acc + a.size()) <= n ){
			acc += a.size();
			truque.push( mp( -acc, a ) );
			visitado[acc] = true;
		}
		else if ( !acc && a.size() > n ){
				acc = a.size() % n;
				if ( !acc ) acc = n;
				truque.push( mp( -(acc), a ) );
				visitado[acc] = true;
				ok = 1;
		}
		else{
			ok = 1;
			if ( acc == n ) acc = 1;
			else acc++;
			int qtd = 0;
			while ( qtd < a.size() ){
				if ( !visitado[acc] ) qtd++;
				if ( qtd == a.size() ) break;
				if ( acc == n ) acc = 1;
				else acc++;
			}
			truque.push( mp( -(acc), a ) );
			visitado[acc] = true;
		}
	}
	int cont = 0;
	while ( !truque.empty() ){
		cout << truque.top().second << "\n";
		truque.pop();
	}
	
	return 0;
}


