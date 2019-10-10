#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAXV 10010
#define COLOR 0

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<list<int>> graph(MAXV);
int dfs_low[MAXV], dfs_num[MAXV];
int dfs_parent[MAXV], articulation_vertex[MAXV];

int counter, r, c, q, rootChildren, dfsRoot;
bool flag = false;

void PointBridge(int u)
{
    dfs_low[u] = dfs_num[u] = counter++;
    list<int>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i) {
        if (dfs_num[*i] == COLOR) {
            dfs_parent[*i] = u;
            if (u == dfsRoot)
                rootChildren++;
            PointBridge(*i);
            if (dfs_low[*i] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[*i] > dfs_num[u]) {
                flag = true;
                return;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[*i]);
        } else if (*i != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[*i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int de, para;
    while (cin >> r >> c && r + c) {
        for (int i = 0; i < r; ++i) {
            dfs_low[i] = dfs_num[i] = COLOR;
            dfs_parent[i] = articulation_vertex[i] = COLOR;
            graph[i].clear();
        }
        counter = 0;
        for (int i = 0; i < c; ++i) {
            cin >> de >> para;
            graph[de - 1].pb(para - 1);
            graph[para - 1].pb(de - 1);
        }
        for (int k = 0; k < r; k++) {
            if (dfs_num[k] == COLOR) {
                dfsRoot = k, rootChildren = 0;
                PointBridge(k);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        if (flag)
            cout << "N\n";
        else
            cout << "S\n";
        flag = false;
    }
    return 0;
}
