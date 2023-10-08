#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int main()
{


	string A;
	string B;
	cin >> A >> B;

	while (B.length() != A.length())
	{
		if (B[B.length() - 1] == 'A') // ���� �� ���ڰ� A�϶�
			B.pop_back(); // ����
		else // ���� �� ���ڰ� B�϶�
		{
			B.pop_back(); // ����
			reverse(B.begin(), B.end()); // ���ڿ� ������
		}
	}

	if (!A.compare(B))
		cout << 1;
	else
		cout << 0;
}