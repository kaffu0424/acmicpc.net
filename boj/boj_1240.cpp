#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

vector<pair<int, int>> graph[1001];
int visit[1001];
int N, M;

int bfs(int start, int end)
{
	// 거리/방문여부 초기화
	for (int i = 0; i < 1001; i++)
		visit[i] = -1;

	queue<int> q;
	q.push(start);
	visit[start] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			if (visit[next] == -1)
			{
				int nextCost = graph[cur][i].second;
				visit[next] = visit[cur] + nextCost;
				q.push(next);
			}
		}
	}

	return visit[end];
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b) << "\n";
	}
}
