#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef unsigned long long int64;

int a, n;

const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	priority_queue<ii> pq;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		vi trail(a);
		int f = 1, b = 1, MAX = 0;
		for (int j = 0; j < a; ++j)
		{
			cin >> trail[j];
			if (j == 0)
				MAX = trail[j];
			else if (trail[j] - MAX > 0)
			{
				f += trail[j] - MAX;
				MAX = trail[j];
			}
			else
				MAX = trail[j];
		}
		MAX = 0;
		for (int j = a - 1; j >= 0; --j)
		{
			if (j == a - 1)
				MAX = trail[j];
			else if (trail[j] - MAX > 0)
			{
				b += trail[j] - MAX;
				MAX = trail[j];
			}
			else
				MAX = trail[j];
		}
		pq.push(mp(-min(b, f), -i));
	}
	cout << -pq.top().second;
	return 0;
}
