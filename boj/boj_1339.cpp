#include <iostream>
#include <algorithm>
using namespace std;

int N;
int alp[26];
long long result = 0;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		int pow = 1;
		for (int j = str.length() - 1; j >= 0; j--)
		{
			alp[str[j] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(alp, alp + 26, comp);

	int num = 9;
	int answer = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alp[i] == 0)
			break;

		result += alp[i] * num--;
	}

	cout << result << endl;
}
