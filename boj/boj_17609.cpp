#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include<cmath>

using namespace std;

int N;
string str;
bool flag;

bool palin(int s, int e)
{
	while (s < e)
	{
		if (str[s] == str[e])
		{
			s++;
			e--;
		}
		else
		{
			if (flag)
				return false;
			flag = true;
			bool ref = palin(s + 1, e) || palin(s, e - 1);
			return ref;
		}
	}
	return true;
}

void input()
{
	cin >> N;
}

void solve()
{
	while (N--)
	{
		cin >> str;
		flag = false;
		int s = 0;
		int e = str.length() - 1;

		bool ans = palin(s, e);
		if (ans && !flag)
			cout << 0 << "\n";
		else if (ans && flag)
			cout << 1 << "\n";
		else
			cout << 2 << "\n";
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