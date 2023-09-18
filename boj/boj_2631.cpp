#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[201];
int arr[201];
int m = 0;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;

		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if (m < dp[i])
			m = dp[i];
	}

	cout << N-m;
}