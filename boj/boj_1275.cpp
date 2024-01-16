#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;
long long arr[100011];
long long tree[100011 * 4];

long long initTree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	long long sm = initTree(start, mid, node * 2);
	long long me = initTree(mid + 1, end, node * 2 + 1);
	tree[node] = sm + me;
	return tree[node];
}

long long sum(int start, int end, int node, int left, int right)
{
	if (end < left || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	long long sm = sum(start, mid, node * 2, left, right);
	long long me = sum(mid + 1, end, node * 2 + 1, left, right);
	return sm + me;
}

void updateTree(int start, int end, int node, int idx, long long dif)
{
	if (idx < start || end < idx)
		return;

	tree[node] += dif;

	if (start == end)
		return;

	int mid = (start + end) / 2;
	updateTree(start, mid, node * 2, idx, dif);
	updateTree(mid + 1, end, node * 2 + 1, idx, dif);
}

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	initTree(1, N, 1);
}

void solve()
{
	while (M--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;


		if (x <= y)
			cout << sum(1, N, 1, x, y) << "\n";
		else
			cout << sum(1, N, 1, y, x) << "\n";

		updateTree(1, N, 1, a, b - arr[a]);
		arr[a] = b;
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