#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int N, M, K;
int arr[1000][1000];
int visit[1000][1000];

int eY, eX;
void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visit[y][x] = 1;
	q.push({ y,x });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.first == eY - 1 && cur.second == eX - 1) // ���� ��ġ�� ���������̸�
			return; // ����

		for (int i = 0; i < 4; i++) // �����¿� ���⸸ŭ �ݺ�
		{
			for (int j = 1; j <= K; j++) // Kĭ �̵�����
			{
				int ny = cur.first +(dy[i] * j); // ����ġ + (���Ⱚ * k )
				int nx = cur.second + (dx[i] * j);

				// ������� || ���϶�
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == '#')
					break; // �ش� �������� �̵� ����

				//����ĭ�� ���� �湮�����ʾҴٸ�
				if (visit[ny][nx] == 0) 
				{
					visit[ny][nx] = visit[cur.first][cur.second] + 1; // ������ġ���� + 1��ŭ ����ġ 
					q.push({ ny,nx }); // q�� ����ֱ�
				}
				// �̹� �湮�� ������ ����ġ�� �����ϴٸ� �� �̵��Ҽ�����
				else if (visit[ny][nx] == visit[cur.first][cur.second] + 1) 
					continue;

				// �̹� �湮���߰�, ����ġ�� �ٸ��ٸ�  �ش�������� �̵� ����
				else
					break;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	int y1, x1;
	cin >> y1 >> x1;
	bfs(y1-1, x1-1);

	cin >> eY >> eX;
	cout << visit[eY-1][eX-1] - 1; 
	// ������������ +1 ���ְ�
	// ����Ҷ� -1�� �ϸ�  ���������� ���������� ���������� visit�� ���� 0 - 1 = -1
}