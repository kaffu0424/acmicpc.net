#include <iostream>
using namespace std;

int N, Th, Tm, c;
int main() {

	cin >> N >> Th >> Tm;
	while (N--)
	{
		cin >> c;
		Tm += c;
		if (Tm >= 60) // 60분이 넘으면
		{
			Th += Tm / 60;
			Tm %= 60;
		}
		if (Th >= 24)
		{
			Th -= 24;
		}
	}

	cout << Th << " " << Tm;
	return 0;
}