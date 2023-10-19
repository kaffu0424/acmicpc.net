#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

vector<pii> graph[100001];
int dist[100001];

int N, M, S, P1, P2;

void djikstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist[start] = 0;
	q.push({ 0,start });

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
				q.push({ dist[next],next });
			}
		}
	}
}

void reset()
{
	for (int i = 0; i <= 100000; i++)
		dist[i] = INF;
}

int main()
{
	cin >> N >> M >> S >> P1 >> P2;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int ans1, ans2;

	reset();
	djikstra(S);
	// S -> P1
	// S -> P2
	ans1 = dist[P1];
	ans2 = dist[P2];

	reset();
	djikstra(P1);
	// P1 <-> P2
	ans1 += dist[P2];
	ans2 += dist[P2];

	cout << min(ans1, ans2);
}