/************************************************************
    File Name : 36_二叉搜索树与双向链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 19:30:16
************************************************************/

//通过中序遍历保证二叉搜索树在转链表后保持有序，定义pre记录前一节点指针，让当前利用中序遍历与二叉树性质，让当前节点指向pre节点
//让前一节点指向当前节点，来完成原地转化。
class Solution {
public:
    void change_Tree(Node *root, Node* &head, Node* &pre) {
        if (!root) return ;
        change_Tree(root->left, head, pre);
        if (!head) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        change_Tree(root->right, head, pre);
        return ;
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node *head = nullptr, *pre = nullptr;
        change_Tree(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
};