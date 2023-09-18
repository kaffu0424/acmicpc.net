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

		if (cur.first == eY - 1 && cur.second == eX - 1) // 현재 위치가 도착지점이면
			return; // 종료

		for (int i = 0; i < 4; i++) // 상하좌우 방향만큼 반복
		{
			for (int j = 1; j <= K; j++) // K칸 이동가능
			{
				int ny = cur.first +(dy[i] * j); // 내위치 + (방향값 * k )
				int nx = cur.second + (dx[i] * j);

				// 범위벗어남 || 벽일때
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == '#')
					break; // 해당 방향으로 이동 중지

				//다음칸을 아직 방문하지않았다면
				if (visit[ny][nx] == 0) 
				{
					visit[ny][nx] = visit[cur.first][cur.second] + 1; // 이전위치에서 + 1만큼 가중치 
					q.push({ ny,nx }); // q에 담아주기
				}
				// 이미 방문을 했지만 가중치가 동일하다면 더 이동할수있음
				else if (visit[ny][nx] == visit[cur.first][cur.second] + 1) 
					continue;

				// 이미 방문을했고, 가중치도 다르다면  해당방향으로 이동 중지
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
	// 시작지점에서 +1 해주고
	// 출력할때 -1을 하면  도착지점에 갈수없을때 도착지점의 visit의 값은 0 - 1 = -1
}