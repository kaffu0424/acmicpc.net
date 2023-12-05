#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int parent[1001];
vector<pair<int, pair<int, int>>> vec; // { 비용 { A , B }

int getParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return;

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
	int n;
	cin >> N;

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	// i -> j 
	// n == 비용
	for (int from = 1; from <= N; from++)
	{
		for (int to = 1; to <= N; to++)
		{
			cin >> n;
			if (from == to) // 자기자신의 번호는 패스.
				continue;

			vec.push_back({ n,{from,to} });
		}
	}
	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (!findParent(vec[i].second.first, vec[i].second.second))
		{
			unionParent(vec[i].second.first, vec[i].second.second);
			ans += vec[i].first;
		}
	}

	cout << ans;
	return 0;
}