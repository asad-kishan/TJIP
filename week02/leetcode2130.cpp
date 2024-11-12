// 2130. Maximum Twin Sum of a Linked List >> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Time: O(N) where N is the length of the linkedlist
// Space: O(1) as it uses constant space

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while(curr) {
            ListNode* _next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = _next;
        }
        slow->next = prev;

        int _max = 0;
        ListNode* p1 = head;
        ListNode* p2 = slow->next;
        while(p2) {
            _max = max(p1->val + p2->val, _max);
            p1 = p1->next;
            p2 = p2->next;
        }
        return _max;
    }
};
