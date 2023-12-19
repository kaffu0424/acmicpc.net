#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int ans = 0;
int parent[100001];
vector<pair<int, int>> xv;
vector<pair<int, int>> yv;
vector<pair<int, int>> zv;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i <= N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		xv.push_back({ x,i }); // x의 위치와 노드번호를 저장
		yv.push_back({ y,i }); // y의 위치와 노드번호를 저장
		zv.push_back({ z,i }); // z의 위치와 노드번호를 저장
	}
	sort(xv.begin(), xv.end()); // x의 위치를 기준으로 오름차순 정렬
	sort(yv.begin(), yv.end()); // y의 위치를 기준으로 오름차순 정렬
	sort(zv.begin(), zv.end()); // z의 위치를 기준으로 오름차순 정렬

	int a, b, cost;

	/*
	x,y,z 각각 기준으로 오름차순으로 정렬했을때
	연속된 두 (위치값,노드번호)값이  최소 거리가될수있는 노드쌍
	두 노드의 번호와, 문제에서 제시된 거리값을
	모든 간선값을 담아두는 vec에 pushback
	*/
	for (int i = 1; i < xv.size(); i++)
	{
		a = xv[i - 1].second;
		b = xv[i].second;
		cost = abs(xv[i].first - xv[i - 1].first);
		vec.push_back({ cost,{a,b} });
	}

	for (int i = 1; i < yv.size(); i++)
	{
		a = yv[i - 1].second;
		b = yv[i].second;
		cost = abs(yv[i].first - yv[i - 1].first);
		vec.push_back({ cost,{a,b} });
	}

	for (int i = 1; i < zv.size(); i++)
	{
		a = zv[i - 1].second;
		b = zv[i].second;
		cost = abs(zv[i].first - zv[i - 1].first);
		vec.push_back({ cost,{a,b} });
	}


	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		a = vec[i].second.first;
		b = vec[i].second.second;
		cost = vec[i].first;
		if (!findParent(a, b))
		{
			unionParent(a, b);
			ans += cost;
		}
	}
	cout << ans;
}