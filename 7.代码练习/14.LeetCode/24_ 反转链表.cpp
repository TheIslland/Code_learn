/************************************************************
    File Name : 24_ 反转链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 14:25:12
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
    ListNode* reverseList(ListNode* head) {
        ListNode *vhead = new ListNode(0);
        vhead->next = NULL;
        while (head) {
            ListNode *temp = head->next;
            head->next = vhead->next;
            vhead->next = head;
            head = temp;
        }
        return vhead->next;
    }
};

//妖魔化双指针
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return NULL; }
        ListNode* cur = head;
        while (head->next != NULL) {
            ListNode* t = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = t;
        }
        return cur;
    }
};