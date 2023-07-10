#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 백준 14698번
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const long long mod = 1000000007;

	long long s;
	int T, N;
	cin >> T;
	while (T--)
	{
		priority_queue<long long, vector<long long>, greater<long long>> q;
		long long answer = 1;
		cin >> N;
		while (N--)
		{
			cin >> s;
			q.push(s);
		}

		while (q.size() >= 2)
		{
			long long a = q.top(); q.pop();
			long long b = q.top(); q.pop();
			q.push(a * b);

			int val = ((a % mod) * (b % mod)) % mod;
			answer *= val;
			answer %= mod;
		}

		cout << answer % mod << "\n";
	}
}