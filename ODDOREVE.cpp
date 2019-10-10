#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n, x;
    for (scanf("%d", &n); n != 0; scanf("%d", &n)) {
        int soma = 0;
        for (int i = 0; i < 2 * n; ++i) {
            scanf("%d", &x);
            if (x % 2 == 0)
                soma++;
        }
        printf("%d\n", abs(n - soma));
    }
    return 0;
}
