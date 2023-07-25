#include <iostream>
#include <algorithm>
using namespace std;


int dp[1001][1001];
int arr[1001][1001];

int Y, X;


int main()
{
	cin >> Y >> X;
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			int t = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			dp[i][j] = t + arr[i][j];
		}
	}

	cout << dp[Y][X];
}