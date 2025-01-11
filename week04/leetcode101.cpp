// 101. Symmetric Tree >> https://leetcode.com/problems/symmetric-tree/
// Time: O(N) where N is the number of nodes in the tree
// Space: O(H) where H is the height of the tree

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left || !right) return false;

        return (left -> val == right -> val) &&
                isMirror(left -> left, right -> right) &&
                isMirror(left -> right, right -> left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root -> left, root -> right);
    }
};
