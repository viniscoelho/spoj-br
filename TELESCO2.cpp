#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a, e, f, count = 0;
    cin >> a >> e;
    for ( int i = 0; i < e; ++i ){
        cin >> f;
        if ( a*f >= 40000000 ) count++;
    }
    cout << count;
    return 0;
}
