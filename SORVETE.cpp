#include <vector>
#include <iostream>
#include <algorithm>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int main()
{
	ios::sync_with_stdio(false);
	int c, s, p = 1;
	for (cin >> c >> s; c + s != 0; cin >> c >> s)
	{
		cout << "Teste " << p++ << "\n";
		int x1, x2, sum = 0;
		vector<ii> sorvete;
		vector<ii>::iterator it, resp;
		for (int i = 0; i < s; ++i)
		{
			cin >> x1 >> x2;
			sorvete.push_back(mp(x1, x2));
		}
		sort(sorvete.begin(), sorvete.end());
		it = sorvete.begin();
		while (it != sorvete.end())
		{
			resp = it++;
			int a = resp->first;
			int b = resp->second;
			while (b >= it->first && it != sorvete.end())
			{
				if (b == it->first)
					b = it->second;
				else if (b > it->first && b < it->second)
					b = it->second;
				it++;
			}
			cout << a << " " << b << "\n";
		}
		cout << "\n";
	}
	return 0;
}
