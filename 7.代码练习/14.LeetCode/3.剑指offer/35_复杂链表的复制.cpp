/************************************************************
    File Name : 35_复杂链表的复制.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 16:15:54
************************************************************/
//哈希法，通过hashmap建立原表复制表对应关系，通过映射特性进行建表
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<Node*, Node*> m;
        Node *p = head;
        while (p) {
            m[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p) {
            if (p->next) m[p]->next = m[p->next];
            if (p->random) m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }
};

//错位分割法，先在原表中在每一个节点后面加入一个赋值了值的复制点，然后根据前后对应关系复制random关系，最后分割两表
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *p = head;
        while (p) {
            Node *temp = p->next;
            p->next = new Node(p->val);
            p->next->next = temp;
            p = temp;
        }
        cout << endl;
        p = head;
        Node *q, *ret = p->next;
        while (p) {
            q = p->next;
            if (p->random != NULL) q->random = p->random->next;
            p = q->next;
        }
        p = head, q = p->next;
        while (q->next) {
            p->next = q->next;
            p = q->next;
            q->next = p->next;
            q = p->next;
        }
        p->next = NULL;
        return ret;
    }
};