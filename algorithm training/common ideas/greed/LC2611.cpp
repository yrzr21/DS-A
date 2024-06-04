#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 老鼠吃奶酪
    1 1 3 4 vs.
    4 4 1 1
    第一只老鼠吃掉其中的k块，求得分最大
    二者相减得：
    -3 -3 2 3，小于0则应第二只老鼠吃，否则第一只老鼠吃
    那么问题转化为：让第一只老鼠吃掉此数组中最大的k个奶酪，在k=2时，为3，4；第二只老鼠吃：4，4

    则吃的方案为：
        第二只老鼠吃完;第一只老鼠吃相对于它的差值的前k个
 */
int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
{
    vector<int> minus;
    int sum = 0;
    for (int i = 0; i < reward1.size(); i++)
    {
        minus.push_back(reward1[i] - reward2[i]);
        sum += reward2[i];
    }
    sort(minus.begin(), minus.end());
    for (int i = 0; i < k; i++)
    {
        sum += minus[minus.size() - 1 - i];
    }

    return sum;
}