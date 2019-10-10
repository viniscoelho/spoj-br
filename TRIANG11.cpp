#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	int x = b - c, y = a - c, z = a - b;
	x = abs(x), y = abs(y), z = abs(z);
	if (!(x < a && a < b + c) && !(y < b && b < a + c) && !(z < c && c < a + b))
		cout << 'n';
	else if ((a * a == b * b + c * c) || (b * b == c * c + a * a) || (c * c == b * b + a * a))
		cout << 'r';
	else if ((a * a > b * b + c * c) || (b * b > a * a + c * c) || (c * c > b * b + a * a))
		cout << 'o';
	else if ((a * a < b * b + c * c) || (b * b < a * a + c * c) || (c * c < a * a + b * b))
		cout << 'a';
	return 0;
}
