#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1025][1025];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
		}
	}

	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << arr[y2][x2] + arr[y1 - 1][x1 - 1] - arr[y2][x1 - 1] - arr[y1 - 1][x2] << "\n";
	}
}

/*
01 03 06 10
03 08 15 24
06 15 27 42
10 24 42 64
*/

// (arr[y2][x2] + arr[y1-1][x1-1]) - (arr[y2][x1 - 1] - arr[y1 - 1][x2])