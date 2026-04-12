class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ret = 0;
        int lIdx = 0, rIdx = n - 1;

        for (int i = n; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] & (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ret++;
                }
            }
        }

        return ret;
    }
};
