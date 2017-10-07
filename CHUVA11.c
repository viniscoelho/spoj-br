/*
	Resolucao:
		Somar duas matrizes e imprimir o resultado
*/

#include <stdio.h>

int mat[101][101];

int main(){
    int i, j, k, n, x;
    scanf("%d", &n);            
    for ( k = 0; k < 2; ++k )
        for ( i = 0; i < n; ++i )
            for ( j = 0; j < n; ++j ){
                scanf("%d", &x);
                mat[i][j] += x;
            }
    for ( i = 0; i < n; ++i ){
        for ( j = 0; j < n; ++j )
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}
