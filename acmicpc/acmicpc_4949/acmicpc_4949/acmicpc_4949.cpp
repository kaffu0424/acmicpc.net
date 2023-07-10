#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;


// 백준 4949번
int main()
{
	while (true)
	{
		string str;
		getline(cin, str);
		if (str == ".")
			break;

		stack<char> s;
		bool flag = 0;
		for (int i = 0; i < str.length(); i++)
		{
			char c = str[i];

			if (c == '(' || c == '[')
				s.push(c);

			else if (c == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}

			else if (c == ']')
			{
				if (!s.empty() && s.top() == '[')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
		}

		if (flag == 0 && s.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}