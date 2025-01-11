// 98. Validate Binary Search Tree >> https://leetcode.com/problems/validate-binary-search-tree/
// Time: O(N) where N is the number of nodes in the tree
// Space: O(H) where H is the height of the tree

class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, TreeNode* low, TreeNode* high) { 
        if(!root) return true;
        if(low && root -> val <= low -> val || high && root -> val >= high -> val) return false;
        bool leftStatus = isValidBSTHelper(root -> left, low, root);
        bool rightStatus = isValidBSTHelper(root -> right, root, high);
        return leftStatus && rightStatus;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
};
