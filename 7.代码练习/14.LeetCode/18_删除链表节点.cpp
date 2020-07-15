/************************************************************
    File Name : 18_删除链表节点.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 11:49:18
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *vhead = new ListNode(0);
        vhead->next = head;
        ListNode *p = vhead;
        while (p->next) {
            if (p->next->val == val) {
                ListNode *del_node = p->next;
                p->next = del_node->next;
                //del_node->next = NULL;
                //delete(del_node);
                break;
            } else {
                p = p->next;
            }
        }
        return vhead->next;
    }
};