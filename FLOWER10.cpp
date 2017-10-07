/*
	Resolucao:
		Verificar se a primeira letra de cada palavra
		e a mesma para a frase inteira utilizando
		processamento de strings e uso de stringstream
*/

#include <iostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string str, saida;
    for ( getline(cin, str); str != "*"; getline(cin, str) ){
        istringstream test(str);
        bool flag = true;
        int count = 0;
        char p;
        while ( test >> saida ){
			if ( count == 0 ) p = saida[0];
			if ( p != saida[0] )
				if ( p + 32 != saida[0] )
					if ( p - 32 != saida[0] ){
						cout << "N\n";
						flag = false;
						break;
                    }
			count++;
        }
        if ( flag ) cout << "Y\n";
    }
    return 0;
}