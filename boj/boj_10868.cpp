#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
vector<int> arr;
vector<int> tree;
vector<pair<int, int>> ab;

int initTree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	int sm = initTree(start, mid, node * 2); // 현재 위치의 왼쪽
	int me = initTree(mid + 1, end, node * 2 + 1); // 현재 위치의 오른쪽

	return tree[node] = min(sm, me);
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
	}

	tree.resize(N * 4);

	initTree(0, N - 1, 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ab.push_back({ a,b });
	}
}

int findMin(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 2100000000;

	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	int a = findMin(start, mid, node * 2, left, right);
	int b = findMin(mid + 1, end, node * 2 + 1, left, right);
	return  min(a, b);
}

void solve()
{
	for (int i = 0; i < ab.size(); i++)
	{
		int a = ab[i].first - 1;
		int b = ab[i].second - 1;

		cout << findMin(0, N - 1, 1, a, b) << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}