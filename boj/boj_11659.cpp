#include <iostream>
using namespace std;

int N, M;
int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] = arr[i - 1] + arr[i]; // 누적합 저장.
	}

	while (M--)
	{
		int a, b;
		cin >> a >> b;

		cout << arr[b] - arr[a - 1] << "\n";
	}
}