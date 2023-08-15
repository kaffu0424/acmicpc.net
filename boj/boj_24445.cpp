#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R, u, v;
vector<int> graph[100001];
int visit[100001];
int cnt = 1;
void bfs(int start)
{
	queue<int> q;
	visit[start] = cnt++;
	q.push(start);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i : graph[tmp])
		{
			if (visit[i] == 0) // 방문하지않은곳
			{
				visit[i] = cnt++;
				q.push(i);
			}
		}
	}
}

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		// 내림차순으로 방문하기위해 정렬
		sort(graph[i].begin(), graph[i].end(), comp);
	}
	bfs(R);

	for (int i = 1; i <= N; i++)
		cout << visit[i] << "\n";
}