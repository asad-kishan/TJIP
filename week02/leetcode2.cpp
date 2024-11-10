// 2. Add Two Numbers >> https://leetcode.com/problems/add-two-numbers/
// Time: O(max(M,N)) where M & N are the lengths of l1 & l2
// Space: O(max(M,N))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dHead = new ListNode;
        ListNode* curr = dHead;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = carry;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dHead->next;
    }
};
