#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <math.h>

#define RED 1
#define BLUE 2

using namespace std;

int T;
int V, E;
vector<int> graph[20001];
int visit[20001];

void init()
{
	memset(visit, 0, sizeof(visit));
	memset(graph, 0, sizeof(graph));
	/*for (int i = 0; i <= V; i++)
	{
		graph[i].clear();
		visit[i] = 0;
	}*/
}

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	visit[n] = RED;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int v : graph[cur])
		{
			if (visit[v] == 0)
			{
				q.push(v);
				if (visit[cur] == RED)
					visit[v] = BLUE;
				else
					visit[v] = RED;
			}
		}
	}
}

bool checkGraph()
{
	for (int i = 1; i <= V; i++)
	{
		for (int v : graph[i])
		{
			if (visit[i] == visit[v])
				return false;
		}
	}
	return true;
}

void input()
{
	cin >> T;
}
void solve()
{
	while (T--)
	{
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= V; i++)
		{
			if (visit[i] == 0)
				bfs(i);
		}

		if (checkGraph())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	init();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}