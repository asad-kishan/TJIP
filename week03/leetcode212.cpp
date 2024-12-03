// 212. Word Search II >> https://leetcode.com/problems/word-search-ii/
// Time: O(MxNx3^L) where M is the number of rows, N is the number of columns & L is the max len of a word
// Space: O(T) T is the total length of all words combined

class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            isEnd = false;
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
            curr->isEnd = true;
        }
    };

    void backtrack(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& result, string& word) {
        char c = board[i][j];
        if(c == '#' || !curr->child[c - 'a']) return;

        word.push_back(c);
        board[i][j] = '#'; // Mark the cell as visited
        curr = curr->child[c - 'a'];
        if(curr->isEnd) {
            result.push_back(word);
            curr->isEnd = false;
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto& [di, dj] : directions) {
            int ni = i + di, nj = j + dj;
            if(ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                backtrack(board, ni, nj, curr, result, word);
            }
        }

        board[i][j] = c;
        word.pop_back();
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        TrieNode* root = trie->root;
        for(auto &word : words) {
            trie->insert(word);
        }

        vector<string> result;
        string word;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                backtrack(board, i, j, root, result, word);
            }
        }

        return result;
    }
};
