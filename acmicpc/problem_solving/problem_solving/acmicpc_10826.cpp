#include <iostream>
using namespace std;

int N;
int F[10001]{ -1 };

void Fibonacci(int n)
{

}

int main()
{
	cin >> N;
	F[0] = 0;
	F[1] = 1;

	Fibonacci(N);
	cout << F[N];
}