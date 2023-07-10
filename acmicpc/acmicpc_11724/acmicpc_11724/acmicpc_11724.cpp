#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cnt = 0;
vector<bool> visit;
vector<vector<int>> graph;

void dfs(int n)
{
    visit[n] = false;
    for (int v : graph[n])
    {
        if (visit[v])
            dfs(v);
    }
}

int main()
{
    cin >> N >> M;
    visit.push_back(false);
    graph.resize(N+1);
    for (int i = 0; i < N; i++)
    {
        visit.push_back(true);
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visit[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;
}
