/*
	Resolucao:
		Contar o numero de PAs no array. Ficar atento a restricao
		de que a razao e o anterior - o atual, somente.
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
#define MAX 500
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef long long int64;

const int INF = 0x3f3f3f3f;

int64 a, b, n;

int main(){
	scanf("%d", &n);
	int sub = INF, ant = INF, diff, cont = 0;
	for ( int i = 0; i < n; ++i ){
		scanf("%d", &a);
		if ( ant == INF ) ant = a;
		else{
			diff = ant-a;
			ant = a;
			if ( sub == INF ) sub = diff;
			else if ( sub != diff ){
					cont++;
					sub = INF;
			}
		}
    }
	printf("%d", cont+1);
       
    return 0;
}
