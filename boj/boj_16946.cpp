#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int map[1001][1001];
int visit[1001][1001];
int answer[1001][1001];

int groupNumbers[1000001];
int groupNumber = 1;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

void input()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
		{
			map[y][x] = str[x] - '0';
		}
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visit[y][x] = groupNumber;

	int cnt = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (map[ny][nx] > 0 || visit[ny][nx])
				continue;

			visit[ny][nx] = groupNumber;
			q.push({ ny,nx });
		}
	}
	groupNumbers[groupNumber++] = cnt;
}

void setMap(int y, int x)
{
	int cnt = 1;
	vector<int> vec;

	for (int i = 0; i < 4; i++)
	{
		bool tmp = false;

		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;

		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j] == visit[ny][nx])
			{
				tmp = true;
				break;
			}
		}

		vec.push_back(visit[ny][nx]);
		if (!tmp)
			cnt += groupNumbers[visit[ny][nx]];
	}
	answer[y][x] = cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] != 0 || visit[y][x] > 0)
				continue;

			bfs(y, x);
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] > 0)
			{
				setMap(y, x);
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << answer[y][x] % 10;
		}
		cout << "\n";
	}
}