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

int main()
{
	ios::sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	if (x >= 0 && x <= 432 && y >= 0 && y <= 468)
		cout << "dentro";
	else
		cout << "fora";
	return 0;
}