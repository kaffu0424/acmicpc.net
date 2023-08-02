#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int T, N, K, W;

vector<int> v[1001];
int degree[1001];
int result[1001];
int times[1001];

void solve()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0) // 진입차수가 0인 노드
		{
			q.push(i); // 큐에 삽입
			result[i] = times[i]; // 시간도 넣어주기
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int t = q.front();
		q.pop();

		for (int u : v[t]) // 2 3
		{
			degree[u]--;

			result[u] = max(result[u], result[t] + times[u]);

			if (degree[u] == 0)
			{

				q.push(u);
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> times[i];
			result[i] = 0;
			degree[i] = 0;
			v[i].clear();
		}

		int A, B;
		for (int i = 0; i < K; i++)
		{
			cin >> A >> B;
			v[A].push_back(B);
			degree[B]++;
		}
		cin >> W;

		solve();

		cout << result[W] << "\n";
	}
}