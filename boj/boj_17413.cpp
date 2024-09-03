#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

string str;
stack<char> st;

void input()
{
	getline(cin, str);
}

void solve()
{
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ' ')
		{
			// 스택에 있는 문자를 전부 출력
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
		else if (str[i] == '<')
		{
			// 스택에 문자가 있다면 출력하고 >가 나올때가지 출력
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			while (str[i] != '>')
			{
				cout << str[i];
				i++;
			}
			cout << ">";
		}
		else
		{
			// st에 추가
			st.push(str[i]);
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}