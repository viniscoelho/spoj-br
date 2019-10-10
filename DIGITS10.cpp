#include <bits/stdc++.h>

using namespace std;

int resp[2][10], pow10[10];

//up representa a posicao do vetor correspondente ao
//inicio ou fim do intervalo
void count(int x, bool up)
{
    int *cnt = resp[up], d, pos = 0, r = 0, remainder = 0, pw;
    while (x) {
        d = x % 10; //pego o ultimo digito
        x /= 10; //pego o numero sem o ultimo digito
        if (pos) {
            pw = d * pow10[pos - 1] * pos;
            for (int i = 0; i < 10; ++i)
                cnt[i] += pw;
            if (!d)
                remainder += (pow10[pos] - 1) - r;
        }
        pw = pow10[pos];
        for (int i = 1; i < d; ++i)
            cnt[i] += pw;
        if (d)
            cnt[d] += r + 1;
        r += pow10[pos++] * d;
    }
    cnt[0] -= remainder;
}

int main()
{
    //quantidade de vezes que o primeiro digito aparece
    pow10[0] = 1;
    for (int i = 1; i < 10; ++i)
        pow10[i] = 10 * pow10[i - 1];

    int a, b;
    while (scanf("%d %d", &a, &b) && (a || b)) {
        for (int i = 0; i < 10; ++i)
            resp[0][i] = resp[1][i] = 0;
        count(b, 1); //conto os digitos de b
        count(a - 1, 0); //conto os digitos de a-1
        for (int i = 0; i < 10; ++i) {
            if (i)
                printf(" ");
            printf("%d", resp[1][i] - resp[0][i]); //imprimo a diferenca entre os intervalos
        }
        printf("\n");
    }
    return 0;
}