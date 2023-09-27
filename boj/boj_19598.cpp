#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;
int N;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		pq.push({ start,end });
	}

	priority_queue<int, vector<int>, greater<int>> result;
	while (!pq.empty())
	{
		pii cur = pq.top();
		pq.pop();

		if (result.empty()) // 현재 result 가 비어있으면. ( 첫번째 값)
		{
			result.push(cur.second);
			continue;
		}


		if (result.top() <= cur.first)
		{
			result.pop();
			result.push(cur.second);
		}
		else
		{
			result.push(cur.second);
		}
	}
	cout << result.size();
}