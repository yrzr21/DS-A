

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 返回倒数第cnt个结点 */

ListNode *trainingPlan(ListNode *head, int cnt)
{
    /* 一个指针遍历到末尾，记录共有多少个结点; 另一个指针再cur=cur->next sum-cnt次即可 */
    ListNode *cur = head;
    int length = 0;
    while (cur != nullptr)
    {
        length++;
        cur = cur->next;
    }
    cur = head;
    for (int i = 0; i < length - cnt; i++)
    {
        cur = cur->next;
    }

    return cur;
}
