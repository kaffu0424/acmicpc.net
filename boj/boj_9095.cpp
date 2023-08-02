#include <iostream>
#include <vector>
using namespace std;

// 백준 9095
int dp[101];
int combination(int n, int target)
{
	if (n == target)
		return 1;
	if (n > target)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = combination(n + 1, target) + combination(n + 2, target) + combination(n + 3, target);
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 101; i++)
		{
			dp[i] = -1;
		}
		int n;
		cin >> n;
		cout << combination(0, n) << "\n";
	}
}
