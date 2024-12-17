// 108. Convert Sorted Array to Binary Search Tree >> https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Time: O(N) where N is the size of the input array
// Space: O(N) 

class Solution {
public:
    TreeNode* BSTBuilder(vector<int>& nums, int L, int R) {
        if(L > R) return nullptr;
        int M = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[M]);
        root->left = BSTBuilder(nums, L, M - 1);
        root->right = BSTBuilder(nums, M + 1, R);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BSTBuilder(nums, 0, nums.size() - 1);
    }
};
