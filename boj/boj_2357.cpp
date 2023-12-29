#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int arr[100001];
vector<pair<int, int>> tree; // { 최대값 , 최소값 }
vector<pair<int, int>> ab;

pair<int, int> initTree(int start, int end, int node)
{
	if (start == end)
	{
		pair<int, int> tmp = { arr[start] , arr[start] };
		tree[node] = tmp;
		return tree[node];
	}

	int mid = (start + end) / 2;

	pair<int, int> sm = initTree(start, mid, node * 2); // 현재 위치의 왼쪽
	pair<int, int> me = initTree(mid + 1, end, node * 2 + 1); // 현재 위치의 오른쪽

	int maxNum = max(sm.first, me.first);
	int minNum = min(sm.second, me.second);
	return tree[node] = make_pair(maxNum, minNum);
}

pair<int, int > findTree(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) // 범위를 벗어날때.
		return { 0,2100000000 };

	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> a = findTree(start, mid, node * 2, left, right);
	pair<int, int> b = findTree(mid + 1, end, node * 2 + 1, left, right);
	pair<int, int> tmp = { max(a.first,b.first) , min(a.second, b.second) };
	return tmp;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	tree.resize(100001 * 4);
	initTree(0, N - 1, 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ab.push_back({ a,b });
	}
}

void solve()
{
	for (int i = 0; i < ab.size(); i++)
	{
		int a = ab[i].first - 1;
		int b = ab[i].second - 1;

		pair<int, int> ans = findTree(0, N - 1, 1, a, b);
		cout << ans.second << " " << ans.first << "\n";
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