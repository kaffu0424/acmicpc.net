#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


long long N, M, K;
long long arr[1000001];
long long tree[4444444];

long long init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2; // ºÐÇÒ
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, long long dif)
{
	if (index < start || index > end)
		return;

	tree[node] += dif;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

long long sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(0, N - 1, 1);

	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;
		cin >> a;
		cin >> b >> c;
		if (a == 1)
		{
			long long dif;
			dif = c - arr[b - 1];
			arr[b - 1] = c;
			update(0, N - 1, 1, b - 1, dif);
		}
		if (a == 2)
		{
			cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
		}
	}
}
