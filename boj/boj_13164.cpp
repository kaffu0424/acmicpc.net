#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N, K;
int arr[300001];
vector<int> cost;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		cost.push_back(arr[i] - arr[i - 1]);
	}
	sort(cost.begin(), cost.end());

	int answer = 0;
	for (int i = 0; i < N - K; i++)
	{
		answer += cost[i];
	}
	cout << answer;
}