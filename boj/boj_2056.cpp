#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int times[10001];
int degree[10001];
int result[10001];
vector<int> task[10001];

void solve()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
		result[i] = times[i];
	}

	while (!q.empty())
	{
		int t = q.front();
		q.pop();

		for (int v : task[t])
		{
			degree[v]--;
			result[v] = max(result[v], result[t] + times[v]);
			if (degree[v] == 0)
			{
				q.push(v);
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int time, v, u;
		cin >> time >> v;
		times[i] = time;
		for (int j = 0; j < v; j++)
		{
			cin >> u;
			task[u].push_back(i);
			degree[i]++;
		}
	}

	solve();

	int answer = -1;
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, result[i]);
	}
	cout << answer;
}