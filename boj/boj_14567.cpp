#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[1001];
int result[1001];
int degree[1001];

void solve()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0) // 진입차수가 0인 노드
		{
			q.push(i); // 큐에 삽입
			result[i] = 1; // 진입차수가 0인노드 == 1학기 
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int t = q.front();
		q.pop();
		for (int u : v[t])
		{
			degree[u]--;
			if (degree[u] == 0)
			{
				q.push(u);
				result[u] = result[t] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		v[A].push_back(B); // A -> B 연결
		degree[B]++; // B 진입차수 ++ 
	}

	solve();

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
}