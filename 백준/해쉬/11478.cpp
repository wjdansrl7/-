#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    unordered_map<string, int> m;

    string tmp;
    int cnt = 1;
    // for (int i = 1; i <= str.size(); i++)
    // {
    for (int j = 0; j <= str.size() - cnt; j++)
    {
        for (int k = j; k < cnt + j; k++)
        {
            tmp += str[k];
        }
        m[tmp]++;
        tmp.clear();
        cnt++;
    }
    // }

    cout << m.size();

    return 0;
}
