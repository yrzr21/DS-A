#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* 给定入栈序列，询问是否可能的出栈序列为~ */

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        // input
        int n;
        cin >> n;
        vector<int> pushed, poped;
        for (int j = 0; j < n; j++)
        {
            int number;
            cin >> number;
            pushed.push_back(number);
        }
        for (int j = 0; j < n; j++)
        {
            int number;
            cin >> number;
            poped.push_back(number);
        }

        // 计算
        stack<int> s;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            s.push(pushed[i]);
            while (j != n && !s.empty() && poped[j] == s.top()) // 调试1：应递归检查
            {                                                   // 调试2：两个前置条件
                j++;
                s.pop();
            }
        }

        if (s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}