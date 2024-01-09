#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;
int arr[100001]; // 최소값의 index
vector<int> tree;

int initTree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;
	int sm = initTree(start, mid, node * 2);
	int me = initTree(mid + 1, end, node * 2 + 1);
	tree[node] = arr[sm] < arr[me] ? sm : me;
	if (arr[sm] == arr[me]) // 값이 같을때
		tree[node] = sm < me ? sm : me;
	return tree[node];
}

int updateTree(int start, int end, int node, int idx)
{
	if (idx < start || end < idx)
		return tree[node];

	if (start == end)
		return tree[node];

	int mid = (start + end) / 2;
	int sm = updateTree(start, mid, node * 2, idx);
	int me = updateTree(mid + 1, end, node * 2 + 1, idx);
	tree[node] = arr[sm] < arr[me] ? sm : me;
	if (arr[sm] == arr[me]) // 값이 같을때
		tree[node] = sm < me ? sm : me;
	return tree[node];
}

int findTree(int start, int end, int node, int left, int right)
{
	if (end < left || right < start)
		return -1; // 범위 벗어났을때

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int sm = findTree(start, mid, node * 2, left, right);
	int me = findTree(mid + 1, end, node * 2 + 1, left, right);
	if (sm == -1)
		return me;

	else if (me == -1)
		return sm;

	else if (arr[sm] == arr[me])
		return sm < me ? sm : me;

	else
		return arr[sm] < arr[me] ? sm : me;
}

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	tree.resize((N + 1) * 4);
	initTree(1, N, 1);
}
void solve()
{
	cin >> M;
	while (M--)
	{
		int command;
		int a, b;
		cin >> command >> a >> b;
		if (command == 1)
		{
			arr[a] = b;
			updateTree(1, N, 1, a);
		}
		else
		{
			cout << findTree(1, N, 1, a, b) << "\n";
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