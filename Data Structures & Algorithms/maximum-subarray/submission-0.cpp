class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int currentSub = 0;
        for (int& num : nums){
            if (currentSub < 0){
                currentSub = 0;
            }

            currentSub += num;
            maxSub = max(maxSub, currentSub);
        }

        return maxSub;
    }
};
