#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

pair<int, int> arr[200][200]; // {방향 , 횟수} 
// 방향값 0 1 2 3  순서대로 위 오른 아래 왼
int gY, gX, pY, pX;
bool pVisit[200][200], gVisit[200][200];
int N;

void goorm()
{
	gVisit[gY][gX] = true;
	while (true)
	{
		int dir = arr[gY][gX].first; // 방향
		int n = arr[gY][gX].second; // 횟수

		if (dir == 0) //위로 
		{
			for (int i = 0; i < n; i++)
			{
				gY--; // 한칸 위로
				if (gY < 0) // 0보다 작아지면
					gY = N - 1; // 배열의 반대쪽으로.

				if (gVisit[gY][gX]) // 이미 방문한곳이라면
					return; // 종료
				gVisit[gY][gX] = true; // 방문여부 체크.
			}
		}

		else if (dir == 1) // 오른쪽으로
		{
			for (int i = 0; i < n; i++)
			{
				gX++; // 한칸 오른쪽으로
				if (gX >= N) // 배열의 사이즈보다 커지면
					gX = 0; // 배열의 반대쪽으로 

				if (gVisit[gY][gX]) // 이미방문한곳이라면
					return;

				gVisit[gY][gX] = true;
			}
		}

		else if (dir == 2) // 아래로
		{
			for (int i = 0; i < n; i++)
			{
				gY++; // 한칸 아래로
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
				gX--; // 한칸 왼쪽으로
				if (gX < 0) // 0보다 작아지면
					gX = N - 1;

				if (gVisit[gY][gX]) // 이미방문한곳이라면
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
		int dir = arr[pY][pX].first; // 방향
		int n = arr[pY][pX].second; // 횟수

		if (dir == 0) //위로 
		{
			for (int i = 0; i < n; i++)
			{
				pY--; // 한칸 위로
				if (pY < 0) // 0보다 작아지면
					pY = N - 1; // 배열의 반대쪽으로.

				if (pVisit[pY][pX]) // 이미 방문한곳이라면
					return; // 종료
				pVisit[pY][pX] = true; // 방문여부 체크.
			}
		}

		else if (dir == 1) // 오른쪽으로
		{
			for (int i = 0; i < n; i++)
			{
				pX++; // 한칸 오른쪽으로
				if (pX >= N) // 배열의 사이즈보다 커지면
					pX = 0; // 배열의 반대쪽으로 

				if (pVisit[pY][pX]) // 이미방문한곳이라면
					return;

				pVisit[pY][pX] = true;
			}
		}

		else if (dir == 2) // 아래로
		{
			for (int i = 0; i < n; i++)
			{
				pY++; // 한칸 아래로
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
				pX--; // 한칸 왼쪽으로
				if (pX < 0) // 0보다 작아지면
					pX = N - 1;

				if (pVisit[pY][pX]) // 이미방문한곳이라면
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
