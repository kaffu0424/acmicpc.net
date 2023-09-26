#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	string str;
	cin >> str;
	sort(str.rbegin(), str.rend());
	
	if (str[str.length() - 1] == '0')
	{
		long long ans = 0;
		for (int i = 0; i < str.length(); i++)
			ans += str[i] - '0';

		if (ans % 3 == 0)
		{
			cout << str;
			return 0;
		}
	}
	cout << -1;
}