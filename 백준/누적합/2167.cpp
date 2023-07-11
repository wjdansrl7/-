#include <iostream>
using namespace std;

int arr[301][301];
int dp[301][301];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    int k;
    cin >> k;

    int x1, x2, y1, y2;
    int result;
    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}
