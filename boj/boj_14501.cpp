#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int T[16];
int P[16];
int dp[16];

int solve(int n)
{
	if (n > N + 1) // N+1보다 크다면 퇴사날에도 상담이 끝나지않았
		return -11111;

	if (n == N + 1)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = max(solve(n + 1), solve(n + T[n]) + P[n]);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
		dp[i] = -1;
	}

	int m = solve(1);
	cout << m;
}
