#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 백준 1417번
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int> q;

	int answer = 0;
	int T, ds, num;
	cin >> T;
	T--;
	cin >> ds;
	while (T--)
	{
		cin >> num;
		if (ds <= num)
			q.push(num);
	}

	while (!q.empty())
	{
		int val = q.top();
		q.pop();

		val--;
		ds++;
		answer++;

		q.push(val);

		if (ds > q.top())
			break;
	}

	cout << answer;
}