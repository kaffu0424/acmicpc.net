#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


// 백준 7562
int arr[301][301];
int dy[]{ -2, -1, 1, 2,  2,  1, -1,-2 };
int dx[]{ 1,  2, 2, 1, -1, -2, -2,-1 };
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				arr[i][j] = 0;
		int y, x;
		int targetY, targetX;
		cin >> y >> x;
		cin >> targetY >> targetX;

		queue<pair<int, int>> q;
		q.push(make_pair(y, x));
		arr[y][x] = 0;
		while (q.size())
		{
			pair<int, int> temp = q.front();
			if (temp.first == targetY && temp.second == targetX)
			{
				cout << arr[targetY][targetX] << "\n";
				break;
			}
			q.pop();
			for (int i = 0; i < 8; i++)
			{
				int ny = dy[i] + temp.first;
				int nx = dx[i] + temp.second;

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (arr[ny][nx])
					continue;

				q.push(make_pair(ny, nx));
				arr[ny][nx] = arr[temp.first][temp.second] + 1;
			}
		}
	}
}