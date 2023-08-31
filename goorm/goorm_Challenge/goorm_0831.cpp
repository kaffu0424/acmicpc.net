#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M, K;
vector<int> graph[2001];
bool visit[2001];
int dfs(int node)
{
	visit[node] = true; // 방문 처리
	if (graph[node].size() == 0) // 간선이없는 노드가 시작노드면
		return node;  // 현재 노드를 리턴.

	for (int num : graph[node])
	{
		if (visit[num]) // 방문했으면 
			continue; // 접근안함

		return dfs(num);
	}
	return node;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	int node = dfs(K);
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i])
			cnt++;
	}
	cout << cnt << " " << node;
}