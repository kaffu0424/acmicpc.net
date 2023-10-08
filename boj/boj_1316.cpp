#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N;
int answer;

void solve(string str)
{
	bool alp[26]{ false, };
	alp[str[0] - 'a'] = true;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[i - 1])
			continue;

		else if (str[i] != str[i - 1] && alp[str[i] - 'a'])
		{
			answer--;
			break;
		}
		else
		{
			alp[str[i] - 'a'] = true;
		}
	}
}
int main()
{
	cin >> N;
	answer = N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		solve(str);
	}
	cout << answer;
}