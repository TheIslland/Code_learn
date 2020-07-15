/************************************************************
    File Name : 25_ 合并两个排序的链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 14:42:24
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(0), *p = ret;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    ret->next = l1;
                    ret = l1;
                    l1 = l1->next;
                } else {
                    ret->next = l2;
                    ret = l2;
                    l2 = l2->next;
                }
            }
            if (l1) {
                ret->next = l1;
            }
            if (l2) {
                ret->next = l2;
            }
            return p->next;
        }
    };