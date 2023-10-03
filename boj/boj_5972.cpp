#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

priority_queue<pii> pq;
vector<pii> graph[50001];
int dist[50001];
int N, M;

void dijkstra(int start)
{
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cost > dist[cur])
			continue;


		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;

			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 50001; i++)
		dist[i] = INF;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	dijkstra(1);
	cout << dist[N];
}
