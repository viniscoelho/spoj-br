/*
	Resolucao:
		Realiza operacoes de multiplicacao e divisao
		Imprime o resultado arredondado
*/

#include <stdio.h>

int main()
{
  int n;
  double resp = 1;
  char c[5];
  scanf("%d", &n);
  while (n--)
  {
    scanf(" %[^\n]s", &c);
    if (c[2] == '*')
      resp *= (c[0] - 48);
    else
      resp /= (c[0] - 48);
  }
  printf("%0.0lf", resp);
  return 0;
}
