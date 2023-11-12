#include <iostream>
using namespace std;

string str;
int t[2]{ 0,0 };
int main()
{
    cin >> str;

    int tmp = str[0] - '0';
    t[tmp]++;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] - '0' == tmp)
            continue;
        else
        {
            tmp = str[i] - '0';
            t[tmp]++;
        }
    }

    cout << min(t[0], t[1]);
}
