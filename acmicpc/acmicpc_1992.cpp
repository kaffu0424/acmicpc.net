#include <iostream>
using namespace std;


int N;
int arr[64][64];
void quad(int y, int x, int size)
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (arr[y][x] != arr[i][j])
			{
				cout << "(";
				quad(y, x, size / 2);
				quad(y, x + size / 2, size / 2);
				quad(y + size / 2, x, size / 2);
				quad(y + size / 2, x + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << arr[y][x];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	quad(0, 0, N);
}