#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int dp[10001];
int arr[10001];
int ans = 0;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	if (N <= 2)
	{
		for (int i = 1; i <= N; i++)
			ans += arr[i];
		cout << ans;
		return 0;
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(max(arr[1] + arr[2], arr[2] + arr[3]), arr[1] + arr[3]);

	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 1]));
	}
	cout << dp[N];
}