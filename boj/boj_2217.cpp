#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> wk;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		wk.push_back(num);
	}

	sort(wk.begin(), wk.end(), comp);

	for (int i = 0; i < wk.size(); i++)
	{
		wk[i] = wk[i] * (i + 1);
	}
	sort(wk.begin(), wk.end(), comp);

	cout << wk[0];
}