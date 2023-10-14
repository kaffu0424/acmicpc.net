#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

vector<pii> graph[2501];
int dist[2501];
int N, M, S, E;

void dijkstra(int start)
{
	dist[start] = 0; // 시작위치의 비용은 0
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start }); // 탐색 시작 , {비용,위치}

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;

			if (dist[next] > nextCost + dist[cur])
			{
				dist[next] = nextCost + dist[cur];
				pq.push({ dist[next],next });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> S >> E;

	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	dijkstra(S);
	cout << dist[E];
}