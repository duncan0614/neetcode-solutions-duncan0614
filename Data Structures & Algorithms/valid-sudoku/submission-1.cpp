class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){

                if(board[row][col] == '.'){
                    continue;
                }

                int val = board[row][col] - '1';
                int subSquare = (row / 3) * 3 + col / 3;
                if(rows[row] & 1 << val || cols[col] & 1 << val || squares[subSquare] & 1 << val){
                    return false;
                }

                rows[row] |= 1 << val;
                cols[col] |= 1 << val;
                squares[subSquare] |= 1 << val;
            }
        }

        return true;
    }
};
