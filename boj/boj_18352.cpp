#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<int> graph[300001];
int dist[300001];

vector<int> result;

int N, M, K, X;

void dijkstra(int start)
{
	for (int i = 0; i <= N; i++) dist[i] = INF;

	priority_queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.top(); // 현재 위치
		q.pop();


		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i]; // 다음 도시
			if (dist[next] > dist[cur] + 1)
			{
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K >> X;
	int a, b;
	while (M--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}

	dijkstra(X);


	for (int i = 1; i <= N; i++)
		if (dist[i] == K)
			result.push_back(i);

	if (result.size() == 0)
	{
		cout << -1;
		return 0;
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
}