#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool comp(pii a, pii b)
{
	if (a.first < b.first)
		return true;

	if (a.first == b.first)
		return a.second < b.second;

	return false;
}

int main()
{
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, s, e;
		cin >> a >> s >> e;
		v.push_back({s, e});
	}
	sort(v.begin(), v.end(), comp);

	for (pii time : v)
	{
		//cout << time.first << " " << time.second << endl;
		if (pq.empty())
		{
			pq.push(time.second);
			continue;
		}

		if (pq.top() > time.first)
		{ 
			pq.push(time.second);
			continue;
		}

		pq.pop();
		pq.push(time.second);

	}
	cout << pq.size();
}
// s  e
// 2, 14
// 3, 8
// 6, 20
// 6, 27
// 7, 13
// 12,18
// 15,21
// 20,25

//pq
// 8 18
// 20 
// 13 21
// 14 25
// 27