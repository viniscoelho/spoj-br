#include <iostream>
#include <vector>
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
#define MAXV 10100

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int64;

int main(){
	ios::sync_with_stdio(false);
	int64 m, a, b;
	while ( cin >> m && m ){
		vector<int64> monkey;
		for ( int k = 0; k < m; ++k ){
			cin >> a;
			monkey.pb(a);
		}
		sort( monkey.begin(), monkey.end() );
		int64 MAX = monkey[0]+monkey[m-1], i = 1, j = m-2;
		while ( i < m/2 ){
			MAX = max(MAX, monkey[i]+monkey[j]);
			i++, j--;
		}
		cout << MAX << "\n";
	}
	return 0;
}
