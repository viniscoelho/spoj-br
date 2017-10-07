#include <stdio.h>

int main(){
    int m, n, i, j, f = 0;
    scanf("%d %d", &n, &m);
    int worm[n][m], x[n], y[m];
    for ( i = 0; i < n; i++ )
		for ( j = 0; j < m; j++ )
			scanf("%d", &worm[i][j]);
	for ( j = 0; j < m; j++ ){
		y[j] = 0;
		for ( i = 0; i < n; i++ ){
			y[j] += worm[i][j];
			if ( y[j] > f ) f = y[j];
		}
	}
	for ( i = 0; i < n; i++ ){
		x[i] = 0;
		for ( j = 0; j < m; j++ ){
			x[i] += worm[i][j];
			if ( x[i] > f ) f = x[i];
		}
	}
	printf("%d", f);
    return 0;
}
