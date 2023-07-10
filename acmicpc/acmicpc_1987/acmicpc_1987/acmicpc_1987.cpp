#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Y, X;
int count = 0;
vector<string> alp;
vector<vector<string>> arr;
vector<vector<int>> visited;

int dy[]{ -1,0,1,0 };
int dx[]{ 0,1,0,-1 };

void dfs(int y, int x)
{

}

int main()
{
    cin >> Y >> X;
    for (int y = 0; y < Y; y++)
    {
        string str;
        cin >> str;
        for (int x = 0; x < X; x++)
        {
            arr[y].push_back(to_string(str[x]));
            visited[y].push_back(0);
        }
    }

    dfs(0, 0);
}
