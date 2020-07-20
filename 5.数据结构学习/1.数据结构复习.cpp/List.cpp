/************************************************************
    File Name : List.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-19 星期天 20:27:22
************************************************************/
#include <iostream>
using namespace std;
template <typename Type>
class Node {
   public:
    Node() {}
    Node(Type val) {
        next = NULL;
        this->val = val;
    }

   public:
    Node<Type> *next;
    Type val;
};
template <typename Type>
class List {
   public:
    List() {
        head = Node<Type>();
        len = 0;
    }
    ~List() {
        Node<Type> *p = head.next;
        while (p) {
            Node<Type> *delete_node = p;
            p = p->next;
            delete p;
        }
    }
    bool insert(Type val, int ind) {
        if (ind < 0 || ind > len) return false;
        Node<Type> *node = new Node<Type>(val);
        Node<Type> *current_node = &head;
        while (ind--) {
            current_node = current_node->next;
        }
        node->next = current_node->next;
        current_node->next = node;
        len++;
        return true;
    }

    bool delete_node(int ind) {
        if (ind < 0 || ind >= len) return false;
        Node<Type> *current_node = &head;
        while (ind--) current_node = current_node->next;
        Node<Type> *delete_node = current_node->next;
        current_node->next = delete_node->next;
        delete_node->next = NULL;
        delete delete_node;
        len--;
        return true;
    }

    bool reverse() {
        if (len == 0) return true;
        Node<Type> *current_ndoe = head.next;
        head.next = NULL;
        while (current_ndoe) {
            Node<Type> *temp = current_ndoe->next;
            current_ndoe->next = head.next;
            head.next = current_ndoe;
            current_ndoe = temp;
        }
        return true;
    }
    void output() {
        Node<Type> *p = head.next;
        cout << "List = [";
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "]\n";
    }

   private:
    Node<Type> head;
    int len = 0;
};

int main() {
    List<int> a;
    int m, t;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        int b, c;
        if (t == 1) {
            cin >> b >> c;
            a.insert(b, c);
        } else if (t == 2) {
            cin >> b;
            a.delete_node(b);
        } else if (t == 3) {
            a.reverse();
            // a.search(b);
        } else {
            a.output();
        }
    }

    return 0;
}