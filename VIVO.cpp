#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int p, r, n = 1, k = 0;
    while ( scanf("%d %d", &p, &r) && p + r ){
		vector<int> vivo( p );
		for ( int i = 0; i < p; ++i )
			scanf("%d", &vivo[i]);
		int l, npar, ord, num;
		for ( int i = 0; i < r; ++i ){
			scanf("%d %d", &npar, &ord);
			for ( int j = 0; j < npar; ++j ){
				scanf("%d", &num);
				if ( num != ord ) vivo.erase( vivo.begin()+k );
				else ++k;
			}
			k = 0;
		}
		printf( "Teste %d\n", n++ );
		for ( int i = 0; i < vivo.size(); ++i )
			printf("%d ", vivo[i]);
		printf("\n\n");
    }
    return 0;
} 
