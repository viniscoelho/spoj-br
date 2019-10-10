#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, string> is;

bool func(is a, is b)
{
	if ((a.first) > (b.first))
		return true;
	else if ((a.first) == (b.first))
		if ((a.second).compare(b.second) < 0)
			return true;
		else
			return false;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k = 1;
	for (cin >> n; n != 0; cin >> n)
	{
		cin.ignore();
		cout << "Teste " << k++ << "\n";
		vector<is> tetris;
		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			int sum = 0, x;
			string str;
			cin >> str;
			for (int j = 0; j < 12; j++)
			{
				cin >> x;
				v.push_back(x);
			}
			sort(v.begin(), v.end());
			for (int j = 1; j < 11; j++)
				sum += v[j];
			tetris.push_back(make_pair(sum, str));
		}
		sort(tetris.begin(), tetris.end(), func);
		int count = 1;
		for (int i = 0; i < tetris.size(); ++i)
		{
			int ant = 0;
			cout << count << " " << tetris[i].first << " " << tetris[i].second << "\n";
			while (i + 1 < tetris.size() && tetris[i].first == tetris[i + 1].first)
			{
				cout << count << " " << tetris[i + 1].first << " " << tetris[i + 1].second << "\n";
				i++;
				ant++;
			}
			count += ant;
			count++;
		}
		cout << "\n";
	}
	return 0;
}
