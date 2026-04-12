class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const auto& num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;
        int target = sum / 2;
        unordered_set<int> dp;
        dp.insert(0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> tmp_dp;
            for (int num : dp) {
                if (num + nums[i] == target) {
                    return true;
                }
                tmp_dp.insert(num + nums[i]);
                tmp_dp.insert(num);
            }
            dp = tmp_dp;
        }
        return false;
    }
};
