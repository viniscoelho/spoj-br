/*
	Resolucao:
		Verificar se existe uma area que e interseccao de todas as areas
*/

#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    int n, a, b, c, d, x, y, w, z, t = 1;
    while (cin >> n && n) {
        cout << "Teste " << t++ << "\n";
        a = d = -INF;
        b = c = INF;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> w >> z;
            a = max(a, x);
            b = min(b, y);
            c = min(c, w);
            d = max(d, z);
        }
        if (a < c && d < b)
            cout << a << " " << b << " " << c << " " << d << "\n\n";
        else
            cout << "nenhum\n\n";
    }
    return 0;
}
