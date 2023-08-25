#include <iostream>
using namespace std;

long long dp[81];
int N;
int main()
{
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << ((dp[N] + dp[N - 1]) * 2) + (dp[N] * 2);
}
// N=4
// dp[N] = dp[N-1] +dp[N-2]
// ((dp[N]+dp[N-1]) * 2 ) + ( dp[N] * 2 )
