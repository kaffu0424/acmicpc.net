#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N, L;
vector<pii> hole;
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		hole.push_back({ a,b });
	}

	sort(hole.begin(), hole.end());

	int cur = 0;
	int answer = 0;
	for (pii v : hole)
	{
		if (cur >= v.second)
			continue;

		cur = max(cur, v.first);

		int tmp = (v.second - (cur + 1)) / L + 1;
		answer += tmp;
		cur += L * tmp;
	}
	cout << answer;
}