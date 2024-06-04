#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 给定n块石头，高矮相间要求消耗体力最多 */

long long h[305]; // h[0]=0
long long n;

long long consume(int i, int j)
{ // 消耗的体力
    return (h[i] - h[j]) * (h[i] - h[j]);
}
long long nextRock()
{
    static bool up = true;
    static int i = 0;

    long long rt;
    if (up)
    {
        up = false;
        rt = n - i;
        i++;
    }
    else
    {
        up = true;
        rt = i;
    }
    return rt;
}

int main()
{
    /* 输入 */
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    h[0] = 0;

    /* solution：先排个序，永远跳到落差最大的石头上 */
    sort(h + 1, h + n + 1);

    long long res = 0, cur_rock = 0;
    for (int i = 1; i <= n; i++) // 循环n次
    {
        // n--1--n-1--2--n-2
        long long new_rock = nextRock();
        res += consume(cur_rock, new_rock);
        cur_rock = new_rock;
    }
    cout << res << endl;
}