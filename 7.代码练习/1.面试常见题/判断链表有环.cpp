/************************************************************
    File Name : 判断链表有环.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 19:27:34
************************************************************/
bool isLinkedListCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode *p = head, *q = head;
    while (p && p->next) {
        p = p->next->next;
        q = q->next;
        if (p == q) return true;
    }
    return false;
}