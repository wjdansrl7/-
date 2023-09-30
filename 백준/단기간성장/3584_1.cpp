#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = a;     \
    }
#define MAX_NODE 100001;

using namespace std;

int depth[MAX_NODE];
int ac[MAX_NODE][20];

typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];

int max_level;

void getTree(int here, int parent)
{
    depth[here] = depth[parent] + 1;

    ac[here][0] = parent;

    max_level = (int)floor(log2(MAX_NODE));

    for (int i = 1; i <= max_level; i++)
    {
        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }

    int len = graph[here].size();
    for (int i = 0; i < len; i++)
    {
        int there = graph[here][i];

        if (there != parent)
        {
            getTree(there, here);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    depth[0] = -1;

    getTree(1, 0);

    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        if (depth[a] != depth[b])
        {
            if (depth[a] > depth[b])
            {
                swap(a, b);
            }

            for (int i = max_level; i >= 0; i--)
            {
                if (depth[a] <= depth[ac[b][i]])
                {
                    b = ac[b][i];
                }
            }
        }

        int lca = a;

        if (a != b)
        {
            for (int i = max_level; i >= 0; i--)
            {
                if (ac[a][i] != ac[b][i])
                {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }

        cout << lca << '\n';
    }

    return 0;
}
