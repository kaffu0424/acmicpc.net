#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

priority_queue<int, vector<int>, less<int>> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
map<int, int> m;

int TC, num;
string command;

void Insertpq(int n)
{
	maxq.push(n);
	minq.push(n);

	m[n]++;
}

void deletepq(int n)
{
	// 최대값 삭제
	if (n == 1)
	{
		if (!maxq.empty())
		{
			m[maxq.top()]--;
			maxq.pop();
		}
	}

	//최소값 삭제
	else
	{
		if (!minq.empty())
		{
			m[minq.top()]--;
			minq.pop();
		}
	}
}

void Clearpq()
{
	while (!maxq.empty() && m[maxq.top()] == 0)
		maxq.pop();

	while (!minq.empty() && m[minq.top()] == 0)
		minq.pop();
}

void Printpq()
{
	if (maxq.empty() || minq.empty())
		cout << "EMPTY" << "\n";
	else
		cout << maxq.top() << " " << minq.top() << "\n";;
}

void Reset()
{
	while (!maxq.empty())
	{
		maxq.pop();
	}
	while (!minq.empty())
	{
		minq.pop();
	}

	m.clear();
}
int main()
{
	cin >> TC;
	while (TC--)
	{
		Reset();
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			cin >> command >> num;
			if (command == "I")
				Insertpq(num);
			else
				deletepq(num);
			Clearpq();
		}
		Clearpq();
		Printpq();
	}
}