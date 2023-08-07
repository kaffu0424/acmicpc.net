#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visit[9];

void dfs(int n)
{
	if (n == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr[n] = i;
			dfs(n + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
}