// 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/description/

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int _val = 0, Node* _next = nullptr) {
            val = _val;
            next = _next;
        }
    };

    int len;
    Node* head;

public:
    MyLinkedList() {
        len = 0;
        head = new Node;
    }
    
    int get(int idx) {
        if(idx < 0 || idx >= len) return -1;

        Node* curr = head->next;
        while(idx--) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > len) return;

        Node* curr = head;
        while(index--) {
            curr = curr->next;
        }

        Node* newNode = new Node(val, curr->next);
        curr->next = newNode;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len) return;

        Node* curr = head;
        while(index--) {
            curr = curr->next;
        }

        Node* candidate = curr->next;
        curr->next = curr->next->next;
        delete candidate;
        len--;
    }
};
