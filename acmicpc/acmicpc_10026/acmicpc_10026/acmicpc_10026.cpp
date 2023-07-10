#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 10026번
int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int N;
char arr1[101][101]{ 0 }; // R , G : 1, B : 2
char arr2[101][101]{ 0 }; // R : 1 , B : 2 , G : 3
bool visited1[101][101]; // 방문가능상태로 초기화
bool visited2[101][101];

int result1 = 0; // 적록색약
int result2 = 0; // 적록색약 아님


void dfs1(int y, int x, char target)
{
	arr1[y][x] = '-';
	visited1[y][x] = false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		if (arr1[ny][nx] == target && visited1[ny][nx])
			dfs1(ny, nx, target);
	}
}
void dfs2(int y, int x, char target)
{
	arr2[y][x] = '-';
	visited2[y][x] = false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		if (arr2[ny][nx] == target && visited2[ny][nx])
			dfs2(ny, nx, target);
	}
}

int main()
{
	fill(&arr1[0][0], &arr1[100][100], 0);
	fill(&arr2[0][0], &arr2[100][100], 0);
	fill(&visited1[0][0], &visited1[100][100], true);
	fill(&visited2[0][0], &visited2[100][100], true);

	string str;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'R')
			{
				arr1[n][i] = 'R';
				arr2[n][i] = 'R';
			}
			else if (str[i] == 'B')
			{
				arr1[n][i] = 'B';
				arr2[n][i] = 'B';
			}
			else if (str[i] == 'G')
			{
				arr1[n][i] = 'R';
				arr2[n][i] = 'G';
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (arr1[y][x] == 'R' || arr1[y][x] == 'B' && visited1[y][x])
			{
				dfs1(y, x, arr1[y][x]);
				result1++;
			}


			if (arr2[y][x] == 'R' || arr2[y][x] == 'B' || arr2[y][x] == 'G' && visited2[y][x])
			{
				dfs2(y, x, arr2[y][x]);
				result2++;
			}
		}
	}

	cout << result2 << " " << result1;
}