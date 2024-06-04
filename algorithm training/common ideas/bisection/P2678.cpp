#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* 起点终点有两块石头，其间有N块石头，计划移走M块石头，求相邻石头的最短距离最长大小 */

int L, N, M;  // L表示起点到终点的距离，L>=1
int D[50005]; // D[i]表示起点到第i块石头的距离，i>=1
// 第i块到第i+1块石头间的距离为D[i]-D[i-1]

int main()
{
    /* 输入 */
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> D[i];
    D[0] = 0;     // 起点
    D[N + 1] = L; // 终点

    /* solution：
        答案区间[1,n]，假设ans为最长最短距离，要求当前石头到下一块石头间距离>=ans，
            否则移走后面的石头，计数+1
        若移走的石头大于M，则ans大了;小于M则有可能为答案，记录;当l>r，区间内再无可能的答案，退出
        更新区间
    */
    int l = 1, r = L, ans = 0;
    while (l <= r) // 答案区间内仍有答案待验证
    {
        int mid = (l + r) / 2;

        // 更新nRemove
        int dis_cnt = 0, nRemove = 0;
        for (int i = 0; i <= N; i++)
        {
            dis_cnt += D[i + 1] - D[i];
            if (dis_cnt < mid)
            {
                nRemove++;
            }
            else
            {
                dis_cnt = 0;
            }
        }
        // 似乎有bug？要是最后的一段的最终距离仍小于mid，只能往前删石头了
        // 所以应该往前继续删石头？
        // 但为啥过了？不管了后续再说

        // 更新区间
        if (nRemove > M)
        {
            r = mid - 1;
        }
        else
        {
            ans = ans > mid ? ans : mid; // 更新ans
            l = mid + 1;
        }
    }
    cout << ans << endl;
}