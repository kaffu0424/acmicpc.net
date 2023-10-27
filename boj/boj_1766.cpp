#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;

int degree[32001];
vector<int> graph[32001];

void solve()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			degree[next]--;
			if (degree[next] == 0)
				pq.push(next);
		}
	}
}

int main()
{

	/*
		1. N���� ������ ��� Ǯ��� �Ѵ�.
		2. ���� Ǫ�� ���� ���� ������ �ִ� ������, ���� Ǫ�� ���� ���� ������ �ݵ�� ���� Ǯ��� �Ѵ�.
		3. �����ϸ� ���� �������� Ǯ��� �Ѵ�.
	*/

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b); // ���� ����
		degree[b]++; // ����ġ ++
	}

	solve();
}