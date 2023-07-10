#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 1926번
int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

char arr[501][501];
bool visited[501][501];

int Y, X;

int maxsize = 0;
int cnt = 0;

int ret = 0;

void dfs(int y, int x)
{
	ret++;
	arr[y][x] = 0;
	visited[y][x] = false;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
			continue;

		if (arr[ny][nx] == 1 && visited[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	fill(&arr[0][0], &arr[500][500], 0);
	fill(&visited[0][0], &visited[500][500], true);

	int num;
	cin >> Y >> X;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> num;
			arr[y][x] = num;
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
				if (ret > maxsize)
					maxsize = ret;

				ret = 0;
			}
		}
	}

	cout << cnt << "\n";
	cout << maxsize;
}