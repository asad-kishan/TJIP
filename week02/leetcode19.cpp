// 19. Remove Nth Node From End of List >> https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time: O(N) where N is the length of the linkedlist
// Space: O(1) as it uses constant space

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = dummy;
        while(n--) {
            right = right->next;
        }
        while(right->next) {
            left = left->next;
            right = right->next;
        }
        ListNode* temp = left->next;
        left->next = left->next->next;
        delete temp;
        return dummy->next;
    }
};
