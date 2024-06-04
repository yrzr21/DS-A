struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head)
{
    /* 法1：哈希表 */
    /* 法2：快慢指针法
        note 1：有循环的话，不断next下去永远结束不了
        note 2：如果两个指针的相对速度为1，那么在有循环的情况下，二者终将相遇
        note 3：发现一个nullptr就不干了！
     */
    ListNode *fast = head, *slow = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast == nullptr)
            break;
        fast = fast->next;

        if (slow == fast) // 这需要一定的数学公式推导...
        {
            ListNode *ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }

    return nullptr;
}