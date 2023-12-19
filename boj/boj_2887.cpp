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
		xv.push_back({ x,i }); // x�� ��ġ�� ����ȣ�� ����
		yv.push_back({ y,i }); // y�� ��ġ�� ����ȣ�� ����
		zv.push_back({ z,i }); // z�� ��ġ�� ����ȣ�� ����
	}
	sort(xv.begin(), xv.end()); // x�� ��ġ�� �������� �������� ����
	sort(yv.begin(), yv.end()); // y�� ��ġ�� �������� �������� ����
	sort(zv.begin(), zv.end()); // z�� ��ġ�� �������� �������� ����

	int a, b, cost;

	/*
	x,y,z ���� �������� ������������ ����������
	���ӵ� �� (��ġ��,����ȣ)����  �ּ� �Ÿ����ɼ��ִ� ����
	�� ����� ��ȣ��, �������� ���õ� �Ÿ�����
	��� �������� ��Ƶδ� vec�� pushback
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