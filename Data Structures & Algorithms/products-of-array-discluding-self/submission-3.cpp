class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = nums.size();
        vector<int> ret(count, 1);

        for (int i = 1; i < count; i++) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        
        int postfix = 1;
        for (int i = count - 1; i >= 0; i--) {
            ret[i] *= postfix;
            postfix *= nums[i];
        }
        return ret;
    }
};
