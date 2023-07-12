// 백준 1149
#include <iostream>
#include <algorithm>

using namespace std;

int home[1001][3];
int cost[1001][3];
int N;
int main()
{
    cin >> N;
    for (int i = 0; i < 3; i++)
    {
        home[0][i] = 0;
        cost[0][i] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int i = 1; i <= N; i++)
    {
        home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
        home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
        home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
    }

    cout << min( home[N][0],min(home[N][1], home[N][2]));
}