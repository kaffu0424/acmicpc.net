#include <iostream>
#include <string>
#include <deque>
#include <queue>>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr[201];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;

		arr[age].push_back(name);
	}

	for (int i = 0; i < 201; i++)
	{
		if (arr[i].size() > 0)
		{
			for (int j = 0; j < arr[i].size(); j++)
			{
				cout << i << " " << arr[i][j] << "\n";
			}
		}
	}
}