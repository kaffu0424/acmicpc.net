#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<int> v;
	long long N;
	cin >> N;

	long long num = 1;
	long long temp = 0;
	while (true)
	{
		temp += num;
		v.push_back(num);
		if (temp > N)
		{
			v.pop_back();
			break;
		}
		num++;
	}
	cout << v.size();
}