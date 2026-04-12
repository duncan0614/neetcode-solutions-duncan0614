class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        return max(helper(vector<int>(nums.begin() + 1, nums.end())), helper(vector<int>(nums.begin(), nums.end() - 1)));
        
    }

    int helper(vector<int> nums) {
        int n = nums.size();
        if (nums.empty()) {
            return 0;
        }

        if (n == 1){
            return nums[0];
        }

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};