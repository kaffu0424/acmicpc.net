#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 2667번
int arr[26][26];
int visited[26][26];

int cnt = 0;
int _size = 0;
vector<int> v;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int N;
void dfs(int y, int x)
{
	_size++;
	arr[y][x] = 0;
	visited[y][x] = false;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		if (arr[ny][nx] == 1 && visited[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < N; x++)
		{
			arr[y][x] = str[x] - '0';
			visited[y][x] = true;
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (arr[y][x] == 1 && visited[y][x])
			{
				_size = 0;
				dfs(y, x);
				cnt++;
				v.push_back(_size);
			}
		}
	}

	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}