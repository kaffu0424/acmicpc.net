#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int graph[101][101];

int N;
priority_queue<int> tree;
priority_queue<int> ans;

int T = 0;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		tree.push(n);
	}

	while (!tree.empty())
	{
		int cur = tree.top();
		tree.pop();

		T++;
		ans.push(cur - tree.size());
	}

	cout << T + ans.top() + 1;
}
