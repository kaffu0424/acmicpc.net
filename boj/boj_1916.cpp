#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dis[1001];
vector<pair<int, int>> graph[1001];

void solve(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });

	while (!q.empty())
	{
		int cur = q.top().second;
		int cost = q.top().first;
		q.pop();

		if (cost > dis[cur])
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = dis[cur] + graph[cur][i].second;

			if (nextCost < dis[next])
			{
				dis[next] = nextCost;
				q.push({ nextCost, next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	int s, e;
	cin >> s >> e;
	fill_n(dis, 1001, 987654321);
	dis[s] = 0;
	solve(s);

	cout << dis[e];
}