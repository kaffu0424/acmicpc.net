#include <iostream>
using namespace std;


int map[500][500];
int dp[500][500];
int Y, X;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int dfs(int y, int x)
{
	if (x == X - 1 && y == Y - 1) // 도칙하면 return 1
		return 1;

	if (dp[y][x] != -1) 
		return dp[y][x]; 

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
			continue;

		if (map[ny][nx] < map[y][x])
		{
			dp[y][x] = dp[y][x] + dfs(ny, nx);
		}
	}

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Y >> X;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> map[y][x];
			dp[y][x] = -1;
		}
	}
	cout << dfs(0, 0);
}