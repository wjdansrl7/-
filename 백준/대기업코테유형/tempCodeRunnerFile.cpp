#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
long long s;
vector<long long> v;

int partial_sum(long long target)
{
    int start = 0, end = 1;
    int minLen = 987654321;

    // if (v[start] >= target)
    // {
    //     return 1;
    // }
    // else
    // {
    //     end++;
    // }

    while (start <= end && start <= v.size() - 1)
    {
        long long sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum += v[i];
        }
        if (sum >= target)
        {
            if (minLen >= end - start + 1)
            {
                minLen = end - start + 1;
                if (minLen == 2)
                {
                    return 2;
                }
            }
            start++;
        }
        else
        {
            if (end < v.size() - 1)
            {
                end++;
            }
            else
            {
                start++;
            }
        }
    }

    if (minLen == 987654321)
    {
        return 0;
    }
    else
    {
        return minLen;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> tmp;
    cin >> n >> s;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    tmp.assign(v.begin(), v.end());
    sort(tmp.begin(), tmp.end(), greater<>());

    if (tmp[0] >= s)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << partial_sum(s) << '\n';
    }

    return 0;
}
