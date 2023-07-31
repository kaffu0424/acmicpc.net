#include <iostream>
using namespace std;

int N;
int answer = 0;
int arr[1001];
int dp[1001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(dp[i], answer);
	}

	cout << answer;
}
