#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* 给定小行星序列，每个元素绝对值表示大小，+向右移动，-向左移动，且速度相同
    碰撞规则：相对运动，小的爆; 一样大都爆 ; 相同方向不碰撞
    返回最终剩余的小行星
 */

vector<int> asteroidCollision(vector<int> &asteroids)
{
    /* 从左端开始查看：第一颗小行星为-，则不碰撞，留下
        为+则可能碰撞，保留，检查第二颗，向左则碰撞，向右则

        不碰撞的情况：-栈空/+栈空
        检查一颗行星后，如果不碰撞，入栈，否则，与另一栈顶碰撞，直到不碰撞

        当遍历所有小行星，终止
     */
    /* 问题：左,右不可能碰撞 */
    /* 当前行星的方向：
        右：当前不可能碰撞，入栈
        左：1、右栈空，不可能碰撞，入栈；2、右栈有，检查
     */

    stack<int> left, right;
    for (auto cur : asteroids)
    {
        if (cur > 0)
        {
            right.push(cur);
            continue;
        }
        else if (right.empty())
        {
            left.push(cur);
            continue;
        }

        while (!right.empty() && right.top() < -1 * cur)
            right.pop();

        if (right.empty())
        {
            left.push(cur);
        }
        else
        { // cur爆炸了
            if (cur == -1 * right.top())
            {
                right.pop();
            }
        }
    }

    vector<int> res(left.size() + right.size());
    int size = res.size();
    // 三种情况：全左，全右，左右
    if (left.empty())
    {
        for (int i = 0; i < size; i++)
        {
            res[size - 1 - i] = right.top();
            right.pop();
        }
    }
    else if (right.empty())
    {
        for (int i = 0; i < size; i++)
        {
            res[size - 1 - i] = left.top();
            left.pop();
        }
    }
    else
    {
        int lsize = left.size(), rsize = right.size();
        for (int i = 0; i < rsize; i++)
        {
            res[size - 1 - i] = right.top();
            right.pop();
        }
        for (int i = 0; i < lsize; i++)
        {
            res[lsize - 1 - i] = left.top();
            left.pop();
        }
    }
    return res;
}