#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <cstdio>
#include <map>
#define MAX 500
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef long long int64;

const int INF = 0x3f3f3f3f;

int64 a, b, n;

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	while (cin >> n && n)
	{
		cout << "Teste " << t++ << "\n";
		vector<map<int, int>> senha(6);
		map<int, int>::iterator mit;
		for (int i = 0; i < n; ++i)
		{
			pair<map<int, int>::iterator, bool> ver;
			map<char, ii> pass;

			char c = 'A', d;
			for (int j = 0; j < 5; ++j)
			{
				cin >> a >> b;
				pass.insert(mp(c++, mp(a, b)));
			}
			for (int i = 0; i < 6; ++i)
			{
				cin >> d;
				ver = senha[i].insert(mp(pass[d].first, 1));
				if (!ver.second)
					senha[i][pass[d].first]++;
				ver = senha[i].insert(mp(pass[d].second, 1));
				if (!ver.second)
					senha[i][pass[d].second]++;
			}
		}
		for (int i = 0; i < 6; ++i)
		{
			priority_queue<int> pq;
			ii resp = mp(-1, -1);
			for (mit = senha[i].begin(); mit != senha[i].end(); ++mit)
				if (mit->second > resp.second)
				{
					resp.second = mit->second;
					resp.first = mit->first;
				}
			if (i == 0)
				cout << resp.first;
			else
				cout << " " << resp.first;
		}
		cout << "\n\n";
	}

	return 0;
}
