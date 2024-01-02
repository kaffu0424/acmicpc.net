#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

#define MAX 2100000000

using namespace std;

int N;
int dp[1001][3];
int cost[1001][3]; // 1, 2, 3번집 비용
int ans = MAX;
void input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
}
void solve()
{
	for (int choiceHome = 0; choiceHome < 3; choiceHome++) // 1 , 2, 3번집을 선택했을때로 나뉨.
	{
		for (int i = 0; i < 3; i++) // DP의 시작을 MAX로 초기화
			dp[1][i] = MAX;

		// 선택한 집만 바꿔주김
		dp[1][choiceHome] = cost[1][choiceHome];

		// rgb거리1과 동일
		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			// 선택한 집의 번호는 제외한 나머지
			if (i != choiceHome)
				ans = min(ans, dp[N][i]);
		}
	}
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}