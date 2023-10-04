#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}


	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size() - 2; i++)
	{
		if (v[i] < v[i + 1] + v[i + 2])
		{
			cout << v[i] + v[i + 1] + v[i + 2];
			return 0;
		}
	}
	cout << -1;
}
