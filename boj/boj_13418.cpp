#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int A, B, C;

int parent[1001];
vector < pair<int, pair<int, int>>> vec;

bool cmp_increase(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

bool cmp_decrease(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first > b.first;
}

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
	return getParent(a) == getParent(b);
}

void init()
{
	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}
}

int kruskal()
{
	init();
	int ans = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int cost = vec[i].first;
		int a = vec[i].second.first;
		int b = vec[i].second.second;
		if (!findParent(a, b))
		{
			unionParent(a, b);
			ans += cost;
		}
	}
	return ans;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M + 1; i++)
	{
		cin >> A >> B >> C;
		if (C == 0)
			vec.push_back({ 1,{A,B} });
		else
			vec.push_back({ 0,{A,B} });
	}

	sort(vec.begin(), vec.end(), cmp_decrease);
	int ans1 = kruskal();

	sort(vec.begin(), vec.end(), cmp_increase);
	int ans2 = kruskal();

	cout << (int)(pow(ans1, 2) - pow(ans2, 2));
}