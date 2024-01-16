#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

#define INF 1000000001;

using namespace std;

int N, M;
long long arr[100011];
long long tree[100011 * 4];

long long initTree(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return tree[node];
	}

	int mid = (start + end) / 2;
	int sm = initTree(start, mid, node * 2);
	int me = initTree(mid + 1, end, node * 2 + 1);

	tree[node] = min(sm, me);
	return tree[node];
}

long long findMin(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return INF;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int sm = findMin(start, mid, node * 2, left, right);
	int me = findMin(mid + 1, end, node * 2 + 1, left, right);
	return min(sm, me);
}

long long updateTree(int start, int end, int node, int idx, int value)
{
	if (idx < start || end < idx)
		return tree[node];

	if (start == end)
		return tree[node] = value;

	int mid = (start + end) / 2;
	long long sm = updateTree(start, mid, node * 2, idx, value);
	long long me = updateTree(mid + 1, end, node * 2 + 1, idx, value);

	tree[node] = min(sm, me);
	return tree[node];
}


void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> M;

	initTree(1, N, 1);
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 1)
		{
			arr[a] = b;
			updateTree(1, N, 1, a, b);
		}
		else
		{
			cout << findMin(1, N, 1, a, b) << "\n";
		}
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