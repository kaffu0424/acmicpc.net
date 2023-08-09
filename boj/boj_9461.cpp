#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101];
int T, N;
int main()
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 5;
	dp[9] = 7;
	dp[10] = 9;
	for (int i = 11; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}
}