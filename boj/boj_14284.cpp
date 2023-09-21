#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[100001];
int dist[100001];
int N, M;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push({ 0, start });

	while (!q.empty())
	{
		int cur = q.top().second;
		int cost = q.top().first;
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;

			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				q.push({ dist[next], next });
			}
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		dist[i] = INF;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int s, t;
	cin >> s >> t;
	dijkstra(s);
	cout << dist[t];
}