#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[200001];
int N, K;

int solve()
{
	deque<int> q;
	q.push_back(N);
	dist[N] = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop_front();

		if (t == K)
			return dist[t];

		if (t - 1 >= 0 && dist[t - 1] > dist[t] + 1)
		{
			q.push_back(t - 1);
			dist[t - 1] = dist[t] + 1;
		}
		if (t + 1 <= 200000 && dist[t + 1] > dist[t] + 1)
		{
			q.push_back(t + 1);
			dist[t + 1] = dist[t] + 1;
		}
		if (t * 2 <= 200000 && dist[t * 2] > dist[t])
		{
			q.push_front(2 * t);
			dist[t * 2] = dist[t];
		}

	}
}

int main()
{
	cin >> N >> K;
	if (N == K)
	{
		cout << "0";
		return 0;
	}
	fill(&dist[0], &dist[200000], 1442311234);
	cout << solve();
}
