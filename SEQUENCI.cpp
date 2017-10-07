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
#include <cstring>
#include <cstdio>
#define mp make_pair
#define pb push_back
#define MAXV 100100
#define INF 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef pair<int, string> is;
typedef unsigned long long int64;

int m[1010], seq[1010];

int main(){
	ios::sync_with_stdio(false);
	int n, t = 1;
	while ( cin >> n ){
		cout << "Case #" << t++ << ":";
		vector<int> a(n);
		int MAX = -INF;
		bool flag = false;
		for ( int i = 0; i < n ; i++ ){
			cin >> a[i];
			cout << " " << a[i];
			if ( a[i] > MAX ) MAX = a[i];
			else flag = true;
		}
		for( int i = 0; i <= MAX; i++ )
			m[i] = seq[i] = 0;
		m[0] = 1;
		for ( int i = 0; i < n ; i++ )
			for ( int j = MAX; j >= a[i]; j-- ){
				m[j] |= m[j-a[i]];
				if ( m[j] ) seq[j]++;
			}
		for ( int i = 0; i < n ; i++ )
			if ( seq[a[i]] > 1 ){
				flag = true;
				break;
			}
		if ( !flag ) cout << "\nThis is an A-sequence.\n";
		else cout << "\nThis is not an A-sequence.\n";
		
	}
	return 0;
}


