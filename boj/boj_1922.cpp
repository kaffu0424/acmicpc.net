#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
/*
	1. ������ ���� V , ������ ���� E
	2. ������ ���� A B C
	  - A �������� B������ ����ġ C�� ������ ����Ǿ�����
	  - C�� ���� ��  ���� ������, ������ 1,000,000�� ���� �ʴ´�.

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
		vec.push_back({ C,{A,B} });   // ���� ���� ����
	}

	sort(vec.begin(), vec.end());     // ���� ��� ����

	// ������ �θ���
	for (int i = 1; i < V; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		// ����Ŭ�� �߻������ʴ� ���  �׷����� ����
		// ������ ���1 , ���2�� ����Ǿ�����������������
		if (!findParent(vec[i].second.first, vec[i].second.second))
		{
			sum += vec[i].first; // �Ÿ��� +
			unionFind(vec[i].second.first, vec[i].second.second); // �� ��带 ����
		}
	}

	cout << sum;
}