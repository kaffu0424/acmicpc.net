#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
* 문제
* 근력운동을 할때 1회 최대한으로 들 수 있는 무게를 IRM
* W는 무게 R은 반복횟수
* IRM = W x ( 1 + 30/R )
* IRM을 소수점 이하의 값을 버린후 출력
* 플레이어가 들 수 있는 무게는 무한히 크다고 가정
* 
* 입력
* 첫번째 줄에 무게W 와 반복횟수 R이 공백을 두고 주어진다.
* 1 <= W <= 1,000,000
* 1 <= R <= 100
*/
int main()
{
	float W, R,RM;
	cin >> W >> R;

	RM = W * (1 + (R/30));
	cout << static_cast<int>(RM);
}

