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
int arr[100010];
int tree_even[100010 * 4]; // Â¦¼ö
int tree_odd[100010 * 4]; // È¦¼ö

void initTree_odd(int start, int end, int node)
{
	if (start == end)
	{
		if (arr[start] % 2 == 1)
			tree_odd[node] += 1;
		return;
	}

	int mid = (start + end) / 2;
	initTree_odd(start, mid, node * 2);
	initTree_odd(mid + 1, end, node * 2 + 1);
	tree_odd[node] = tree_odd[node * 2] + tree_odd[node * 2 + 1];
}
void initTree_even(int start, int end, int node)
{
	if (start == end)
	{
		if (arr[start] % 2 == 0)
			tree_even[node] += 1;
		return;
	}

	int mid = (start + end) / 2;
	initTree_even(start, mid, node * 2);
	initTree_even(mid + 1, end, node * 2 + 1);
	tree_even[node] = tree_even[node * 2] + tree_even[node * 2 + 1];
}

int findTree_odd(int start, int end, int node, int left, int right)
{
	if (end < left || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree_odd[node];

	int mid = (start + end) / 2;
	int sm = findTree_odd(start, mid, node * 2, left, right);
	int me = findTree_odd(mid + 1, end, node * 2 + 1, left, right);
	return sm + me;
}
int findTree_even(int start, int end, int node, int left, int right)
{
	if (end < left || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree_even[node];

	int mid = (start + end) / 2;
	int sm = findTree_even(start, mid, node * 2, left, right);
	int me = findTree_even(mid + 1, end, node * 2 + 1, left, right);
	return sm + me;
}


void updateTree_even(int start, int end, int node, int idx, int value)
{
	if (idx < start || end < idx) // ¹üÀ§ ¹Û
		return;

	tree_even[node] += value;

	if (start == end)
		return;

	int mid = (start + end) / 2;
	updateTree_even(start, mid, node * 2, idx, value);
	updateTree_even(mid + 1, end, node * 2 + 1, idx, value);
}
void updateTree_odd(int start, int end, int node, int idx, int value)
{
	if (idx < start || end < idx) // ¹üÀ§ ¹Û
		return;

	tree_odd[node] += value;

	if (start == end)
		return;

	int mid = (start + end) / 2;
	updateTree_odd(start, mid, node * 2, idx, value);
	updateTree_odd(mid + 1, end, node * 2 + 1, idx, value);
}

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	initTree_odd(1, N, 1);
	initTree_even(1, N, 1);
}
void solve()
{
	cin >> M;
	while (M--)
	{
		int command, left, right;
		cin >> command >> left >> right;;
		if (command == 1)
		{
			if (arr[left] % 2 == right % 2) // È¦/È¦ or Â¦/Â¦
				arr[left] = right;

			else
			{
				arr[left] = right;
				if (right % 2 == 0) //È¦ --> Â¦
				{
					updateTree_even(1, N, 1, left, 1);
					updateTree_odd(1, N, 1, left, -1);
				}
				else if (right % 2 == 1) //Â¦ --> È¦
				{
					updateTree_even(1, N, 1, left, -1);
					updateTree_odd(1, N, 1, left, 1);
				}
			}
		}
		else if (command == 2) // Â¦¼öÀÇ °³¼ö 
		{
			cout << findTree_even(1, N, 1, left, right) << "\n";
		}
		else // È¦¼öÀÇ °³¼ö
		{
			cout << findTree_odd(1, N, 1, left, right) << "\n";
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