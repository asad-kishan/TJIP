// 1268. Search Suggestions System >> https://leetcode.com/problems/search-suggestions-system/
// Time: O(3xLxS) where L is the maximum length of a product & S is the length of search word
// Space: O(T) T is the total length of all products combined

class Solution {
    struct TrieNode {
        bool isEnd;
        TrieNode* child[26];
        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(string &word) {
            TrieNode* curr = root;
            for(char ch : word) {
                if(!curr->child[ch - 'a']) {
                    curr->child[ch - 'a'] = new TrieNode();
                }
                curr = curr->child[ch - 'a'];
            }
            curr->isEnd = true;
        }
    };

    Trie* initTrie(vector<string> & strs) {
        Trie* trie = new Trie();
        for(string &str : strs) {
            trie->insert(str);
        }
        return trie;
    }

    void dfs(TrieNode* u, string &currWord, vector<string> &results) {
        if(!u || results.size() == 3) return;
        if(u->isEnd) {
            results.push_back(currWord);
        }
        for(int i = 0; i < 26; i++) {
            if(!u->child[i]) continue;
            currWord += (char) (i + 'a');
            dfs(u->child[i], currWord, results);
            currWord.pop_back();
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = initTrie(products);
        vector<vector<string>> suggestions;
        string typedWord;
        TrieNode* curr = trie->root;
        for(char ch : searchWord) {
            typedWord += ch;
            curr = curr ? curr->child[ch - 'a'] : nullptr;
            vector<string> results;
            dfs(curr, typedWord, results);
            suggestions.push_back(results);
        }
        return suggestions;
    }
};
