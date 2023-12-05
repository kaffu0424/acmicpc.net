#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
/*
* �׷����� ����Ŭ�� �߻��ϸ� ������ ���ϴ°��� �Ұ����� ���  0 ���
*/
int N, M;

int degree[1001];
vector<int> graph[1001];
queue<int> answer;

void sort()
{
	queue<int> q;

	// ���� ����  0�� ���
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
		{
			cout << "0";
			return;
		}

		int cur = q.front();
		q.pop();

		answer.push(cur);

		for (int v : graph[cur])
		{
			degree[v]--;
			if (degree[v] == 0)
			{
				q.push(v);
			}
		}
	}

	while (!answer.empty())
	{
		cout << answer.front() << endl;
		answer.pop();
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n, num;
		vector<int> input;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			input.push_back(num);
		}

		for (int j = 0; j < input.size() - 1; j++)
		{
			int from = input[j];
			int to = input[j + 1];

			graph[from].push_back(to);
			degree[to]++;
		}
	}

	sort();
}