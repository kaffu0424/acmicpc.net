#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include<cmath>

using namespace std;

int N, M;

vector<pair<int, int>> vec;
vector<pair<double, pair<int, int>>> edge;
int parent[1001];

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
		parent[a] = b;
	else
		parent[b] = a;
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	return a == b;
}

double findDistance(int x1, int y1, int x2, int y2)
{
	double dx = pow(x1 - x2, 2);
	double dy = pow(y1 - y2, 2);
	double dist = sqrt(dx + dy);

	return dist;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}
}
void solve()
{
	for (int i = 0; i < N - 1; i++)
	{
		int x1 = vec[i].first;
		int y1 = vec[i].second;
		for (int j = i + 1; j < N; j++)
		{
			int x2 = vec[j].first;
			int y2 = vec[j].second;

			double dist = findDistance(x1, y1, x2, y2);

			edge.push_back({ dist,{i + 1,j + 1} });
		}
	}
	sort(edge.begin(), edge.end());

	double ans = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		pair<double, pair<int, int>> tmp = edge[i];

		if (!findParent(tmp.second.first, tmp.second.second))
		{
			unionParent(tmp.second.first, tmp.second.second);
			ans += tmp.first;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}