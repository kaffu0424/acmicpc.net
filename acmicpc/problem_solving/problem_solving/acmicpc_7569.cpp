#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int Z, Y, X;
int arr[100][100][100];
int day[100][100][100];

int dz[6] = { 0,0,0 ,0,-1,1 };
int dx[6] = { 0,0 ,1,-1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };

int t = 0;

queue<tuple<int, int, int>> q;
int bfs()
{
	while (q.size())
	{
		int _z = get<0>(q.front());
		int _y = get<1>(q.front());
		int _x = get<2>(q.front());
		q.pop();
		arr[_z][_y][_x] = 1;
		for (int i = 0; i < 6; i++)
		{
			int nz = _z + dz[i];
			int ny = _y + dy[i];
			int nx = _x + dx[i];

			if (nx < 0 || nx >= X || ny < 0 || ny >= Y || nz < 0 || nz >= Z)
				continue;

			if (day[nz][ny][nx] >= 0) 
				continue;

			day[nz][ny][nx] = day[_z][_y][_x] + 1;
			q.push({nz,ny,nx});
		}
	}

	for (int z = 0; z < Z; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if (day[z][y][x] == -1)
				{
					return -1;
				}
				t = max(t, day[z][y][x]);
			}
		}
	}
	return t;
}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> X >> Y >> Z;
	bool flag = false;
	for (int z = 0; z < Z; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				cin >> arr[z][y][x];
				if (arr[z][y][x] == 1)
					q.push({ z,y,x });

				if (arr[z][y][x] == 0)
				{
					day[z][y][x] = -1;
					flag = true;
				}
			}
		}
	}

	if (flag)
		cout << bfs();
	else
		cout << "0";
}
