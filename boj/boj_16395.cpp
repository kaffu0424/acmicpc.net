#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Y, X;
int arr[31][31];

int main()
{
	int t = 1;
	cin >> Y >> X;
	arr[0][0] = 1;
	for (int i = 1; i < Y; i++)
	{
		arr[i][0] = 1;
		arr[i][t++] = 1;
	}

	t = 2;
	for (int y = 2; y < Y; y++)
	{
		for (int x = 1; x < t; x++)
		{
			arr[y][x] = arr[y - 1][x] + arr[y - 1][x - 1];
		}
		t++;
	}

	cout << arr[Y - 1][X - 1];
}
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
arr[y][x] = [y - 1][x] + [y - 1][x - 1]
*/