#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int l, d, k, p;
    cin >> l >> d >> k >> p;
    cout << l * k + (l / d) * p;
    return 0;
}