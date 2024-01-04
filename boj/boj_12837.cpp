#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

#define MAX 2100000000

using namespace std;

int N, Q;
vector<long long> tree;

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

long long findTree(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	long long sm = findTree(start, mid, node * 2, left, right);
	long long me = findTree(mid + 1, end, node * 2 + 1, left, right);
	return sm + me;
}

void input()
{
	cin >> N >> Q;
	tree.resize(1000001 * 4);
}
void solve()
{
	while (Q--)
	{
		int q, p, x;
		cin >> q >> p >> x;
		if (q == 1) // update
		{
			updateTree(0, N, 1, p, x);
		}
		else // find
		{
			cout << findTree(0, N, 1, p, x) << "\n";
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