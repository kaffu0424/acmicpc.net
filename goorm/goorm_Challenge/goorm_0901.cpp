include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> fruit; // { 가격 , 포만감 } , 1원당 조각 포만감 
int N, K, P, C;
long long answer = 0;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second > b.second;
}
int main()
{
	cin >> N >> K;
	pair<int, int> tmp;

	for (int i = 0; i < N; i++)
	{
		cin >> P >> C;
		pair<int, int> t = { P , C };
		fruit.push_back({ t, C / P });
	}

	sort(fruit.begin(), fruit.end(), comp);

	for (int i = 0; i < N; i++)
	{
		if (K - fruit[i].first.first >= 0)
		{
			answer += fruit[i].first.second;
			K -= fruit[i].first.first;
			continue;
		}
		answer += fruit[i].second * K;
		break;
	}

	cout << answer;
}
/*
P / C
2 , 8
7 , 35
1 , 5
3 , 12
10, 30
1 , 7

35 / 7 =

1 , 4
1 , 5
1 , 5
1 , 4
1 , 3
1 , 7

13 *
*/