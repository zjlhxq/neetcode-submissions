class Solution {
public:
    Solution() { root = new TrieNode();}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        insertWords(words);
        int m = board.size();
        int n = board[0].size();
        vector<string> result;
        function<void(int, int, TrieNode*,string&)> dfs = [&](int r, int c, TrieNode* node,string& word) {
            if(r<0 || r == m || c < 0 || c == n ) return;
            
            char ch = board[r][c];
            if (board[r][c] == '#' || !node->children[ch - 'a']) {
                return;
            }
            
            node = node->children[ch - 'a'];
            word.push_back(ch);
            if(node->is_word) {
                result.push_back(word);
                node->is_word = false;
            }

            board[r][c] = '#';

            dfs(r + 1, c, node, word);
            dfs(r - 1, c, node, word);
            dfs(r, c + 1, node, word);
            dfs(r, c - 1, node, word);

            board[r][c] = ch;
            word.pop_back();
        };
        
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                string word = "";
                dfs(r, c, root, word);
            }
        }

        return result;
    }
    

private:
    struct TrieNode {
        bool is_word;
        vector<TrieNode*> children;

        TrieNode(): is_word(false), children(26, nullptr) {}
    };
    
    TrieNode* root;

    void insertWords(const vector<string>& words) {
        for(auto word: words) {
            insert(word);
        }
    }

    void insert(const string& word) {
        auto curr = root;
        for( char ch: word) {
            int index = ch - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->is_word = true;
    }
};
