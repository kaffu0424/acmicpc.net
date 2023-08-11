#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dp[1000001];
int main()
{
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[N];
}

/*
N = 1
1
dp[1] = 1;

N = 2
00 , 11
dp[2] = 2;

N = 3
111
100
001
dp[3] = 3;

N = 4
0000
1001
1100
0011
1111
dp[4] = 5;

N = 5
00000
10000
00100
00001
11001
10011
11100
00111
11111
dp[5] = 9
*/

// dp[n] = dp[n-1] + dp[n-2]