#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <map>
#define mp make_pair
#define pb push_back
#define MAXV 200100

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int64;

int main(){
	ios::sync_with_stdio(false);
	int v, t, a;
	cin >> v >> t;
	while ( t-- )
	{
		cin >> a;
		v += a;
		if ( v < 0 ) v = 0;
		if ( v > 100 ) v = 100;
	}
	cout << v << endl;
	return 0;
}