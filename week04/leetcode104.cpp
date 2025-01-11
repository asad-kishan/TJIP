// 104. Maximum Depth of Binary Tree >> https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Time: O(N) where N is the number of nodes in the tree
// Space: O(H) where H is the height of the tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        return max(left_max, right_max) + 1;
    }
};
