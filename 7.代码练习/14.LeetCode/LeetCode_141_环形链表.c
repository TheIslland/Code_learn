/*************************************************************************
	> File Name: LeetCode_141_环形链表.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月19日 星期五 18时10分38秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    struct ListNode *p = head, *q = head->next;
    while (q && q->next) {
        if (p == q) return true;
        p = p->next;
        q = q->next->next;
    }
    return false;
}
