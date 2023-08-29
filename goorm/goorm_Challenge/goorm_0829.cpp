#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int arr[1000][1000];
int result = 0;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	arr[y][x] = 0;
	while (!q.empty())
	{
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) // 범위 초과
				continue;

			if (arr[ny][nx] == 0) // 조건에 맞지않은곳
				continue;

			q.push(make_pair(ny, nx));
			arr[ny][nx] = 0;
		}
	}

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 1)
			{
				bfs(i, j);
				result++;
			}
	cout << result;
}