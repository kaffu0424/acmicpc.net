#include <iostream>
#include <algorithm>
using namespace std;

int dp[15][15];

int main()
{
	for (int j = 1; j <= 14; j++)
		dp[0][j] = j;

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int k, n;
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}
}