#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
* ����
* �ٷ¿�� �Ҷ� 1ȸ �ִ������� �� �� �ִ� ���Ը� IRM
* W�� ���� R�� �ݺ�Ƚ��
* IRM = W x ( 1 + 30/R )
* IRM�� �Ҽ��� ������ ���� ������ ���
* �÷��̾ �� �� �ִ� ���Դ� ������ ũ�ٰ� ����
* 
* �Է�
* ù��° �ٿ� ����W �� �ݺ�Ƚ�� R�� ������ �ΰ� �־�����.
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

