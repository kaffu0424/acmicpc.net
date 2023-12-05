#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
/*
	1. 정점의 개수 N , 간선의 개수 M
	2. 정점 A -> B  거리 C
*/

int N, M; // 
int A, B, C;

vector<pair<int, pair<int, int>>> vec; // { 거리 { A , B } }
vector<int> graph[111111];
bool visit[111111];
int parent[111111];
long long sum1 = 0;
long long sum2 = 0;

int getParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}

void unionFind(int a, int b)
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

void dfs(int n)
{
	visit[n] = true;
	for (int next : graph[n])
	{
		if (!visit[next])
		{
			dfs(next);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		vec.push_back({ C,{A,B} });
		sum1 += C;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}


	dfs(1);
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		if (!visit[i])
		{
			cout << "-1";
			return 0;
		}
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		// 연결되어있지않을때
		if (!findParent(vec[i].second.first, vec[i].second.second))
		{
			unionFind(vec[i].second.first, vec[i].second.second); // 연결
			sum2 += vec[i].first;
		}
	}

	long long ans = sum1 - sum2;
	cout << ans;
	return 0;

}