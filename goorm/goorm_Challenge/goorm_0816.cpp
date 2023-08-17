#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int a, b;
char c;
int result = 0;
int main()
{
	cin >> N;
	while (N--)
	{
		cin >> a >> c >> b;
		switch (c)
		{
		case '+':
			result += a + b;
			break;
		case '-':
			result += a - b;
			break;
		case '*':
			result += a * b;
			break;
		case '/':
			result += a / b;
			break;
		}
	}
	cout << result;
}
