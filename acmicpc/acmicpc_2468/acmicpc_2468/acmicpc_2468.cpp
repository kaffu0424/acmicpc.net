#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 2468번
int dy[]{ -1,0,1,0 };
int dx[]{ 0,1,0,-1 };

int map[101][101];
bool visited[101][101];

int N;
int cnt;
int answer = 0;

void dfs(int y, int x, int h)
{
	visited[y][x] = false;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		if (map[ny][nx] > h && visited[ny][nx])
			dfs(ny, nx, h);
	}
}

int main()
{
	fill(&visited[0][0], &visited[100][100], true);
	int num;
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> num;
			map[y][x] = num;
		}
	}

	for (int h = 0; h <= 100; h++)
	{
		fill(&visited[0][0], &visited[100][100], true);
		cnt = 0;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (map[y][x] > h && visited[y][x])
				{
					dfs(y, x, h);
					cnt++;
				}
			}
		}
		if (cnt > answer)
			answer = cnt;
	}

	cout << answer;
}
