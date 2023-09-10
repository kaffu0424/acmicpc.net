#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int Y, X;
int arr[1000][1000];
int visit[1000][1000][2];

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int bfs(int y, int x)
{
	queue<pair<pair<int, int>, int>> q; // {{ y , x } , 해당경로가 벽을 부술수있는 횟수}
	q.push({ {y,x},1 });
	visit[y][x][1] = 1;
	while (!q.empty())
	{
		pair<pair<int, int>, int> tmp = q.front();
		q.pop();

		if (tmp.first.first == Y - 1 && tmp.first.second == X - 1)
			return visit[tmp.first.first][tmp.first.second][tmp.second];

		for (int i = 0; i < 4; i++)
		{
			int ny = tmp.first.first + dy[i];
			int nx = tmp.first.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= Y || nx >= X) // 범위 초과
				continue; 

			// 다음칸이 벽 + 벽을 부술수있을때.
			if (arr[ny][nx] == 1 && tmp.second)
			{
				q.push({ {ny,nx},0 });
				visit[ny][nx][tmp.second - 1] = visit[tmp.first.first][tmp.first.second][tmp.second] + 1;
			}

			// 다음칸이 벽이 아님 + 아직 방문하지않은곳.
			else if (arr[ny][nx] == 0 && visit[ny][nx][tmp.second] == 0)
			{
				q.push({ {ny,nx},tmp.second });
				visit[ny][nx][tmp.second] = visit[tmp.first.first][tmp.first.second][tmp.second] + 1;
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> Y >> X;
	for (int y = 0; y < Y; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < X; x++)
		{
			arr[y][x] = str[x] - '0';
		}
	}

	cout << bfs(0, 0);
	
}