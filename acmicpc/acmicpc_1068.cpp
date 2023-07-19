#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
bool visit[50];
int N, root, del;
int answer = 0;
void dfs(int n)
{
	if (visit[n])
		return;
	visit[n] = true;

	// 자식노드가없거나, 
	// 자식노드가 1개 있지만,  삭제된 노드일경우
	if (tree[n].size() == 0 || (tree[n].size() == 1 && tree[n][0] == del))
		answer++;

	for (int v : tree[n])
	{
		if (v != del)
			dfs(v);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == -1)
			root = i;
		else
			tree[num].push_back(i);
	}
	cin >> del;
	if (root == del)
	{
		cout << 0;
		return 0;
	}
	dfs(root);
	cout << answer;
}

