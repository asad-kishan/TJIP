// 421. Maximum XOR of Two Numbers in an Array >> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Time: O(N) where N is the size of the given array
// Space: O(N)

class Solution {
    struct TrieNode {
        TrieNode* child[2];
        TrieNode() {
            for(int i = 0; i < 2; i++) {
                child[i] = nullptr;
            }
        }
    };

    class Trie {
        TrieNode* root;

        bool checkBit(int num, int pos) {
            int state = num & (1 << pos);
            return state > 0;
        }
        
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            auto curr = root;
            for(int pos = 30; pos >= 0; pos--) {
                bool curr_bit = checkBit(num, pos);
                if(!curr->child[curr_bit]) {
                    curr->child[curr_bit] = new TrieNode();
                }
                curr = curr->child[curr_bit];
            }
        }

        int findBestMatch(int num) {
            auto curr = root;
            int best_match = 0;
            for(int pos = 30; pos >= 0; pos--) {
                bool currBit = checkBit(num, pos);
                bool oppositeBit = currBit ^ 1;
                if(curr->child[oppositeBit]) {
                    best_match = best_match | (oppositeBit << pos);
                    curr = curr->child[oppositeBit];
                } else {
                    best_match = best_match | (currBit << pos);
                    curr = curr->child[currBit];
                }
            }
            return best_match;
        }
    };
    
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        trie->insert(nums[0]); 
        int max_xor = 0;
        for(int i = 1; i < nums.size(); i++) {
            int best_match = trie->findBestMatch(nums[i]);
            max_xor = max(best_match ^ nums[i], max_xor);
            trie->insert(nums[i]);
        }
        return max_xor;
    }
};
