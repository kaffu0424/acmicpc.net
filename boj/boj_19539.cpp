#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;


int N;
int sum;
int n;
int tmp;
int main()
{
	// 1 and 2  || 3
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		sum += n;
		tmp += n / 2;
	}
	// 3�� ��� +
	// 2�Ѹ����� ����� Ƚ���� 3�Ѹ��� �����Ƚ������ ���ų� ������ YES
	// �ƴϸ� NO ?
	if (sum % 3 != 0)
		cout << "NO";
	else
		if (tmp >= sum / 3)
			cout << "YES";
		else
			cout << "NO";
}