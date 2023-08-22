#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int N;
string str;
set<string> set1;
vector<string> v;
set<tuple<string, string, string>> set2;

int result = 0;


int main()
{
	cin >> N;
	cin >> str; // abcdefg

	string s, m, e;
	for (int i = 0; i < N - 2; i++)
	{
		// 초기화
		s += str[i]; // a, ab, abc, abcd , abcde
		m = "";
		e = "";
		for (int j = i + 1; j < N - 1; j++)
		{
			m += str[j]; // b , bc, bcd, bcde, bcdef
			e = str.substr(j + 1); // cdefg, defg, efg, fg, g

			set1.insert(s); // 중복 제거 set1
			set1.insert(m);
			set1.insert(e);
			set2.insert(make_tuple(s, m, e)); // tuple로 조합 추가 , 중복 제거 set2
		}
	}

	// vector에 다시 사전순으로 담아주기
	v.push_back(" ");
	for (auto it = set1.begin(); it != set1.end(); it++)
	{
		v.push_back(*it);
	}

	for (auto it = set2.begin(); it != set2.end(); it++)
	{
		tuple<string, string, string> tmp = *it;

		auto s1 = find(v.begin(), v.end(), get<0>(tmp));
		auto s2 = find(v.begin(), v.end(), get<1>(tmp));
		auto s3 = find(v.begin(), v.end(), get<2>(tmp));

		int n1 = distance(v.begin(), s1);
		int n2 = distance(v.begin(), s2);
		int n3 = distance(v.begin(), s3);

		result = max(result, n1 + n2 + n3);
	}

	cout << result;
}
