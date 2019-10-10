/*
	Resolucao:
		Realiza operacoes de soma e subtracao
		Armazenando em uma stringstream
		lendo numeros e operadores
		Imprime o resultado no final
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int ex, num, i = 1;
	char c;
	string str;
	for (cin >> ex; ex != 0; cin >> ex)
	{
		int resp = 0, count = 0;
		cin.ignore();
		getline(cin, str);
		istringstream calcula(str);
		char x = '0';
		while (calcula >> num)
		{
			calcula >> c;
			if (count == 0)
				resp += num;
			if (count < ex)
			{
				if (x == '+')
					resp += num;
				else if (x == '-')
					resp -= num;
				x = c;
				count++;
			}
		}
		cout << "Teste " << i++ << "\n";
		cout << resp << "\n\n";
	}
	return 0;
}
