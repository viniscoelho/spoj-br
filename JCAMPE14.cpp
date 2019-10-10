#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAXV 200100

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int64;

int main()
{
    ios::sync_with_stdio(false);
    int a, b, c1, c2;
    cin >> a >> b >> c1;
    int corP = a * 3 + b;
    cin >> a >> b >> c2;
    int flaP = a * 3 + b;
    if (corP == flaP) {
        if (c1 == c2)
            cout << "=\n";
        else if (c1 > c2)
            cout << "C\n";
        else
            cout << "F\n";
    } else if (corP > flaP)
        cout << "C";
    else
        cout << "F";
    return 0;
}