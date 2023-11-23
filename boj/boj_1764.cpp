#include <iostream>
#include <string>
#include <deque>
#include <queue>>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
string str;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	map<string, int> m;
	vector<string> v;
	for (int i = 0; i < N + M; i++)
	{
		cin >> str;
		m[str]++;

		if (m[str] > 1)
			v.push_back(str);
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}
