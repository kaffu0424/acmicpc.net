#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int T, N;
int arr[2][100001];
int dp[2][100001];
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> arr[i][j];
			}
		}

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + arr[1][i];
		}
		cout << max(dp[0][N], dp[1][N]) << "\n";
	}
}
