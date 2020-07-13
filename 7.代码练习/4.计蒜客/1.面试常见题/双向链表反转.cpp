/************************************************************
    File Name : 双向链表反转.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 20:44:19
************************************************************/
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *pre;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* reverseLinkedList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *vhead = (ListNode *)malloc(sizeof(ListNode));
    vhead->next = head;
    head = head->next;
    vhead->next->pre = vhead;
    vhead->next->next = NULL;
    while (head) {
        ListNode *temp = head->next;
        head->next = vhead->next;
        head->pre = vhead;
        vhead->next->pre = head;
        vhead->next = head;
        head = temp;
    }
    return vhead->next;
}