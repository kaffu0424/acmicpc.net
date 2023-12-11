#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int ansSum = 2000000000;
int ansSIndex;
int ansEIndex;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int sindex = 0;
	int eindex = N - 1;
	int sum = arr[sindex] + arr[eindex];
	ansSum = abs(sum);
	ansSIndex = sindex;
	ansEIndex = eindex;

	while (sindex < eindex)
	{
		if (sum == 0)
		{
			cout << arr[sindex] << " " << arr[eindex];
			return 0;
		}
		if (sindex + 1 == eindex)
			break;

		if (sum > 0)
		{
			sum -= arr[eindex];
			eindex--;
			sum += arr[eindex];
		}
		else
		{
			sum -= arr[sindex];
			sindex++;
			sum += arr[sindex];
		}

		if (abs(sum) < ansSum)
		{
			ansSum = abs(sum);
			ansSIndex = sindex;
			ansEIndex = eindex;
		}
	}
	cout << arr[ansSIndex] << " " << arr[ansEIndex];

}