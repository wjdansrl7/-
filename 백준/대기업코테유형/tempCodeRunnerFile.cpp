#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int n, m;
int pan[10][10];
int cost[10][10] = {
    0,
};
int dx[] = {1, 1, 1};
int dy[] = {-1, 0, 1};
stack<pair<int, pair<int, int>>> stk;

void DFS(int x, int y, int d)
{
    stk.push({d, {x, y}});
    cost[x][y] = pan[x][y];

    while (!stk.empty())
    {
        int x = stk.top().second.first;
        int y = stk.top().second.second;
        int d = stk.top().first;
        stk.pop();

        for (int i = 0; i < 3; i++)
        {
            if (d == i)
                continue;

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            else
            {
                if (cost[nx][ny] == 0)
                {
                    stk.push({i, {nx, ny}});
                    cost[nx][ny] = cost[x][y] + pan[nx][ny];
                }
                else if (cost[nx][ny] > cost[x][y] + pan[nx][ny])
                {
                    cost[nx][ny] = cost[x][y] + pan[nx][ny];
                    stk.push({i, {nx, ny}});
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pan[i][j];

    int res = INT_MAX;
    for (int i = 0; i < m; i++)
        DFS(0, i, -1);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < m; i++)
        res = min(res, cost[n - 1][i]);

    cout << res;
    return 0;
}
