#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int arr[32777];
long long ans;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int height = arr[i];

		ans += (height * 4) + 2;

		if (arr[i - 1] > height)
			ans -= height;
		else
			ans -= arr[i - 1];

		if (arr[i + 1] > height)
			ans -= height;
		else
			ans -= arr[i + 1];
	}

	cout << ans;
}