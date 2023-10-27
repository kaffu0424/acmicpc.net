#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
int N;
int map[52][52];
int visit[52][52];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs() {

    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    visit[0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (map[ny][nx] == 1)
                {
                    if (visit[ny][nx] > visit[y][x])
                    {
                        visit[ny][nx] = visit[y][x];
                        q.push(make_pair(nx, ny));
                    }
                }
                else
                {
                    if (visit[ny][nx] > visit[y][x] + 1)
                    {
                        visit[ny][nx] = visit[y][x] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int y = 0; y < N; y++)
    {
        string str;
        cin >> str;
        for (int x = 0; x < N; x++)
        {
            map[y][x] = str[x] - '0';
        }
    }
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            visit[y][x] = 987654321;
        }
    }
    bfs();
    cout << visit[N - 1][N - 1];
}
