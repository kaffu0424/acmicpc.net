#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 11047번
int main()
{
	int N, K, num;
	int count = 0;
	int idx = 0;
	vector<int> v;
	cin >> N >> K;
	while (N--)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.rbegin(), v.rend());
	while (K > 0)
	{
		if (idx >= v.size())
			break;
		if (K - v[idx] >= 0)
		{
			K -= v[idx];
			count++;
		}
		else
			idx++;
	}

	cout << count;
}