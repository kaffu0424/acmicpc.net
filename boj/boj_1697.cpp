#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 1697번
int arr[1000001];
int N, K;
int main()
{
	cin >> N >> K;

	queue<int> q;
	q.push(N);

	while (q.size())
	{
		int n = q.front();
		if (n == K)
			break;
		q.pop();

		int nn1 = n + 1;
		if (nn1 >= 0 && nn1 <= 100000 && arr[nn1] == 0)
		{
			q.push(nn1);
			arr[nn1] = arr[n] + 1;
		}

		int nn2 = n - 1;
		if (nn2 >= 0 && nn2 <= 100000 && arr[nn2] == 0)
		{
			q.push(nn2);
			arr[nn2] = arr[n] + 1;
		}

		int nn3 = 2 * n;
		if (nn3 >= 0 && nn3 <= 100000 && arr[nn3] == 0)
		{
			q.push(nn3);
			arr[nn3] = arr[n] + 1;
		}
	}

	cout << arr[q.front()];
}