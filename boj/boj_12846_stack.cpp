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
long long ans = 0;
long long tmp;
int tmp2;
stack<pair<int, int>> st;

void input()
{
	cin >> N;
}
void solve()
{
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (st.empty())
		{
			st.push({ i,num });
		}

		else if (st.top().second < num)
		{
			st.push({ i,num });
		}

		else if (st.top().second > num)
		{
			while (!st.empty() && st.top().second > num)
			{
				int mul = i - st.top().first;
				tmp = st.top().second * mul;
				tmp2 = st.top().first;
				st.pop();

				if (tmp > ans)
					ans = tmp;
			}
			st.push({ tmp2,num });
		}
	}

	while (!st.empty())
	{
		int mul = N - st.top().first;
		tmp = st.top().second * mul;
		st.pop();
		if (tmp > ans)
			ans = tmp;
	}
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}