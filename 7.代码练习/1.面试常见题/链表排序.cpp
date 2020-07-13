/************************************************************
    File Name : 链表排序.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 16:55:28
************************************************************/
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* linkedListSort(ListNode *head) {
    ListNode *p, *end = NULL;
    while (head != end) {
        p = head;
        while (p->next != end) {
            if (p->val > p->next->val) {
                p->val ^= p->next->val;
                p->next->val ^= p->val;
                p->val ^= p->next->val;
            }
            p = p->next;
        }
        end = p;
    }
    return head;
}