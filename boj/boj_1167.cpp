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
vector<pii> graph[100001]; // [출발] { 도착, 비용 }
int dist[100001];

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

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a;
        while (true)
        {
            cin >> b;
            if (b == -1)
                break;
            cin >> c;

            graph[a].push_back({ b,c });
        }
    }

    for (int i = 0; i < 100001; i++)
        dist[i] = INF;
    dijkstra(1);
    int maxCost = 0;
    int maxIndex = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dist[i] == INF)
            continue;

        if (maxCost <= dist[i])
        {
            maxCost = dist[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < 100001; i++)
        dist[i] = INF;
    dijkstra(maxIndex);

    maxCost = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dist[i] == INF)
            continue;

        if (maxCost <= dist[i])
            maxCost = dist[i];
    }

    cout << maxCost;
}