#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string convertInt(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

int main()
{
    ios::sync_with_stdio(false);
    string str;
    for (getline(cin, str); str != "0"; getline(cin, str)) {
        int count = 1, sum = 0;
        for (int i = 0; i < str.size(); ++i)
            sum += (int)str[i] - 48;
        if (sum % 9 == 0) {
            while (sum / 9 != 1) {
                string aux = convertInt(sum);
                sum = 0;
                for (int i = 0; i < aux.size(); ++i)
                    sum += (int)aux[i] - 48;
                count++;
            }
            cout << str << " is a multiple of 9 and has 9-degree " << count << ".\n";
        } else
            cout << str << " is not a multiple of 9.\n";
    }
    return 0;
}
