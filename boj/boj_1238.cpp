#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, X;
vector<pair<int, int>> graph[1001];
int result[1001];
int dis[1001];

int solve(int start)
{
	for (int i = 0; i <= N; i++) dis[i] = INF; // �ʱ�ȭ

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });
	dis[start] = 0;

	while (!q.empty())
	{
		int cur = q.top().second;
		int cost = q.top().first;
		q.pop();

		if (cost > dis[cur])
			continue;

		for (pair<int, int> i : graph[cur])
		{
			int next = i.first;
			int nextCost = dis[cur] + i.second;

			if (nextCost < dis[next])
			{
				dis[next] = nextCost;
				q.push({ nextCost,next });
			}
		}
	}

	return dis[X];
}

int main()
{
	cin >> N >> M >> X;
	while (M--)
	{
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back({ b,t }); // �ܹ���
	}

	int t = solve(X); // ������ ���ư��� ��ΰ��
	for (int i = 1; i <= N; i++)
		result[i] = dis[i];

	for (int i = 1; i <= N; i++)
		result[i] += solve(i);

	int m = 0;
	for (int i = 1; i <= N; i++)
	{
		if (m < result[i])
			m = result[i];
	}

	cout << m;
}