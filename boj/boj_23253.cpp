#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
int N, M;
int li[200001];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		for (int j = n - 1; j >= 0; j--)
		{
			int m;
			cin >> m;
			pq.push({ m,{i,j} });
		}
	}

	while (!pq.empty())
	{
		pair<int, pii> tmp = pq.top();
		pq.pop();
		if (li[tmp.second.first] != tmp.second.second)
		{
			cout << "No";
			return 0;
		}
		li[tmp.second.first]++;
	}
	cout << "Yes";
}