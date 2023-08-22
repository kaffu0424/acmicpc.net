#include <iostream>
#include <math.h>
using namespace std;


int N, M;
bool arr[1000001];
int main()
{
	cin >> M >> N;
	arr[1] = true;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i])
			continue;
		for (int j = i + i; j <= N; j += i)
			arr[j] = true;
	}

	for (int i = M; i <= N; i++)
		if (!arr[i])
			cout << i << "\n";
}
