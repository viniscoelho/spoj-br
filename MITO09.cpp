#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAX 220

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef unsigned long long int64;

int a, b, n;
int myth[510][510];

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    bool flag = false;
    while (n--) {
        cin >> a >> b;
        if (myth[a][b] == 0)
            myth[a][b]++;
        else
            flag = true;
    }
    if (flag)
        cout << "1";
    else
        cout << "0";
    return 0;
}
