#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;

const int MAXN = 1e5 + 2;
int N, M;
int pre[MAXN];

struct Edge
{
    Edge(int _n1, int _n2, int _days) :n1(_n1), n2(_n2), days(_days) {}
    int n1, n2, days;
    bool operator<(const Edge& e) const
    {
        return days < e.days;
    }
};
vector<Edge> ve;

int f(int x)
{
    int f0 = x, f1 = x;
    for (; pre[f0] > 0;) f0 = pre[f0];
    for (; pre[f1] > 0;)
    {
        int t = f1;
        f1 = pre[f1];
        pre[t] = f0;
    }
    return f0;
}

void u(int n1, int n2)
{
    int f1 = f(n1);
    int f2 = f(n2);
    if (f1 != f2)
    {
        cout<<pre[f1]<<" "<<pre[f2]<<endl;

        if (pre[f1] <= pre[f2])
        {
            pre[f1] += pre[f2];
            pre[f2] = f1;
        }
        else
        {
            pre[f2] += pre[f1];
            pre[f1] = f2;
        }
    }
}

int main()
{
    memset(pre, -1, sizeof pre);
    int a, b, c;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        //ve.push_back({ a,b,c });        // 用这个会编译错误的
        ve.push_back(Edge(a, b, c));
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < ve.size(); i++)
    {
        u(ve[i].n1, ve[i].n2);
        if (f(1) == f(N))
        {
            printf("%d\n", ve[i].days);
            break;
        }
    }

    return 0;
}