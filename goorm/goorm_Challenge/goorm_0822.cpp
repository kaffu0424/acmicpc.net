#include <iostream>
using namespace std;

int N, K;
int arr[1000][1000];
int result[1000][1000];
int dy[8]{ -1, -1, 0, 1, 1, 1 , 0 , -1 };
int dx[8]{ 0 , 1 , 1, 1, 0, -1, -1, -1 };


void solve(int y, int x)
{
	for (int i = 0; i < 8; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;

		if (arr[ny][nx] == 0)
			result[ny][nx]++;
	}
}

int main()
{
	cin >> N >> K;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (arr[y][x] == 1)
			{
				solve(y, x);
			}
		}
	}

	int r = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (result[y][x] == K)
				r++;
		}
	}
	cout << r;
}
