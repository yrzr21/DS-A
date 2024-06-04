#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void move(int size, vector<int> &A, vector<int> &B, vector<int> &C)
{
    if (size == 1)
    {
        C.push_back(A.back()); // A[0]不一定为要求移动的块
        A.pop_back();
    }
    else
    {
        move(size - 1, A, C, B);
        move(1, A, B, C);
        move(size - 1, B, A, C);
    }
}

/* 从A移到C上, 一次移动一个 */
void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
{
    move(A.size(), A, B, C);
    // 用A.erase会超时，需要指定移动个数

    // /* 一个盘：直接移动 */
    // if (A.size() == 1)
    // {
    //     C.push_back(A[0]);
    //     A.erase(A.begin());
    // }
    // else if (A.size() == 2) // 两个盘，小盘移动到B，大盘-C，小盘-C
    // {
    //     hanota(A, C, B);
    //     hanota(A, B, C);
    //     hanota(B, A, C);
    // }
    // else
    // { // 三个盘及以上, 先移动最上面的一堆到B，再移动最大的到C，再移动最上面的到C
    //     int bottom = A[0];
    //     A.erase(A.begin());
    //     hanota(A, C, B);
    //     C.push_back(bottom);
    //     hanota(B, A, C);
    // }
}