#include <iostream>
using namespace std;

/*
10 ^ 11 % 12
= (10^5) * (10^5*10)
(a^b/2) * (a^b/2*a)
(A*B)%C = (A%C) * (B%C) % C;
((a^b/2)%c)*((a^b/2*a)%c) % c
*/

long long A, B, C;

long long modpow(long long b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return A % C;

	long long tmp = modpow(b / 2);
	b = static_cast<long long>(b);
	if (b % 2 == 0)
		return (tmp * tmp) % C;
	return (((tmp * tmp) % C) * A) % C;

}

int main()
{
	cin >> A >> B >> C;

	cout << modpow(B);
}