#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, L;
int arr[5000001];
deque<int> chain;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		if (!chain.empty()) // 있을때.
		{
			if (chain.front() < i - L + 1)
				chain.pop_front();
		}

		while (!chain.empty())
		{

			if (arr[chain.back()] > arr[i])
				chain.pop_back();
			else
				break;
		}

		// 모든 연산에서 하는것
		chain.push_back(i);
		cout << arr[chain.front()] << " ";
	}
}