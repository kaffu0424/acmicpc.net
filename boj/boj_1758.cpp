#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
long long answer;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.rbegin(), v.rend());

	for (int i = 0; i < N; i++)
	{
		if (v[i] - i > 0)
			answer += v[i] - i;
	}

	cout << answer;
}