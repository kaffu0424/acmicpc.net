#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> primeNum;
int main()
{
	cin >> N;
	vector<bool> vec(N + 1, true);
	for (int i = 2; i * i <= N; i++)
	{
		if (vec[i])
		{
			for (int j = i + i; j <= N; j += i)
			{
				vec[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (vec[i])
			primeNum.push_back(i);
	}

	int front = 0;
	int back = 0;
	int sum = 0;
	int ans = 0;
	while (front <= back && back < primeNum.size())
	{
		if (sum < N)
		{
			sum += primeNum[back++];
		}
		else if (sum >= N)
		{
			sum -= primeNum[front++];
		}

		if (sum == N)
			ans++;
	}
	cout << ans;
}