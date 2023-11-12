#include <iostream>
#include <string>
#include<regex>
#include <deque>
#include <vector>

using namespace std;

int N;
bool comp(string a, string b)
{
    // ���� ���ڿ��϶��� �н�
    if (a == b)
        return false;

    // �� ���ڿ��� �������� ���ڿ� ��
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

    // ��� �Է°��� 0�϶�.
    if (flag)
    {
        cout << "0";
        return 0;
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++)
        cout << v[i];
}
