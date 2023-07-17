#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[301];
int arr[301];
int answer = 0;
int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i]; // 계단 입력
	}

	if (N <= 2) // 계단수가 2개 이하일때
	{
		for (int i = 1; i <= N; i++)
			answer += arr[i];  // 전부 더한후
		cout << answer; //출력
		return 0;
	}

	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	DP[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= N; i++)
	{
		DP[i] = max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << DP[N];
}