#include <iostream>
#include <string>
using namespace std;

/* 输入一个string和开始的index，返回第一个单词的index，-1为无单词 */
int find_word(const string &str, int cur)
{
    while (cur != str.length() && str[cur] == ' ')
        cur++;
    return cur == str.length() ? -1 : cur;
}
/* 输入一个string和一个word开始的indx，返回word最后一个字符的下一个位置的indx，可能为str.length() */
int word_end(const string &str, int cur)
{
    while (cur != str.length() && isalpha(str[cur]))
        cur++;
    return cur;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    // 流程：找到第一个单词，找到则--第一个单词末尾--计算长度--找下一个单词...
    int len = 9, last_word, cur = 0;
    while (str[cur] != str.length())
    {
        cur = find_word(str, cur);
        if (cur == -1)
            break;
        last_word = cur;
        cur = word_end(str, cur);
        len = cur - last_word;
    }
    cout << len << endl;

    return 0;
}
