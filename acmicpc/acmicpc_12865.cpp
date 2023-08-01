#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dp[101][100001];
int wArr[101];
int vArr[101];
int N, K, W, V;

int main()
{
	cin >> N >> K;  // 물건의 개수 n ,  무게 k
	for (int i = 1; i <= N; i++)
	{
		cin >> wArr[i] >> vArr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= wArr[i]) // 배낭에 넣을수있으면
				// 현재 물건을 넣었을때의 가치의 합이 이전의 최대 가치합보다 높은것을 담아주기
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wArr[i]] + vArr[i]);
			else // 배낭에 못넣으면
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}