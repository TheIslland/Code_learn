/************************************************************
    File Name : 合并两个有序链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 21:21:00
************************************************************/
/**
 * 已经定义的 ListNode 结点
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int _val) : val(_val), next(NULL) {}
 * };
 */
ListNode* mergeTwoSortedLinkList(ListNode *head1, ListNode *head2) {
    ListNode *vhead = new ListNode(0);
    ListNode *p = head1, *q = head2, *t = vhead;
    while (p && q) {
        if (p->val < q->val) {
            ListNode *temp = p->next;
            p->next = NULL;
            t->next = p;
            t = t->next;
            p = temp;
        } else {
            ListNode *temp = q->next;
            q->next = NULL;
            t->next = q;
            t = t->next;
            q = temp;
        }
    }
    while (p) {
        ListNode *temp = p->next;
        p->next = NULL;
        t->next = p;
        t = t->next;
        p = temp;
    } 
    while (q) {
        ListNode *temp = q->next;
        q->next = NULL;
        t->next = q;
        t = t->next;
        q = temp;
    }
    return vhead->next;
}

/**
 * 已经定义的 ListNode 结点
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int _val) : val(_val), next(NULL) {}
 * };
 */
ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    ListNode *p = head1, *q = head2;
    while (p != q) {
        p = (p ? p->next : head2);
        q = (q ? q->next : head1);
    }
    return p;
    
}