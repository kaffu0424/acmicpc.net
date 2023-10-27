#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N, ans;
int queen[16];

bool check(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (queen[i] == queen[x])
			return false;

		// X,Y 대각선 A,B
		// X - A == Y - B
		if (abs(queen[x] - queen[i]) == x - i)
			return false;

	}
	return true;
}

void solve(int x)
{
	if (x == N)
		ans++;

	else
	{
		for (int i = 0; i < N; i++)
		{
			queen[x] = i;
			if (check(x))
				solve(x + 1);
		}
	}
}

int main()
{
	ans = 0;

	cin >> N;
	solve(0);
	cout << ans;
	// 1행 또는 1열에는 하나의 퀸만 존재 가능...
	// 무조건 N개의 퀸이 놓일수있는가 ?
}
