#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int degree[32001];
int answer[32001];
vector<int> v[32001];

void sort()
{
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 삽입.
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}

	//N개의 노드 방문
	for (int i = 1; i <= N; i++)
	{
		int tmp = q.front();
		q.pop(); // pop
		answer[i] = tmp;
		for (int u : v[tmp])
		{
			// 진입차수가 0이 된 노드를 큐에 삽입.
			if (--degree[u] == 0)
				q.push(u);
		}
	}
}

int main()
{
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}

	sort();
	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << " ";
	}
}