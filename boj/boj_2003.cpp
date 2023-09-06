#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[10000];
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int front = 0;
	int back = 0;

	int result = arr[0];
	int cnt = 0;
	while (front <= back && back < N) 
	{
		if (result < M) 
			result += arr[++back]; 

		else if (result == M) 
		{
			cnt++; 
			result += arr[++back]; 
		}

		else if (result > M)
		{
			result -= arr[front++];

			if (front > back)
			{
				back = front;
				result = arr[front];
			}
		}
	}

	cout << cnt;
}
