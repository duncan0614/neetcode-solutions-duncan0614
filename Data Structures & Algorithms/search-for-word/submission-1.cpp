class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int x = board.size(), y = board[0].size();

        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int index) {
        if (word.length() == index) {
            return true;
        }

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }

        if (board[x][y] != word[index]) {
            return false;
        }
        
        char temp = board[x][y];
        board[x][y] = '*';

        bool foundWord = dfs(board, word, x + 1, y, index + 1) ||
                         dfs(board, word, x - 1, y, index + 1) ||
                         dfs(board, word, x, y + 1, index + 1) ||
                         dfs(board, word, x, y - 1, index + 1);
        
        board[x][y] = temp;
        return foundWord;
        
    }

};
