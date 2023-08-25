#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

pair<int, int> arr[200][200]; // {���� , Ƚ��} 
// ���Ⱚ 0 1 2 3  ������� �� ���� �Ʒ� ��
int gY, gX, pY, pX;
bool pVisit[200][200], gVisit[200][200];
int N;

void goorm()
{
	gVisit[gY][gX] = true;
	while (true)
	{
		int dir = arr[gY][gX].first; // ����
		int n = arr[gY][gX].second; // Ƚ��

		if (dir == 0) //���� 
		{
			for (int i = 0; i < n; i++)
			{
				gY--; // ��ĭ ����
				if (gY < 0) // 0���� �۾�����
					gY = N - 1; // �迭�� �ݴ�������.

				if (gVisit[gY][gX]) // �̹� �湮�Ѱ��̶��
					return; // ����
				gVisit[gY][gX] = true; // �湮���� üũ.
			}
		}

		else if (dir == 1) // ����������
		{
			for (int i = 0; i < n; i++)
			{
				gX++; // ��ĭ ����������
				if (gX >= N) // �迭�� ������� Ŀ����
					gX = 0; // �迭�� �ݴ������� 

				if (gVisit[gY][gX]) // �̹̹湮�Ѱ��̶��
					return;

				gVisit[gY][gX] = true;
			}
		}

		else if (dir == 2) // �Ʒ���
		{
			for (int i = 0; i < n; i++)
			{
				gY++; // ��ĭ �Ʒ���
				if (gY >= N)
					gY = 0;

				if (gVisit[gY][gX])
					return;

				gVisit[gY][gX] = true;
			}
		}

		else if (dir == 3)
		{
			for (int i = 0; i < n; i++)
			{
				gX--; // ��ĭ ��������
				if (gX < 0) // 0���� �۾�����
					gX = N - 1;

				if (gVisit[gY][gX]) // �̹̹湮�Ѱ��̶��
					return;

				gVisit[gY][gX] = true;
			}
		}
	}
}

int goormCheck()
{
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (gVisit[i][j])
				t++;
		}
	}
	return t;
}

void player()
{
	pVisit[pY][pX] = true;
	while (true)
	{
		int dir = arr[pY][pX].first; // ����
		int n = arr[pY][pX].second; // Ƚ��

		if (dir == 0) //���� 
		{
			for (int i = 0; i < n; i++)
			{
				pY--; // ��ĭ ����
				if (pY < 0) // 0���� �۾�����
					pY = N - 1; // �迭�� �ݴ�������.

				if (pVisit[pY][pX]) // �̹� �湮�Ѱ��̶��
					return; // ����
				pVisit[pY][pX] = true; // �湮���� üũ.
			}
		}

		else if (dir == 1) // ����������
		{
			for (int i = 0; i < n; i++)
			{
				pX++; // ��ĭ ����������
				if (pX >= N) // �迭�� ������� Ŀ����
					pX = 0; // �迭�� �ݴ������� 

				if (pVisit[pY][pX]) // �̹̹湮�Ѱ��̶��
					return;

				pVisit[pY][pX] = true;
			}
		}

		else if (dir == 2) // �Ʒ���
		{
			for (int i = 0; i < n; i++)
			{
				pY++; // ��ĭ �Ʒ���
				if (pY >= N)
					pY = 0;

				if (pVisit[pY][pX])
					return;

				pVisit[pY][pX] = true;
			}

		}

		else if (dir == 3)
		{
			for (int i = 0; i < n; i++)
			{
				pX--; // ��ĭ ��������
				if (pX < 0) // 0���� �۾�����
					pX = N - 1;

				if (pVisit[pY][pX]) // �̹̹湮�Ѱ��̶��
					return;

				pVisit[pY][pX] = true;
			}
		}
	}
}

int playerCheck()
{
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (pVisit[i][j])
				t++;
		}
	}
	return t;
}

int main()
{
	cin >> N;
	cin >> gY >> gX >> pY >> pX;
	gY--; gX--; pY--; pX--;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			string str;
			cin >> str;

			char tmp = str[str.length() - 1];
			str.erase(str.length() - 1, str.length());
			int n1;
			if (tmp == 'U') n1 = 0;
			else if (tmp == 'R') n1 = 1;
			else if (tmp == 'D') n1 = 2;
			else if (tmp == 'L') n1 = 3;
			int n2 = stoi(str);

			arr[i][j] = make_pair(n1, n2);
		}
	}

	goorm();
	int gr = goormCheck();
	player();
	int pr = playerCheck();
	if (gr > pr)
		cout << "goorm " << gr;
	else
		cout << "player " << pr;
}
