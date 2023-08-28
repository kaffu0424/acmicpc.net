#include <iostream>
#include <algorithm>
#define INF 123456789
using namespace std;


int N, K;
int coin[101], dp[10001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i <= K; i++)
		dp[i] = INF;
	dp[0] = 0;

	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[K] == INF)
		cout << -1;
	else
		cout << dp[K];
}

// DP[N] = min(DP[N] , DP[N - j] + 1]