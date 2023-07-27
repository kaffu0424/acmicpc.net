#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int N;

bool comp1(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
bool comp2(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(make_pair(num, i));
	}

	sort(v.begin(), v.end(), comp1);

	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp = v[i].first;
		v[i].first = idx;
		for (int j = i + 1; j < N; j++)
		{
			if (v[j].first == tmp)
			{
				v[j].first = idx;
				i++;
				continue;
			}
			break;
		}
		idx++;
	}

	sort(v.begin(), v.end(), comp2);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " ";
	}
}