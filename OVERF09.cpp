#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int m, n, l;
    char c;
    cin >> l >> n; cin.ignore();
    cin >> c >> m;
    if ( c == '*' ){
       if ( n*m <= l ) cout << "OK";
       else cout << "OVERFLOW";
    }
    else{
         if ( n+m <= l ) cout << "OK";
         else cout << "OVERFLOW";
    }
    return 0;
}
