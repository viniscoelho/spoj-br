/*
	Resolucao:
		Converte uma palavra representando um numero binario
		pra decimal. 'a's representam 0 e 'b's representam 1
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long int64;

char resp[70];

int main(){
    int t = 1;
    while ( scanf(" %s", &resp) != EOF ){
		int64 num = 0;
		printf("Palavra %d\n", t++);
		int pos = 0;
        for ( int i = 0; i < strlen(resp); ++i ){
			if ( resp[i] == 'b' )
				num ^= 1;
			num <<= 1;
		}
		num >>= 1;
		printf("%llu\n\n", num);
    }
    return 0;
}
