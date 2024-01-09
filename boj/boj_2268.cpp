#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;
vector<long long> tree;
vector<long long> vec;
void input()
{
	cin >> N >> M;
	tree.resize((N + 1) * 4);
	vec.resize(N + 1);
}

long long sumTree(int start, int end, int node, int left, int right)
{
	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	long long sm = sumTree(start, mid, node * 2, left, right);
	long long me = sumTree(mid + 1, end, node * 2 + 1, left, right);
	return sm + me;
}

void updateTree(int start, int end, int node, int idx, int value)
{
	if (idx < start || end < idx)
		return;

	tree[node] += value;

	if (start == end)
		return;

	int mid = (start + end) / 2;
	updateTree(start, mid, node * 2, idx, value);
	updateTree(mid + 1, end, node * 2 + 1, idx, value);
}

void solve()
{
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) // sum
		{
			cout << sumTree(0, N - 1, 1, min(b, c) - 1, max(b, c) - 1) << "\n";
		}
		else // update
		{
			int dif = c - vec[b - 1];
			vec[b - 1] = c;
			updateTree(0, N - 1, 1, b - 1, dif);
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