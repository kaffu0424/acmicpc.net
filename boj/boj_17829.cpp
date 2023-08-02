#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1024][1024];
int N;

vector<int> tmp;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (N != 2)
	{
		int yt = 0;
		int xt = 0;
		for (int y = 0; y < N; y += 2)
		{
			for (int x = 0; x < N; x += 2)
			{
				tmp.push_back(arr[y][x]);
				tmp.push_back(arr[y][x + 1]);
				tmp.push_back(arr[y + 1][x]);
				tmp.push_back(arr[y + 1][x + 1]);
				sort(tmp.begin(), tmp.end(), comp);
				arr[yt][xt++] = tmp[1];
				tmp.clear();
			}
			xt = 0;
			yt++;
		}
		N /= 2;
	}

	tmp.push_back(arr[0][0]);
	tmp.push_back(arr[0][1]);
	tmp.push_back(arr[1][0]);
	tmp.push_back(arr[1][1]);
	sort(tmp.begin(), tmp.end(), comp);
	cout << tmp[1];
}