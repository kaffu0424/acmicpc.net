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

		// X,Y �밢�� A,B
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
	// 1�� �Ǵ� 1������ �ϳ��� ���� ���� ����...
	// ������ N���� ���� ���ϼ��ִ°� ?
}
