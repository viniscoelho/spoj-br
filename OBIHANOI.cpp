#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    float discos, i = 1;
    for (cin >> discos; discos != 0; cin >> discos) {
        cout << "Teste " << i++ << "\n";
        cout << (int)pow(2, discos) - 1 << "\n\n";
    }
    return 0;
}
