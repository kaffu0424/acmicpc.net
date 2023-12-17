#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<pair<double, double>> vec;
vector<pair<double, pair<int, int>>> graph;
int parent[101];

double ans = 0;

double getCost(double x, double y, double x2, double y2)
{
	double dx = (x - x2) * (x - x2);
	double dy = (y - y2) * (y - y2);
	return sqrt(dx + dy);
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
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		double x = vec[i].first;
		double y = vec[i].second;

		for (int j = i + 1; j < vec.size(); j++)
		{
			double x2 = vec[j].first;
			double y2 = vec[j].second;

			double cost = getCost(x, y, x2, y2);
			graph.push_back({ cost, {i,j} });
		}
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++)
	{
		if (!findParent(graph[i].second.first, graph[i].second.second))
		{
			unionParent(graph[i].second.first, graph[i].second.second);
			ans += graph[i].first;
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << ans;
}