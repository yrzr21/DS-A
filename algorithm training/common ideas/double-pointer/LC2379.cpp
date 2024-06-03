#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* 给定wb字符串，寻找长度最小为k的连续黑字符串，返回涂黑的最小操作数 */

int minimumRecolors(string blocks, int k)
{
    /* lr从0开始染色，mark(01)数组标记染色，和为操作数
        区间长度小于k则r继续右移，碰到白的就记录，统计白的个数——即寻求长度为k的区间内，白色最少的数目
        一旦区间长度==k，记录当前白色数是否最小，l右移至白色——其余区间白色数一定相同
        r继续右移至长度等于k...l右移至下一个白色...r右移至...
     */
    int l = 0, minWhite = blocks.size() + 1, curWhite = 0;
    for (int r = 0; r < blocks.length(); r++)
    {
        curWhite += blocks[r] == 'W' ? 1 : 0;
        if (r - l + 1 < k)
            continue;
        // len = k
        while (l <= r && blocks[l] == 'B')
            l++;
        minWhite = curWhite < minWhite ? curWhite : minWhite; // 调试1
        if (l <= r)                                           // 调试3
        {
            l++;
            curWhite--; // 调试2
        }
    }
    return minWhite;
}

int main()
{
    string str;
    int k;
    cin >> str >> k;
    int rt = minimumRecolors(str, k);
    cout << rt << endl;
}