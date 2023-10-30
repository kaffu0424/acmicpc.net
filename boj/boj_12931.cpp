#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N;
int ans = 0;
list<int> v;

bool flag = true;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		if (n != 0)
		{
			if (n % 2 == 0)
			{
				v.push_back(n);
			}

			else
			{
				n--;
				ans++;

				if (n == 0)
					continue;

				v.push_back(n);
			}
		}

	}

	while (v.size() > 0)
	{

		//  n / 2
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it % 2 == 0)
			{
				*it /= 2;
			}
		}
		ans++;

		// 홀수인것 확인.
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it % 2 != 0)
			{
				*it -= 1;
				ans++;
			}
		}

		v.remove(0);
	}
	cout << ans;
}