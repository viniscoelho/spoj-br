#include <stdio.h>

int main(){
	long i, k = 1, n, x1, x2, y1, y2;
	while ( scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && x1 + y1 + x2 + y2 ){
		scanf("%d", &n);
	    int j = 0, x[n], y[n];
	    for ( i = 0; i < n; i++ )
			scanf("%d %d", &x[i], &y[i]);
		for ( i = 0; i < n; i++ )
		    if ( x[i] >= x1 && y[i] >= y2 && x[i] <= x2 && y[i] <= y1 ) j++;
		printf("Teste %d\n%d\n\n", k++, j);
	}
	return 0;
}