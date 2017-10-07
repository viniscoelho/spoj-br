/*
	Resolucao:
		Imprime 91 se o numero for menor ou igual a 101
		Senao, impime o numero menos 10
*/

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    do{
		if ( n <= 101 ) printf("f91(%d) = 91\n", n);
		else printf("f91(%d) = %d\n", n, n-10);
		scanf("%d", &n);
    }while ( n != 0 );
    return 0;
}
