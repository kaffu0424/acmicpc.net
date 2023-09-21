#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[101];
int item[101];
int dist[101];
int N, M, R;

void dijkstra(int start)
{
	for (int i = 0; i <= N; i++) // 거리 초기화
		dist[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push({ 0,start });

	while (!q.empty())
	{
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();

		//if (cost < dist[cur])
		//	continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;
			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				q.push({ dist[next],next });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		cin >> item[i];

	for (int i = 0; i < R; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}


	int m = 0;
	for (int i = 1; i <= N; i++)
	{
		dijkstra(i);

		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			if (dist[j] <= M)
			{
				sum += item[j];
			}
		}
		if (m < sum)
			m = sum;
	}
	cout << m;
}