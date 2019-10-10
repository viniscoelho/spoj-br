#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n, a;
    for (cin >> n; n != 0; cin >> n)
    {
        string bin;
        long long a = n;
        int p = 0, par = 0;
        while (a != 0)
        {
            if (n & (1 << p))
            {
                bin += '1';
                par++;
            }
            else
                bin += '0';
            p++;
            a /= 2;
        }
        cout << "The parity of ";
        for (int i = p - 1; i >= 0; i--)
            cout << bin[i];
        cout << " is " << par << " (mod 2).\n";
    }
    return 0;
}
