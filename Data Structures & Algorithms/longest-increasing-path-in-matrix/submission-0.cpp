class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp;

    int dfs (vector<vector<int>>& matrix, int r, int c, int prevVal) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || matrix[r][c] <= prevVal) {
            return 0;
        }

        if (dp[r][c] != -1) return dp[r][c];

        int ret = -1;
        for (vector<int> d : directions) {
            ret = max(ret, 1 + dfs(matrix, r + d[0], c + d[1], matrix[r][c]));
        }
        dp[r][c] = ret;
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        dp = vector<vector<int>>(ROWS, vector<int>(COLS, -1));
        int LIP = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                LIP = max(LIP, dfs(matrix, i, j, INT_MIN));
            }
        }
        return LIP;
    }
};
