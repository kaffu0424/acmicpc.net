#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 1260번
int N, M, V;
vector<int> graph[1001];
bool bfs_visited[1001];

vector<int> arr[1001];
bool dfs_visited[1001];

void dfs(int v)
{
	cout << v << " ";
	dfs_visited[v] = true;

	for (int i : arr[v])
	{
		if (!dfs_visited[i])
			dfs(i);
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	bfs_visited[v] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!bfs_visited[y])
			{
				q.push(y);
				bfs_visited[y] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int v, u;
		cin >> v >> u;
		arr[v].push_back(u);
		arr[u].push_back(v);
		graph[v].push_back(u);
		graph[u].push_back(v);

		sort(arr[v].begin(), arr[v].end());
		sort(arr[u].begin(), arr[u].end());

		sort(graph[v].begin(), graph[v].end());
		sort(graph[u].begin(), graph[u].end());
	}

	dfs(V);
	cout << "\n";
	bfs(V);
}