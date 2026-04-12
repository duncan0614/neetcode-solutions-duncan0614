class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int r = 0, c = 0;
        for (r = 0; r < m; r++){
            dp[r][c] = 1;
        }
        
        r = 0;
        for (c = 0; c < n; c++){
            dp[r][c] = 1;
        }

        for (r = 1; r < m; r++){
            for(c = 1; c < n; c++){
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
            }
        }
        

        return dp[m-1][n-1];
    }
};
