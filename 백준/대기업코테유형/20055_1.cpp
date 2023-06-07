#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

int n, k, x;
deque<bool> check; // 로봇이 있는지 없는지를 판단
deque<int> dq;     // 내구도가 저장된 덱
int ans = 0;

// 컨베이어 벨드의 내구도 측정 -> 0이 몇 개인지 반환
int find()
{
    int ret = 0;
    for (int i = 0; i < dq.size(); i++)
    {
        if (dq[i] == 0)
        {
            ret++;
        }
    }
    return ret;
}

void simul()
{
    while (1)
    {
        if (find() >= k)
            break;
        ans++;
        // 1. 벨트 회전
        dq.push_front(dq.back());
        dq.pop_back();
        // 벨트가 회전하면 로봇들도 회전해야 함.
        check.push_front(check.back());
        check.pop_back();
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
