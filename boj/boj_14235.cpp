#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 백준 14235번
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int> q;
	int n, num;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		if (a != 0)
		{
			while (a--)
			{
				cin >> num;
				q.push(num);
			}
		}
		else
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
			{
				cout << q.top() << endl;
				q.pop();
			}
		}
	}
}
