/*
	Resolucao:
		Calcula o candidato que obteve o maior numero
		de votos, utilizando estrutura de dados map ( arvore binaria )
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, num, maior, cont = 0;
    map<int, int> can;
    map<int, int>::iterator it;
    pair<map<int, int>::iterator, bool> ret;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        ret = can.insert(make_pair(num, 1));
        if (!ret.second)
            can[num]++;
    }
    for (it = can.begin(); it != can.end(); ++it)
    {
        if (it->second > cont)
        {
            maior = it->first;
            cont = it->second;
        }
    }
    cout << maior;
    return 0;
}
