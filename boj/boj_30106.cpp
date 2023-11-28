#include <iostream>
#include <string>
#include <deque>
#include <queue>>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int ans = 0;
int arr[501][501];
bool visit[501][501];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;

	visit[y][x] = true;
	q.push({ y,x });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + cur.first;
			int nx = dx[i] + cur.second;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
				continue;

			int heightDifference = abs(arr[cur.first][cur.second] - arr[ny][nx]);

			if (heightDifference <= K)
			{
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j])
			{
				bfs(i, j);
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}