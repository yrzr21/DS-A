// 铺地毯问题
// 每次得到地毯后对矩形区域进行赋值会产生大量冗余操作
// 不如先得到所有地毯编号，然后对查询点，遍历地毯，得到最后的地毯编号

#include <iostream>
#include <vector>
using namespace std;

int n, rx, ry; // require x/y
vector<int> a, b, x, y;
int id = -1; // 最终id

// 查询点是否在该地毯内
bool inCarpet(int i)
{
    return rx >= a[i] && rx <= a[i] + x[i] && ry >= b[i] && ry <= b[i] + y[i];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a_, b_, x_, y_;
        cin >> a_ >> b_ >> x_ >> y_;
        a.push_back(a_);
        b.push_back(b_);
        x.push_back(x_);
        y.push_back(y_);
    }
    cin >> rx >> ry;

    // 针对查询点遍历
    for (int i = 0; i < a.size(); i++)
    {
        if (!inCarpet(i))
            continue;
        id = i + 1;
    }

    cout << id;
}