#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* N堆香蕉，第i堆中有piles[i]根香蕉，可以吃h次，每小时吃k根，
    若吃完一堆也不会接着再吃
    求能吃完所有香蕉的最小k
 */

int minEatingSpeed(vector<int> &piles, int h)
{
    /* 吃的速度可能为:[1,max(piles)]或[1,10^9]
        反向验证得到耗时，比较耗时：
            若time>h，则吃得太慢了，l=mid+1;若time<=h，则有可能为答案，更新final_k，r=mid-1
     */
    int l = 1, r = 0, final_k = 1000000001;
    // 调试1：10^9似乎不太行？还是统计一遍吧
    for (auto &pile : piles)
        r = r < pile ? pile : r;

    while (l <= r)
    {
        int eating_speed = (l + r) / 2, time = 0;
        for (auto pile : piles)
        {
            time += pile / eating_speed; // 调试2：直接用除法吧，一点一点减时间还是会超时
            time += pile % eating_speed == 0 ? 0 : 1;
            // while (pile > 0)
            // {
            //     pile -= eating_speed;
            //     time++;
            // }
        }

        if (time > h)
        {
            l = eating_speed + 1;
        }
        else
        {
            final_k = final_k < eating_speed ? final_k : eating_speed;
            r = eating_speed - 1;
        }
    }
    return final_k;
}