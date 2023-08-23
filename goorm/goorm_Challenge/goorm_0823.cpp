#include <iostream>
using namespace std;
int N;
int result = 0;
int main()
{
	cin >> N;

	result += (N / 14);
	N %= 14;

	result += (N / 7);
	N %= 7;

	result += (N / 1);
	N %= 1;

	cout << result;
}