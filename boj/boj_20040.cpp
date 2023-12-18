#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int parent[500001];

int getParent(int n)
{
	if (parent[n] == n)
		return n;
	return parent[n] = getParent(parent[n]);
}
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (findParent(a, b)) // 서로 이미 연결된 노드 == 사이클 발생
		{
			cout << i;
			return 0;
		}
		else
		{
			unionParent(a, b);
		}
	}
	cout << 0;
}