#include <iostream>
#include <string>
#include<regex>
#include <deque>
#include <vector>

using namespace std;

int N;
bool comp(string a, string b)
{
    // 동일 문자열일때는 패스
    if (a == b)
        return false;

    // 두 문자열을 더했을때 문자열 비교
    if (a + b > b + a)
        return true;

    return false;
}

int main()
{
    vector<string> v;
    cin >> N;

    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        string n;
        cin >> n;
        v.push_back(n);

        if (n != "0")
            flag = false;
    }

    // 모든 입력값이 0일때.
    if (flag)
    {
        cout << "0";
        return 0;
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++)
        cout << v[i];
}
