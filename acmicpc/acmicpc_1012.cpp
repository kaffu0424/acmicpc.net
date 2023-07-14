#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



// 백준 1012번
int T, X, Y, K;
int arr[51][51];
bool visited[51][51];
int cnt;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void dfs(int y, int x)
{
	arr[y][x] = 0;
	visited[y][x] = false;

	for (int i = 0; i < 4; i++)
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

	cin >> T;
	while (T--)
	{
		fill(&arr[0][0], &arr[50][50], 0);
		fill(&visited[0][0], &visited[50][50], true);
		cnt = 0;
		cin >> X >> Y >> K;
		while (K--)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
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
