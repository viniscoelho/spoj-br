/*
	Resolucao:
		Ler a string e criar a expressao e armazenar em duas listas,
		uma em que as operacoes de multiplicao serao contabilizadas
		primeiro e outra onde as de soma serao primeiro
		Depois, basta realizar a soma com o que foi multiplicado + o que faltava somar
		e na outra multiplicar o que tinha somado * o que fatava multiplicar
		As somas primeiro geram o maior resultado e as multiplicacoes primeiro
		geram o menor resultado
			
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <bitset>
#include <stack>
#include <sstream>
#include <climits>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, char> ic;
typedef pair<int, ic> iic;

typedef long long int64;

int num;

int main(){
    ios::sync_with_stdio(false);
	cin >> num;
	cin.ignore();
	string exp;
	for ( int i = 0; i < num; ++i ){
		getline(cin, exp);
		deque<int64> number, numbers;
		deque<char> opers;
		for ( int k = 0; k < exp.size(); ++k ){
			string a;
			if ( exp[k] >= '0' && exp[k] <= '9' ){
				while ( k < exp.size() && exp[k] >= '0' && exp[k] <= '9' ){
					a += exp[k];
					k++;
				}
				int numA;
				istringstream istrA(a);
				istrA >> numA;
				numbers.pb(numA);
				k--;
			}
			else opers.pb( exp[k] );
		}
		number = numbers;
		int p1 = 0, p2 = 0;
		for ( int k = 0; k < opers.size(); ++k ){
			if ( opers[k] == '+' ){
				int64 x = numbers[p1]; numbers[p1++] = LONG_MAX;
				int64 y = numbers[p1];
                numbers[p1] = x + y;
			}
			else p1++;
			if ( opers[k] == '*' ){
				int64 x = number[p2]; number[p2++] = LONG_MAX;
				int64 y = number[p2];
                number[p2] = x * y;
			}
			else p2++;
		}
		
		int64 MAX = 1, MIN = 0;
		for ( int k = 0; k < numbers.size(); ++k ){
			if ( numbers[k] != LONG_MAX ) MAX *= numbers[k];
			if ( number[k] != LONG_MAX ) MIN += number[k];
		}
		cout << "The maximum and minimum are " << MAX << " and " << MIN << ".\n";
	}
    return 0;
}
