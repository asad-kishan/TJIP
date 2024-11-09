// 237. Delete Node in a Linked List >> https://leetcode.com/problems/delete-node-in-a-linked-list/
// Time: O(1)
// Space: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;
    }
};
