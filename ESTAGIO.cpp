/*
	Resolucao:
		Calcula a maior media obtida entre os alunos
		Caso haja mais de uma maior media, imprima todos que obtiveram
*/

#include <iostream>
#include <vector>
#define pb push_back
#define MAX_ALUNOS 1000

using namespace std;

struct aluno
{
    int codigo, media;
};

aluno alunos[MAX_ALUNOS];

int main()
{
    ios::sync_with_stdio(false);
    int n, turma = 1;
    for (cin >> n; n != 0; cin >> n)
    {
        int aux = 0;
        vector<int> melhor;
        for (int i = 0; i < n; i++)
            cin >> alunos[i].codigo >> alunos[i].media;
        for (int i = 0; i < n; i++)
            if (alunos[i].media >= aux)
                aux = alunos[i].media;
        for (int i = 0; i < n; i++)
            if (alunos[i].media == aux)
                melhor.pb(alunos[i].codigo);
        cout << "Turma " << turma++ << "\n";
        for (int i = 0; i < melhor.size(); i++)
            cout << melhor[i] << " ";
        cout << "\n\n";
    }
    return 0;
}
