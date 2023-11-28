#include <iostream>
#include <math.h>
using namespace std;


int N;
void hanoi(int n, int from, int to, int by)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
    }
    else
    {
        hanoi(n - 1, from, by, to);
        cout << from << " " << to << "\n";
        hanoi(n - 1, by, to, from);
    }
}

int main()
{
    cin >> N;
    cout << (int)pow(2, N) - 1 << "\n"; // 이동횟수
    if (N == 1)
    {
        cout << 1 << " " << 3 << "\n";
        return 0;
    }
    hanoi(N, 1, 3, 2); // 이동경로
}