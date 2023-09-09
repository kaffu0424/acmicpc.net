#include <iostream>
#include <algorithm>
using namespace std;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int arr[500][500];
bool visit[500][500];
bool dp[500][500];

int Y, X;
int result = 0;
bool solve(int y, int x)
{
	if (visit[y][x]) // �̹� �����������ִ� ���̸�
		return dp[y][x];

	visit[y][x] = true; // �湮���� üũ.

	int ny = y + dy[arr[y][x]]; // ���� y��
	int nx = x + dx[arr[y][x]]; // ���� x��

	if (ny < 0 || nx < 0 || ny >= Y || nx >= X)
	{
		dp[y][x] = true;
		return true; // �̷� ������ ��������
	}
	// dp[y][x] = solve(ny, nx);   // ���
	return dp[y][x] = solve(ny, nx);
}

int main()
{
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < X; j++)
		{
			if (str[j] == 'U')
				arr[i][j] = 0;
			else if (str[j] == 'R')
				arr[i][j] = 1;
			else if (str[j] == 'D')
				arr[i][j] = 2;
			else if (str[j] == 'L')
				arr[i][j] = 3;

		}
	}

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (!visit[i][j])
			{
				solve(i, j);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (dp[i][j])
				result++;
		}
	}
	cout << result;
}