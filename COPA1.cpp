/*
	Resolucao:
		Armazena os times numa fila e entao comeca o "mata mata"
		onde dois times disputam uma partida e o vencedor e novamente inserido na fila
		Vence o ultimo time na fila
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int x, y;
  char time = 'A', a, b;
  queue<char> copa;
  for (int i = 0; i < 8; ++i)
  {
    cin >> x >> y;
    if (x > y)
      copa.push(time);
    else
      copa.push(time + 1);
    time += 2;
  }
  for (int i = 0; i < 4; ++i)
  {
    a = copa.front();
    copa.pop();
    b = copa.front();
    copa.pop();
    cin >> x >> y;
    if (x > y)
      copa.push(a);
    else
      copa.push(b);
  }
  for (int i = 0; i < 2; ++i)
  {
    a = copa.front();
    copa.pop();
    b = copa.front();
    copa.pop();
    cin >> x >> y;
    if (x > y)
      copa.push(a);
    else
      copa.push(b);
  }
  cin >> x >> y;
  a = copa.front();
  copa.pop();
  b = copa.front();
  copa.pop();
  if (x > y)
    cout << a;
  else
    cout << b;
  return 0;
}
