#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 백준 4963번
int X, Y, cnt;
int arr[51][51];
bool visited[51][51];

int dy[8]{ -1,-1, 0, 1 , 1, 1 , 0 , -1 };
int dx[8]{ 0 , 1, 1, 1 , 0, -1, -1, -1 };

void dfs(int y, int x)
{
	arr[y][x] = 0;
	visited[y][x] = false;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
			continue;

		if (arr[ny][nx] == 1 && visited[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> X >> Y;
		if (X == 0 && Y == 0)
			break;

		cnt = 0;
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				int num;
				cin >> num;
				arr[y][x] = num;
				visited[y][x] = true;
			}
		}

		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if (arr[y][x] == 1 && visited[y][x])
				{
					dfs(y, x);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}