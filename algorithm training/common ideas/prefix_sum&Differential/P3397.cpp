/* 正方形格子上，盖m张地毯，求每个格子被上的地毯数目 */

#include <iostream>

using namespace std;
int n, m; // 边长n，m张地毯
int carpet[1002][1002];
int sum[1002][1002]; // 地毯矩阵和
int x1, y1, x2, y2;

// 加到地毯上
void add2carpet()
{
    carpet[x1][y1] += 1;
    carpet[x2 + 1][y2 + 1] += 1;
    carpet[x1][y2 + 1] -= 1;
    carpet[x2 + 1][y1] -= 1;
}

int main()
{
    cin >> n >> m;

    /* 总体思路：对于每张地毯，有：
            carpet[x1][y1]+=1,carpet[x2+1][y2+1]+=1,carpet[x1][y2+1]-=1,carpet[x2+1][y1]-=1
        对地毯矩阵求和，即可得到每个格子实际覆盖的地毯数目：
            sum[i][j]=carpet[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
        输出即可
     */
    for (int i = 1; i <= m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        add2carpet();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = carpet[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }
}