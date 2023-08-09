#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
pair<int, int> dp[41]; // first : 0,  second : 1

int main()
{
	dp[3] = make_pair(1, 2);
	dp[2] = make_pair(1, 1);
	dp[1] = make_pair(0, 1);
	dp[0] = make_pair(1, 0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		if (dp[N].first != 0 || dp[N].second != 0) // �̹� ���Ȱ��� ������
		{
			cout << dp[N].first << " " << dp[N].second << "\n"; // ���
			continue; // ����
		}

		// �̹� ���Ȱ��� ���ٸ�
		for (int i = 4; i <= N; i++)  // ��������
		{
			if (dp[i].first != 0 || dp[i].second != 0)
				continue;

			// f(n) �� f(n-1) + f(n-2) 
			// f(n-1) �� 0,1 ȣ��Ƚ���� f(n-2) ȣ��Ƚ���� ���ϸ�
			// f(n) �� ȣ��Ƚ��
			dp[i] = { dp[i - 1].first + dp[i - 2].first , dp[i - 1].second + dp[i - 2].second };
			// ��� �����Ǿ �غ��� ��!
		}

		cout << dp[N].first << " " << dp[N].second << "\n";
	}
}