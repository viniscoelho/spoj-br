#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int c, p, f;
    cin >> c >> p >> f;
    if ( c*f <= p ) cout << "S";
    else cout << "N";
    return 0;
}
