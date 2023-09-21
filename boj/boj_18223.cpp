#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

vector<pii> graph[10001];
int dist[10001];

int V, E, P;
void dijkstra(int start)
{
	for (int i = 0; i <= V; i++)
		dist[i] = INF;

	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist[start] = 0;
	q.push({ 0,start });

	while (!q.empty())
	{
		int cur = q.top().second;
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
	cin >> V >> E >> P;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	dijkstra(1);
	int one_v = dist[V];
	int one_p = dist[P];

	dijkstra(P);
	int p_v = dist[V];

	if (one_v == one_p + p_v)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
	// 1번 -> V번
	// 1번 -> P번 -> V번
}