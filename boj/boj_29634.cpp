#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[30][30];
bool visit[30][30];
int N, M;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visit[y][x] = true;
	int ret = 1;

	while (!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = t.first + dy[i];
			int nx = t.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx] || arr[ny][nx] == '*')
				continue;

			q.push({ ny,nx });
			visit[ny][nx] = true;
			ret++;
		}
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	int m = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '.' && !visit[i][j])
			{
				int cnt = bfs(i, j);
				if (m < cnt)
					m = cnt;
			}
		}
	}

	cout << m;
}