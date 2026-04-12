class Solution {
    /*
    U:
        I: n queens
        O: 2D matrix with 'Q' indicates a queen and '.' indicates an empty space.
        C: 
        E
    P:
    */
public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> ret;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return ret;
    }

private:
    void backtrack(int r, int n, vector<string>& board) {
        if (r == n) {
            ret.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n, board);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};
