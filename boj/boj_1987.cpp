#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Y, X;
char arr[21][21];
int visit[26];

int dy[4]{ -1, 0, 1 ,0 };
int dx[4]{ 0, 1, 0, -1 };

int answer = 0;

void dfs(int y, int x, int cnt)
{
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= X || ny >= Y) // 범위를 넘어가면
			continue;

		if (!visit[arr[ny][nx] - 'A'])
		{
			visit[arr[ny][nx] - 'A'] = 1;
			dfs(ny, nx, cnt + 1);
			visit[arr[ny][nx] - 'A'] = 0;

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < X; j++)
		{
			arr[i][j] = str[j];
		}
	}
	visit[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << answer;
}