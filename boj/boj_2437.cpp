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
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int ans = 1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > ans)
			break;

		ans += v[i];
	}
	cout << ans;
}
//1 1 2 3 6 7 30
//
//1 2 3  4  5  6  7  8  9  10 11 12 13
//8 9 10 11 12 13 14 15 16 17 18 19 20
//
//38 39 40
