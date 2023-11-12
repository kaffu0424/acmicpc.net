#include <iostream>
#include <string>
#include<regex>
#include <deque>
#include <vector>

using namespace std;


int N;
vector<int> v[8];
long long dp[101];

void maxNum(int m)
{
	string maxNum = "";
	if (m % 2 != 0)
	{
		m -= 3;
		maxNum += to_string(v[3][0]);
	}
	while (true)
	{
		if (m == 0)
			break;
		m -= 2;
		maxNum += to_string(v[2][0]);
	}

	cout << maxNum;
}
void minNum()
{
	int minnums[8] = { 0,0,1,7,4,2,0,8 };
	memset(dp, 127, sizeof(dp));

	dp[1] = 9;
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;

	for (int i = 8; i < 101; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			dp[i] = min(dp[i], dp[i - j] * 10 + minnums[j]);
		}
	}
}

int main()
{
	v[2].push_back(1);
	v[3].push_back(7);
	v[4].push_back(4);
	v[5].push_back(5);
	v[5].push_back(3);
	v[5].push_back(2);
	v[6].push_back(9);
	v[6].push_back(6);
	v[6].push_back(0);
	v[7].push_back(8);

	cin >> N;
	minNum();
	while (N--)
	{
		int m;
		cin >> m;

		cout << dp[m] << " ";
		maxNum(m);
		cout << "\n";
	}
}