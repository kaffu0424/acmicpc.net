#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> v[501];
int times[501];
int result[501];
int degree[501];

void solve()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			result[i] = times[i];
			q.push(i);
		}
	}



	for (int i = 1; i <= N; i++)
	{
		int t = q.front();
		q.pop();
		for (int u : v[t])
		{
			result[u] = max(result[u], result[t] + times[u]);
			if (--degree[u] == 0)
			{
				q.push(u);
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> times[i];
		while (true)
		{
			int n;
			cin >> n;
			if (n == -1)
				break;

			v[n].push_back(i);
			degree[i]++;
		}
	}
	solve();

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
}