#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    double n, p;
    for (cin >> n >> p; n != 0. && p != 0.; cin >> n >> p)
    {
        double resp = ceil(n / p);
        if (resp <= 6.)
            cout << "Poodle\n";
        else
        {
            cout << "Poo";
            int i = 0;
            while (i < 14 && i < resp - 6)
            {
                cout << "o";
                i++;
            }
            cout << "dle\n";
        }
    }
    return 0;
}
