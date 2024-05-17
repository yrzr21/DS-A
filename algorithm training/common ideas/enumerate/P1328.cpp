// 生活大爆炸石头剪刀布
// 两人各自规律性出拳,赢了加1分,其余不得分
#include <iostream>
#include <vector>
using namespace std;

int n, na, nb;
vector<int> a_circle, b_circle;
int winTable[5][5] = {
    {0, 1, -1, -1, 1}, // 1,-1,-1,1
    {-1, 0, 1, -1, 1},
    {1, -1, 0, 1, -1},
    {1, 1, -1, 0, -1},
    {-1, -1, 1, 1, 0}};
int nexta = -1, nextb = -1;
int nextA()
{
    nexta++;
    return a_circle[nexta % na];
}
int nextB()
{
    nextb++;
    return b_circle[nextb % nb];
}
int main()
{
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
    {
        int num;
        cin >> num;
        a_circle.push_back(num);
    }
    for (int i = 0; i < nb; i++)
    {
        int num;
        cin >> num;
        b_circle.push_back(num);
    }

    int score_a = 0, score_b = 0;
    for (int i = 0; i < n; i++)
    {
        int res = winTable[nextA()][nextB()];
        if (res == 0)
            continue;
        else if (res == 1)
        {
            score_a++;
        }
        else
        {
            score_b++;
        }
    }
    cout << score_b << " " << score_a; // 打表打反了,所以这里也反一下
}