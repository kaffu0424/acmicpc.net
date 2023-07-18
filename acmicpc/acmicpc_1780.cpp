#include <iostream>
#include <string>
using namespace std;

int n;
int paper[2200][2200];
int cnt[3];

void div(int y, int x, int size)
{
	int check = paper[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (check == -1 && paper[i][j] != check)
				check = 2;
			else if (check == 0 && paper[i][j] != check)
				check = 2;
			else if (check == 1 && paper[i][j] != check)
				check = 2;

			if (check == 2)
			{
				div(y, x, size / 3); // 왼쪽 위
				div(y, x + size / 3, size / 3); // 중간위
				div(y, x + ((size / 3) * 2), size / 3); // 오른쪽 위

				div(y + size / 3, x, size / 3); // 왼쪽 중간
				div(y + size / 3, x + size / 3, size / 3); // 중간
				div(y + size / 3, x + ((size / 3) * 2), size / 3);// 오른쪽 중간

				div(y + ((size / 3) * 2), x, size / 3); // 왼쪽 아래
				div(y + ((size / 3) * 2), x + size / 3, size / 3); // 중간 아래
				div(y + ((size / 3) * 2), x + ((size / 3) * 2), size / 3); // 오른쪽 아래
				return;
			}
		}
	}

	cnt[check + 1]++;

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	div(0, 0, n);

	cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2] << "\n";
}