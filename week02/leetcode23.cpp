// 23. Merge k Sorted Lists >> https://leetcode.com/problems/merge-k-sorted-lists/
// Time: O(NlogK) where N is the total number of nodes and K is the number of linkedlists
// Space: O(logK) due to the recursion stack depth though it's an inplace sorting 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0, list1);
        ListNode* prev = dummy; // Previous node of the list1
        while(list1 && list2) {
            if(list2->val < list1->val) {
                ListNode* temp = list2->next;
                prev->next = list2;
                prev = prev->next;
                prev->next = list1;
                list2 = temp;
            } else {
                prev = list1;
                list1 = list1->next;
            }
        }
        if(list2) {
            prev->next = list2;
        }
        list1 = dummy->next;
        delete dummy;
        return list1;
    }

    ListNode* merger(int l, int r, vector<ListNode*>& lists) {
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        int m = l + (r - l) / 2;
        ListNode* left = merger(l, m, lists);
        ListNode* right = merger(m + 1, r, lists);
        return mergeTwoLists(left, right); 
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merger(0, lists.size() - 1, lists);
    }
};
