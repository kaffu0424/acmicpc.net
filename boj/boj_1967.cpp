#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N;
vector<pii> graph[10001]; // [출발] { 도착, 비용 }
int dist[10001];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second;

            if (dist[next] > dist[cur] + nextCost)
            {
                dist[next] = dist[cur] + nextCost;
                pq.push({ dist[next],next });
            }
            ;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    dijkstra(1);

    int maxCost = 0;
    int maxIndex = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INF)
            continue;

        if (maxCost <= dist[i])
        {
            maxCost = dist[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    dijkstra(maxIndex);

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INF)
            continue;

        if (maxCost <= dist[i])
            maxCost = dist[i];
    }

    cout << maxCost;
}