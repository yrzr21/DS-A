
/* 写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，
    然后输出输入字符串中该字符的出现次数。（不区分大小写字母） */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    char ch;
    getline(cin, str);
    ch = getchar();

    /* 先把所有大写转换为小写，再遍历统计 */
    for (auto &i : str)
        i = tolower(i);
    ch = tolower(ch);

    int cnt = 0;
    for (auto i : str)
        if (i == ch)
            cnt++;

    cout << cnt;
    return 0;
}
