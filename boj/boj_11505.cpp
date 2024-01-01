#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#define MOD 1000000007
using namespace std;

int N, M, K;
vector<long long> arr;
vector<long long> tree;
vector<pair<int, pair<int, int>>> query;

long long initTree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	long long sm = initTree(start, mid, node * 2);
	long long me = initTree(mid + 1, end, node * 2 + 1);

	return tree[node] = (sm * me) % MOD;
}

long long findTree(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	long long sm = findTree(start, mid, node * 2, left, right);
	long long me = findTree(mid + 1, end, node * 2 + 1, left, right);
	return (sm * me) % MOD;
}

long long update(int start, int end, int node, int idx, long long value)
{
	if (idx < start || end < idx)
		return tree[node];

	if (start == end)
	{
		return tree[node] = value;
	}

	int mid = (start + end) / 2;
	long long sm = update(start, mid, node * 2, idx, value);
	long long me = update(mid + 1, end, node * 2 + 1, idx, value);
	return tree[node] = (sm * me) % MOD;
}

void input()
{
	cin >> N >> M >> K;
	tree.resize(1000001 * 4);
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
	}
	initTree(0, N - 1, 1);

	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		query.push_back({ a,{b,c} });
	}
}
void solve()
{
	for (int i = 0; i < query.size(); i++)
	{
		int a = query[i].first;
		int b = query[i].second.first;
		int c = query[i].second.second;

		if (a == 1) // 수 바꾸기
		{
			update(0, N - 1, 1, b - 1, c);
		}
		else // 범위 곱 값
		{
			cout << findTree(0, N - 1, 1, b - 1, c - 1) << "\n";
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