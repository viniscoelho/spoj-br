/*
	Resolucao:
		Calculo do fatorial iterativo
*/

#include <stdio.h>

int main(){
    int i, n, resp = 1;
    scanf("%d", &n);
    if ( n == 1 || n == 0 ) printf("1");
    else{
		for ( i = 2; i <= n; ++i ) resp *= i;
		printf("%d", resp);
    }
    return 0;
}
