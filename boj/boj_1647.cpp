#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int ans = 0;
int parent[100001];
vector<pair<int, pair<int, int>>> vec;
vector<int> costs;
int getParent(int n)
{
	if (parent[n] == n)
		return n;
	return parent[n] = getParent(parent[n]);
}
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	return a == b;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}
	sort(vec.begin(), vec.end());
	costs.resize(N + 1, 0);
	for (int i = 0; i < vec.size(); i++)
	{
		int a = vec[i].second.first;
		int b = vec[i].second.second;
		int cost = vec[i].first;
		if (!findParent(a, b))
		{
			unionParent(a, b);
			costs.push_back(cost);
			ans += cost;
		}
	}
	cout << ans - costs[costs.size() - 1];
}