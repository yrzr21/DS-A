/* 给定单链表的头节点，要求反转链表，并返回反转后的单链表 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    /* 指针一：指向当前node，指针二：需更改指向的node，指向下一个node，指针三：指向node3
        2->1，1=2，2=3, 3->4,什么时候终止？2==nullptr
     */
    if (head == nullptr) // 调试2
        return nullptr;
    ListNode *prev = nullptr, *cur = head, *next = head->next;
    while (cur != nullptr)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next != nullptr) // 调试1
            next = next->next;
    }

    return prev;
}
