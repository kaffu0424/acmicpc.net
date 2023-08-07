#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];

void dfs(int v, int n)
{
	if (n == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = v; i <= N; i++)
	{
		arr[n] = i;
		dfs(i + 1, n + 1);
	}
}

int main()
{
	cin >> N >> M;
	dfs(1, 0);
}