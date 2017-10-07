#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <string>
#include <sstream>
#define mp make_pair
#define pb push_back
#define MAXV 10010

using namespace std;

typedef unsigned long long int64;
typedef pair<int, int> ii;

string convertInt( int number ){
	stringstream ss;
	ss << number;
	return ss.str();
}

int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
    while ( t-- ){
		string seq;
		int q = 0;
		cin >> seq >> q;
		cout << seq << "\n";
		for ( int i = 0; i < q; ++i ){
			string ans;
			char s = seq[0];
			int qtd = 0;
			for ( int j = 0; j < seq.size(); ++j ){
				if ( s == seq[j] ) qtd++;
				else{
					ans += convertInt(qtd);
					ans += s;
					s = seq[j], qtd = 1;
				}
			}
			ans += convertInt(qtd);
			ans += s;
			cout << ans << "\n";
			seq = ans;
		}
		cout << "\n";
    }
    return 0;
}
