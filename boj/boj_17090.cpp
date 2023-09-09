#include <iostream>
#include <algorithm>
using namespace std;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int arr[500][500];
bool visit[500][500];
bool dp[500][500];

int Y, X;
int result = 0;
bool solve(int y, int x)
{
	if (visit[y][x]) // 이미 지나가본적있는 길이면
		return dp[y][x];

	visit[y][x] = true; // 방문여부 체크.

	int ny = y + dy[arr[y][x]]; // 다음 y값
	int nx = x + dx[arr[y][x]]; // 다음 x값

	if (ny < 0 || nx < 0 || ny >= Y || nx >= X)
	{
		dp[y][x] = true;
		return true; // 미로 밖으로 나갔을때
	}
	// dp[y][x] = solve(ny, nx);   // 재귀
	return dp[y][x] = solve(ny, nx);
}

int main()
{
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < X; j++)
		{
			if (str[j] == 'U')
				arr[i][j] = 0;
			else if (str[j] == 'R')
				arr[i][j] = 1;
			else if (str[j] == 'D')
				arr[i][j] = 2;
			else if (str[j] == 'L')
				arr[i][j] = 3;

		}
	}

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (!visit[i][j])
			{
				solve(i, j);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (dp[i][j])
				result++;
		}
	}
	cout << result;
}