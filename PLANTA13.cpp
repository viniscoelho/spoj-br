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

int tree[100100];

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	char p;
	cin >> n >> k;
	
	for ( int i = 0; i < k; i++ )
		cin >> tree[i];
	
	sort(tree, tree+k);
	
	long long sum = 0, resp = 0;
	int dead = 0, d = 0;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> p;
		if ( p == 'C' ) d++;
		else d--;
		
		sum += d;
		
		while ( tree[dead] <= -d && dead < k )
		{
			resp += sum + i*tree[dead++];
		}
	}
	
	while ( dead < k )
	{
		resp += sum + n*tree[dead++];
	}
	cout << resp << endl;
	return 0;
}