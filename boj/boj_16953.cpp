#include <iostream>
#include <queue>
using namespace std;

long long A, B;
queue<pair<long, long>> q;
long long bfs(long long a)
{
	q.push(make_pair(a, 1));
	while (!q.empty())
	{
		pair<long, long> t = q.front();
		q.pop();

		long long n = t.first;
		if (t.first == B)
		{
			return t.second;
		}

		if ((n * 10) + 1 <= B)
		{
			q.push(make_pair((n * 10) + 1, t.second + 1));
		}
		if (n * 2 <= B)
		{
			q.push(make_pair(n * 2, t.second + 1));
		}
	}
	return -1;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	cout << bfs(A);
}