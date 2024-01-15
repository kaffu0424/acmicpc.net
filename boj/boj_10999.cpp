#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;
long long arr[1000010];
long long lazy[1000010 * 4 + 100];
long long tree[1000010 * 4 + 100];

void initTree(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	initTree(node * 2, start, mid);
	initTree(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void input()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	initTree(1, 1, N);
}


void lazyUpdate(int node, int start, int end)
{
	if (lazy[node] == 0)
		return;

	tree[node] += lazy[node] * (end - start + 1);
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, long long dif)
{
	lazyUpdate(node, start, end);
	if (right < start || end < left)
		return;

	if (left <= start && end <= right)
	{
		lazy[node] += dif;
		lazyUpdate(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, dif);
	update(node * 2 + 1, mid + 1, end, left, right, dif);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int node, int start, int end, int left, int right)
{
	lazyUpdate(node, start, end);
	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	long long sm = sum(node * 2, start, mid, left, right);
	long long me = sum(node * 2 + 1, mid + 1, end, left, right);
	return sm + me;
}

void solve()
{
	for (int i = 0; i < M + K; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b, c;
			long long d;
			cin >> b >> c >> d;
			update(1, 1, N, b, c, d);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			cout << sum(1, 1, N, b, c) << "\n";
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