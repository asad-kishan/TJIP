// 212. Word Search II >> https://leetcode.com/problems/word-search-ii/
// Time: O(MxNx3^L) where M is the number of rows, N is the number of columns & L is the max len of a word
// Space: O(T) T is the total length of all words combined

class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            word = "";
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* curr = root;
            for(char c : word) {
                if(!curr->child[c - 'a']) {
                    curr->child[c - 'a'] = new TrieNode();
                }
                curr = curr->child[c - 'a'];
            }
            curr->word = word;
        }
    };

    void backtrack(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& result) {
        char c = board[i][j];
        if(c == '#' || !curr->child[c - 'a']) return;

        curr = curr->child[c - 'a'];
        if(!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = "";
        }

        board[i][j] = '#'; // Mark the cell as visited
        if(i > 0) backtrack(board, i - 1, j, curr, result);
        if(i < board.size() - 1) backtrack(board, i + 1, j, curr, result);
        if(j > 0) backtrack(board, i, j - 1, curr, result);
        if(j < board[0].size() - 1) backtrack(board, i, j + 1, curr, result);

        board[i][j] = c;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        TrieNode* root = trie->root;
        for(auto &word : words) {
            trie->insert(word);
        }

        vector<string> result;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                backtrack(board, i, j, root, result);
            }
        }

        return result;
    }
};
