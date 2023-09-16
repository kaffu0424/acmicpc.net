#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dy[4]{ -1, 0, 1, 0 };
int dx[4]{ 0, 1, 0, -1 };

int N;
int arr[125][125];
int dis[125][125];
int answer;
void bfs()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dis[i][j] = INF;

	queue<pair<int, int>> q;
	dis[0][0] = arr[0][0];
	q.push({ 0, 0 });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;

			// 다음경로의 값 >  현재경로 + 다음경로 cost
			if (dis[ny][nx] > dis[cur.first][cur.second] + arr[ny][nx])
			{
				dis[ny][nx] = dis[cur.first][cur.second] + arr[ny][nx];
				q.push({ ny,nx });
			}
		}
	}
	answer = dis[N - 1][N - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c = 1;
	while (c)
	{
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		bfs();
		cout << "Problem " << c++ << ": " << answer << "\n";
	}
}