// 138. Copy List with Random Pointer >> https://leetcode.com/problems/copy-list-with-random-pointer/
// Time: O(N) where N is the number of nodes 
// Space: O(N) considering the output list

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* copyHead = head->next;
        curr = head;
        Node* copyCurr = copyHead;
        while(curr) {
            curr->next = copyCurr->next;
            curr = copyCurr->next;
            if(curr) {
                copyCurr->next = curr->next;
                copyCurr = curr->next;
            }
        }
        return copyHead;
    }
};
