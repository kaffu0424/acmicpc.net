#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 1000000;
int V, E, K;
vector<pair<int, int>> graph[20001]; // graph[출발] { 비용, 도착 }
int cost[20001];

void dijkstra(int start)
{
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int distance = -pq.top().first; // 짧은것이먼저 오도록 음수화
		int current = pq.top().second;
		pq.pop();

		// 최단거리가 아닌경우 스킵.
		//if (cost[current] < distance)
		//	continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i].first;
			int nextDistance = graph[current][i].second;

			if (cost[next] > distance + nextDistance)
			{
				cost[next] = distance + nextDistance;
				pq.push(make_pair(-cost[next], next));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;
	cin >> V >> E >> K;

	for (int i = 1; i <= V; i++)
		cost[i] = INF;

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w));
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (cost[i] == INF)
			cout << "INF" << "\n";
		else
			cout << cost[i] << "\n";
	}
}
