#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;
int arr[2001];
int dp[2001][2001];
void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i][i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int len = 2; len < N; len++) // len - 펠린드롬 길이
	{
		for (int j = 1; j + len <= N; j++)
		{
			if (arr[j] == arr[len + j] && dp[j + 1][len + j - 1] == 1)
				dp[j][len + j] = 1;
		}
	}
}

void solve()
{
	cin >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
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