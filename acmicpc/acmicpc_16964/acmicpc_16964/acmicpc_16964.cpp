#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[100001];
bool visit[100001];
vector<int> order(100001);
vector<int> answer;

bool cp(int& a, int& b)
{
    return order[a] < order[b];
}

void dfs(int n)
{
    answer.push_back(n);

    for (int v : graph[n])
    {
        if (visit[v])
            continue;

        visit[v] = true;
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }


    vector<int> temp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> temp[i];
        order[temp[i]] = i + 1;
    }

    if (temp[0] != 1)
    {
        cout << "0";
        return 0;
    }


    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), cp);
    }

    visit[temp[0]] = true;
    dfs(temp[0]);

    for (int i = 0; i < answer.size(); i++)
    {
        if (temp[i] != answer[i])
        {
            cout << "0";
            return 0;
        }
    }
    cout << "1";
}