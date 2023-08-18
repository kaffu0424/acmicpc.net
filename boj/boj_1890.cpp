#include <iostream>
#include <algorithm>
using namespace std;


int N;
int arr[101][101];
long long dp[101][101];
int main()
{
	cin >> N;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> arr[y][x];
		}
	}
	dp[1][1] = 1;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (arr[y][x] == 0 || dp[y][x] == 0)
				continue;

			int nx = arr[y][x] + x;
			int ny = arr[y][x] + y;

			if (ny <= N)
				dp[ny][x] += dp[y][x];
			if (nx <= N)
				dp[y][nx] += dp[y][x];
		}
	}
	cout << dp[N][N];
}