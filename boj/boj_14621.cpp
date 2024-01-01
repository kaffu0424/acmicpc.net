#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
string sex[1001];
int parent[1001];
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

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		sex[i] = s;

		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}
	sort(vec.begin(), vec.end());
}
void solve()
{
	int ans = 0;
	int edge = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int a = vec[i].second.first;
		int b = vec[i].second.second;
		int cost = vec[i].first;
		if (sex[a] == sex[b]) // 같은 성별이면 continue
			continue;

		if (!findParent(a, b))
		{
			unionParent(a, b);
			ans += cost;
			edge++;
		}
	}

	if (edge == N - 1)
		cout << ans;
	else
		cout << -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}