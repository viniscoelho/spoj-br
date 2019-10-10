#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    int m, n, o, p, b;
    cin >> n >> m;
    map<int, int> olim;
    priority_queue<ii> pq;
    for (int i = 0; i < n; ++i)
        olim.insert(make_pair(i + 1, 0));
    for (int i = 0; i < m; ++i)
    {
        cin >> o >> p >> b;
        olim[o]++;
        olim[p]++;
        olim[b]++;
    }
    for (map<int, int>::iterator mp = olim.begin(); mp != olim.end(); mp++)
        pq.push(make_pair(mp->second, -mp->first));

    while (!pq.empty())
    {
        cout << -pq.top().second << " ";
        pq.pop();
    }
    return 0;
}
