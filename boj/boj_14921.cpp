#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int absSum = 999999999;
int sum = 0;
int ans = 0;
int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int frontIdx = 0;
	int backIdx = N - 1;
	while (frontIdx < backIdx)
	{
		sum = arr[frontIdx] + arr[backIdx];

		if (sum == 0)
		{
			cout << 0;
			return 0;
		}

		if (absSum > abs(sum))
		{
			absSum = abs(sum);
			ans = sum;
		}

		if (sum < 0)
		{
			frontIdx++;
		}
		else
		{
			backIdx--;
		}
	}
	cout << ans;
}