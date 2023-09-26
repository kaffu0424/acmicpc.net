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
	// 3의 배수 +
	// 2뿌리개를 사용한 횟수가 3뿌리개 사용한횟수보다 많거나 같으면 YES
	// 아니면 NO ?
	if (sum % 3 != 0)
		cout << "NO";
	else
		if (tmp >= sum / 3)
			cout << "YES";
		else
			cout << "NO";
}