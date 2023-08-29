#include <iostream>
#include <map>
#include <algorithm>
#define MOD 1000000007LL
using namespace std;

map<long long, long long> dp;

long long f(long long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	// key�� n�� ����  �ش� Ű���� �ش��ϴ� dp�� ���� ����.
	if (dp.count(n) > 0) return dp[n];

	// N �� ¦���ϋ�
	if (n % 2 == 0)
	{
		long long m = n / 2;
		long long tmp1 = f(m - 1);
		long long tmp2 = f(m);
		return dp[n] = (((2LL * tmp1) + tmp2) * tmp2) % MOD;
	}
	// Ȧ���϶�
	long long m1 = (n + 1) / 2;
	long long m2 = (n - 1) / 2;
	long long tmp1 = f(m1);
	long long tmp2 = f(m2);
	return dp[n] = (tmp1 * tmp1 + tmp2 * tmp2) % MOD;
}

int main()
{
	long long N;
	cin >> N;
	cout << f(N);
}
// m = n/2
// tmp1 = f(m-1)
// tmp2 = f(m)
// F[n] = tmp2 x ( (2*tmp1) + tmp2 )
// 
// 
// F[n] = F[(n + 1) / 2] ^ 2 + F[(n - 1) / 2] ^ 2