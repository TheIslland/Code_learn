/************************************************************
    File Name : 6_从尾到头打印链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 10:33:53
************************************************************/
//暴力
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        ListNode *p = head;
        while (p) {
            ret.push_back(p->val);
            p = p->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
//递归
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
    vector<int> reversePrint(ListNode* head) {
        if (head == NULL) return {};
        vector<int> ret = reversePrint(head->next);
        ret.push_back(head->val);
        return ret;
    }
};
