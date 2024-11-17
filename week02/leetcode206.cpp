// 206. Reverse Linked List >> https://leetcode.com/problems/reverse-linked-list/
// Time: O(N) where N is the number of nodes
// Space: O(1) as it uses few constant spaces

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* _next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = _next;
        }
        return prev;
    }
};
