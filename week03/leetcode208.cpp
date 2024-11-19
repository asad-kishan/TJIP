// 208. Implement Trie (Prefix Tree) >> https://leetcode.com/problems/implement-trie-prefix-tree/
// Time: O(L) per operation, where L is the length of the word
// Space: O(L) for a single insert() operation, O(1) for search() & startsWith()

class Trie {
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        bool isEnd;
        TrieNode() {
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char &ch : word) {
            if(!curr->child[ch]) {
                curr->child[ch] = new TrieNode();
            }
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }
    
    bool search(string word, bool is_prefix_search = false) {
        TrieNode* curr = root;
        for(char &ch : word) {
            if(!curr->child[ch]) return false;
            curr = curr->child[ch];
        }
        return is_prefix_search || curr && curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
