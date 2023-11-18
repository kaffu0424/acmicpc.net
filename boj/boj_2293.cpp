#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int arr[101];
int dp[10001];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 1;

	for (int i = 0; i < N; i++)
	{
		int coin = arr[i];
		for (int j = coin; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - coin];
		}
	}

	cout << dp[K];
}