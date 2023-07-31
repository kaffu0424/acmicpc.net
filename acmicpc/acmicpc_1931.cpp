#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());

	int answer = 1;
	pair<int, int> time = v[0];
	for (int i = 1; i < N; i++)
	{
		if (time.first <= v[i].second)
		{
			answer++;
			time = v[i];
		}
	}

	cout << answer;
}