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

int main()
{
	ios::sync_with_stdio(false);
	int a, soma = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		soma += a;
	}
	cout << soma - 3 << endl;
	return 0;
}