#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int N, m = 0;
int arr[1000001];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (arr[n + 1] > 0)
		{
			arr[n + 1]--;
		}
		arr[n]++;

		m = max(m, n);
	}

	int ans = 0;
	for (int i = 0; i <= m; i++)
	{
		if (arr[i] != 0)
			ans += arr[i];
	}
	cout << ans;
}