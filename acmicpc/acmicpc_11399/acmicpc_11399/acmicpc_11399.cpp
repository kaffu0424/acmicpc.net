#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 백준 11399
int main()
{
	int answer = 0;
	int temp = 0;
	int N, num;
	vector<int> v;
	cin >> N;
	while (N--)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		temp += v[i];
		answer += temp;
	}

	cout << answer;
}