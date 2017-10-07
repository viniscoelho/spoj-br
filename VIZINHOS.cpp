#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t, p, k;
    cin >> t;
    for ( int i = 0; i < t; ++i ){
        cin >> p;
        string str;
        int num, menor = 0;
        int neigh[p][2];
        cin.ignore();
        for ( int j = 1; j <= p; ++j ){
            getline(cin, str);
            neigh[j-1][1] = j;
            istringstream test(str);
            int count = 0;
            while ( test >> num ) count++;
            if ( menor == 0 || count < menor ) menor = count;
            neigh[j-1][0] = count;
        }
        int k = 0;
        for ( int j = 0; j < p; ++j){
            if ( k > 0 ){
				if ( menor == neigh[j][0] )
					cout << " " << neigh[j][1];
            }
            else{
                if ( menor == neigh[j][0] ){
					cout << neigh[j][1];
					k++;
				}
            }
        }
        cout << "\n";
    }
    return 0;
}
