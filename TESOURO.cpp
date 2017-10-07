/*
	Resolucao:
		Aplicacao do algoritmo da mochila ( knapsack )
		Neste caso, o peso e valores sao os mesmos, e o
		peso maximo para colocar na mochila e a soma dos
		pesos de todos os itens + os valores encontrados de
		cada um dividido por 2 menos o valor minimo dos valores
		que cada um encontrou. Se a soma de todos os valores nao for
		impar e for possivel dividir os itens para aquele valor, entao "S";
		caso contrario "N"
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#define MAX 110
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef long long int64;

const int INF = 0x3f3f3f3f;

int64 a, x, y, n;

int weight[MAX], value[MAX];
int dp[MAX][5000]; /*Number of items x maxWeight */

int fill_sack ( int items, int maxWeight ){
    for ( int i = 0; i <= max(maxWeight, items); i++ ){
        if ( i <= maxWeight ) dp[0][i] = 0;
		if ( i <= items ) dp[i][0] = 0;
	}    
    for ( int i = 1; i <= items; ++i )
        for ( int j = 0; j <= maxWeight; ++j ){
            dp[i][j] = dp[i-1][j]; /* If I do not take this item */
            if ( j-weight[i] >= 0 ){
				/* suppose if I take this item */
				dp[i][j] = max( dp[i][j], dp[i-1][j-weight[i]] + value[i] );
            }
        }
    return dp[items][maxWeight];
}

int main(){
	ios::sync_with_stdio(false);
	int t = 1;
	while ( cin >> x >> y >> n && x+y+n ){
		cout << "Teste " << t++ << "\n";
		int sum = 0;
		for ( int i = 1; i <= n; ++i ){
			cin >> value[i];
			sum += value[i];
			weight[i] = value[i];
		}
		if ( (sum+x+y) % 2 == 1 || (sum+x+y)/2-min(x, y) != fill_sack(n, (sum+x+y)/2-min(x, y)) ) cout << "N\n\n";
		else cout << "S\n\n";
    }
       
    return 0;
}
