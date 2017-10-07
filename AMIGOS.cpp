#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ponto[66000][2];
int vet[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct reta{
	double x1, x2, y1, y2;
}m;

int intercepta( int px, int py ){
	double a, b, c, d, ua, ub;
	a = ( (m.x2 - m.x1) * (ponto[px][1] - m.y1) - (m.y2 - m.y1) * (ponto[px][0] - m.x1) );
	b = ( (m.y2 - m.y1) * (ponto[py][0] - ponto[px][0]) - (m.x2 - m.x1) * (ponto[py][1] - ponto[px][1]) );
	c = ( (ponto[py][0] - ponto[px][0]) * (ponto[px][1] - m.y1) - (ponto[py][1] - ponto[px][1]) * (ponto[px][0] - m.x1) );
	d = ( (m.y2 - m.y1) * (ponto[py][0] - ponto[px][0]) - (m.x2 - m.x1) * (ponto[py][1] - ponto[px][1]) );
	if ( !(b + d + a + c) ) return 1;
	ua = a / b;
	ub = c / d;
	if ( ua >= 0. && ua <= 1. && ub >= 0. && ub <= 1. ) return 1;
	return 0;
}

int main(){
	int t, a, b, n, x, y, qp, qnt, num, pulos, dir, mp, dado1, dado2, cont = 1, i;
	scanf("%d", &t);
	while ( t-- ){
		qp = 1;
		qnt = num = mp = 0;
		scanf("%d %d %d", &a, &b, &n);
		if ( a != 0 ){
			m.y1 = 10000000.0*(double)a + (double)b;
			m.y2 = -10000000.0*(double)a + (double)b;
			m.x1 = (double)(m.y1 - b)/(double)a;
			m.x2 = (double)(m.y2 - b)/(double)a;
		}
		else{
			m.y1 = (double)b;
			m.y2 = (double)b;
			m.x1 = 10000000;
			m.x2 = -10000000;
		}
		x = y = pulos = dir = 0;
		while ( num < 65536 ){
			if ( y == (a*x + b) ){
				pulos++;
				x += vet[dir][0];
				y += vet[dir][1];
				if ( pulos == qp ){
					pulos = 0;
					qnt++, mp++;
					dir = mp % 4;
					if ( qnt % 2 == 0 ) qp++;
				}				
				continue;
			}
			ponto[num][0] = x;
			ponto[num][1] = y;
			x += vet[dir][0];
			y += vet[dir][1];
			num++, pulos++;
			if ( pulos == qp ){
				pulos = 0;
				qnt++, mp++;
				dir = mp % 4;
				if ( qnt%2 == 0 ) qp++;
			}
		}
		int flag;
		printf("Caso %d\n",cont++);
		for ( i = 0; i < n; i++ ){
			scanf("%d %d", &x, &y);
			flag = intercepta(y, x);
			if ( !flag ) printf("Mesmo lado da fronteira\n");
			else printf("Lados opostos da fronteira\n");
		}
	}
	return 0;
}
