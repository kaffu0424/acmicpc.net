#include <iostream>
#include <vector>
using namespace std;


vector<int> arr[101];
bool visit[101];
int n, m, a, b, x, y;
int flag = false;
int answer;
void dfs(int v, int cnt)
{
	visit[v] = true;
	if (v == b)
	{
		answer = cnt;
		flag = true;
		return;
	}

	for (int u : arr[v])
	{
		if (!visit[u] && !flag)
			dfs(u, cnt + 1);
	}
}
int main()
{
	cin >> n; // ��ü�����
	cin >> a >> b; // �̼��� ����� ��ȣ
	cin >> m; // ���� ����
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	dfs(a, 0);
	if (flag)
		cout << answer;
	else
		cout << "-1";
}