#include <iostream>
using namespace std;

int n, m;
int arr[10];
void dfs(int L, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    else
    {
        for (int i = L; i <= n; i++)
        {
            arr[cnt] = i;
            dfs(i, cnt + 1);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dfs(1, 0);

    return 0;
}
