#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a[4], maior = 0, soma = 0;
	for (int i = 0; i < 4; i++)
		cin >> a[i];
	if (a[0] * a[1] == a[2] * a[3] || a[0] * a[2] == a[1] * a[3] || a[0] * a[3] == a[1] * a[2])
		cout << "S\n";
	else
		cout << "N\n";

	return 0;
}
