#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <cstdio>
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int toads[110], n, m;

void pula_tras(int pos, int b)
{
	if (pos < 0)
		return;
	toads[pos] = 1;
	pula_tras(pos - b, b);
}

void pula_frente(int pos, int b)
{
	if (pos >= n)
		return;
	toads[pos] = 1;
	pula_frente(pos + b, b);
}

int main()
{
	ios::sync_with_stdio(false);
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		toads[a - 1] = 1;
		pula_tras(a - b - 1, b);
		pula_frente(a + b - 1, b);
	}
	for (int i = 0; i < n; ++i)
		cout << toads[i] << "\n";
	return 0;
}
