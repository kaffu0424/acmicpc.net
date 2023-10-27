#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N;
priority_queue<pair<int, int>> pq;
bool checked[10001];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ b,a });
	}

	int ans = 0;
	while (!pq.empty())
	{
		for (int i = pq.top().second; i >= 1; i--)
		{
			if (!checked[i])
			{
				checked[i] = true;
				ans += pq.top().first;
				break;
			}
		}
		pq.pop();
	}
	cout << ans;
}
