class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        function<bool(int r, int c, int start, string& word)> backtrack = [&](int r, int c, int start, string& word) {
            if(start == word.size()) {
                return true;
            }

            if(r<0 || r == m || c < 0 || c == n) return false;

            char ch = board[r][c];
            if (ch == '#' || board[r][c] != word[start]) {
                return false;
            }

            board[r][c] = '#';
            if (backtrack(r+1, c, start + 1 , word)) return true;

            if (backtrack(r-1, c, start + 1, word)) return true;
            
            if (backtrack(r, c+1, start+ 1, word)) return true;

            if (backtrack(r, c-1, start + 1, word)) return true;

            board[r][c] = ch;

            return false;
        };

        for(int r=0; r<m; r ++) {
            for(int c=0; c<n; c++) {
                if (backtrack(r, c, 0, word) ) return true;
            }
        }    
        
        return false;
    }
};
