/*
	Resolucao:
		Calcula a conta de agua de acordo com a tabela
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int mc, resp = 7;
	cin >> mc;
	if (mc <= 10)
		cout << "7";
	else
	{
		mc -= 10;
		if (mc > 20)
		{
			mc -= 20;
			resp += 20;
			if (mc > 70)
			{
				mc -= 70;
				resp += 70 * 2;
				if (mc >= 1)
					cout << resp + mc * 5;
			}
			else
				cout << resp + (mc * 2);
		}
		else
			cout << resp + mc;
	}
	return 0;
}
