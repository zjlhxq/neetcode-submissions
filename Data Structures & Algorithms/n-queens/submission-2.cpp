class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n,'.'));

        unordered_set<int> cols_set;
        unordered_set<int> upper_left;
        unordered_set<int> upper_right;

        function<void(int)> backtrack = [&](int row) {
            if(row == n) {
                result.push_back(board);
                return;
            }

            for(int col = 0; col < n; col ++) {
                if(cols_set.contains(col) || upper_left.contains(row - col) || upper_right.contains(row + col))
                    continue;

                board[row][col] = 'Q';
                cols_set.insert(col);
                upper_left.insert(row-col);
                upper_right.insert(row+col);

                backtrack(row + 1);
                
                board[row][col] = '.';
                cols_set.erase(col);
                upper_left.erase(row - col);
                upper_right.erase(row + col);
            }
        };

        backtrack(0);
        return result;
    };

};
