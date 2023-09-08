#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visit[9];

void dfs(int num, int n)
{
	if (n == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = i; i <= N; i++)
	{
		visit[i] = true;
		arr[n] = i;
		dfs(i, n + 1);
		visit[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	dfs(1, 0);
}
