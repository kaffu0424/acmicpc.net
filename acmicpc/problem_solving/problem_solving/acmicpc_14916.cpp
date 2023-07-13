#include <iostream>
#include <vector>
using namespace std;

vector<int>dp;
int result;
int N;
int solving(int n)
{
	dp.push_back(-1);
	dp.push_back(-1);
	dp.push_back(1);
	dp.push_back(-1);
	dp.push_back(2);
	dp.push_back(1);
	dp.push_back(3);
	dp.push_back(2);
	dp.push_back(4);

	for (int i = 9; i <= n; i++)
	{
		dp.push_back(dp[i - 5] + 1);
	}
	return dp[n];
}

//int main()
//{
//	cin >> N;
//	result = solving(N);
//	cout << result;
//}