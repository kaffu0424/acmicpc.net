#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N, V, E;
vector<pii> graph[1001]; // graph[출발] {도착,거리}
int dist[1001];
vector<int> people;
int KIST, SSIAL;

int answer = 0;
void djikstra(int start)
{
	for (int i = 0; i <= V; i++)
		dist[i] = INF;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dist[cur])
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;

			if (dist[next] > nextCost + dist[cur])
			{
				dist[next] = nextCost + dist[cur];
				pq.push({ dist[next], next });
			}
		}
	}
}

int main()
{
	cin >> N >> V >> E;
	cin >> KIST >> SSIAL;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		people.push_back(n);
	}
	for (int i = 0; i < E; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}

	for (int v : people)
	{
		djikstra(v);

		answer += dist[KIST] == INF ? -1 : dist[KIST];
		answer += dist[SSIAL] == INF ? -1 : dist[SSIAL];
	}
	cout << answer;
}