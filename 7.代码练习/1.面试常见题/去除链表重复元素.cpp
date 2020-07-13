/************************************************************
    File Name : 去除链表重复元素.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 17:15:50
************************************************************/
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* linkedListUnique(ListNode *head) {
    ListNode *vhead = (ListNode *)malloc(sizeof(ListNode));
    vhead->next = head;
    ListNode *p = head;
    while (head) {
        if (p->val == head->val) {
            p->next = head->next;
            head = head->next; 
        } else {
            p = head;
        }
    }
    return vhead->next;
}