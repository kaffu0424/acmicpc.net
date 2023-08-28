#include <iostream>
#include <algorithm>
#define INF 123456789
using namespace std;

int N;
int dp[1000001];
int arr[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N; // 통증수치 입력
	cin >> arr[0] >> arr[1]; // 


	for (int i = 0; i <= N; i++)
	{
		dp[i] = INF;
	}
	dp[0] = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = arr[i]; j <= N; j++)
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
	}


	if (dp[N] == INF)
	{
		cout << -1;
	}
	else
		cout << dp[N];
}