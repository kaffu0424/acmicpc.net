#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
vector<pair<int, int>> graph[801];
int dis[801];

void solve(int start)
{
	for (int i = 0; i <= N; i++) dis[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });
	dis[start] = 0;

	while (!q.empty())
	{
		int cur = q.top().second;
		int cost = q.top().first;
		q.pop();

		if (cost > dis[cur])
			continue;

		for (pair<int, int> i : graph[cur])
		{
			int next = i.first;
			int nextCost = dis[cur] + i.second;

			if (nextCost < dis[next])
			{
				dis[next] = nextCost;
				q.push({ nextCost,next });
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	solve(1);
	int s_to_v1 = dis[v1];
	int s_to_v2 = dis[v2];

	solve(v1);
	int v1_to_v2 = dis[v2];
	int v1_to_n = dis[N];

	solve(v2);
	int v2_to_n = dis[N];

	int result = INF;
	result = min(result, s_to_v1 + v1_to_v2 + v2_to_n);
	result = min(result, s_to_v2 + v1_to_v2 + v1_to_n);

	if (v1_to_v2 == INF || result == INF)
		cout << -1;
	else
		cout << result;
}