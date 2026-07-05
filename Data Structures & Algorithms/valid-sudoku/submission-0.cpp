class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        int m = board.size(), n = board[0].size();

        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                char curr_char = board[r][c];
                
                if(curr_char == '.') continue;
                
                int box = (r / 3) * 3 + c / 3;

                if(rows[r].contains(curr_char) || cols[c].contains(curr_char) || boxes[box].contains(curr_char)){
                    return false;
                }

                rows[r].insert(curr_char);
                cols[c].insert(curr_char);
                boxes[box].insert(curr_char);
            }
        }

        return true;
    }
};
