#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N;

int maxDp[3];
int minDp[3];
int main()
{
	cin >> N;
	for (int i = 0; i < 3; i++)
	{
		cin >> maxDp[i];
		minDp[i] = maxDp[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		int max0, max1, max2,
			min0, min1, min2;

		cin >> a >> b >> c;
		max0 = max(maxDp[0] + a, maxDp[1] + a);
		max1 = max(max(maxDp[0] + b, maxDp[1] + b), maxDp[2] + b);
		max2 = max(maxDp[1] + c, maxDp[2] + c);

		min0 = min(minDp[0] + a, minDp[1] + a);
		min1 = min(min(minDp[0] + b, minDp[1] + b), minDp[2] + b);
		min2 = min(minDp[1] + c, minDp[2] + c);

		maxDp[0] = max0; maxDp[1] = max1; maxDp[2] = max2;
		minDp[0] = min0; minDp[1] = min1; minDp[2] = min2;
	}

	cout << max(max(maxDp[0], maxDp[1]), maxDp[2]) << " ";
	cout << min(min(minDp[0], minDp[1]), minDp[2]);
}