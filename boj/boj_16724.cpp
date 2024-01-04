#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;
int map[1001][1001];
int visit[1001][1001];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int ans = 0;
void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			if (str[j] == 'U')
				map[i][j] = 0;

			else if (str[j] == 'R')
				map[i][j] = 1;

			else if (str[j] == 'D')
				map[i][j] = 2;

			else if (str[j] == 'L')
				map[i][j] = 3;
		}
	}
}

void dfs(int y, int x)
{
	visit[y][x] = 1;

	int dir = map[y][x];
	int nextY = y + dy[dir];
	int nextX = x + dx[dir];

	if (visit[nextY][nextX] == 0)
		dfs(nextY, nextX);

	else if (visit[nextY][nextX] == 1)
		ans++;

	visit[y][x] = 2;

}

void solve()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (visit[y][x] == 0)
			{
				dfs(y, x);
			}
		}
	}
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}