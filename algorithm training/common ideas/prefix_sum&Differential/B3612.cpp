/* 给定一个正整数序列，求某区间内所有数的和，要求求多次这种和 */
#include <iostream>
using namespace std;

int n, m;
int a[100005];            // 正整数序列
int l[100005], r[100005]; // 所求区间，共m个
int sum[100005];          // 和数组

int main(int argc, char const *argv[])
{
    /* 输入 */
    cin >> n;
    for (size_t i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;
    cin >> m;
    for (size_t i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    sum[0] = 0;

    /* 求解 */
    // 先求原数组的和数组，然后某区间和 = sum[r[i]] - sum[l[i]-1]
    for (size_t i = 1; i <= n; i++)
        sum[i] = a[i] + sum[i - 1];
    for (size_t i = 1; i <= m; i++)
        cout << sum[r[i]] - sum[l[i] - 1] << "\n";

    return 0;
}
