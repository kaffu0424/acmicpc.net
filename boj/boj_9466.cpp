#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int TC, N;
int ans = 0;
int graph[100001];
bool visit[100001];
bool done[100001];
void reset(int n)
{
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
		done[i] = 0;
	}
	ans = 0;
}

void dfs(int node)
{
	visit[node] = true;
	int next = graph[node];
	if (next == 0)
		return;
	if (!visit[next]) // 아직 방문안한곳
	{
		dfs(next);
	}
	else if (!done[next])
	{
		for (int i = next; i != node; i = graph[i])
			ans++;
		ans++;
	}
	done[node] = true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> TC;
	while (TC--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> graph[i];
		}

		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
				dfs(i);
		}

		cout << N - ans << endl;
		reset(N);
	}
}