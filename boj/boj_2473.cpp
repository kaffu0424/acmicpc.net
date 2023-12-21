#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

long long N;
vector <long long> arr;

long long ans[3];
long long sum = 5555555555;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long n;
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size() - 1; i++)
	{
		long long  frontIdx = i + 1;
		long long  backIdx = N - 1;
		while (frontIdx < backIdx)
		{
			long long  tmp = arr[i] + arr[frontIdx] + arr[backIdx];
			if (abs(tmp) < sum)
			{
				sum = abs(tmp);
				ans[0] = arr[i];
				ans[1] = arr[frontIdx];
				ans[2] = arr[backIdx];
			}

			if (tmp > 0)
				backIdx--;
			else
				frontIdx++;
		}
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}