// 正方形内生产螺旋矩阵
// 一次做完一行/列
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));

        int l = 0, r = n - 1, t = 0, b = n - 1; // 上下左右,闭区间
        for (int number = 1; number <= n * n;)
        {
            // 从左到右
            for (int i = l; i <= r; i++)
                matrix[t][i] = number++;
            t++;
            // 从上到下
            for (size_t i = t; i <= b; i++)
                matrix[i][r] = number++;
            r--;
            // 从右到左
            for (int i = r; i >= l; i--)
                matrix[b][i] = number++;
            b--;
            // 从下到上
            for (int i = b; i >= t; i--)
                matrix[i][l] = number++;
            l++;
        }
        return matrix;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m = (new Solution)->generateMatrix(n);
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m.size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}