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

int update(int start, int end, int node, int idx)
{
	if (idx < start || end < idx)
		return tree[node];

	if (start == end)
		return tree[node];

	int mid = (start + end) / 2;
	int sm = update(start, mid, node * 2, idx);
	int me = update(mid + 1, end, node * 2 + 1, idx);
	tree[node] = arr[sm] < arr[me] ? sm : me;
	if (arr[sm] == arr[me]) // 값이 같을때
		tree[node] = sm < me ? sm : me;
	return tree[node];
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
		cin >> command;
		if (command == 1)
		{
			int a, b;
			cin >> a >> b;
			arr[a] = b;
			update(1, N, 1, a);
		}
		else
		{
			cout << tree[1] << "\n";
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