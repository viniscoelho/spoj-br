#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int mdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int num, den;
    if (b == d) {
        num = a + c;
        den = b;
    } else {
        num = a * d + c * b;
        den = b * d;
    }
    int m = mdc(num, den);
    cout << num / m << " " << den / m << endl;
    return 0;
}
