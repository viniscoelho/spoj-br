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
#include <tr1/unordered_map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#define mp make_pair
#define pb push_back
#define COLOR 0

using namespace std;
using namespace tr1;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<string, string> ss;
typedef pair<int, ss> iss;

int main(){
	ios::sync_with_stdio(false);
	int n, p;
	while ( cin >> n && n ){
		unordered_map<int, int> hist;
		pair<unordered_map<int, int>::iterator, bool> ret;
		int ans = 0, t = 0;
		list<int> ps;
		list<int>::iterator li;
		for ( int i = 0; i < n; ++i ){
			cin >> p;
			if ( !ans ){
				ans += p;
				ret = hist.insert( mp(p, p) );
				ps.push_front(p);
				t++;
			}
			else{
				ret = hist.insert( mp(p, p) );
				if ( !ret.second ){
					int c = 1;
					li = ps.begin();
					while ( *li != p ){
						c++;
						li++;
					}
					ps.push_front(p);
					ans += c;
					t++;
				}
				else{
					ps.push_front(p);
					ans += p+t;
					t++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
