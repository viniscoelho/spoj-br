/*
	Resolucao:
		Ordena o nome dos alunos e entao imprime
		o aluno que corresponde ao numero sorteado
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, m;
    cin >> n >> m;
    string nome;
    vector<string> chamada;
    for (int k = 0; k < n; ++k) {
        cin >> nome;
        chamada.push_back(nome);
    }
    sort(chamada.begin(), chamada.end());
    cout << chamada[m - 1];
    return 0;
}
