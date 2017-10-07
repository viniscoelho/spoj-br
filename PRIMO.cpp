#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long k = 0, n;
    cin >> n;
    n = abs(n);
    if ( n == 2 || n == 3 ){
		cout << "sim\n";
		return 0;
    }
    else if ( n == 1 || n % 2 == 0 ){
			cout << "nao\n";
			return 0;
    }
    for ( long long i = 3; i <= sqrt(n); i += 2 ){
        if ( n % i == 0 ){
			cout << "nao\n";
			return 0;
        }
    }
    cout << "sim\n";
    return 0;
}
