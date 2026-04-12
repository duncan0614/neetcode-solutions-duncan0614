class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = nums[1];
        if (nums.size() == 1){
            return dp[0];
        }
        else if (nums.size() == 2) {
            return max(dp[0], dp[1]);
        }

        for (int i = 2; i < n; i++) {
            int maxVal = 0;
            for (int j = 0; j < i - 1; j++) {
                maxVal = max(maxVal, dp[j] + nums[i]);
            }
            dp[i] = max(maxVal, dp[i - 1]);
        }

        return dp[n - 1];
    }
};
