#include <iostream>
using namespace std;

int N;
bool arr[7000][7000];

void star(int y, int x, int size, bool flag)
{
	if (size == 1 || size == 0)
	{
		arr[y][x] = true;
		return;
	}


	// 상단
	star(y, x, size / 3, true);
	star(y, x + (size / 3), size / 3, true);
	star(y, x + ((size / 3) * 2), size / 3, true);

	// 중단
	star(y + (size / 3), x, size / 3, true);

	star(y + (size / 3), x + ((size / 3) * 2), size / 3, true);

	// 하단
	star(y + ((size / 3) * 2), x, size / 3, true);
	star(y + ((size / 3) * 2), x + (size / 3), size / 3, true);
	star(y + ((size / 3) * 2), x + ((size / 3) * 2), size / 3, true);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	star(0, 0, N, false);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j])
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}