#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int Y, X;
int arr[1000][1000];
int visit[1000][1000];
queue<pair<int, int>> q;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void bfs()
{
	while (!q.empty())
	{
		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == 0)
			{
				q.push(make_pair(ny, nx));
				visit[ny][nx] = visit[tmp.first][tmp.second] + 1;

			}
		}
	}
}


int main()
{
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
				cout << "-1 ";
			else
				cout << visit[i][j] << " ";

		}
		cout << "\n";
	}
}

//00 01 02 03 04 05 06 07 08 09 10 11 12 13 14
//01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
//02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
//03 04 05 06 07 08 09 10 11 12 13 14 15 16 17
//04 05 06 07 08 09 10 11 12 13 14 15 16 17 18
//05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
//06 07 08 09 10 11 12 13 14 15 16 17 18 19 20
//07 08 09 10 11 12 13 14 15 16 17 18 19 20 21
//08 09 10 11 12 13 14 15 16 17 18 19 20 21 22
//09 10 11 12 13 14 15 16 17 18 19 20 21 22 23
//10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
//11 12 13 14 15 16 17 18 19 20 00 00 00 00 25
//12 13 14 15 16 17 18 19 20 21 00 29 28 27 26
//13 14 15 16 17 18 19 20 21 22 00 30 00 00 00
//14 15 16 17 18 19 20 21 22 23 00 31 32 33 34