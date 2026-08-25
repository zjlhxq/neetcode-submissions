class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n,'.'));

        function<void(int)> backtrack = [&](int row) {
            if(row == n) {
                result.push_back(board);
                return;
            }

            for(int col = 0; col < n; col ++) {
                if(!isValid(board, row, col)) continue;

                board[row][col] = 'Q';
                backtrack(row + 1);
                board[row][col] = '.';
            }
        };

        backtrack(0);
        return result;
    };

private:
    bool isValid(vector<string>& board, int row, int col) {
        // check column
        for(int r = 0; r < row; r ++ ) {
            if(board[r][col] == 'Q') return false;
        }

        // check upper-left diagonal
        for(int r = row - 1, c = col - 1; r>=0 && c >= 0; r --, c--) {
            if(board[r][c] == 'Q') return false;
        }

        // check upper-right diagonal
        for(int r = row -1, c = col + 1; r >= 0 && c < board.size(); r --, c ++) {
            if(board[r][c] == 'Q') return false;
        }

        return true;
    }
};
