#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N, M;
int arr[1000001];

// 부모노드 찾기
int getParent(int x)
{
	if (arr[x] == x)
		return x;
	return arr[x] = getParent(arr[x]);
}

// 합치기
void Union(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a < b) arr[b] = a;
	else arr[a] = b;
}

void FindUnion(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0)
		{
			Union(a, b);
		}
		else
		{
			FindUnion(a, b);
		}

	}
}