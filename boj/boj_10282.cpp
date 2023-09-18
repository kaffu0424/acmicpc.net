#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, d, c;
int T;
vector<pair<int,int>> graph[10001];
int dist[10001];

void djikstra(int start) 
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ dist[start],start});

	while (!pq.empty())
	{
		int time = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (time > dist[cur])
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first; // 다음 경로
			int nextTime = graph[cur][i].second;  // 다음 경로 시간

			if (dist[next] > dist[cur] + nextTime)
			{
				dist[next] = dist[cur] + nextTime;
				pq.push({ dist[next],next });
			}
		}
	}

	int cnt = 0;
	int mNum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (dist[i] != INF)
		{
			cnt++;
			mNum = max(mNum, dist[i]);
		}
	}
	cout << cnt << " " << mNum << "\n";
}

int main()
{
	cin >> T;
	while (T--)
	{
		for (int i = 0; i <= n; i++)
			graph[i].clear();

		cin >> n >> d >> c;
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}

		fill_n(dist, 10001, INF);
		djikstra(c);
	}
}