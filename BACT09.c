 /*
	Resolucao:
		Como o expoente pode ser muito grande, assim como o numero
		basta verificar qual o logaritmo e o maior, pois:
		log(a^b) = b*log(a)
*/

#include <stdio.h>
#include <math.h>

int main(){
    int i, n, resp = 0;
    scanf("%d", &n);
	double a, b, bact = 0.0;
    for ( i = 0; i < n; ++i ){
		scanf("%lf %lf", &a, &b);
		if ( bact < b*log(a) ){
			bact = b*log(a);
			resp = i;
		}
    }
	printf("%d", resp);
    return 0;
}
