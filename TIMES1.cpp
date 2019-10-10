#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, t, p;
    cin >> n >> t;
    map<int, string> jogadores;
    map<int, string>::reverse_iterator mp;
    vector<vector<string>> times(t);
    string jog;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cin >> jog >> p;
        jogadores.insert(make_pair(p, jog));
    }
    int pos = 0;
    mp = jogadores.rbegin();
    while (mp != jogadores.rend()) {
        if (pos == t)
            pos = 0;
        string ijog = (*mp).second;
        times[pos].push_back(ijog);
        pos++;
        mp++;
    }
    for (int j = 0; j < t; j++)
        sort(times[j].begin(), times[j].end());
    for (int j = 1; j <= t; ++j) {
        cout << "Time " << j << "\n";
        for (int i = 0; i < times[j - 1].size(); ++i)
            cout << times[j - 1][i] << "\n";
        cout << "\n";
    }

    return 0;
}
