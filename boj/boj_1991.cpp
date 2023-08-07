#include <iostream>
#include <vector>
using namespace std;

// . = 46
// A = 65
vector<pair<int, int>> v[26];

void preoder(int n)
{
	cout << static_cast<char>(n + 'A');
	if (v[n][0].first >= 0)
		preoder(v[n][0].first);
	if (v[n][0].second >= 0)
		preoder(v[n][0].second);
}

void inorder(int n)
{
	if (v[n][0].first >= 0)
		inorder(v[n][0].first);
	cout << static_cast<char>(n + 'A');
	if (v[n][0].second >= 0)
		inorder(v[n][0].second);
}

void postorder(int n)
{
	if (v[n][0].first >= 0)
		postorder(v[n][0].first);
	if (v[n][0].second >= 0)
		postorder(v[n][0].second);
	cout << static_cast<char>(n + 'A');
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char s, a, b;
		cin >> s >> a >> b;

		v[s - 'A'].push_back(make_pair(a - 'A', b - 'A'));
	}

	preoder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}