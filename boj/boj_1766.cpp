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
		1. N개의 문제는 모두 풀어야 한다.
		2. 먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
		3. 가능하면 쉬운 문제부터 풀어야 한다.
	*/

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b); // 간선 연결
		degree[b]++; // 가중치 ++
	}

	solve();
}