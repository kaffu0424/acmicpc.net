#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int visit[101];
vector<int> graph[101];

void ResetVisit()
{
	for (int i = 0; i <= N; i++)
		visit[i] = -1;
}

int bfs(int node)
{
	int ret = 0;
	queue<int> q;
	visit[node] = 0;
	q.push(node);
	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (int next : graph[curNode])
		{
			if (visit[next] == -1)
			{
				visit[next] = visit[curNode] + 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		ret += visit[i];

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int minNode = 0;
	int minAns = 987654321;
	for (int i = 1; i <= N; i++)
	{
		ResetVisit();
		int tmp = bfs(i);
		if (minAns > tmp)
		{
			minAns = tmp;
			minNode = i;
		}
	}

	cout << minNode;
}