#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 7576번
int Y, X;
int arr[1001][1001];
int day[1001][1001];

int dy[]{ -1,0,1,0 };
int dx[]{ 0,1,0,-1 };

int ay = 0;
int ax = 0;
int bfs()
{
	queue<pair<int, int>> q;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (arr[y][x] == 1)
			{
				q.push(make_pair(y, x));
			}
		}
	}

	while (q.size())
	{
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;
			if (arr[ny][nx] == 1 || arr[ny][nx] == -1)
				continue;

			q.push(make_pair(ny, nx));
			arr[ny][nx] = 1;
			day[ny][nx] = day[temp.first][temp.second] + 1;
			ax = nx;
			ay = ny;
		}
	}

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (arr[y][x] == 0)
			{
				return -1;
			}
		}
	}
	return day[ay][ax];
}

int main()
{
	cin >> X >> Y;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> arr[y][x];
		}
	}

	cout << bfs();
}
