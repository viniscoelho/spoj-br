#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, p, x, test = 1;
    for ( cin >> n >> p; n != 0 && p != 0; cin >> n >> p ){
        vector<int> jog, pal;
        int cont = 0;
        for ( int i = 0; i < n; ++i ){
            cin >> x;
            jog.push_back(x);
        }
        for ( int i = 0; i < n; ++i ){
            int pos = 0, flag = 0, lugar = 0;
            for ( int j = 0; j < pal.size(); ++j )
                if ( pal[j] == jog[i] ) flag = 1;
            if ( pal.size() < p && !flag ) pal.push_back(jog[i]);
            else if ( pal.size() == p && !flag ){
					vector<int> aux;
                    lugar = 0;
                    /*
                     *verifica se o numero está na lista de proximos
                     */
                    for ( int k = 0; k < pal.size(); ++k ){
                        for ( int j = i+1; j < n; ++j ){
                            if ( pal[k] == jog[j] ){
								aux.push_back(j);
								lugar = 1;
								break;
                            }
                            else lugar = 0;
                        }
                        /*
                         *se nao estiver, eu troco
                         */
                        if ( !lugar ){
							pal[k] = jog[i];
							++cont;
							break;
                        }
                    }
                    if ( lugar ){
						/*
                        *caso esteja, verifico qual q possui a incidencia mais distante
                        */
						sort( aux.begin(), aux.end() );
						pos = aux[aux.size()-1];
						for ( int k = 0; k < pal.size(); ++k )
							if ( pal[k] == jog[pos] ){
								pal[k] = jog[i];
								++cont;
								break;
							}
                    }
			}
        }
        cout << "Teste " << test++ << "\n" << cont << "\n\n";
    }
    return 0;
}
