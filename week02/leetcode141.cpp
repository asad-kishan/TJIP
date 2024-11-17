// 141. Linked List Cycle >> https://leetcode.com/problems/linked-list-cycle/
// Time: O(N) where N is the length of the linkedlist
// Space: O(1) as it uses constant space

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
