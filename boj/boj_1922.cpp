#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
/*
	1. 정점의 개수 V , 간선의 개수 E
	2. 간선의 정보 A B C
	  - A 정점에서 B정점이 가중치 C인 간선이 연결되어있음
	  - C는 음수 일  수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

	3 3
	1 2 1
	2 3 2
	1 3 3
*/

int V, E, A, B, C;

vector<pair<int, pair<int, int>>> vec;
int parent[10001];
int sum;

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


int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		vec.push_back({ C,{A,B} });   // 간선 정보 저장
	}

	sort(vec.begin(), vec.end());     // 간선 비용 정렬

	// 정점의 부모설정
	for (int i = 1; i < V; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		// 사이클이 발생하지않는 경우  그래프에 포함
		// 간선의 노드1 , 노드2가 연결되어있지않은상태을때
		if (!findParent(vec[i].second.first, vec[i].second.second))
		{
			sum += vec[i].first; // 거리값 +
			unionFind(vec[i].second.first, vec[i].second.second); // 두 노드를 연결
		}
	}

	cout << sum;
}