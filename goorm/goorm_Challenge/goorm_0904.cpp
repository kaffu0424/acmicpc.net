#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[2001][2001];
int visit[2001];
vector<int> v[2001];

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visit[node] = 1;

	while (!q.empty())
	{
		int t = q.front();
		q.pop();

		for (int n : v[t])
		{
			if (visit[n])
				continue;
			visit[n] = 1;
			q.push(n);
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		arr[s][e] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (arr[i][j] && arr[j][i])
			{
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i])
			continue;
		answer++;
		BFS(i);
	}

	cout << answer;
}