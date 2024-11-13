// 116. Populating Next Right Pointers in Each Node >> https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Time: O(N) where N is the number of nodes in the tree
// Space: O(1) as it uses constant space

class Solution {
public:
    Node* connect(Node* root) {
        Node* firstNode = root; // First node of the current level
        Node* curr = firstNode;
        while(curr) {
            Node* nextToCurr = curr->next;
            if(curr->left) {
                curr->left->next = curr->right;
            }
            if(curr->right && nextToCurr) {
                curr->right->next = nextToCurr->left;
            } 
            if(!nextToCurr) {
                curr = firstNode->left;
                firstNode = curr;
            } else {
                curr = nextToCurr;
            }
        }
        return root;
    }
};
