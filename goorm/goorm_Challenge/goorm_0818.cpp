#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;


int N, K, n1, n2;
vector<pair<int, int>> arr;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) // 1의 개수가 같으면
		return a.first > b.first; // 10진수 기준으로 정렬

	return a.second > b.second; // 2진수 1의 개수기준으로 정렬
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