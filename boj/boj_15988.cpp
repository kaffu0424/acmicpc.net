#include <iostream>
using namespace std;

int N, T;
long long dp[1000001];
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--)
	{
		cin >> N;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= N; i++)
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

		cout << dp[N] % 1000000009 << "\n";
	}
}