#include <iostream>
#include <algorithm>
#include <functional>
#include <locale>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <cctype>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
//#include <tr1/unordered_map>
#define FOR(i, a, b) for( int i = a; i <= b; ++i )
#define RFOR(i, b, a) for( int i = b; i >= a; --i )
#define REP(i, N) for( int i = 0; i < N; ++i )
#define MAX 5010
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f

using namespace std;
//using namespace tr1;

typedef long long int64;

struct Node
{
    int rounds;
    int x, y, h;
    
    Node(int rounds, int x, int y, int h) : rounds(rounds), x(x), y(y), h(h) {}
};

//possiveis vizinhos
const int dir[][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int adj[60][60], visited[60][60];

int main()
{
    ios::sync_with_stdio(false);
    int m, n, count = 0;
    cin >> m >> n;
    for ( int i = 0; i < m; ++i )
        for ( int j = 0; j < n; ++j )
        {
            cin >> adj[i][j];
            visited[i][j] = 0;
        }

    queue<Node> bfs;
    bfs.push( Node(0, 0, 0, adj[0][0]) );
    visited[0][0] = 1;
    
    int resp = 0;
    while ( !bfs.empty() )
    {
        Node q = bfs.front();
        bfs.pop();
        resp = q.rounds;
		
        if ( q.x == m-1 && q.y == n-1 )
        {
            cout << resp;
            break;
        }
        
        for ( int i = 0; i < 4; i++ )
        {
            int x = q.x + dir[i][0];
            int y = q.y + dir[i][1];
            
            if ( x >= m || y >= n || x < 0 || y < 0 ) continue;
            
            if ( !visited[x][y] && ((q.h+q.rounds) % 10 + 1) >= (adj[x][y]+q.rounds) % 10 )
            {
                bfs.push(Node(q.rounds+1, x, y, adj[x][y]));
                visited[x][y] = 1;
            }
        }
        bfs.push(Node(q.rounds+1, q.x, q.y, adj[q.x][q.y]));
    }
    return 0;
}