#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, L;
vector<int> v;
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= L)
		{
			L++;
		}
	}

	cout << L;
}
