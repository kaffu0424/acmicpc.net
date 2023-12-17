#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int M, N;
int parent[200001];
vector<pair<int, pair<int, int>>> vec;
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


void init(int n)
{
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	vec.clear();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> M >> N;
		if (M == 0 && N == 0)
			break;

		init(M);

		int sum = 0;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			vec.push_back({ z,{x,y} });
			sum += z;
		}
		sort(vec.begin(), vec.end());

		for (int i = 0; i < vec.size(); i++)
		{
			int a = vec[i].second.first;
			int b = vec[i].second.second;
			int cost = vec[i].first;
			if (!findParent(a, b))
			{
				unionParent(a, b);
				ans += cost;
			}
		}

		cout << sum - ans << "\n";
	}
}