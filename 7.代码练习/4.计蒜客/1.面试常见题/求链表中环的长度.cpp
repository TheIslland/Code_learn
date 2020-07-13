/************************************************************
    File Name : 求链表中环的长度.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 19:13:11
************************************************************/
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
int linkedListCycleLength(ListNode *head) {
    if (head == NULL || head->next == NULL) return 0;
    ListNode *p = head->next->next, *q = head->next;
    while (p != q) {
        if (p->next == NULL || p->next->next == NULL) return 0;
        p = p->next->next;
        q = q->next;
    }
    int sum = 1;
    while (p->next != q) {
        p = p->next;
        sum++;
    }
    return sum;
}