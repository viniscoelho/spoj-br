#include <stdio.h>

int main(){
	int i, j = 1, n;
	char x[11], y[11];
	while ( scanf("%d", &n) && n ){
		int r[n], s[n];
		scanf(" %s %s", &x, &y);
		for ( i = 0; i < n; i++ )
			scanf("%d %d", &r[i], &s[i]);
		printf("Teste %d\n", j++);
		for ( i = 0; i < n; i++ )
			if ( (r[i] + s[i]) % 2 == 0 ) printf("%s\n", x);
		    else printf("%s\n", y);
		printf("\n");
	}
	return 0;
}