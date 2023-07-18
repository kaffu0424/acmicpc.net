#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[128][128];
int N;

int w = 0;
int b = 0;


void div(int y, int x, int _size)
{
	int check = arr[y][x];
	for (int i = y; i < y+ _size; i++)
	{
		for (int j = x; j < x+_size; j++)
		{	
			if (check == 0 && arr[i][j] == 1)
				check = 2;

			else if (check == 1 && arr[i][j] == 0)
				check = 2;

			if (check == 2)
			{
				div(y, x, _size / 2);
				div(y, x + _size / 2, _size / 2);
				div(y + _size / 2, x, _size / 2);
				div(y + _size / 2, x + _size / 2, _size / 2);
				return;
			}
		}
	}
	
	if (check == 0)
		w++;
	else
		b++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> arr[i][j];

	div(0, 0, N);

	cout << w << endl;
	cout << b << endl;
}