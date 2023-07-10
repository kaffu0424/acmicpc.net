#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 2606번
vector<int> graph[101];
bool visited[101];

int N, M;


int cnt = 0;
void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = false;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i : graph[u])
		{
			if (visited[i])
			{
				visited[i] = false;
				q.push(i);
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
		graph[u].push_back(v);

		visited[v] = true;
		visited[u] = true;
	}

	bfs(1);
	cout << cnt;
}