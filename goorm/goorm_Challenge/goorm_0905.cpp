#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int MAX = 100007;
vector<int> G[MAX];
ll compNum[MAX], edge[MAX], node[MAX];
bool visited[MAX];

void DFS(int cur, int num) {
    compNum[cur] = num;
    edge[num] += G[cur].size();
    node[num]++;
    for (int next : G[cur]) {
        if (visited[next]) continue;
        visited[next] = 1;
        DFS(next, num);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int num = 0;
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        DFS(i, ++num);
        edge[num] /= 2;
    }

    int ans = 1;
    for (int i = 2; i <= num; ++i) {
        if (edge[i] * node[ans] > edge[ans] * node[i]) ans = i;
        else if (edge[i] * node[ans] == edge[ans] * node[i]) {
            if (node[i] < node[ans]) ans = i;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (compNum[i] == ans) cout << i << ' ';
    }
    return 0;
}