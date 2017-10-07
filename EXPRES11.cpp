/*
	Resolucao:
		Aplicacao direta de estrutura de dados pilha;
		verificar se a pilha fica vazia apos as diversas insercoes
*/

#include <string.h>
#include <stdio.h>

int main(){
    int i, j, n;
	char resp[100100], stack[100100];
    scanf("%d", &n);
    for ( i = 0; i < n; ++i ){
        scanf(" %s", &resp);
        int topo = 0, flag = 0;
        for ( j = 0; j < strlen(resp); ++j ){
            if ( topo == 0 ){
               stack[topo] = resp[j];
               topo++;
            }
            else if ( stack[topo-1] == '(' && resp[j] == ')' ) topo--;
            else if ( stack[topo-1] == '[' && resp[j] == ']' ) topo--;
            else if ( stack[topo-1] == '{' && resp[j] == '}' ) topo--;
			else if ( stack[topo-1] == '(' && ( resp[j] == ']' || stack[topo-1] == '}' ) ){
					flag = 1; break; 
			}
			else if ( stack[topo-1] == '[' && ( resp[j] == ')' || stack[topo-1] == '}' ) ){
					flag = 1; break;
			}
			else if ( stack[topo-1] == '{' && ( resp[j] == ')' || stack[topo-1] == ']' ) ){
					flag = 1; break;
			}
            else{
				stack[topo] = resp[j];
				topo++;
            }
        }
		if ( flag ) printf("N\n");
        else if ( topo != 0 ) printf("N\n");
        else printf("S\n");
    }
    return 0;
}