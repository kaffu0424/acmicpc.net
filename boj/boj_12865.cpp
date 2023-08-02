#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dp[101][100001];
int wArr[101];
int vArr[101];
int N, K, W, V;

int main()
{
	cin >> N >> K;  // ������ ���� n ,  ���� k
	for (int i = 1; i <= N; i++)
	{
		cin >> wArr[i] >> vArr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= wArr[i]) // �賶�� ������������
				// ���� ������ �־������� ��ġ�� ���� ������ �ִ� ��ġ�պ��� �������� ����ֱ�
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wArr[i]] + vArr[i]);
			else // �賶�� ��������
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}