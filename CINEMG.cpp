#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#define mp make_pair
#define pb push_back
#define MAXV 10100

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
	ios::sync_with_stdio(false);
	int m, a, b;
	cin >> m;
	while ( m-- ){
		cin >> a >> b;
		string str;
		map<string, bool> spec;
		for ( int i = 0; i < a; ++i ){
			cin >> str;
			string st;
			for ( int k = 0; k < str.size(); ++k ){
				char c = tolower(str[k]);
				st += c;
			}
			spec.insert( mp(st, true) );
		}
		cin.ignore();
		for ( int i = 0; i < b; ++i ){
			getline(cin, str);
			int qtd = 0;
			for ( int i = 0; i < str.size(); ++i ){
				string aux;
				while ( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') ){
					if ( str[i] >= '0' && str[i] <= '9' ) aux += str[i];
					else{
						char c = tolower(str[i]);
						aux += c;
					}
					i++;
				}
				if ( !aux.size() );
				else if ( spec.count(aux) && !qtd ) qtd++;
				else if ( spec.count(aux) && qtd ) cout << char(tolower(aux[0]));
				else if ( !spec.count(aux) && ( !qtd || qtd ) && aux.compare(" ") != 0 ){
						cout << char(toupper(aux[0]));
						qtd++;
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
