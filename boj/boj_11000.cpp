#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;
priority_queue<int, vector<int>, greater<int>> result;
int N;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	while (!pq.empty())
	{
		pii n = pq.top();
		pq.pop();
		if (result.empty())
		{
			result.push(n.second);
		}
		else
		{
			if (result.top() > n.first)
			{
				result.push(n.second);
			}
			else
			{
				result.pop();
				result.push(n.second);
			}
		}
	}
	cout << result.size();
}
