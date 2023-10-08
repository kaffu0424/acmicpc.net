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
		if (B[B.length() - 1] == 'A') // 가장 뒤 문자가 A일때
			B.pop_back(); // 삭제
		else // 가장 뒤 문자가 B일때
		{
			B.pop_back(); // 삭제
			reverse(B.begin(), B.end()); // 문자열 뒤집기
		}
	}

	if (!A.compare(B))
		cout << 1;
	else
		cout << 0;
}