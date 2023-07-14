#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<int> v;
int answer = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.rbegin(), v.rend());
	if (v.size() % 3 == 0)
	{
		for (int i = 0; i < n; i+=3)
		{
			answer += v[i] + v[i+1];
		}
		cout << answer;
		return 0;
	}
	else
	{
		int t = v.size() - (v.size() % 3);
		for (int i = 0; i < t; i += 3)
		{
			answer += v[i] + v[i + 1];
		}
		for (int i = t; i < n; i++)
		{
			answer += v[i];
		}
		cout << answer;
		return 0;
	}
}