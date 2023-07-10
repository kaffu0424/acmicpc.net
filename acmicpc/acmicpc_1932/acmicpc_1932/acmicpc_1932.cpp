#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//백준 1932번
vector<vector<int>> v;
vector<vector<int>> cache;
int n;

int cal(int y, int x)
{
	if (y >= n)
		return 0;


	int& ret = cache[y][x];
	if (ret != 0)
		return ret;


	ret = cal(y + 1, x) > cal(y + 1, x + 1) ? cal(y + 1, x) : cal(y + 1, x + 1);
	ret += v[y][x];
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		v.resize(n);
		cache.resize(n);
		for (int j = 0; j < i + 1; j++)
		{
			int num;
			cin >> num;
			v[i].push_back(num);
			cache[i].push_back(0);
		}
	}

	cout << cal(0, 0);
}