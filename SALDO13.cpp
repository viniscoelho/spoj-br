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
    int n, s, x, min_saldo;
    cin >> n >> s;
    min_saldo = s;
    while (n--) {
        cin >> x;
        s += x;
        min_saldo = min(min_saldo, s);
    }
    cout << min_saldo << endl;
    return 0;
}