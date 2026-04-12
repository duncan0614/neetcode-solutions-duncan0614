class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(curMax * num, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            ret = max(ret, curMax);
        }

        return ret;
    }
};
