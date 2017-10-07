#include <stdio.h>

int main(){
    int i, j = 1, n;
    while ( scanf("%d", &n) != EOF ){
		int aux[n], a = 0, soma = 0;
		if ( n == 1 ){
			scanf("%d", &soma);
			printf("Instancia %d\n%d\n\n", j++, soma);
		}
		else{
			for ( i = 0; i < n; i++ )
				scanf("%d", &aux[i]);
			while ( a < n ){
				soma += aux[a];
				if ( soma == aux[a+1] ) a = n+1;
				else a++;
			}
			if ( a == n+1 ) printf("Instancia %d\n%d\n\n", j++, soma);
			else printf("Instancia %d\nnao achei\n\n", j++);
		}
	}
	return 0;
}
