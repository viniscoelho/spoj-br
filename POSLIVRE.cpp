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
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long int64;
typedef pair<int, int> ii;

map<int, ii> positions;

int dir[][2] = {
    { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }
};

int matrix[510][510], v = 1;

int main()
{
    ios::sync_with_stdio(false);
    int w, h, n;
    int x1, x2, y1, y2;
    while (cin >> w >> h >> n && w + h + n) {
        int count = w * h;
        for (int i = 0; i < n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            int xMin = min(x1, x2);
            int xMax = max(x1, x2);
            int yMin = min(y1, y2);
            int yMax = max(y1, y2);

            for (int i = xMin - 1; i < xMax; i++)
                for (int j = yMin - 1; j < yMax; j++) {
                    if (matrix[i][j] != v)
                        count--;
                    matrix[i][j] = v;
                }
        }
        if (count == 0)
            cout << "There is no empty spots.\n";
        else if (count == 1)
            cout << "There is one empty spot.\n";
        else if (count > 1)
            cout << "There are " << count << " empty spots.\n";
        v++;
    }

    return 0;
}