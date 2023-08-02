#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101];

int main()
{
	int N;
	int cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (true)
	{
		bool flag = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (arr[i] >= arr[i + 1])
			{
				arr[i]--;
				cnt++;
				flag = false;
			}
		}

		if (flag)
		{
			cout << cnt;
			return 0;
		}
	}
}