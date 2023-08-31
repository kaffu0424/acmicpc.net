#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M, K;
vector<int> graph[2001];
bool visit[2001];
int dfs(int node)
{
	visit[node] = true; // �湮 ó��
	if (graph[node].size() == 0) // �����̾��� ��尡 ���۳���
		return node;  // ���� ��带 ����.

	for (int num : graph[node])
	{
		if (visit[num]) // �湮������ 
			continue; // ���پ���

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