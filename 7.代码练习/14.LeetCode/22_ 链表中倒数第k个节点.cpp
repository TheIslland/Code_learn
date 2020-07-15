/************************************************************
    File Name : 22_ 链表中倒数第k个节点.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 14:21:52
************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //if (head == NULL || k < 0) return NULL;
        ListNode *p = head, *q = head;
        while (k--) {
            if (p == NULL) break; 
            p = p->next;
        }
        if (k > 0) return NULL;
        while (p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};