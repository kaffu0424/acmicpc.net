#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;


int N, K, n1, n2;
vector<pair<int, int>> arr;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) // 1�� ������ ������
		return a.first > b.first; // 10���� �������� ����

	return a.second > b.second; // 2���� 1�� ������������ ����
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> n1;
		n2 = bitset<24>(n1).count();
		arr.push_back(make_pair(n1, n2));
	}

	sort(arr.begin(), arr.end(), comp);

	cout << arr[K - 1].first;
}