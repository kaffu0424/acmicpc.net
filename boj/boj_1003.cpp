#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
pair<int, int> dp[41]; // first : 0,  second : 1

int main()
{
	dp[3] = make_pair(1, 2);
	dp[2] = make_pair(1, 1);
	dp[1] = make_pair(0, 1);
	dp[0] = make_pair(1, 0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		if (dp[N].first != 0 || dp[N].second != 0) // 이미 계산된값이 있으면
		{
			cout << dp[N].first << " " << dp[N].second << "\n"; // 출력
			continue; // 종료
		}

		// 이미 계산된값이 없다면
		for (int i = 4; i <= N; i++)  // 연산해줌
		{
			if (dp[i].first != 0 || dp[i].second != 0)
				continue;

			// f(n) 는 f(n-1) + f(n-2) 
			// f(n-1) 의 0,1 호출횟수와 f(n-2) 호출횟수를 더하면
			// f(n) 의 호출횟수
			dp[i] = { dp[i - 1].first + dp[i - 2].first , dp[i - 1].second + dp[i - 2].second };
			// 라고 생각되어서 해보니 됨!
		}

		cout << dp[N].first << " " << dp[N].second << "\n";
	}
}