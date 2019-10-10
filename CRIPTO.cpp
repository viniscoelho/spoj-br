/*
	Resolucao:
		Dada um codigo de letras por ordem de maior recorrencia,
		substituir na mensagem. As letras na mensagem que tem maior
		recorrencia sao substituidas por aquelas do codigo. Caso haja
		empate no numero de recorrencias, considerar a ordem alfabetica.
*/

#include <iostream>
#include <map>
#include <queue>
#include <string>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    int a, b, t = 1;
    string cript, word;
    while (cin >> a >> b && a + b) {
        cin.ignore();
        cin >> cript;
        cin.ignore();
        getline(cin, word);
        map<int, int> bib;
        map<char, char> ans;
        map<int, int>::iterator it;
        pair<map<int, int>::iterator, bool> resp;
        priority_queue<ii> pq;
        for (int i = 0; i < a; ++i) {
            if (word[i] != ' ') {
                resp = bib.insert(mp((int)word[i], 1));
                if (!resp.second)
                    bib[(int)word[i]]++;
            }
        }
        for (it = bib.begin(); it != bib.end(); it++)
            pq.push(mp(it->second, -(it->first)));
        int pos = 0;
        while (!pq.empty()) {
            ans.insert(mp(-pq.top().second, cript[pos++]));
            pq.pop();
        }
        cout << "Teste " << t++ << "\n";
        for (int i = 0; i < a; ++i) {
            if (word[i] == ' ')
                cout << word[i];
            else
                cout << ans[word[i]];
        }
        cout << "\n\n";
    }
    return 0;
}
