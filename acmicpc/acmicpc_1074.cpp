#include <iostream>
using namespace std;


int N, Y, X;
int ans = 0;

void Z(int y, int x, int size)
{
	if (y == Y && x == X)
	{
		cout << ans;
		return;
	}

	if ((y <= Y && y + size > Y) && (x <= X && x + size > X))
	{
		Z(y, x, size / 2);
		Z(y, x + size / 2, size / 2);
		Z(y + size / 2, x, size / 2);
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else
	{
		ans += size * size;
	}
}
int main()
{
	cin >> N >> Y >> X;

	int z = 2;
	for (int i = 0; i < N - 1; i++)
	{
		z *= 2;
	}

	Z(0, 0, z);
}