#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 1026번: 보물
vector<int> A;
vector<int> B;


int main()
{
    int n,num;
    int sum = 0;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        B.push_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for (int i = 0; i < n; i++)
    {
        sum += A[i] * B[i];
    }

    cout << sum;
}
