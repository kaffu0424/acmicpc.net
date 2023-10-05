#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;


int N, T;
priority_queue<pii> pq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int t, s;
		cin >> t >> s;
		pq.push({ s,t });
	}

	pii tmp = pq.top();
	T = tmp.first - tmp.second;
	pq.pop();
	while (!pq.empty())
	{
		pii cur = pq.top();
		pq.pop();

		if (T < cur.first)
		{
			T -= cur.second;
		}
		else
		{
			T = cur.first;
			T -= cur.second;
		}
	}

	if (T < 0)
		cout << -1;
	else
		cout << T;
}
