#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100001];
int visit[100001];
int N, M, R;
int u, v;
int cnt = 0;

void dfs(int start)
{
	cnt++;
	visit[start] = cnt;
	for (int i : graph[start])
	{
		if (visit[i] == 0)
			dfs(i);
	}
}

bool comp(int a, int b)
{
	return a < b;
}

int main()
{

	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end(), comp);
	}
	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << visit[i] << "\n";
}